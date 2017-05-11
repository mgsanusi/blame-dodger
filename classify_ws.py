from ast_lib import *
import random
from sklearn import preprocessing, model_selection, svm, metrics, ensemble, linear_model
from multiprocessing import Pool
from contextlib import closing
from functools import partial
from itertools import izip
import pandas as pd
import os
import numpy

def one_pair(f):
  print(f.name)
  f.ws_vec = get_ws("dataset/" + f.name)
  return f
  
def do_whitespace(filenames, files):
  os.system("mkdir temp")

  with closing(Pool(processes=8)) as p:
    results = p.map(one_pair, files)
    p.terminate()

  os.system("rm -r temp")
  return results

def run_main():
  filenames = os.listdir("dataset")
  files = []
  random.shuffle(filenames)
  # 1) Populate dictionary and make file objects
  for f in filenames:
    fl = File(f, f.split("_")[0])
    files.append(fl)

  files = do_whitespace(filenames, files)

  data = []
  tmpdata = []
  same = 0
  for f1 in files:
    for f2 in files:
      if f1 is f2 : break
      result = [(a-b)**2 for a, b in zip(f1.ws_vec, f2.ws_vec)]
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
  print(df)
  y = df.iloc[:,-1]
  X = preprocessing.scale(df.ix[:, :len(data[0])-2])
  X_train, X_test, y_train, y_test = model_selection.train_test_split(X, y)

  classifier = linear_model.LinearRegression()
  #classifier = ensemble.RandomForestClassifier()
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

  # 5) Train the model on unmodified data
  # 6) Later: Run it on modified data

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