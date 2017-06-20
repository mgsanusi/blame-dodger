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

  feature_csv_file = open("feature_vectors_master.csv", "r")
  feature_csv = feature_csv_file.read().split("\n")
  for line in feature_csv:
    if line == "": continue
    split_line = line.split(",")
    f = File(split_line[0], split_line[1])
    f.vec = [float(x) for x in split_line[2:]]
    fileappend(f)
    filenameappend(split_line[0])

  feature_csv_file.close()

  print("getting variable names...")
  do_vars(filenames, files, folder) # 1 feature

  #var_len = len(files[0].vars_vec)
  labels = ["variable names", "casing"]
  labels += ["s4", "s6"]
  labels += f_labels
  labels += l_labels
  #labels += ["var kmer" for x in range(0, var_len)]

  for f in files:
    f.vec += f.vars_vec

# now its: ws, fc, lib, vars
  if len(labels) != len(files[0].vec)+2: # +1
    print("HOUSTON WE HAVE A PROBLEM")
  return process_data(files, labels)

def run_main(folder, write_csv=False):
  np.seterr(divide='ignore', invalid='ignore')

  f_labels = ["for", "typedef", "dowhile", "while", "case", "ternary", "avg line length", "percent empty lines"]
  #f_labels = ["assign to decl", "avg meth length", "nested", "main to method", "avg num params", "struct", "if", "for", "typedef", "dowhile", "while", "case", "ternary", "avg line length", "percent empty lines"]
  l_labels = ["abs", "strtol", "qsort", "bzero", "strncmp", "strncpy", "strerror", "read", "memcmp", "free", "snprintf", "realloc", "atoi", "strtoll", "exit", "fgets", "sscanf", "memcpy", "atof", "atol", "puts", "srand", "fgetc", "sqrtl", "powl", "getline", "assert", "getchar", "putchar", "printf", "fprintf", "scanf", "fscanf", "strcat", "strcmp", "strcpy", "isdigit", "isalpha", "isalnum", "isspace", "toupper", "tolower", "errno", "islower", "isupper", "fabs", "pow", "sqrt", "time", "malloc", "calloc", "rand", "strlen", "freopen", "fopen", "strchr", "sprintf", "getc", "fclose", "memset"] 

  allfiles = os.listdir(folder)
  files = []
  filenames = []
  fileappend = files.append
  filenameappend = filenames.append

  for fname in allfiles: 
    if not fname.endswith(".c"): continue
    f = File(fname, fname.split("_")[0])
    f.folder = folder
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
  #labels = ["variable names"]
  labels = ["s4", "s6"]
  labels += f_labels
  labels += l_labels
  labels += ["var kmer" for x in range(0, var_len)]
  if len(f_labels) != fc_len:
    print("STOP NOW")
  if len(l_labels) != lib_len:
    print("STOP IMMEDIATELY")
  #labels += ["avg comment length", "num comments"]

  feature_vectors = []

  for f, ws in zip(files, whitespace):
    f.vec = ws.ws_vec + f.fc_vec + f.lib_vec + f.vars_vec #+ f.com_vec
    feature_vectors.append(",".join([str(x) for x in [f.name, f.author] + ws.ws_vec + f.fc_vec + f.lib_vec]))

  if write_csv:
    with open("feature_vectors.csv", "a+") as f:
      f.write("\n".join(feature_vectors))

# now its: ws, fc, lib, vars
  if len(labels) != len(files[0].vec) + 1: # +1
    print("HOUSTON WE HAVE A PROBLEM")
  return process_data(files, labels)

