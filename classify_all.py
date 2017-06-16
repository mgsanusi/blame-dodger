from ast_lib import *
from sklearn import preprocessing, model_selection, svm, metrics, ensemble, linear_model
from sklearn.externals import joblib
from sklearn.feature_selection import SelectPercentile, mutual_info_classif, f_classif
from classify_vars import do_vars
from classify_fc import do_functional
from classify_lib import do_lib
from classify_ws import do_whitespace
from classify_com import do_comments
import pandas as pd
import random
import math
import sys
import os
import numpy as np

def run_from_csv(folder):
  np.seterr(divide='ignore', invalid='ignore')

  f_labels = ["for", "typedef", "dowhile", "while", "case", "ternary", "avg line length", "percent empty lines"]
  #f_labels = ["avg meth length", "avg num params", "struct", "while", "case", "ternary", "avg line length", "percent empty lines"]
  l_labels = ["abs", "strtol", "qsort", "bzero", "strncmp", "strncpy", "strerror", "read", "memcmp", "free", "snprintf", "realloc", "atoi", "strtoll", "exit", "fgets", "sscanf", "memcpy", "atof", "atol", "puts", "srand", "fgetc", "sqrtl", "powl", "getline", "assert", "getchar", "putchar", "printf", "fprintf", "scanf", "fscanf", "strcat", "strcmp", "strcpy", "isdigit", "isalpha", "isalnum", "isspace", "toupper", "tolower", "errno", "islower", "isupper", "fabs", "pow", "sqrt", "time", "malloc", "calloc", "rand", "strlen", "freopen", "fopen", "strchr", "sprintf", "getc", "fclose", "memset"] 

  allfiles = os.listdir(folder)
  files = []
  filenames = []
  fileappend = files.append
  filenameappend = filenames.append

  feature_csv = open("feature_vectors.csv", "r").read().split("\n")
  for line in feature_csv:
    split_line = line.split(",")
    f = File(split_line[0], split_line[1])
    f.vec = [float(x) for x in split_line[2:]]
    fileappend(f)
    filenameappend(split_line[0])

  print("getting variable names...")
  do_vars(filenames, files, folder) # 1 feature

  var_len = len(files[0].vars_vec)
  labels = ["s4", "s6"]
  labels += f_labels
  labels += l_labels
  labels += ["var kmer" for x in range(0, var_len)]

  for f in files:
    f.vec += f.vars_vec

# now its: ws, fc, lib, vars
  if len(labels) != len(files[0].vec): # +1
    print("HOUSTON WE HAVE A PROBLEM")
  return process_data(files, labels)

def run_main(folder, write_csv=False):
  np.seterr(divide='ignore', invalid='ignore')

  #f_labels = ["for", "typedef", "dowhile", "while", "case", "ternary", "avg line length", "percent empty lines"]
  f_labels = ["assign to decl", "avg meth length", "nested", "main to method", "avg num params", "struct", "if", "for", "typedef", "dowhile", "while", "case", "ternary", "avg line length", "percent empty lines"]
  l_labels = ["abs", "strtol", "qsort", "bzero", "strncmp", "strncpy", "strerror", "read", "memcmp", "free", "snprintf", "realloc", "atoi", "strtoll", "exit", "fgets", "sscanf", "memcpy", "atof", "atol", "puts", "srand", "fgetc", "sqrtl", "powl", "getline", "assert", "getchar", "putchar", "printf", "fprintf", "scanf", "fscanf", "strcat", "strcmp", "strcpy", "isdigit", "isalpha", "isalnum", "isspace", "toupper", "tolower", "errno", "islower", "isupper", "fabs", "pow", "sqrt", "time", "malloc", "calloc", "rand", "strlen", "freopen", "fopen", "strchr", "sprintf", "getc", "fclose", "memset"] 

  allfiles = os.listdir(folder)
  files = []
  filenames = []
  fileappend = files.append
  filenameappend = filenames.append

  for fname in allfiles: 
    if not fname.endswith(".c"): continue
    f = File(fname, fname.split("_")[0])
    fileappend(f)
    filenameappend(fname)

  if not write_csv:
    print("getting variable names...")
    do_vars(filenames, files, folder) # 1 feature
  print("getting functional features...")
  do_functional(filenames, files, folder) # 12 features
  print("getting library features...")
  do_lib(filenames, files, folder) # 1 feature

  print("getting comments features...")
  do_comments(filenames, files, folder)

  print("getting whitespace features...")
  whitespace = do_whitespace(filenames, files, folder) # 5 features? 1 feature?

  var_len = len(files[0].vars_vec)
  fc_len = len(files[0].fc_vec)
  lib_len = len(files[0].lib_vec)
  #labels = ["variable names"]
  labels = ["s4", "s6"]
  labels += f_labels
  labels += l_labels
  labels += ["var kmer" for x in range(0, var_len)]
  if len(f_labels) != fc_len:
    print("STOP NOW")
  if len(l_labels) != lib_len:
    print("STOP IMMEDIATELY")
  labels += ["avg comment length", "num comments"]

  feature_vectors = []

  for f, ws in zip(files, whitespace):
    f.vec = ws.ws_vec + f.fc_vec + f.lib_vec + f.vars_vec + f.com_vec
    feature_vectors.append(",".join([str(x) for x in [f.name, f.author] + f.vec]))

  if write_csv:
    with open("feature_vectors.csv", "a+") as f:
      f.write("\n".join(run_main(sys.argv[1])))
    exit(0)

# now its: ws, fc, lib, vars
  if len(labels) != len(files[0].vec): # +1
    print("HOUSTON WE HAVE A PROBLEM")
  return process_data(files, labels)

def process_data(files, labels):

  data = []
  tmpdata = []
  same = 0
  notsame = 0
  dataappend = data.append
  tmpdataappend = tmpdata.append
  for f1 in files:
    for f2 in files:
      if f1 is f2 : break
      #dot = 0
      #bag1 = f1.bag
      #bag2 = f2.bag
      #len1 = len(f1.words)
      #len2 = len(f2.words)
      #mag1 = 0
      #mag2 = 0
      #for word in set(bag1.keys() + bag2.keys()):
      #  if word in bag1 and word in bag2:
      #    dot += (bag1[word]/float(len1))*(bag2[word]/float(len2))
      #    mag1 += (bag1[word]/float(len1))**2
      #    mag2 += (bag2[word]/float(len2))**2
      #  elif word in bag1:
      #    mag1 += (bag1[word]/float(len1))**2
      #  elif word in bag2:
      #    mag2 += (bag2[word]/float(len2))**2
      #  else:
      #    dot += 0
      #cos_sim = dot/(math.sqrt(mag1)*math.sqrt(mag2))
      #result = [cos_sim]
      #result += [(a-b)**2 for a, b in zip(f1.vec, f2.vec)]
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
  #joblib.dump(classifier, "my_model.pkl", compress=9)

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
    #p, r, f, s = run_from_csv(sys.argv[1])
    prec += p[0]
    rec += r[0]
    fscore += f[0]
  print("precision: " + str(prec))
  print("recall: " + str(rec))
  print("fscore: " + str(fscore))
 
