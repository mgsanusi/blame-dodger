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
                    cpp_args=['-E', '-c', '-std=c99',  r'-I/usr/bin/pycparser/utils/fake_libc_include'])
    except:
      print("removing... " + f)
      error += 1
      total -= 1
      os.system("rm " + sys.argv[1] + "/" + f)

print("removed " + str(error) + ". You have " + str(total) + " left.")
#print(str(error) + " out of " + str(total) + " have parse errors")

