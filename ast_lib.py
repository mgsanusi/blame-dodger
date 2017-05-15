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
    self.ws_vec = []

class FuncCallVisitor(c_ast.NodeVisitor):
  def __init__(self):
    self.names = []
    self.total = 0
    self.nested = 0

  def visit_FuncCall(self, node):
    self.nested += 1
    self.names.append(node.name.name)
    self.total += 1
    self.generic_visit(node)

class FuncDefVisitor(c_ast.NodeVisitor):
  def __init__(self):
    self.names = []
    self.main = 0
    self.coords = []
    self.num_params = 0
    self.num_methods = 0

  def visit_FuncDef(self, node):
    self.names.append(node.decl.name) 
    self.coords.append((node.decl.name, node.coord.line))
    self.num_methods += 1
    self.num_params += 0 #len(node.decl.args) #if node.param_decls is not None else 0
    self.generic_visit(node)

class FuncDeclVisitor(c_ast.NodeVisitor):
  def __init__(self):
    self.num_params = 0
    self.num_methods = 0

  def visit_FuncDecl(self, node):
    self.num_methods += 1
    if node.args:
      self.num_params += len(node.args.params) 
    else:
      self.num_params += 0
    self.generic_visit(node)

class IDVisitor(c_ast.NodeVisitor):
  def __init__(self):
    self.tokens = []
    self.kmers = []
    self.var_names = []

  def visit_ID(self, node):
    self.var_names.append(node.name)
    for i in range(0, len(node.name)-3):
      self.kmers.append(node.name[i:i+3])
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

class StructVisitor(c_ast.NodeVisitor):
  def __init__(self):
    self.count = 0

  def visit_Struct(self, node):
    self.count += 1
    self.generic_visit(node)

class TernaryOpVisitor(c_ast.NodeVisitor):
  def __init__(self):
    self.count = 0

  def visit_TernaryOp(self, node):
    self.count += 1
    self.generic_visit(node)

class CaseVisitor(c_ast.NodeVisitor):
  def __init__(self):
    self.count = 0

  def visit_Case(self, node):
    self.count += 1
    self.generic_visit(node)

class SwitchVisitor(c_ast.NodeVisitor):
  def __init__(self):
    self.count = 0

  def visit_Switch(self, node):
    self.count += 1
    self.generic_visit(node)

class DoWhileVisitor(c_ast.NodeVisitor):
  def __init__(self):
    self.count = 0

  def visit_DoWhile(self, node):
    self.count += 1
    self.generic_visit(node)

class WhileVisitor(c_ast.NodeVisitor):
  def __init__(self):
    self.count = 0

  def visit_While(self, node):
    self.count += 1
    self.generic_visit(node)

class IfVisitor(c_ast.NodeVisitor):
  def __init__(self):
    self.count = 0

  def visit_If(self, node):
    self.count += 1
    self.generic_visit(node)

class ForVisitor(c_ast.NodeVisitor):
  def __init__(self):
    self.count = 0

  def visit_For(self, node):
    self.count += 1
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
  fdv = FuncDefVisitor()
  fcv = FuncCallVisitor()
  fdcv = FuncDeclVisitor()
  sv = StructVisitor()
  iv = IfVisitor()
  fv = ForVisitor()
  dwv = DoWhileVisitor()
  wv = WhileVisitor()
  cv = CaseVisitor()
  swv = SwitchVisitor()
  tv = TernaryOpVisitor()
  av.visit(ast)
  dv.visit(ast)
  fdv.visit(ast)
  fcv.visit(ast)
  fdcv.visit(ast)
  sv.visit(ast)
  iv.visit(ast)
  fv.visit(ast)
  dwv.visit(ast)
  wv.visit(ast)
  cv.visit(ast)
  swv.visit(ast)
  tv.visit(ast)

  sorted_coords = sorted(fdv.coords, key=lambda x: x[1])

  ret = [float(len(av.assignments))/len(dv.declarations) if len(dv.declarations) != 0 else 0]

  proc = subprocess.Popen(["wc","-l", os.path.abspath(filename)], stdout=subprocess.PIPE)
  file_len = int(proc.stdout.read().split()[0])

  main_len = 0
  for i, pair in enumerate(sorted_coords): # name, lineno
    if pair[0] == "main":
      if i == len(sorted_coords)-1: # if no methods after main
        main_len = file_len - pair[1]
      else:
        main_len = sorted_coords[i+1][1] - pair[1]
      break
      
  avg_meth = float(fdcv.num_methods)/file_len
  main_to_method = float(main_len)/avg_meth if avg_meth != 0 else 0
  params_to_methods = float(fdcv.num_params)/fdcv.num_methods if fdcv.num_methods != 0 else 0
  ret.append(avg_meth)
  ret.append(fcv.nested)
  #ret.append(main_to_method)
  #ret.append(params_to_methods)
  #ret.append(sv.count/float(file_len))
  #ret.append(iv.count/float(file_len))
  #ret.append(fv.count/float(file_len))
  #ret.append(wv.count/float(file_len))
  #ret.append(cv.count/float(file_len))
  #ret.append(tv.count/float(file_len))
  #ret.append(float(fdv.num_params)/fdv.num_methods) # average num params
  return ret

