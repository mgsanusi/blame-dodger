"""
python transform_libcalls.py old_folder new_folder
"""
import os
import sys
import re
import numpy as np
import cPickle as pickle

function_calls = ["abs", "strtol", "qsort", "bzero", "strncmp", "strncpy", "strerror", "read", "memcmp", "free", "snprintf", "realloc", "atoi", "strtoll", "exit", "fgets", "sscanf", "memcpy", "atof", "atol", "puts", "srand", "fgetc", "sqrtl", "powl", "getline", "assert", "getchar", "putchar", "printf", "fprintf", "scanf", "fscanf", "strcat", "strcmp", "strcpy", "isdigit", "isalpha", "isalnum", "isspace", "toupper", "tolower", "errno", "islower", "isupper", "fabs", "pow", "sqrt", "time", "malloc", "calloc", "rand", "strlen", "freopen", "fopen", "strchr", "sprintf", "getc", "fclose", "memset"] 
uses_sizet = set(["sort", "bzero", "strncmp", "strncpy", "read", "memcmp", "snprintf", "realloc", "memcpy", "malloc", "calloc", "memset"])

func_info = { \
  "abs"     : (1, "int", ("int x")),
  "strtol"  : (3, "long int", ("const char* str", "char** endptr", "int base")),
  "qsort"   : (4, "void", ("void* base", "int num", "int size", "int (*compar)(const void*,const void*)")),
  "bzero"   : (2, "void", ("void *s", "int n")),
  "strncmp" : (3, "int", ("const char *str1", "const char *str2", "int num")),
  "strncpy" : (3, "char *", ("char *destination", "const char* source", "int num")),
  "strerror": (1, "char *", ("int errnum")),
  "read"    : (3, "int", ("int fd", "void *buf", "int count")),
  "memcmp"  : (3, "int", ("const void *ptr1", "const void *ptr2", "int num")),
  "free"    : (1, "void", ("void *ptr")),
  "snprintf": (-1, "int", "char *s, int n, const char *format, ..."), # 3
  "realloc" : (2, "void*", ("void *ptr", "int size")),
  "atoi"    : (1, "int", ("const char *str")),
  "strtoll" : (3, "long long int", ("const char *str", "char **endptr", "int base")),
  "exit"    : (1, "void", ("int status")),
  "fgets"   : (3, "char *", ("char *str", "int num", "FILE *stream")),
  "sscanf"  : (-1, "int", "const char *s, const char *format, ..."), #2
  "memcpy"  : (3, "void *", ("void *destination", "const void *source", "int num")),
  "atof"    : (1, "double", ("const char *str")),
  "atol"    : (1, "long int atol", ("const char *str")),
  "puts"    : (1, "int", ("const char *str")),
  "srand"   : (1, "void", ("unsigned int seed")),
  "fgetc"   : (1, "int", ("FILE *stream")),
  "sqrtl"   : (1, "double", ("double x")),
  "powl"    : (2, "double", ("double base", "double exponent")),
  "getline" : (3, "istream&", ("istream& is", "string& str")),
  "assert"  : (1, "void", ("int expression")),
  "getchar" : (0, "int", ()),
  "putchar" : (1, "int", ("int character")),
  "printf"  : (-1, "int", "const char *format,..."), #1
  "fprintf" : (-1, "int", "FILE *stream, const char *format, ..."), #2
  "scanf"   : (-1, "int", "const char *format,..."), #1
  "fscanf"  : (-1, "int", "FILE *stream, const char *format, ..." ), #2
  "strcat"  : (2, "char *", ("char *destination", "const char *source")),
  "strcmp"  : (2, "int", ("const char *str1", "const char *str2")),
  "strcpy"  : (2, "char *", ("char *destination", "const char *source")),
  "isdigit" : (1, "int", ("int c")),
  "isalpha" : (1, "int", ("int c")),
  "isalnum" : (1, "int", ("int c")),
  "isspace" : (1, "int", ("int c")),
  "toupper" : (1, "int", ("int c")),
  "tolower" : (1, "int", ("int c")),
  "errno"   : (0),
  "islower" : (1, "int", ("int c")),
  "isupper" : (1, "int", ("int c")),
  "fabs"    : (1, "double", ("double x")),
  "pow"     : (2, "double", ("double base", "double exponent")),
  "sqrt"    : (2, "double", ("double x")),
  "time"    : (1, "time_t", ("time_t *timer")),
  "malloc"  : (1, "void*", ("int size")),
  "calloc"  : (1, "void*", ("int num", "int size")),
  "rand"    : (0, "int", ()),
  "strlen"  : (1, "int", ("const char *str")),
  "freopen" : (3, "FILE *", ("const char *filename", "const char *mode", "FILE *stream")),
  "fopen"   : (2, "FILE *", ("const char *filename", "const char *mode")),
  "strchr"  : (2, "char *", ("char *str", "int character")),
  "sprintf" : (-1, "int", "char *str, const char *format, ..."), #2
  "getc"    : (1, "int", ("FILE *stream")),
  "fclose"  : (1, "int", ("FILE *stream")),
  "memset"  : (3, "void *", ("void *ptr", "int value", "int num"))
  }

