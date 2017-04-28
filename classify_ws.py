from ast_lib import *
import random
from sklearn import preprocessing, model_selection, svm, metrics
from multiprocessing import Pool
from contextlib import closing
from functools import partial
from itertools import izip
import pandas as pd
import os
import numpy

def one_pair(fname, f):
    print(fname)
    f.ws_vec = get_ws("dataset/" + fname)
    os.system("rm dataset/.* dataset/*~ dataset/*_gnu.c dataset/*_kr.c dataset/*_lx.c dataset/*_s1.c dataset/*_s2.c dataset/*_s3.c dataset/*_s4.c dataset/*_s5.c dataset/*_s6.c dataset/*_norm.c")
  

def do_whitespace(filenames, files):
  for fname, f in zip(filenames, files):
    one_pair(fname, f)
"""
  with closing(Pool(processes=8)) as p:
    p.map(one_pair, izip(filenames, files))
    p.terminate()
"""

filenames = os.listdir("dataset")
files = []
# 1) Populate dictionary and make file objects
for f in filenames:
  fl = File(f, f.split("_")[0])
  files.append(fl)

do_whitespace(filenames, files)
"""
with closing(Pool(processes=8)) as p:
  p.map(partial(do_whitespace, [filenames for i in range(len(filenames))]), [files for i in range(len(files))])
  p.terminate()
"""

data = []
for f1 in files:
  for f2 in files:
    if f1 is f2 : break
    result = [(a-b)**2 for a, b in zip(f1.ws_vec, f2.ws_vec)]
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


