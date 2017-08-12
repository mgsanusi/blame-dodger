from ast_lib import *
from sklearn import preprocessing, model_selection, svm, metrics, ensemble, linear_model
from sklearn.externals import joblib
from sklearn.feature_selection import SelectPercentile, mutual_info_classif, f_classif, SelectFromModel
from classify_vars import do_cos_vars, do_tf_vars, do_all
from classify_fc import do_functional
from classify_lib import do_lib
from classify_ws import do_whitespace
from classify_com import do_comments
from itertools import combinations, combinations_with_replacement
import matplotlib
matplotlib.use('Agg')
import matplotlib.pyplot as plt
import pandas as pd
import scipy
import random
import math
import sys
import time
import os
import gc
import numpy as np

time0 = 0

from collections import Mapping, Container
from sys import getsizeof

f_labels = ["for", "typedef", "dowhile", "while", "case", "ternary", "avg line length", "percent empty lines"]
#f_labels = ["avg meth length", "avg num params", "struct", "while", "case", "ternary", "avg line length", "percent empty lines"]
l_labels = ["abs", "strtol", "qsort", "bzero", "strncmp", "strncpy", "strerror", "read", "memcmp", "free", "snprintf", "realloc", "atoi", "strtoll", "exit", "fgets", "sscanf", "memcpy", "atof", "atol", "puts", "srand", "fgetc", "sqrtl", "powl", "getline", "assert", "getchar", "putchar", "printf", "fprintf", "scanf", "fscanf", "strcat", "strcmp", "strcpy", "isdigit", "isalpha", "isalnum", "isspace", "toupper", "tolower", "errno", "islower", "isupper", "fabs", "pow", "sqrt", "time", "malloc", "calloc", "rand", "strlen", "freopen", "fopen", "strchr", "sprintf", "getc", "fclose", "memset"] 
 
def run_from_csv(folder, write_csv=False, cos=True, barplot=False, generate_chart=False):
  global time0
  global f_labels
  global l_labels
  np.seterr(divide='ignore', invalid='ignore')
  
  time0 = time.time()

  allfiles = os.listdir(folder)
  file_dict = {}
  files = []
  filenames = []

  print("Getting features from file....", time.time()-time0)
  feature_csv_file = open("feature_vectors_newmaster_gnu.csv", "r")
  feature_csv = feature_csv_file.read().split("\n")
  for line in feature_csv:
    if line == "": continue
    split_line = line.split(",")
    f = File(split_line[0], split_line[1])
    f.vec = [float(x) for x in split_line[2:]] 
    f.folder = folder
    # except i=8
    file_dict[f.name] = f
    files.append(f)
    filenames.append(split_line[0])

  print(len(files[0].vec))
  feature_csv_file.close()

  #var_len = len(files[0].vars_vec) ##
  if cos:
    labels = ["variable names", "casing", "jaccard", "kl divergence"]
    labels += ["gnu", "s4"]#, "s6"]
    labels += f_labels
    labels += l_labels
  else:
    labels = ["s4", "s6"]
    labels += f_labels
    labels += l_labels
    labels += ["VAR: " + x for x in var_labels] #["var kmer" for x in range(0, var_len)] ##

  print(len(labels))

  print("getting variable names...", time.time()-time0)
  #var_labels = do_vars(filenames, files, folder) # 1 feature
  if cos:
    do_cos_vars(filenames, files, folder)
  else:
    var_labels = do_tf_vars(filenames, files, folder)

  #print("getting whitespace...")
  #whitespace = do_whitespace(filenames, files, folder)

  feature_vectors = []
  #for f, ws in zip(files, whitespace):
  #  f.vec.insert(0, ws.ws_vec[0])
  #  feature_vectors.append(",".join([str(x) for x in [f.name, f.author] + f.vec]))

  if write_csv:
    with open("feature_vectors_newmaster_gnu.csv", "a+") as f:
      f.write("\n".join(feature_vectors))
  else:
    del feature_vectors