# BOOKMARK
def fix_distribution(content, func, file_content, filename, defined):  
  if func == "errno": return
  if func in defined: return
  original_content = content
  tupl = func_info[func]
  if isinstance(tupl, int): return
  num_args = tupl[0]
  ret_type = tupl[1]
  param_names = []
  params = tupl[2]
  if func in ["printf", "sprintf", "nprintf", "sscanf", "scanf"]:
    return
  """
    # leave params as is
    param_list = x.split(",")[0:-1] 
    param_names = [x[-1] for x in param_list]
    body = "" + 
      " char fmt_str[MAX_FMT_SIZE;\n" + # define MAX_FMT_SIZE
      " va_list arg_ptr;\n" +
      " va_start(arg_ptr, format);\n" + 
      " format_string(format, arg_ptr, fmt_str)\n" + 
      " va_end(arg_ptr);\n" + 
      " return " + func + "(" + param_names + "," + fmt_str + ");"
    return
    """
  if isinstance(params, tuple):
    param_list = list(params)
    params = ", ".join(param_list)
    param_names_list = [x.split()[-1] for x in param_list]
    if func == "qsort":
      param_names_list[-1] = "compar"
    param_names = ", ".join(param_names_list)
  else:
    param_names = params.split()[-1]
  param_names = param_names.replace("*", "")
  param_names = param_names.replace("[", "")
  param_names = param_names.replace("]", "")
  param_names = param_names.replace("&", "")
  param_names = param_names.replace("(", "")
  param_names = param_names.replace(")", "")
  header = ret_type + " new_" + func + "(" + params + ") {"
  prototype = ret_type + " new_" + func + "(" + params + ");"
  body = "  return " + func + "(" + param_names + ");"
  args = func_info[func]

  if args[0] != -1:
    regex = func + "[\s]*\(" + "[\s\S]+?,"*(args[0]-1) + "[\s\S]+?\)"
    already_replaced = set()
    matches = re.findall(regex, content)
    for match in matches:
      new = "new_" + match 
      if not match in already_replaced:
        content = content.replace(match, new)
      already_replaced.add(match)
    content += "\n" + "\n".join([header, body, "}"])

  # add prototype
  main_regex = "(void|int)\s+?main\s*?\([\s\S]*?\)"
  first_func = "(static)?\s*(inline)?\s*(unsigned|signed)?\s+(void|int|char|short|long|float|double|long long)\s*\*?\s+(\w+)\s*\([^)]*\)"
  includes_regex = "(\s*#include\s*[<\"][\w\.]+[>\"].*\n)+"
  func_start = re.search(first_func, content)
  includes = re.search(includes_regex, content)
  if not func_start is None:
    original_main = func_start.group(0)
    main_with_prototypes = "\n" + prototype + "\n" + original_main
    content = content.replace(original_main, main_with_prototypes)
  if (not includes is None) and func in uses_sizet:
    orig_include = includes.group(0)
    add_include = orig_include + "\n#include <stddef.h>\n"
    content = content.replace(orig_include, add_include)
  file_content[filename] = content

if __name__ == "__main__":
  with open("average_func.pkl", "rb") as f:
    averages = pickle.load(f)
  with open("std_dev_func.pkl", "rb") as f:
    std_dev = pickle.load(f)
  with open("file_vector.pkl", "rb") as f:
    file_vector = pickle.load(f)

  file_content = {}
  folder = sys.argv[1]
  new_folder = sys.argv[2]
  files = os.listdir(folder)
  #files = ["chuckl0416_Noisy_Neighbors.c"]

  for filename in files:
    with open(folder + "/" + filename, "r") as f:
      file_content[filename] = f.read()
    try:
      my_vector = file_vector[filename]
    except: 
      print(filename + " wasn't found!")
      continue
    func_regex = "(unsigned|signed)?\s+(void|int|char|short|long|float|double)\s*\*?\s+(\w+)\s*\([^)]*\)"
    defined = set(re.findall(func_regex, file_content[filename]))
    for i, func in enumerate(function_calls):
      ave = averages[i]
      dev = std_dev[i]
      count = my_vector[i]
      if count - ave > dev:
        fix_distribution(file_content[filename], func, file_content, filename, defined)
    with open(new_folder + "/" + filename, "w") as f:
      f.write(file_content[filename])

      


