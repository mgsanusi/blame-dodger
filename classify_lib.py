from ast_lib import *
import random
from sklearn import preprocessing, model_selection, svm, metrics, ensemble, linear_model
import pandas as pd
import os
import numpy

def do_lib(filenames, files):
  dictionary = set()
  for fname, f in zip(filenames, files):
    f.words = get_lib("dataset/" + fname)
    dictionary.update(f.words)

  for f in files:
    tf = {name:0 for name in dictionary}
    for word in f.words:
      tf[word] += 1
    f.lib_vec = [x/float(len(f.words)) for x in tf.values()]

def run_main():
  filenames = os.listdir("dataset")
  files = []

  # 1) Populate dictionary and make file objects
  for f in filenames:
    fl = File(f, f.split("_")[0])
    files.append(fl)

  do_lib(filenames, files)

  # 4) For each pair of vectors, take the dot product
  data = []
  tmpdata = []
  same = 0
  for f1 in files:
    for f2 in files:
      if f1 is f2 : break
      result = [(a-b)**2 for a, b in zip(f1.lib_vec, f2.lib_vec)]
      if f1.author == f2.author:
        same += 1
        result.append(1)
        data.append(result)
      else:
        result.append(0)
        tmpdata.append(result)

  random.shuffle(tmpdata)
  data += tmpdata[0:same]

  df = pd.DataFrame(data)
  y = df.iloc[:,-1]
  X = preprocessing.scale(df.ix[:, :len(data[0])-2])
  X_train, X_test, y_train, y_test = model_selection.train_test_split(X, y)

  #classifier = ensemble.RandomForestClassifier()
  classifier = linear_model.LinearRegression()
  #classifier = svm.SVC()
  classifier.fit(X_train, y_train)

  prediction = classifier.predict(X_test)
  y_pred = []
  for entry in prediction:
    y_pred.append(1 if entry > 0.5 else 0)

  print("prediction:\n" + str(y_pred))
  print("actual:\n" + str(y_test.values.ravel()))
  print("accuracy: " + str(metrics.accuracy_score(y_test, y_pred)))

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