def process_data(files, labels):

  data = []
  tmpdata = []
  same = 0
  notsame = 0
  dataappend = data.append
  tmpdataappend = tmpdata.append
  print("calculating pairwise vectors...")
  for f1 in files:
    for f2 in files:
      if f1 is f2 : break
      ## redo labels if dot product
      dot = 0
      bag1 = f1.bag
      bag2 = f2.bag
      len1 = len(f1.words)
      len2 = len(f2.words)
      mag1 = 0
      mag2 = 0
      for word in set(bag1.keys() + bag2.keys()):
        if word in bag1 and word in bag2:
          dot += (bag1[word]/float(len1))*(bag2[word]/float(len2))
          mag1 += (bag1[word]/float(len1))**2
          mag2 += (bag2[word]/float(len2))**2
        elif word in bag1:
          mag1 += (bag1[word]/float(len1))**2
        elif word in bag2:
          mag2 += (bag2[word]/float(len2))**2
        else:
          dot += 0
      cos_sim = 0
      if mag1 != 0 and mag2 != 0:
        cos_sim = dot/(math.sqrt(mag1)*math.sqrt(mag2))
      #else:
      #  print(f1.name + " or " + f2.name + " had a problem")
      casing = 1 if f1.camel_case == f2.camel_case else 0
      result = [cos_sim, casing]
      result += [(a-b)**2 for a, b in zip(f1.vec, f2.vec)]
      #result = [(a-b)**2 for a, b in zip(f1.vec, f2.vec)]
      resultappend = result.append
      if f1.author == f2.author:
        same += 1
        resultappend(1)
        resultappend(f1.author + "_" + f2.author)
        dataappend(result)
      else:
        notsame += 1
        resultappend(0)
        resultappend(f1.author + "_" + f2.author)
        tmpdataappend(result)

  
  random.shuffle(tmpdata)
  data += tmpdata[0:same]
  authors = [row[-1] for row in data]
 # if same < notsame:
 # else:
 #   tmpdata += data[0:notsame]
 #   data = tmpdata

  df = pd.DataFrame(data)
  y = df.iloc[:,-2] # -1
  X = preprocessing.scale(df.ix[:, :len(data[0])-3]) # 2
  indices = np.arange(df.shape[0])
  print("Dimensions: " + str(X.shape))
  #X = SelectPercentile(percentile=91).fit_transform(X, y)
  print("Dimensions: " + str(X.shape))
  X_train, X_test, y_train, y_test, i_train, i_test  = model_selection.train_test_split(X, y, indices)
  # 75 -- .90 f
  # 80 -- .91 f
  # 85 -- .90

  print("training classifier...")
  classifier = ensemble.RandomForestClassifier(verbose=3)
  classifier.fit(X_train, y_train)
  #joblib.dump(classifier, "my_model.pkl", compress=9)

  prediction = classifier.predict(X_test)

  y_pred = []
  for entry in prediction:
    y_pred.append(1 if entry > 0.5 else 0)

  author_dataset = {}
  with open("authors.txt", "r") as f:
    content = f.read().split("\n")
    for line in content:
      folder_author = line.split("_") 
      if len(folder_author) < 2: continue
      author_dataset[folder_author[1]] = folder_author[0]

  print("y_test ", y_test)
  print("y_pred ", y_pred)

  same_right = 0
  same_total = 0
  diff_right = 0
  diff_total = 0
  google_right = 0
  google_total = 0
  diffg_right = 0
  diffg_total = 0
  gh_right = 0
  gh_total = 0

  for i, i_pres in enumerate(i_test): # for each test pair
    author_pair = authors[i_pres].split("_")
    true_val = y_test[i_pres]
    pred_val = y_pred[i]
    if not author_pair[0] in author_dataset: 
      folder1 = "different"
    else:
      folder1 = author_dataset[author_pair[0]]
    if not author_pair[1] in author_dataset: 
      folder2 = "different"
    else:
      folder2 = author_dataset[author_pair[1]]
    if folder1 == folder2: 
      if true_val == pred_val:
        same_right += 1
      same_total += 1
    elif folder1 != folder2:
      if true_val == pred_val:
        diff_right += 1
      diff_total += 1
    if folder1 == "gcj" and folder2 == "gcj":
      if true_val == pred_val:
        google_right += 1
      google_total += 1
    elif folder1 == "gcj" or folder2 == "gcj":
      if true_val == pred_val:
        diffg_right += 1
      diffg_total += 1
    else: 
      if true_val == pred_val:
        gh_right += 1
      gh_total += 1

  if diff_total == 0: diff_total = 1
  print("Accuracy of same-folder author pairs: ", float(same_right)/same_total)
  print("Accuracy of different-folder author pairs: ", float(diff_right)/diff_total)
  print("Accuracy of google author pairs: ", float(google_right)/google_total)
  print("Accuracy of google-different author pairs: ", float(diffg_right)/diffg_total)
  print("Accuracy of GH author pairs: ", float(gh_right)/gh_total)

  print("same: " + str(same))
  #print("prediction:\n" + str(y_pred))
  #print("actual:\n" + str(y_test.values.ravel()))
  print("accuracy: " + str(metrics.accuracy_score(y_test, y_pred)))

  # commenting these out in case they're causing the mem error
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
    #p, r, f, s = run_main(sys.argv[1], write_csv=True)
    p, r, f, s = run_from_csv(sys.argv[1])
    prec += p[0]
    rec += r[0]
    fscore += f[0]
  print("precision: " + str(prec))
  print("recall: " + str(rec))
  print("fscore: " + str(fscore))
 
