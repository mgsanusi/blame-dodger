import os
import sys
import subprocess
from pycparser import preprocess_file, parse_file, c_ast, c_parser, c_generator

funcs = ["abs", "strtol", "qsort", "bzero", "strncmp", "strncpy", "strerror", "read", "memcmp", "free", "snprintf", "realloc", "atoi", "strtoll", "exit", "fgets", "sscanf", "memcpy", "strtok_r", "atof", "atol", "puts", "srand", "fgetc", "sqrtl", "powl", "getline", "assert", "getchar", "putchar", "printf", "fprintf", "scanf", "fscanf", "strcat", "strcmp", "strcpy", "isdigit", "isalpha", "isalnum", "isspace", "toupper", "tolower", "errno", "islower", "isupper", "fabs", "pow", "sqrt", "time", "malloc", "calloc", "rand", "strlen", "freopen", "fopen", "strchr", "sprintf", "getc", "fclose", "memset"] 
#TODO either 
#       include every function possible OR
#       include a check that the function is in this list


class File():
  def __init__(self, name=None, author=None, words=None):
    self.name = name
    self.author = author
    self.words = words
    self.tf = {}
    self.vec = []
    self.vars_vec = []
    self.fc_vec = []
    self.lib_vec = []

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

class IDVisitor(c_ast.NodeVisitor):
  def __init__(self):
    self.tokens = []
    self.kmers = []

  def visit_ID(self, node):
    for i in range(0, len(node.name)-2):
      self.kmers.append(node.name[i:i+2])
    if "_" in node.name:
      self.tokens += node.name.split("_")
    else:
      substr = ""
      for c in node.name:
        if c.isupper():
          if substr != "" : self.tokens.append(substr)
          substr = c.lower()
        else:
          substr += c
      if substr != "" : self.tokens.append(substr)

class FuncDeclVisitor(c_ast.NodeVisitor):
  def __init__(self):
    self.nested = 0

  def visit_FuncDecl(self, node):
    self.nested += 1
    self.generic_visit(node)

class DeclVisitor(c_ast.NodeVisitor):
  def __init__(self):
    self.declarations = []
    self.methods = 0

  def visit_Decl(self, node):
    if not isinstance(node.type, c_ast.FuncDecl): 
      self.declarations.append(node.name) 
    elif isinstance(node.type, c_ast.FuncDecl):
      self.methods += 1
    self.generic_visit(node)

class AssignmentVisitor(c_ast.NodeVisitor):
  def __init__(self):
    self.assignments = []

  def visit_Assignment(self, node):
    if isinstance(node.lvalue, c_ast.ID):
      self.assignments.append(node.lvalue) # ID object. Use .name
    self.generic_visit(node)

def lcs(X, Y):
  m = len(X)
  n = len(Y)

  L = [[None]*(n+1) for i in range(m+1)]

  for i in range(m+1):
    for j in range(n+1):
      if i == 0 or j == 0:
        L[i][j] = 0
      elif X[i-1] == Y[j-1]:
        L[i][j] = L[i-1][j-1] + 1
      else:
        L[i][j] = max(L[i-1][j], L[i][j-1])

  return L[m][n]

def get_lib(filename):
  vec = {name:0 for name in funcs}
  tf = {}
  ast = parse_file(filename, use_cpp=True, cpp_path='gcc', 
                    cpp_args=['-E', '-std=c99',  r'-I/usr/bin/pycparser/utils/fake_libc_include'])
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
      
  return tf.values()

def get_functional(filename):
  ast = parse_file(filename, use_cpp=True, cpp_path='gcc', 
                    cpp_args=['-E', '-std=c99',  r'-I/usr/bin/pycparser/utils/fake_libc_include'])
  av = AssignmentVisitor()
  dv = DeclVisitor()
  fdv = FuncDeclVisitor()
  av.visit(ast)
  dv.visit(ast)
  fdv.visit(ast)

  ret = [float(len(av.assignments))/len(dv.declarations) if len(dv.declarations) != 0 else 0]

  proc = subprocess.Popen(["wc","-l", os.path.abspath(filename)], stdout=subprocess.PIPE)
  output = proc.stdout.read().split()[0]
  ret.append(float(dv.methods)/int(output))
  ret.append(fdv.nested)
  return ret

def get_kmers(filename):
  ast = parse_file(filename, use_cpp=True, cpp_path='gcc', 
                    cpp_args=['-E', '-std=c99',  r'-I/usr/bin/pycparser/utils/fake_libc_include'])
  idv = IDVisitor()
  idv.visit(ast)
  return idv.kmers

