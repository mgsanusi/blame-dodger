import os
import re
import numpy as np
import cPickle as pickle

function_calls = ["abs", "strtol", "qsort", "bzero", "strncmp", "strncpy", "strerror", "read", "memcmp", "free", "snprintf", "realloc", "atoi", "strtoll", "exit", "fgets", "sscanf", "memcpy", "atof", "atol", "puts", "srand", "fgetc", "sqrtl", "powl", "getline", "assert", "getchar", "putchar", "printf", "fprintf", "scanf", "fscanf", "strcat", "strcmp", "strcpy", "isdigit", "isalpha", "isalnum", "isspace", "toupper", "tolower", "errno", "islower", "isupper", "fabs", "pow", "sqrt", "time", "malloc", "calloc", "rand", "strlen", "freopen", "fopen", "strchr", "sprintf", "getc", "fclose", "memset"] 

folder = "new_master"
files = os.listdir(folder)
file_vector = {}
matrix = []
for filename in files:
  with open(folder + "/" + filename, "r") as f:
    content = f.read()
  vector = []
  for func in function_calls:
    regex = "[;}{\(=&|!\s]" + func + "[\s]*\("
    matches = re.findall(regex, content)
    if func == "puts" and len(matches) > 1:
      print(filename + ": " + str(len(matches)))
    vector.append(float(len(matches)))
    #vector.append(func + ": " + str(len(matches)))
  file_vector[filename] = vector
  matrix.append(vector)

np_arr = np.array(matrix)
averages = np.mean(np_arr, axis=0)
std_dev = np.std(np_arr, axis=0)
with open("average_func.pkl", "w") as f:
  pickle.dump(averages, f)
with open("std_dev_func.pkl", "w") as f:
  pickle.dump(std_dev, f)
with open("file_vector.pkl", "w") as f:
  pickle.dump(file_vector, f)

