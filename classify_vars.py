from ast_lib import *
from sklearn.feature_selection import VarianceThreshold, SelectPercentile, SelectKBest, f_classif
from sklearn.externals import joblib
from sklearn import preprocessing, model_selection, svm, metrics, ensemble, linear_model
from nltk.stem.wordnet import WordNetLemmatizer
import pandas as pd
from collections import OrderedDict
import numpy as np
import random
import math
import re
import os

def do_all(filenames, files, folder):
  lmtzr = WordNetLemmatizer()
  for fn, fl in zip(filenames, files):
  ## functional
    print(fn)
    ast = parse_file(folder + "/" + fn, use_cpp=True, cpp_path='gcc', 
                      cpp_args=['-E', '-c', '-std=c99',  r'-I/home/mgs9y/pycparser/utils/fake_libc_include'])
    fl.fc_vec = get_functional(folder + "/" + fn, ast)
    total_line = 0
    empty = 0
    num_line = 0
    with open(folder + "/" + fn) as f:
      content = f.readlines()
      for line in content:
        total_line += len(line)
        num_line += 1
        if len(line.strip()) == 0:
          empty += 1
    avg_lines = 0 if num_line == 0 else float(total_line)/num_line
    emp_lines = 0 if num_line == 0 else float(empty)/num_line
    fl.fc_vec.append(avg_lines) # avg line length
    fl.fc_vec.append(emp_lines) # % empty lines
  ## lib
    fl.lib_vec = get_lib(folder + "/" + fn, ast)
    #lib_len = len(fl.lib_vec)
    #fl.lib_vec = [0 for x in range(60)]
  ## varnames
    varnames = get_kmers(fn, folder, ast)
    words = []
    for varname in varnames:
      split_name = re.split('(\d+)', varname)
      for subt in split_name:
        words += split_string(subt)
    fl.words = words  # contains kmers

  for f in files:
    underscores = 0
    for word in f.words:
      if "_" in word:
        underscores += 1
      split_name = [lmtzr.lemmatize(x) for x in split_string(word)] # remove case, split into subtokens, stem
      for subtoken in split_name:
        if subtoken in f.bag:
          f.bag[subtoken] += 1
        else:
          f.bag[subtoken] = 1
      if underscores > 2:
        f.camel_case = False 

def split_string(name):
  if "_" in name:
    return [x.lower() for x in name.split("_")]
  else:
    return [x.lower() for x in re.sub('([a-z])([A-Z])', r'\1 \2', name).split()]

def do_cos_vars(filenames, files, folder):
  lmtzr = WordNetLemmatizer()

  for fn, fl in zip(filenames, files):
    print(fn)
    ast = parse_file(folder + "/" + fn, use_cpp=True, cpp_path='gcc', 
                      cpp_args=['-E', '-c', '-std=c99',  r'-I/home/mgs9y/pycparser/utils/fake_libc_include'])
    varnames = get_kmers(fn, folder, ast)
    words = []
    for varname in varnames:
      split_name = re.split('(\d+)', varname)
      for subt in split_name:
        words += split_string(subt)
    fl.words = words  # contains kmers

  for f in files:
    underscores = 0
    for word in f.words:
      if "_" in word:
        underscores += 1
      split_name = [lmtzr.lemmatize(x) for x in split_string(word)] # remove case, split into subtokens, stem
      for subtoken in split_name:
        if subtoken in f.bag:
          f.bag[subtoken] += 1
        else:
          f.bag[subtoken] = 1
      if underscores > 2:
        f.camel_case = False 

def do_tf_vars(filenames, files, folder):
  dictionary = set() #
  tf_list = {}
  lmtzr = WordNetLemmatizer()

  for fn, fl in zip(filenames, files):
    #words = get_kmers(fn, folder)
    varnames = get_kmers(fn, folder)
    words = []
    for varname in varnames:
      split_name = re.split('(\d+)', varname)
      for subt in split_name:
        words += split_string(subt)
    for word in words:
      if word in tf_list:
        tf_list[word] += 1
      else:
        tf_list[word] = 1
    fl.words = words  # contains kmers
    dictionary.update(words) #

  ordered_dict = list(dictionary)

  # memory starts increasing here
  for f in files:
    underscores = 0
    f.tf = OrderedDict([(name, 0) for name in ordered_dict])
    #f.tf = {name:0 for name in ordered_dict} #
    #for word in f.words:
    #  if "_" in word:
    #    underscores += 1
    #  split_name = [lmtzr.lemmatize(x) for x in split_string(word)] # remove case, split into subtokens, stem
    #  for subtoken in split_name:
    #    if subtoken in f.bag:
    #      f.bag[subtoken] += 1
    #    else:
    #      f.bag[subtoken] = 1
    #  if underscores > 2:
    #    f.camel_case = False 
    for word in f.words:
      f.tf[word] += 1

    l = len(f.words)
    #f.vars_vec = [x/float(l) for x in f.tf.values()] if l != 0 else [0 for x in f.tf.values()]
    f.vars_vec = [tf_idf(x, f.tf, len(f.words), tf_list) for x in f.tf.keys()] if len(f.words) != 0 else [0 for x in f.tf.keys()]
    f.tf.clear()
  return ordered_dict

def run_main():
  filenames = os.listdir(sys.argv[1])
  files = []

  # 1) Populate dictionary and make file objects
  for fname in filenames:
    f = File(fname, fname.split("_")[0])
    files.append(f)

  do_vars(filenames, files, sys.argv[1])
  # 4) For each pair of vectors, take square difference combination
  data = []
  tmpdata = []
  same = 0
  notsame = 0
  for f1 in files:
    for f2 in files:
      if f1 is f2 : continue
      #result = [(a-b)**2 for a, b in zip(f1.vars_vec, f2.vars_vec)]
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
      print("For authors " + f1.author + " and " + f2.author)
      print("vector 1 is " + str(f1.bag))
      print("vector 2 is " + str(f2.bag))
      print("Cos sim: " + str(cos_sim))
      casing = 1 if f1.camel_case == f2.camel_case else 0
      result = [cos_sim, casing]

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

  df = pd.DataFrame(data)
  df.to_csv("out.txt")
  y = df.iloc[:,-1]
  X = preprocessing.scale(df.ix[:, :len(data[0])-2])
  print("Dimensions: " + str(X.shape))
  # default f_classif = ANOVA
  #X = SelectPercentile(percentile=85).fit_transform(X, y)
  #print("X after : " + str(X))
  print("dimensions: " + str(X.shape))
  X_train, X_test, y_train, y_test = model_selection.train_test_split(X, y)

  #classifier = linear_model.LinearRegression()
  #classifier = svm.SVC()
  classifier = ensemble.RandomForestClassifier()
  classifier.fit(X_train, y_train)

  #classifier = joblib.load("my_model.pkl")
  #joblib.dump(classifier, "my_model.pkl", compress=9)

  prediction = classifier.predict(X_test)
  y_pred = []
  for entry in prediction:
    y_pred.append(1 if entry > 0.5 else 0)
  print("same: " + str(same))
  print("not same: " + str(notsame))
  print("accuracy: " + str(metrics.accuracy_score(y_test, y_pred)))
  #print("confusion matrix: " + str(metrics.confusion_matrix(y_test, y_pred)))

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
 
