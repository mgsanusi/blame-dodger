from ast_lib import *
from sklearn import preprocessing, model_selection, svm, metrics, ensemble, linear_model
from classify_vars import do_vars
from classify_fc import do_functional
from classify_lib import do_lib
from classify_ws import do_whitespace
import pandas as pd
import random
import os
import numpy as np

def run_main():
  filenames = os.listdir("dataset")
  files = []
  dictionary = set()

  for f in filenames:
    f = File(f, f.split("_")[0])
    files.append(f)

  print("getting variable names...")
  do_vars(filenames, files)
  print("getting functional features...")
  do_functional(filenames, files)
  print("getting library features...")
  do_lib(filenames, files)
  print("getting whitespace features...")
  whitespace = do_whitespace(filenames, files)

  for f, ws in zip(files, whitespace):
    f.vec = ws.ws_vec + f.vars_vec + f.fc_vec + f.lib_vec

  data = []
  tmpdata = []
  same = 0
  notsame = 0
  for f1 in files:
    for f2 in files:
      if f1 is f2 : break
      result = [(a-b)**2 for a, b in zip(f1.vec, f2.vec)]
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

  #print(data)
  df = pd.DataFrame(data)
  y = df.iloc[:,-1]
  X = preprocessing.scale(df.ix[:, :len(data[0])-2])
  X_train, X_test, y_train, y_test = model_selection.train_test_split(X, y)

  #classifier = linear_model.LinearRegression()
  classifier = ensemble.RandomForestClassifier()
  #classifier = svm.SVC()
  classifier.fit(X_train, y_train)

  print(X_test)
  prediction = classifier.predict(X_test)

  y_pred = []
  for entry in prediction:
    y_pred.append(1 if entry > 0.5 else 0)

  print("same: " + str(same))
  print("prediction:\n" + str(y_pred))
  print("actual:\n" + str(y_test.values.ravel()))
  print("accuracy: " + str(metrics.accuracy_score(y_test, y_pred)))
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
  print("precision: " + str(prec))
  print("recall: " + str(rec))
  print("fscore: " + str(fscore))
 
