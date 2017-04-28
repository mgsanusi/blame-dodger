from ast_lib import *
from sklearn import preprocessing, model_selection, svm, metrics
from classify_vars import do_vars
from classify_fc import do_functional
from classify_lib import do_lib
import pandas as pd
import random
import os
import numpy as np

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

for f in files:
  f.vec = f.vars_vec + f.lib_vec + f.fc_vec

data = []
tmpdata = []
same = 0
notsame = 0
for f1 in files:
  for f2 in files:
    if f1 is f2 : break
    result = [(a-b)**2 for a, b in zip(f1.vec, f2.vec)]
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

