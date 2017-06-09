from ast_lib import *
from sklearn import preprocessing, model_selection, svm, metrics, ensemble, linear_model
from sklearn.feature_selection import SelectPercentile, mutual_info_classif, f_classif
from classify_vars import do_vars
from classify_fc import do_functional
from classify_lib import do_lib
from classify_ws import do_whitespace
from classify_com import do_comments
import pandas as pd
import random
import sys
import os
import numpy as np

def run_main(folder):
  np.seterr(divide='ignore', invalid='ignore')

  f_labels = ["for", "typedef", "dowhile", "while", "case", "ternary", "avg line length", "percent empty lines"]
  #f_labels = ["avg meth length", "avg num params", "struct", "while", "case", "ternary", "avg line length", "percent empty lines"]
  l_labels = ["abs", "strtol", "qsort", "bzero", "strncmp", "strncpy", "strerror", "read", "memcmp", "free", "snprintf", "realloc", "atoi", "strtoll", "exit", "fgets", "sscanf", "memcpy", "atof", "atol", "puts", "srand", "fgetc", "sqrtl", "powl", "getline", "assert", "getchar", "putchar", "printf", "fprintf", "scanf", "fscanf", "strcat", "strcmp", "strcpy", "isdigit", "isalpha", "isalnum", "isspace", "toupper", "tolower", "errno", "islower", "isupper", "fabs", "pow", "sqrt", "time", "malloc", "calloc", "rand", "strlen", "freopen", "fopen", "strchr", "sprintf", "getc", "fclose", "memset"] 

  allfiles = os.listdir(folder)
  files = []
  filenames = []
  fileappend = files.append
  filenameappend = filenames.append

  for fname in allfiles: 
    if not fname.endswith(".c"): continue
    f = File(fname, fname.split("_")[0])
    #files.append(f)
    #filenames.append(fname)
    fileappend(f)
    filenameappend(fname)

  print("getting variable names...")
  do_vars(filenames, files, folder) # 1 feature
  print("getting functional features...")
  do_functional(filenames, files, folder) # 12 features
  print("getting library features...")
  do_lib(filenames, files, folder) # 1 feature
  #print("getting comments features...")
  #do_comments(filenames, files, folder)
  print("getting whitespace features...")
  whitespace = do_whitespace(filenames, files, folder) # 5 features? 1 feature?

  var_len = len(files[0].vars_vec)
  fc_len = len(files[0].fc_vec)
  lib_len = len(files[0].lib_vec)
  labels = ["var kmer" for x in range(0, var_len)]
  if len(f_labels) != fc_len:
    print("STOP NOW")
  if len(l_labels) != lib_len:
    print("STOP IMMEDIATELY")
  labels += f_labels
  labels += l_labels
  #labels += ["avg comment length", "num comments"]
  labels += ["s4", "s6"]


  for f, ws in zip(files, whitespace):
    f.vec = ws.ws_vec + f.vars_vec + f.fc_vec + f.com_vec + f.lib_vec

  if len(labels) != len(files[0].vec):
    print("HOUSTON WE HAVE A PROBLEM")

  data = []
  tmpdata = []
  same = 0
  notsame = 0
  dataappend = data.append
  tmpdataappend = tmpdata.append
  for f1 in files:
    for f2 in files:
      if f1 is f2 : break
      result = [(a-b)**2 for a, b in zip(f1.vec, f2.vec)]
      resultappend = result.append
      if f1.author == f2.author:
        same += 1
        resultappend(1)
        dataappend(result)
      else:
        notsame += 1
        resultappend(0)
        tmpdataappend(result)

  random.shuffle(tmpdata)
  data += tmpdata[0:same]
 # if same < notsame:
 # else:
 #   tmpdata += data[0:notsame]
 #   data = tmpdata

  df = pd.DataFrame(data)
  y = df.iloc[:,-1]
  X = preprocessing.scale(df.ix[:, :len(data[0])-2])
  print("Dimensions: " + str(X.shape))
  X = SelectPercentile(percentile=91).fit_transform(X, y)
  print("Dimensions: " + str(X.shape))
  X_train, X_test, y_train, y_test = model_selection.train_test_split(X, y)
  # 75 -- .90 f
  # 80 -- .91 f
  # 85 -- .90

  classifier = ensemble.RandomForestClassifier()
  classifier.fit(X_train, y_train)

  print(X_test)
  prediction = classifier.predict(X_test)

  y_pred = []
  for entry in prediction:
    y_pred.append(1 if entry > 0.5 else 0)

  print("same: " + str(same))
  #print("prediction:\n" + str(y_pred))
  #print("actual:\n" + str(y_test.values.ravel()))
  print("accuracy: " + str(metrics.accuracy_score(y_test, y_pred)))

  importances = classifier.feature_importances_
  label_power = [(label, power) for label, power in zip(labels, importances)]
  label_power = sorted(label_power, reverse=True, key=lambda x: x[1])
  print("\n".join([str(x) for x in label_power]))

  return metrics.precision_recall_fscore_support(y_test, y_pred)

if __name__ == "__main__":
  prec = 0
  rec = 0
  fscore = 0
  for i in range(1):
    p, r, f, s = run_main(sys.argv[1])
    prec += p[0]
    rec += r[0]
    fscore += f[0]
  print("precision: " + str(prec))
  print("recall: " + str(rec))
  print("fscore: " + str(fscore))
 
