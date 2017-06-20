import os
import sys
import subprocess
import math
import re
from pycparser import preprocess_file, parse_file, c_ast, c_parser, c_generator

funcs = ["abs", "strtol", "qsort", "bzero", "strncmp", "strncpy", "strerror", "read", "memcmp", "free", "snprintf", "realloc", "atoi", "strtoll", "exit", "fgets", "sscanf", "memcpy", "atof", "atol", "puts", "srand", "fgetc", "sqrtl", "powl", "getline", "assert", "getchar", "putchar", "printf", "fprintf", "scanf", "fscanf", "strcat", "strcmp", "strcpy", "isdigit", "isalpha", "isalnum", "isspace", "toupper", "tolower", "errno", "islower", "isupper", "fabs", "pow", "sqrt", "time", "malloc", "calloc", "rand", "strlen", "freopen", "fopen", "strchr", "sprintf", "getc", "fclose", "memset"] 
#TODO either 
#       include every function possible OR
#       include a check that the function is in this list


class File():
  def __init__(self, name=None, author=None, words=None):
    self.name = name
    self.author = author
    self.words = words
    self.folder = ""
    self.camel_case = True
    self.tf = {}
    self.bag = {}
    self.lib_tf = {}
    self.vec = []
    self.vars_vec = []
    self.com_vec = []
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
    if not isinstance(node, c_ast.UnaryOp) and not isinstance(node.name, c_ast.UnaryOp):
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
    #if not node.name in funcs:
    self.var_names.append(node.name) # can I append just var names?
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
    self.names = []
    self.kmers3 = []
    self.kmers2 = []

  def visit_Decl(self, node):
    if not isinstance(node.type, c_ast.FuncDecl) and not isinstance(node.type, c_ast.UnaryOp): 
      if node.name is not None:
        self.declarations.append(node.name) 
        self.names.append(node.name)
        for i in range(0, len(node.name)-1):
          self.kmers2.append(node.name[i:i+2])
        for i in range(0, len(node.name)-2):
          self.kmers3.append(node.name[i:i+3])
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

class TypedefVisitor(c_ast.NodeVisitor):
  def __init__(self):
    self.count = 0

  def visit_Typedef(self, node):
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
    self.var_names = []

  def visit_Assignment(self, node):
    if isinstance(node.lvalue, c_ast.ID):
      self.assignments.append(node.lvalue) # ID object. Use .name
      self.var_names.append(node.lvalue.name)
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

def tf(word, tf_vec):
  return tf_vec[word]

def n_containing(word, tf_list):
  return sum(1 for tf in tf_list if word in tf)

def idf(word, tf_list):
  return math.log(len(tf_list)/1+n_containing(word, tf_list))

def tf_idf(word, tf_vec, tf_list):
  return tf(word, tf_vec)*idf(word, tf_list)

def get_lib_tf_idf(files, filenames, folder):
  exts = [f.split("_")[-1].strip(".c") for f in filenames] # get domain categories
  ext_set = set(exts)
  dictionaries = {ext:set() for ext in ext_set} # create dictionary for each domain

  tf_list = []
  tf_dom = {ext:[] for ext in ext_set}
  # first loop populates dictionaries
  for f in files:
    filename = folder + "/" + f.name
    dom = f.name.split("_")[-1].strip(".c")
    vec = {name:0 for name in funcs} # funcs is global set of all possible functions
    ast = parse_file(filename, use_cpp=True, cpp_path='gcc', 
                      cpp_args=['-E', '-std=c99',  r'-I/home/mgs9y/pycparser/utils/fake_libc_include'])
    fcv = FuncCallVisitor()
    fdv = FuncDefVisitor()
    fcv.visit(ast)
    fdv.visit(ast)

    for function in fcv.names: # for each function called
      fdvn = fdv.names
      #if function not in fdvn: # if it's not a user defined function
      if function in funcs: # if it's a library function
        dictionaries[dom].add(function) # add it to global dictionary

  # second loop finds term frequencies
  for f in files:
    filename = folder + "/" + f.name
    dom = f.name.split("_")[-1].strip(".c")
    vec = {name:0 for name in funcs} # funcs is global set of all possible functions
    ast = parse_file(filename, use_cpp=True, cpp_path='gcc', 
                      cpp_args=['-E', '-std=c99',  r'-I/home/mgs9y/pycparser/utils/fake_libc_include'])
    fcv = FuncCallVisitor()
    fdv = FuncDefVisitor()
    fcv.visit(ast)
    fdv.visit(ast)
    for function in fcv.names: # for each function called
      fdvn = fdv.names
      #if function not in fdvn: # if it's not a user defined function
      if function in dictionaries[dom]: # if it's a library function AND one used in this domain
        vec[function] += 1     # add to the term frequency
    
    for function in vec:
      f.lib_tf[function] = vec[function]/float(fcv.total) if fcv.total != 0 else 0
      tf_dom[dom].append(f.lib_tf)
      tf_list.append(f.lib_tf)
  # everything now populated

  for f in files:
    dom = f.name.split("_")[-1].strip(".c")
    for word in funcs:
      f.lib_vec.append(tf_idf(word, f.lib_tf, tf_dom[dom]))