def get_tokens(filename):
  ast = parse_file(filename, use_cpp=True, cpp_path='gcc', 
                    cpp_args=['-E', '-std=c99',  r'-I/usr/bin/pycparser/utils/fake_libc_include'])
  idv = IDVisitor()
  idv.visit(ast)
  return idv.tokens

def get_ws(fname):
  basename = fname.strip(".c")

  gnu_name= basename + "_gnu.c"
  kr_name = basename + "_kr.c"
  lx_name = basename + "_lx.c"
  s1_name = basename + "_s1.c"
  s2_name = basename + "_s2.c"
  s3_name = basename + "_s3.c"
  s4_name = basename + "_s4.c"
  s5_name = basename + "_s5.c"
  s6_name = basename + "_s6.c"
  norm_name = basename + "_norm.c"

  os.system("gindent -linux " + fname + " -o " + norm_name)
  os.system("gindent -kr " + norm_name)
  os.system("gindent -gnu " + norm_name)
  os.system("gindent -gnu " + fname + " -o " + gnu_name)
  os.system("gindent -kr " + fname + " -o " + kr_name)
  os.system("gindent -linux  " + fname + " -o " + lx_name)
  os.system("gindent -bad -br -brf -brs " + fname + " -o " + s1_name) # braces on same line, force new line after block of declarations
  os.system("gindent -nut " + fname + " -o " + s2_name) # use spaces
  os.system("gindent -i2 -c2 -cd2 -nbap -cli2 " + fname + " -o " + s3_name) # indent twice
  os.system("gindent -nsaf -nsai -nsaw -nlps -nprs -nbfda -nbc -ncs " + fname + " -o " + s4_name) # everything tight
  os.system("gindent -orig " + fname + " -o " + s5_name)
  os.system("gindent -br -brf -brs -l50 -lps -nce -ncdw " + fname + " -o " + s6_name) #braces on same line, short lines, no cuddle

  orig = open(fname, 'r').read()
  gnu_content = open(gnu_name, 'r').read()
  kr_content = open(kr_name, 'r').read()
  lx_content = open(lx_name, 'r').read()
  s1_content = open(s1_name, 'r').read()
  s2_content = open(s2_name, 'r').read()
  s3_content = open(s3_name, 'r').read()
  s4_content = open(s4_name, 'r').read()
  s5_content = open(s5_name, 'r').read()
  s6_content = open(s6_name, 'r').read()

  orig_size = os.path.getsize(fname)
  gnu = float(lcs(orig, gnu_content))/max(orig_size, os.path.getsize(gnu_name))
  kr = float(lcs(orig, kr_content))/max(orig_size, os.path.getsize(kr_name))
  lx = float(lcs(orig, lx_content))/max(orig_size, os.path.getsize(lx_name))
  s1 = float(lcs(orig, s1_content))/max(orig_size, os.path.getsize(s1_name))
  s2 = float(lcs(orig, s2_content))/max(orig_size, os.path.getsize(s2_name))
  s3 = float(lcs(orig, s3_content))/max(orig_size, os.path.getsize(s3_name))
  s4 = float(lcs(orig, s4_content))/max(orig_size, os.path.getsize(s4_name))
  s5 = float(lcs(orig, s5_content))/max(orig_size, os.path.getsize(s5_name))
  s6 = float(lcs(orig, s6_content))/max(orig_size, os.path.getsize(s6_name))

  norm = open(norm_name, 'r').read()
  norm_size = os.path.getsize(norm_name)
  gnu_norm = float(lcs(norm, gnu_content))/max(norm_size, os.path.getsize(gnu_name))
  kr_norm = float(lcs(norm, kr_content))/max(norm_size, os.path.getsize(kr_name))
  lx_norm = float(lcs(norm, lx_content))/max(norm_size, os.path.getsize(lx_name))
  s1_norm = float(lcs(norm, s1_content))/max(norm_size, os.path.getsize(s1_name))
  s2_norm = float(lcs(norm, s2_content))/max(norm_size, os.path.getsize(s2_name))
  s3_norm = float(lcs(norm, s3_content))/max(norm_size, os.path.getsize(s3_name))
  s4_norm = float(lcs(norm, s4_content))/max(norm_size, os.path.getsize(s4_name))
  s5_norm = float(lcs(norm, s5_content))/max(norm_size, os.path.getsize(s5_name))
  s6_norm = float(lcs(norm, s6_content))/max(norm_size, os.path.getsize(s6_name))

  return [gnu, kr, lx, s1, s2, s3, s4, s5, s6]

#------------------------------------------------------------------------------
if __name__ == "__main__":
  if len(sys.argv) > 1:
    get_features(sys.argv[1])
  else:
    print("Please provide a filename as argument")

