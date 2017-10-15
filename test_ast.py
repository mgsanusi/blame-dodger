import os
import sys
import subprocess
from pycparser import preprocess_file, parse_file, c_ast, c_parser, c_generator

filenames = os.listdir(sys.argv[1])
total = 0
error = 0
for f in filenames:
  total += 1
  if f.split(".")[-1] == "c":
    try:
      ast = parse_file(sys.argv[1] + "/" + f, use_cpp=True, cpp_path='gcc', 
                    cpp_args=['-E', '-c', '-std=c99',  r'-I/home/mgs9y/pycparser/utils/fake_libc_include'])
    except:
      error += 1
      print(f + " doesn't compile")

print(str(error) + " out of " + str(total) + " programs didn't compile")