# now its: ws, fc, lib, vars
  if len(labels) != len(files[0].vec)+4: 
    print("HOUSTON WE HAVE A PROBLEM")
  return process_data(files, labels, file_dict, cos, barplot)

def run_main(folder, write_csv=False, cos=True, barplot=False, generate_chart=False):
  global f_labels 
  global l_labels
  np.seterr(divide='ignore', invalid='ignore')

  allfiles = os.listdir(folder)
  files = []
  filenames = []
  file_dict = {}

  for fname in allfiles: 
    if not fname.endswith(".c"): continue
    f = File(fname, fname.split("_")[0])
    f.folder = folder
    file_dict[fname] = f
    files.append(f)
    filenames.append(fname)

  print("getting all except whitespace...")
  do_all(filenames, files, folder)
  print("getting whitespace features...")
  whitespace = do_whitespace(filenames, files, folder) # 5 features? 1 feature?

  if cos:
    labels = ["variable names", "casing", "jaccard"]
    labels += ["s4", "s6"]
    labels += f_labels
    labels += l_labels
  else:
    labels = ["s4", "s6"]
    labels += f_labels
    labels += l_labels
    labels += ["VAR: " + x for x in var_labels] #["var kmer" for x in range(0, var_len)] ##

  feature_vectors = []

  for f, ws in zip(files, whitespace):
    f.vec = ws.ws_vec + f.fc_vec + f.lib_vec 
    if not cos:
      f.vec += f.vars_vec
    feature_vectors.append(",".join([str(x) for x in [f.name, f.author] + ws.ws_vec + f.fc_vec + f.lib_vec]))

  if write_csv:
    with open("feature_vectors_newmaster.csv", "a+") as f:
      f.write("\n".join(feature_vectors))
  else:
    del feature_vectors

# now its: ws, fc, lib, vars
  offset = 0 if not cos else 2
  if len(labels) != len(files[0].vec) + offset: 
    print("HOUSTON WE HAVE A PROBLEM")
  return process_data(files, labels, file_dict, cos, barplot)

