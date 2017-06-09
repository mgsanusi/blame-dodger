from ast_lib import *
from sklearn.feature_selection import VarianceThreshold, SelectPercentile, SelectKBest, f_classif
from sklearn import preprocessing, model_selection, svm, metrics, ensemble, linear_model
import pandas as pd
import random
import os
import numpy as np

def do_vars(filenames, files, folder):
  dictionary = set()

  for fn, fl in zip(filenames, files):
    words = get_kmers(fn, folder)
    fl.words = words  # contains kmers
    dictionary.update(words)

  for f in files:
    f.tf = {name:0 for name in dictionary}
    for word in f.words:
      f.tf[word] += 1

    l = len(f.words)
    f.vars_vec = [x/float(l) for x in f.tf.values()] if l != 0 else [0 for x in f.tf.values()]

def run_main():
  filenames = os.listdir(sys.argv[1])
  files = []

  # 1) Populate dictionary and make file objects
  for fname in filenames:
    f = File(fname, fname.split("_")[0])
    files.append(f)

  do_vars(filenames, files, sys.argv[1])
  # 4) For each pair of vectors, take square difference combination
  data = []
  tmpdata = []
  same = 0
  notsame = 0
  for f1 in files:
    for f2 in files:
      if f1 is f2 : break
      result = [(a-b)**2 for a, b in zip(f1.vars_vec, f2.vars_vec)]
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
  print("Dimensions: " + str(X.shape))
  # default f_classif = ANOVA
  #X = SelectPercentile(percentile=85).fit_transform(X, y)
  #print("X after : " + str(X))
  print("dimensions: " + str(X.shape))
  X_train, X_test, y_train, y_test = model_selection.train_test_split(X, y)

  #classifier = linear_model.LinearRegression()
  #classifier = svm.SVC()
  classifier = ensemble.RandomForestClassifier()
  classifier.fit(X_train, y_train)

  prediction = classifier.predict(X_test)
  y_pred = []
  for entry in prediction:
    y_pred.append(1 if entry > 0.5 else 0)
  print("same: " + str(same))
  print("not same: " + str(notsame))
  print("accuracy: " + str(metrics.accuracy_score(y_test, y_pred)))
  #print("confusion matrix: " + str(metrics.confusion_matrix(y_test, y_pred)))

  return metrics.precision_recall_fscore_support(y_test, y_pred)

if __name__ == "__main__":

  prec = 0
  rec = 0
  fscore = 0
  for i in range(1):
    p, r, f, s = run_main()
    prec += p[0]
    rec += r[0]
    fscore += f[0]
  print("precision: " + str(prec/1))
  print("recall: " + str(rec/1))
  print("fscore: " + str(fscore/1))
 
