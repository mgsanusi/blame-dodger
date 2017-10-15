#-------------------------------------------------
# python transform_ws.py old_folder new_folder
#-------------------------------------------------

from __future__ import print_function
import os
import sys
import re
import nltk
import time
import random
from dowhile import transform_dw

# This is not required if you've installed pycparser into
# your site-packages/ with setup.py
#
sys.path.extend(['.', '..'])

from pycparser import preprocess_file, parse_file, c_ast, c_parser, c_generator

class DoWhileVisitor(c_ast.NodeVisitor):
  def __init__(self):
    self.count = 0

  def visit_DoWhile(self, node):
    self.count += 1
    self.generic_visit(node)


# last step
# takes filename, writes to new file
def transform_ws(filename, folder, new_folder):
  print(filename)
  flags = ["-gnu", "-kr", "-linux"]
  out_name = new_folder + "/" + filename
  mid_file_list = open(folder + "/" + filename, 'r').read().split("\n")
  no_blank_lines = "\n".join([x for x in mid_file_list if len(x) > 0])
  dowhile_modified = no_blank_lines #transform_dw(no_blank_lines)
  with open("mid_file.c", 'w') as f:
    f.write(dowhile_modified)
  os.system("indent " + random.choice(flags) + " mid_file.c" + " -o " + out_name)

#------------------------------------------------------------------------------
if __name__ == "__main__":
  #_zz_test_translate()
  if len(sys.argv) > 1:
    #translate_to_c(sys.argv[1])
    folder = sys.argv[1]
    new_folder = sys.argv[2]
    os.system("mkdir " + new_folder)
    folder_contents = os.listdir(sys.argv[1])

    # for each file
    for filename in folder_contents:
      transform_ws(filename, sys.argv[1].strip(), new_folder)
  else:
    print("please provide a filename as argument")