def get_kmers(filename):
  ast = parse_file(filename, use_cpp=True, cpp_path='gcc', 
                    cpp_args=['-E', '-std=c99',  r'-I/usr/bin/pycparser/utils/fake_libc_include'])
  idv = IDVisitor()
  idv.visit(ast)
  return idv.kmers

def get_full_names(filename):
  ast = parse_file(filename, use_cpp=True, cpp_path='gcc', 
                    cpp_args=['-E', '-std=c99',  r'-I/usr/bin/pycparser/utils/fake_libc_include'])
  idv = IDVisitor()
  idv.visit(ast)
  return idv.var_names

def get_tokens(filename):
  ast = parse_file(filename, use_cpp=True, cpp_path='gcc', 
                    cpp_args=['-E', '-std=c99',  r'-I/usr/bin/pycparser/utils/fake_libc_include'])
  idv = IDVisitor()
  idv.visit(ast)
  return idv.tokens

def get_ws(fname):
  basename = fname.strip(".c").split("/")[-1]
  gnu_name= "temp/" + basename + "_gnu.c"
  kr_name = "temp/" + basename + "_kr.c"
  lx_name = "temp/" + basename + "_lx.c"
  s1_name = "temp/" + basename + "_s1.c"
  s2_name = "temp/" + basename + "_s2.c"
  s3_name = "temp/" + basename + "_s3.c"
  s4_name = "temp/" + basename + "_s4.c"
  s5_name = "temp/" + basename + "_s5.c"
  s6_name = "temp/" + basename + "_s6.c"
  norm_name = "temp/" + basename + "_norm.c"

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

  #norm = open(norm_name, 'r').read()
  #norm_size = os.path.getsize(norm_name)
  #gnu_norm = float(lcs(norm, gnu_content))/max(norm_size, os.path.getsize(gnu_name))
  #kr_norm = float(lcs(norm, kr_content))/max(norm_size, os.path.getsize(kr_name))
  #lx_norm = float(lcs(norm, lx_content))/max(norm_size, os.path.getsize(lx_name))
  #s1_norm = float(lcs(norm, s1_content))/max(norm_size, os.path.getsize(s1_name))
  #s2_norm = float(lcs(norm, s2_content))/max(norm_size, os.path.getsize(s2_name))
  #s3_norm = float(lcs(norm, s3_content))/max(norm_size, os.path.getsize(s3_name))
  #s4_norm = float(lcs(norm, s4_content))/max(norm_size, os.path.getsize(s4_name))
  #s5_norm = float(lcs(norm, s5_content))/max(norm_size, os.path.getsize(s5_name))
  #s6_norm = float(lcs(norm, s6_content))/max(norm_size, os.path.getsize(s6_name))

  return [gnu, kr, lx, s1, s2, s3, s4, s5, s6]

#------------------------------------------------------------------------------
if __name__ == "__main__":
  if len(sys.argv) > 1:
    get_features(sys.argv[1])
  else:
    print("Please provide a filename as argument")