def get_lib(filename):
  vec = {name:0 for name in funcs}
  tf = {}
  ast = parse_file(filename, use_cpp=True, cpp_path='gcc', 
                    cpp_args=['-E', '-c', '-std=c99',  r'-I/home/mgs9y/pycparser/utils/fake_libc_include'])
  fcv = FuncCallVisitor()
  fdv = FuncDefVisitor()
  fcv.visit(ast)
  fdv.visit(ast)

  for f in fcv.names: # for each function called
    fdvn = fdv.names
    #if f not in fdvn: # if it's not a user defined function
    if f in funcs: # if it's a library function
      vec[f] += 1     # add to the term frequency
  
  for f in vec:
    tf[f] = vec[f]/float(fcv.total) if fcv.total != 0 else 0
      
  return tf.values()

def get_functional(filename):
  ast = parse_file(filename, use_cpp=True, cpp_path='gcc', 
                    cpp_args=['-E', '-c', 
                    '-std=c99',  r'-I/home/mgs9y/pycparser/utils/fake_libc_include'])
  av = AssignmentVisitor() #
  dv = DeclVisitor() #
  fdv = FuncDefVisitor()
  fcv = FuncCallVisitor() #
  tdv = TypedefVisitor()
  fdcv = FuncDeclVisitor() #
  sv = StructVisitor() #
  iv = IfVisitor() #
  fv = ForVisitor()
  dwv = DoWhileVisitor()
  wv = WhileVisitor()
  cv = CaseVisitor()
  swv = SwitchVisitor()
  tv = TernaryOpVisitor()
  av.visit(ast) #
  dv.visit(ast) #
  fdv.visit(ast)
  fcv.visit(ast) #
  tdv.visit(ast)
  fdcv.visit(ast) #
  sv.visit(ast) #
  iv.visit(ast) #
  fv.visit(ast)
  dwv.visit(ast)
  wv.visit(ast)
  cv.visit(ast)
  swv.visit(ast)
  tv.visit(ast)

  sorted_coords = sorted(fdv.coords, key=lambda x: x[1])

  # below
 # ret = [float(len(av.assignments))/len(dv.declarations) if len(dv.declarations) != 0 else 0]

  file_len = 0
  with open(os.path.abspath(filename, 'r')) as len_file:
    file_len = len(len_file.readlines())

  # start
  #main_len = 0
  #for i, pair in enumerate(sorted_coords): # name, lineno
  #  if pair[0] == "main":
  #    if i == len(sorted_coords)-1: # if no methods after main
  #      main_len = file_len - pair[1]
  #    else:
  #      main_len = sorted_coords[i+1][1] - pair[1]
  #    break

  #avg_meth = float(fdcv.num_methods)/file_len if file_len != 0 else 0
  #main_to_method = float(main_len)/avg_meth if avg_meth != 0 else 0
  #params_to_methods = float(fdcv.num_params)/fdcv.num_methods if fdcv.num_methods != 0 else 0
  #end
      
  ret = []
  # start
  #ret.append(avg_meth)
  #ret.append(fcv.nested)
  #ret.append(main_to_method)
  #ret.append(params_to_methods) # average num params
  #ret.append(sv.count/float(file_len)) # struct
  #ret.append(iv.count/float(file_len))
  # end
  ret.append(fv.count/float(file_len))
  ret.append(tdv.count/float(file_len))
  ret.append(dwv.count/float(file_len))
  ret.append(wv.count/float(file_len))
  ret.append(cv.count/float(file_len))
  ret.append(tv.count/float(file_len))
  # 8 features
  return ret

def get_id_names(filename, folder):
  ast = parse_file(folder + "/" + filename, use_cpp=True, cpp_path='gcc', 
                    cpp_args=['-E', '-std=c99',  r'-I/home/mgs9y/pycparser/utils/fake_libc_include'])
  #av = AssignmentVisitor()
  #av.visit(ast)
  dv = DeclVisitor()
  dv.visit(ast)
  #return av.var_names
  return dv.declarations