def process_data(files, labels, file_dict, cos=True, barplot=False, generate_chart=False):

  data = []
  tmpdata = []
  same = 0
  notsame = 0
  first_iter = True
  print("calculating pairwise vectors...", time.time()-time0)
  count = 0

  author_dataset = {}
  projects = []
  with open("authors_new.txt", "r") as f:
    content = f.read().split("\n")
    for line in content:
      folder_author = line.split("_") 
      if len(folder_author) < 2: continue
      author_dataset[folder_author[1]] = folder_author[0]
      if not folder_author[0] in projects:
        projects.append(folder_author[0])

  #same_pairs = []
  #diff_pairs = []
  gcj_gcj = 0
  gcj_gh = 0
  gh_gh = 0
  same_pairs = {"gcj_gcj": [], "gh_gh": []}
  diff_pairs = {"gcj_gcj": [], "gcj_gh": [], "gh_gh": []}
  #pairs = {"gcj_gcj": [], "gcj_gh": [], "gh_gh": []}
  for f1, f2 in combinations(files, 2):
    #if not f1.author in author_dataset or not f2.author in author_dataset: continue
    #if author_dataset[f1.author] != "gcj" and author_dataset[f2.author] != "gcj":
    #if not f1.author in author_dataset or not f2.author in author_dataset: continue
    #folder1 = author_dataset[f1.author]
    #folder2 = author_dataset[f2.author]
    #if folder1 == "gcj" or folder2 == "gcj": continue
    if not f1.author in author_dataset or not f2.author in author_dataset: continue
    #if f1.author == f2.author:
    #  same_pairs.append((f1.name, f2.name))
    #else:
    #  diff_pairs.append((f1.name, f2.name))
    folder1 = author_dataset[f1.author]
    folder2 = author_dataset[f2.author]
    if folder1 == folder2 and folder1 == "gcj":
      gcj_gcj += 1
      if f1.author == f2.author:
        same_pairs["gcj_gcj"].append((f1.name, f2.name))
      else:
        diff_pairs["gcj_gcj"].append((f1.name, f2.name))
    elif folder1 == "gcj" or folder2 == "gcj":
      gcj_gh += 1
      diff_pairs["gcj_gh"].append((f1.name, f2.name))
    else:
      gh_gh += 1
      if f1.author == f2.author:
        same_pairs["gh_gh"].append((f1.name, f2.name))
      else:
        diff_pairs["gh_gh"].append((f1.name, f2.name))

  print("gcj gcj: " + str(gcj_gcj))
  print("gcj gh: " + str(gcj_gh))
  print("gh gh: " + str(gh_gh))

  #k = min(len(same_pairs), len(diff_pairs))
  k = min([len(x) for x in same_pairs.values()] + [len(x) for x in diff_pairs.values()])
  data_pairs = random.sample(same_pairs["gcj_gcj"], k) + random.sample(same_pairs["gh_gh"], k) + random.sample(diff_pairs["gcj_gcj"], k) + random.sample(diff_pairs["gcj_gh"], k) + random.sample(diff_pairs["gh_gh"], k)
  print(str(len(data_pairs)) + " data pairs")
  
  for fname1, fname2 in data_pairs:
    f1 = file_dict[fname1]
    f2 = file_dict[fname2]
    if cos:
      # get cosine similarity and jaccard distance
      cos_sim, jaccard = cos_jaccard(f1.bag, f2.bag, len(f1.words), len(f2.words))
      # get kl divergence
      kl_div = kl_divergence(f1.bag, f2.bag)
      casing = 1 if f1.camel_case == f2.camel_case else 0
      result = [cos_sim, casing, jaccard, kl_div]
      #result += np.absolute(np.subtract(f1.vec, f2.vec)).tolist()
      result += np.ndarray.flatten(np.outer(f1.vec, f2.vec)).tolist()
    else:
      result = np.ndarray.flatten(np.outer(f1.vec, f2.vec)).tolist()
    if f1.author == f2.author:
      result.append(1)
    else:
      result.append(0)
    result.append(f1.author + "_" + f2.author)
    result.append(f1.name+ "_" + f2.name)
    if len(result) <= 2: continue
    data.append(result)

  print("Done calculating pairwise vectors...", time.time()-time0) 
  authors = [row[-2] for row in data]

  print("data: " + str(len(data)) + " by " + str(len(data[0])))
  df = pd.DataFrame(data)
  y = df.iloc[:,-3] # -1
  X = preprocessing.scale(df.ix[:, :len(data[0])-4]) # 2

  indices = np.arange(df.shape[0])
  X_train, X_test, y_train, y_test, i_train, i_test  = model_selection.train_test_split(X, y, indices)

  classifier = ensemble.RandomForestClassifier(verbose=3, n_estimators=100)
  classifier.fit(X_train, y_train)
  #model = SelectFromModel(classifier, prefit=True)
  #X_new_train = model.transform(X_train)
  #X_new_test = model.transform(X_test)
  #print("New shape: " + str(X_new_train.shape))
  #classifier.fit(X_new_train, y_train)
  #joblib.dump(classifier, "my_model.pkl", compress=9)

  y_pred = classifier.predict(X_test)
  print("y pred: (should be i pres) " + str(y_pred))

  project_pairs = combinations_with_replacement(projects, 2)
  project_right = {}
  project_total = {}
  project_tps = {}
  project_tns = {}
  project_fps = {}
  project_fns = {}
  project_vectors = {}
  fps = []
  fns = []

  for p1, p2 in project_pairs:
    project_right[p1 + "_" + p2] = 0
    project_total[p1 + "_" + p2] = 0
    project_tps[p1 + "_" + p2] = 0
    project_tns[p1 + "_" + p2] = 0
    project_fps[p1 + "_" + p2] = 0
    project_fns[p1 + "_" + p2] = 0
    project_vectors[p1 + "_" + p2] = []

  num_fps = 0
  num_total = 0
  num_fns = 0

  for i, i_preserved in enumerate(i_test): # for each test pair
    author_pair = authors[i_preserved].split("_")
    true_val = y_test[i_preserved] # changed from i_preserved
    pred_val = y_pred[i] # changed this
    got_right = true_val == pred_val
    tp = pred_val == true_val and true_val == 1
    tn = pred_val == true_val and true_val == 0
    false_pos = pred_val == 1 and true_val == 0
    false_neg = pred_val == 0 and true_val == 1

    if false_pos: fps.append(authors[i_preserved])
    if false_neg: fns.append(authors[i_preserved])

    if not author_pair[0] in author_dataset: 
      folder1 = "different"
    else:
      folder1 = author_dataset[author_pair[0]]
    if not author_pair[1] in author_dataset: 
      folder2 = "different"
    else:
      folder2 = author_dataset[author_pair[1]]

    if folder1 != folder2 and folder1 != "gcj" and folder2 != "gcj": # then GH-GH
      num_total += 1
      if false_pos: num_fps += 1
      if false_neg: num_fns += 1

    if folder1 + "_" + folder2 in project_right:
      if got_right:
        project_right[folder1 + "_" + folder2] += 1
        if tp: 
          project_tps[folder1 + "_" + folder2] += 1
        else:
          project_tns[folder1 + "_" + folder2] += 1
      elif false_pos:
        project_fps[folder1 + "_" + folder2] += 1
      elif false_neg:
        project_fns[folder1 + "_" + folder2] += 1
      project_total[folder1 + "_" + folder2] += 1
      project_vectors[folder1 + "_" + folder2].append(X_test[i].tolist() + [true_val, pred_val])
      #project_vectors[folder1 + "_" + folder2].append(df.ix[i_preserved].tolist() + [pred_val])
    elif folder2 + "_" + folder1 in project_right:
      if got_right:
        project_right[folder2 + "_" + folder1] += 1
        if tp: 
          project_tps[folder2 + "_" + folder1] += 1
        else:
          project_tns[folder2 + "_" + folder1] += 1
      elif false_pos:
        project_fps[folder2 + "_" + folder1] += 1
      elif false_neg:
        project_fns[folder2 + "_" + folder1] += 1
      project_total[folder2 + "_" + folder1] += 1
      project_vectors[folder2 + "_" + folder1].append(X_test[i].tolist() + [true_val, pred_val]) # get from X test arra
      #project_vectors[folder2 + "_" + folder1].append(df.ix[i_preserved].tolist() + [pred_val]) # get from unscaled dataframe
    else: # project not in list
      pass

  print(str(len(fps)) + " false positives")
  print(str(len(fns)) + " false negatives")
  print(str(num_fps) + " FPs in GH-GH")
  print(str(num_fns) + " FNs in GH-GH")
  print(str(num_total) + " total in GH-GH")

  importances = classifier.feature_importances_

