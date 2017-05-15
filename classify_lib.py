from ast_lib import *
import random
from sklearn import preprocessing, model_selection, svm, metrics, ensemble, linear_model
import pandas as pd
import os
import numpy

def do_lib(filenames, files, folder):
  dictionary = set()
  for fname, f in zip(filenames, files):
    f.words = get_lib(folder + "/" + fname)
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

  do_lib(filenames, files, "dataset")

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
        result.append((f1.name, f2.name))
        data.append(result)
      else:
        result.append(0)
        result.append((f1.name, f2.name))
        tmpdata.append(result)

  random.shuffle(tmpdata)
  data += tmpdata[0:same]
  pairs = [x[-1] for x in data]
  indices = [i for i, x in enumerate(data)]

  for i, each in enumerate(data):
    del each[-1]

  df = pd.DataFrame(data)
  y = df.iloc[:,-1]
  X = preprocessing.scale(df.ix[:, :len(data[0])-2])
  X_train, X_test, y_train, y_test, itrain, itest  = model_selection.train_test_split(X, y, indices)

  classifier = ensemble.RandomForestClassifier()
  #classifier = linear_model.LinearRegression()
  #classifier = svm.SVC()
  classifier.fit(X_train, y_train)

  y_pred = classifier.predict(X_test)
  print("prediction:\n" + str(y_pred))
  print("actual:\n" + str(y_test.values.ravel()))
  print("accuracy: " + str(metrics.accuracy_score(y_test, y_pred)))
  print(classifier.feature_importances_)
  """

  fps = []
  fns = []
  for yp, yt, i in zip(y_pred, y_test, itest):
    if yp == 1 and yt == 0: 
      fps.append(pairs[i])
    elif yp == 0 and yt == 1:
      fns.append(pairs[i])
  print("False Positives:")
  print("\n".join([x + ", " + y for x, y in fps]) + "\n")
  print("False Negatives:")
  print("\n".join([x + ", " + y for x, y in fns]))
  """

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


