from ast_lib import *
from sklearn import preprocessing, model_selection, svm, metrics
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

if __name__ == "__main__":
  filenames = os.listdir("dataset")
  files = []

  # 1) Populate dictionary and make file objects
  for f in filenames:
    fl = File(f, f.split("_")[0])
    files.append(fl)

  do_lib(filenames, files)

  # 4) For each pair of vectors, take the dot product
  data = []
  for f1 in files:
    for f2 in files:
      if f1 is f2 : break
      result = [(a-b)**2 for a, b in zip(f1.lib_vec, f2.lib_vec)]
      if f1.author == f2.author:
        result.append(1)
      else:
        result.append(0)
      data.append(result)

  df = pd.DataFrame(data)
  y = df.iloc[:,-1]
  X = preprocessing.scale(df.ix[:, :len(data[0])-2])
  X_train, X_test, y_train, y_test = model_selection.train_test_split(X, y)

  classifier = svm.SVC()
  classifier.fit(X_train, y_train)

  prediction = classifier.predict(X_test)
  print("prediction:\n" + str(prediction))
  print("actual:\n" + str(y_test.values.ravel()))
  print("accuracy: " + str(metrics.accuracy_score(y_test, prediction)))

  # 5) Train the model on unmodified data
  # 6) Later: Run it on modified data
  """
  for f in files:
    print(f.name)
    print(f.author)
    print(f.words)
  """