## generate bar chart
# y = ?
  # probability of appearing = sum([1 for feat in column if feat != 0])
    # what's the quickest way to get a column?
  # times feature importance
  # project_vectors = vector + (name) + [y true, y pred]
  # x = labels
  if generate_chart:
    graph_probs = True
    N = len(labels)
    ind = np.arange(N)
    width = 0.15
    vector_matrix = np.array([lst for val in project_vectors.values() for lst in val])
    num_columns = vector_matrix.shape[1]-2
    if graph_probs:
      probabilities = [np.count_nonzero(vector_matrix[:, i])/float(num_columns) for i in range(num_columns)]
      y = [imp*prob for imp, prob in zip(importances, probabilities)]
      fig, ax = plt.subplots(figsize=(14,8))
      bars = ax.bar(ind, y, width, color='r')
      ax.set_ylabel("importance*probability")
      ax.set_title("Feature Importance Times Probability of Appearance")
      ax.set_xticklabels((labels))
      plt.setp(ax.get_xticklabels(), rotation=90, horizontalalignment='center')
      fig.tight_layout()
      plt.savefig("prob_plot.png")
    else: 
      # ... true_val (-2), pred_val (-1)
      tp_arr = vector_matrix[(vector_matrix[:,-1] == 1) & (vector_matrix[:,-2] == 1)]
      tn_arr = vector_matrix[(vector_matrix[:,-1] == 0) & (vector_matrix[:,-2] == 0)]
      fp_arr = vector_matrix[(vector_matrix[:,-1] == 1) & (vector_matrix[:,-2] == 0)]
      fn_arr = vector_matrix[(vector_matrix[:,-1] == 0) & (vector_matrix[:,-2] == 1)]
      # these all still have two/three extra columns at the end

      print("TP Array: ")
      print(tp_arr)

      tps = np.mean(tp_arr[:,:N], axis=0)
      tns = np.mean(tn_arr[:,:N], axis=0)
      fps = np.mean(fp_arr[:,:N], axis=0)
      fns = np.mean(fn_arr[:,:N], axis=0)

      print("TPs: ", tp_arr.shape)
      print("TNs: ", tn_arr.shape)
      print("FPs: ", fp_arr.shape)
      print("FNs: ", fn_arr.shape)
      
      fig, ax = plt.subplots(figsize=(14,8))
      bars1 = ax.bar(ind, tps, width, color='r', edgecolor='r')
      bars2 = ax.bar(ind + width, tns, width, color='limegreen', edgecolor='limegreen')
      bars3 = ax.bar(ind + 2*width, fps, width, color='dodgerblue', edgecolor='dodgerblue')
      bars4 = ax.bar(ind + 3*width, fns, width, color='gold', edgecolor='gold')

      ax.set_title("Average Feature Values")
      ax.set_xticks(ind + 3*width / 2)
      ax.set_xticklabels((labels))
      ax.legend((bars1[0], bars2[0], bars3[0], bars4[0]), ("TP", "TN", "FP", "FN"))
      plt.setp(ax.get_xticklabels(), rotation=90, horizontalalignment='center')
      fig.tight_layout()

      plt.savefig("avg_feat_vals.png")

  if barplot:
    x = labels
    barplot_file = "barplot_file.csv"
    output_str = "key," + ",".join(labels) + "\n"
    for key in project_vectors:
      key_lists = project_vectors[key]
      for key_list in key_lists:
        output_str += key + "," + ",".join([str(x) for x in key_list]) + "\n"
    #output_str += "\n".join([key + "," + ",".join(project_vectors[key]) for key in project_vectors])
    with open(barplot_file, 'w') as f:
      f.write(output_str)

  ## Create project pairs csv
  print_list = [",".join(labels)]
  for key in project_right:
    num = project_right[key]
    den = project_total[key]
    if den != 0:
      print_list.append(",".join([key.split("_")[0], key.split("_")[1], str(round(float(num)/den, 2)), str(den), str(project_fps[key]), str(project_fns[key]), str(project_tps[key]), str(project_tns[key])]))
    else:
      print_list.append(",".join([key.split("_")[0], key.split("_")[1], str(0), str(den), str(project_fps[key]), str(project_fns[key]), str(project_tps[key]), str(project_tns[key])]))

  print_list.sort(key=lambda x: x[0])
  print_list.sort(key=lambda x: x[0] == x[1], reverse=True)

  with open("project_pairs.csv", "w") as f:
    f.write("\n".join(print_list))

  ## print feature importances
  outer_labels = row_major_labels(labels)
  label_power = [(label, power) for label, power in zip(outer_labels, importances)]
  label_power = sorted(label_power, reverse=True, key=lambda x: x[1])
  print("\n".join(["%-20s %-20s" % (x[0], str(x[1])) for x in label_power[:100]]))
  print(metrics.confusion_matrix(y_test, y_pred))

  return metrics.precision_recall_fscore_support(y_test, y_pred)

if __name__ == "__main__":
  prec = 0
  rec = 0
  fscore = 0
  for i in range(1):
    #p, r, f, s = run_main(sys.argv[1], cos=True, write_csv=True, barplot=False)
    p, r, f, s = run_from_csv(sys.argv[1], write_csv=False, cos=True, barplot=True, generate_chart=False)
    prec += p[0]
    rec += r[0]
    fscore += f[0]
  print("precision: " + str(prec))
  print("recall: " + str(rec))
  print("fscore: " + str(fscore))
 
