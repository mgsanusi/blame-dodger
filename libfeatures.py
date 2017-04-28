import os
import sys
import subprocess
from pycparser import preprocess_file, parse_file, c_ast, c_parser, c_generator

funcs = ["getchar", "putchar", "printf", "fprintf", "scanf", "fscanf", "strcat", "strcmp", "strcpy", "isdigit", "isalpha", "isalnum", "isspace", "toupper", "tolower", "errno", "islower", "isupper", "fabs", "pow", "sqrt", "time", "malloc", "calloc", "rand", "strlen", "freopen", "fopen", "strchr", "sprintf", "getc", "fclose", "memset"] 
#TODO either 
#       include every function possible OR
#       include a check that the function is in this list

class FuncCallVisitor(c_ast.NodeVisitor):
  def __init__(self):
    self.names = []
    self.total = 0

  def visit_FuncCall(self, node):
    self.names.append(node.name.name)
    self.total += 1
    self.generic_visit(node)

class FuncDefVisitor(c_ast.NodeVisitor):
  def __init__(self):
    self.names = []

  def visit_FuncDef(self, node):
    self.names.append(node.decl.name) 
    self.generic_visit(node)

def get_features(filename):
  vec = {name:0 for name in funcs}
  tf = {}
  ast = parse_file(filename, use_cpp=True, cpp_path='gcc', 
                    cpp_args=['-E', '-std=c99',  r'-I/tmp/pycparser/utils/fake_libc_include'])
  fcv = FuncCallVisitor()
  fdv = FuncDefVisitor()
  fcv.visit(ast)
  fdv.visit(ast)

  for f in fcv.names:
    fdvn = fdv.names
    if f not in fdvn:
      vec[f] += 1
  
  for f in vec:
    tf[f] = vec[f]/float(fcv.total) if fcv.total != 0 else 0
      
  print(" ".join([str(x) for x in tf.values()]))

if __name__ == "__main__":
  if len(sys.argv) > 1:
    get_features(sys.argv[1])
  else:
    print("Please provide a filename as argument")