def get_kmers(filename, folder):
  ast = parse_file(folder + "/" + filename, use_cpp=True, cpp_path='gcc', 
                    cpp_args=['-E', '-c', '-std=c99',  r'-I/home/mgs9y/pycparser/utils/fake_libc_include'])
  #idv = IDVisitor()
  #idv.visit(ast)
  #return idv.var_names#var_names
  dv = DeclVisitor()
  dv.visit(ast)
  return dv.names #+ idv.kmers

def get_full_names(filename):
  ast = parse_file(filename, use_cpp=True, cpp_path='gcc', 
                    cpp_args=['-E', '-std=c99',  r'-I/home/mgs9y/pycparser/utils/fake_libc_include'])
  idv = IDVisitor()
  idv.visit(ast)
  return idv.var_names

def get_tokens(filename, folder):
  ast = parse_file(folder + "/" + filename, use_cpp=True, cpp_path='gcc', 
                    cpp_args=['-E', '-std=c99',  r'-I/home/mgs9y/pycparser/utils/fake_libc_include'])
  idv = IDVisitor()
  idv.visit(ast)
  return idv.tokens

def get_comments(filename, file_obj):
  content = open(filename, 'r').read()
  multiline = re.compile('\/\*(\*(?!\/)|[^*])*\*\/')
  singleline = re.compile('\/\/.*')
  multis = multiline.findall(content)
  singles = singleline.findall(content)

  if multis is None and singles is None:
    file_obj.com_vec = [0, 0, 0] # change later

  if multis is None: multis = []
  if singles is None: singles = []

  total_len = 0
  for comment in [multis + singles]:
    total_len += len(comment)
  avg_len = total_len/float(len([multis + singles])) # feature 1

  #ratio_s_to_m = float(len(singles))/len(multis) if len(multis) != 0 else float(len(singles)) # feature 2
  num_comments = float(len([multis + singles]))/len(content) # feature 3

  #file_obj.com_vec = [avg_len, ratio_s_to_m, num_comments]
  file_obj.com_vec = [avg_len, num_comments]
  

def get_ws(fname):
  basename = fname.strip(".c").split("/")[-1]
  #gnu_name= "temp/" + basename + "_gnu.c"
  #kr_name = "temp/" + basename + "_kr.c"
  #s3_name = "temp/" + basename + "_s3.c"
  s4_name = "temp/" + basename + "_s4.c"
  s6_name = "temp/" + basename + "_s6.c"

  #os.system("gindent -gnu " + fname + " -o " + gnu_name)
  #os.system("gindent -kr " + fname + " -o " + kr_name)
  #os.system("gindent -i2 -c2 -cd2 -nbap -cli2 " + fname + " -o " + s3_name) # indent twice
  os.system("indent -nsaf -nsai -nsaw -nlps -nprs -nbfda -nbc -ncs " + fname + " -o " + s4_name) # everything tight
  os.system("indent -br -brf -brs -l50 -lps -nce -ncdw " + fname + " -o " + s6_name) #braces on same line, short lines, no cuddle

  orig_file = open(fname, 'r')
  orig = orig_file.read()
  orig_file.close()
  #gnu_content = open(gnu_name, 'r').read()
  #kr_content = open(kr_name, 'r').read()
  #s3_content = open(s3_name, 'r').read()
  s4_file = open(s4_name, 'r')
  s6_file = open(s6_name, 'r')
  s4_content = s4_file.read()
  s6_content = s6_file.read()
  s4_file.close()
  s6_file.close()

  orig_size = os.path.getsize(fname)
  #gnu = float(lcs(orig, gnu_content))/max(orig_size, os.path.getsize(gnu_name))
  #kr = float(lcs(orig, kr_content))/max(orig_size, os.path.getsize(kr_name))
  #s3 = float(lcs(orig, s3_content))/max(orig_size, os.path.getsize(s3_name))
  s4 = float(lcs(orig, s4_content))/max(orig_size, os.path.getsize(s4_name))
  s6 = float(lcs(orig, s6_content))/max(orig_size, os.path.getsize(s6_name))

  #return [gnu, kr, s3, s4, s6]
  return [s4, s6]

#------------------------------------------------------------------------------
if __name__ == "__main__":
  if len(sys.argv) > 1:
    get_features(sys.argv[1])
  else:
    print("Please provide a filename as argument")

