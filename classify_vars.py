from ast_lib import *
from sklearn import preprocessing, model_selection, svm, metrics, ensemble, linear_model
import pandas as pd
import random
import os
import numpy as np

def do_vars(filenames, files):
  dictionary = set()

  for fn, fl in zip(filenames, files):
    words = get_full_names("dataset/" + fn)
    fl.words = words 
    dictionary.update(words)

  for f in files:
    f.tf = {name:0 for name in dictionary}
    for word in f.words:
      f.tf[word] += 1

    l = len(f.words)
    f.vars_vec = [x/float(l) for x in f.tf.values()]

def run_main():
  filenames = os.listdir("dataset")
  files = []

  # 1) Populate dictionary and make file objects
  for fname in filenames:
    f = File(fname, fname.split("_")[0])
    files.append(f)

  do_vars(filenames, files)
  # 4) For each pair of vectors, take square difference combination
  data = []
  tmpdata = []
  same = 0
  notsame = 0
  for f1 in files:
    for f2 in files:
      if f1 is f2 : break
      result = [(a-b)**2 for a, b in zip(f1.vars_vec, f2.vars_vec)]
      #result = [random.randint(0, 100)/float(100) for a, b in zip(f1.vec, f2.vec)]
      if f1.author == f2.author:
        same += 1
        result.append(1)
        data.append(result)
      else:
        notsame += 1
        result.append(0)
        tmpdata.append(result)

  random.shuffle(tmpdata)
  data += tmpdata[0:same]

  df = pd.DataFrame(data)
  df.to_csv("out.txt")
  y = df.iloc[:,-1]
  X = preprocessing.scale(df.ix[:, :len(data[0])-2])
  X_train, X_test, y_train, y_test = model_selection.train_test_split(X, y)

  classifier = linear_model.LinearRegression()
  #classifier = svm.SVC()
  #classifier = ensemble.RandomForestClassifier()
  classifier.fit(X_train, y_train)

  prediction = classifier.predict(X_test)
  y_pred = []
  for entry in prediction:
    y_pred.append(1 if entry > 0.5 else 0)
  print("same: " + str(same))
  print("not same: " + str(notsame))
  print("prediction:\n" + str(y_pred))
  print("actual:\n" + str(y_test.values.ravel()))
  print("accuracy: " + str(metrics.accuracy_score(y_test, y_pred)))
  print("confusion matrix: " + str(metrics.confusion_matrix(y_test, y_pred)))

  return metrics.precision_recall_fscore_support(y_test, y_pred)

if __name__ == "__main__":

  prec = 0
  rec = 0
  fscore = 0
  for i in range(5):
    p, r, f, s = run_main()
    prec += p[0]
    rec += r[0]
    fscore += f[0]
  print("precision: " + str(prec/5))
  print("recall: " + str(rec/5))
  print("fscore: " + str(fscore/5))
 
