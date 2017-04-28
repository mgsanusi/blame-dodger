from ast_lib import *
from sklearn import preprocessing, model_selection, svm, metrics
import pandas as pd
import random
import os
import numpy as np

def do_vars(filenames, files):
  dictionary = set()

  for fn, fl in zip(filenames, files):
    words = get_kmers("dataset/" + fn)
    fl.words = words 
    dictionary.update(words)

  for f in files:
    f.tf = {name:0 for name in dictionary}
    for word in f.words:
      f.tf[word] += 1

    l = len(f.words)
    f.vars_vec = [x/float(l) for x in f.tf.values()]

if __name__ == "__main__":
  filenames = os.listdir("../googlecodejam/dataset")
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

  #print(data)
  df = pd.DataFrame(data)
  df.to_csv("out.txt")
  y = df.iloc[:,-1]
  X = preprocessing.scale(df.ix[:, :len(data[0])-2])
  X_train, X_test, y_train, y_test = model_selection.train_test_split(X, y)

  classifier = svm.SVC()
  classifier.fit(X_train, y_train)

  print(X_test)

  y_pred = classifier.predict(X_test)
  print("same: " + str(same))
  print("not same: " + str(notsame))
  print("prediction:\n" + str(y_pred))
  print("actual:\n" + str(y_test.values.ravel()))
  print("accuracy: " + str(metrics.accuracy_score(y_test, y_pred)))
  print("confusion matrix: " + str(metrics.confusion_matrix(y_test, y_pred)))

  # 5) Train the model on unmodified data
  # 6) Later: Run it on modified data
  """
  for f in files:
    print(f.name)
    print(f.author)
    print(f.words)
  """
