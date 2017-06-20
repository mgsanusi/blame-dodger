#------------------------------------------------------------------------------
# pycparser: c-to-c.py
#
# Example of using pycparser.c_generator, serving as a simplistic translator
# from C to AST and back to C.
#
# Eli Bendersky [http://eli.thegreenplace.net]
# License: BSD
#------------------------------------------------------------------------------
from __future__ import print_function
import os
import sys
import re
import nltk
import time
import random
from nltk.corpus import wordnet

# This is not required if you've installed pycparser into
# your site-packages/ with setup.py
#
sys.path.extend(['.', '..'])

from pycparser import preprocess_file, parse_file, c_ast, c_parser, c_generator

varnames = {"argc":"argc", "argv":"argv"}
sub_dict = {"buffer":"buf", "buff":"buf", "cnt":"count", "string":"str", "current":"curr", "character":"char", "ch":"char", "res":"result", "rslt":"result", "ans":"answer", "arr":"array", "len":"length", "no":"num", "pointer":"ptr", "pntr":"ptr", "iter":"itr", "iterator":"itr", "return":"ret", "index":"i", "val":"value", "lst":"list", "func":"function"}
code_synonyms = [["buffer", "buf", "buff"], ["cnt", "count"], ["string", "str"], ["current", "curr"], ["character", "char", "ch"], ["res", "result", "rslt", "ans", "answer"], ["arr", "array"], ["len", "length"], ["no", "num"], ["pointer", "ptr"], ["iter", "itr"], ["return", "ret"], ["index", "i"], ["value", "val"], ["lst", "list"], ["func", "function"]]
keywords = ["char", "int", "double", "case", "switch", "for", "while", "if", "else", "union", "argc", "argv", "return", "main", "fin", "fout"]
file_varnames = {}
# still to add: retval/ret
dictionary = []
ptr_vars = []
dict_objects = [[],[],[],[]]
name_dict = {}
universe = []
current_filename = ""
camel_case = False
transformed = 0
kept = 0
#english_dict = [x.lower() for x in nltk.corpus.words.words()]

def get_next(i):
  return "t" + str(i)

def split_string(name):
  if "_" in name:
    return [x.lower() for x in name.split("_")]
  else:
    return [x.lower() for x in re.sub('([a-z])([A-Z])', r'\1 \2', name).split()]

class VariableName():
  def __init__(self, name):
    self.name = name
    self.globl = False
    self.pointer = False
    self.filename = ""
    self.type = type

class TypeDeclVisitor(c_ast.NodeVisitor):
  def __init__(self):
    self.i = 0

  def visit_TypeDecl(self, node):
    global current_filename
    global dict_objects
    global camel_case
    global code_synonyms
    global kept
    global transformed
    if not node.declname is None:
      if node.declname in varnames:
        node.declname = varnames[node.declname]
      else:
        if len(node.declname) <= 2: 
          if not node.declname in name_dict: 
            split_name = split_string(node.declname)
          else:
            name_objects = [x for x in name_dict[node.declname] if x.filename == current_filename]
            if len(name_objects) == 0:
              split_name = split_string(node.declname)
            else:
              name_object = name_objects[0]

              globl = 1 if name_object.globl else 0 # 1
              pointer = 2 if name_object.pointer else 0 # 2

              split_name = split_string(random.choice(dict_objects[globl + pointer]).name)
              #print("dict length was " + str(len(dict_objects[globl+pointer])) + " and changed name to " + "".join(split_name))

        else: # len > 2
          split_name = split_string(node.declname)

          # for each part of the variable name
          t4 = time.time()
          for i, substr in enumerate(split_name):
            code_synset = [x for x in code_synonyms if substr in x]
            if len(code_synset) == 1: # if it's a code term, change it and continue
            # if it's a code term
              # already checked that it's not in varnames so
              random_word = random.choice(code_synset[0])
              varnames[substr] = random_word
              split_name[i] = random_word

              # keep the continue
              continue

            # otherwise look for an English word
            synsets = wordnet.synsets(substr)

            if len(substr) > 1 and len(synsets) != 0: # if it's an English word
              synonyms = [s.lemma_names()[0] for s in synsets]
              if len(synonyms) > 0: # if it has a synonym, choose a random one
                random_word = random.choice(synonyms)
                j = 0
                while (random_word not in universe or random_word in ["argc", "argv"]) and j < 5:
                  j += 1
                  random_word = random.choice(synonyms)
                if random_word in universe:
                  varnames[substr] = random_word
                  split_name[i] = random_word

        # in all cases
        new_name = ""
        if camel_case:
          new_name = "".join(x.capitalize() for x in split_name)
          name_list = list(new_name)
          name_list[0] = name_list[0].lower()
          new_name = "".join(name_list)
        else:
          new_name = "_".join(split_name)

        if new_name in file_varnames[current_filename] or len(new_name) == 0 or new_name in keywords: # if it's already being used, switch it back
          if camel_case:
            new_name = "".join(x.capitalize() for x in split_string(node.declname))
            name_list = list(new_name)
            name_list[0] = name_list[0].lower()
            new_name = "".join(name_list)
          else:
            new_name = "_".join(x for x in split_string(node.declname))
          kept += 1
        elif "".join(split_name) == "".join(split_string(node.declname)):
          kept += 1
        else:
          transformed += 1

        new_name = new_name.replace("-","_")
        new_name = new_name.replace(".","_")
        new_name = new_name.replace(" ","_")
        new_name = new_name.replace("'","")
        varnames[node.declname] = new_name
        node.declname = new_name
    self.generic_visit(node)

class IDVisitor(c_ast.NodeVisitor):
  def __init__(self):
    something = 0

  def visit_ID(self, node):
    if node.name in varnames:
      node.name = varnames[node.name]
    self.generic_visit(node)

class DeclVisitor(c_ast.NodeVisitor):
  def __init__(self):
    something = 0

  def visit_Decl(self, node):
    global current_filename
    global file_varnames
    if isinstance(node.type, c_ast.PtrDecl):
      ptr_vars.append(node.name)
    if not isinstance(node.type, c_ast.FuncDecl) and not isinstance(node.type, c_ast.UnaryOp): 
      dictionary.append((node.name, node.type))
      if current_filename in file_varnames:
        file_varnames[current_filename].append(node.name)
      else:
        file_varnames[current_filename] = [node.name]
        
    self.generic_visit(node)

class AssignmentVisitor(c_ast.NodeVisitor):
  def __init__(self):
    something = 0

  def visit_Assignment(self, node):
    if isinstance(node.lvalue, c_ast.ID):
      node.lvalue.name = "changed"
    self.generic_visit(node)

def populate_and_transform(filenames, folder):
  global dictionary
  global current_filename
  global dict_objects
  global varnames
  global camel_case
  global file_varnames

  for f in filenames:
    ast = parse_file(folder + "/" + f, use_cpp=True, cpp_path='gcc', 
                      cpp_args=['-E', '-c', '-std=c99',  r'-I/usr/bin/pycparser/utils/fake_libc_include'])

    # make dictionary of global/local and ptr/non-ptr
    global_vars = [x[1] for x in ast.children() if isinstance(x[1], c_ast.Decl)]

    current_filename = f.strip()

    # decl visitor to find all var names and populate dictionary
    dv = DeclVisitor()
    dv.visit(ast)
    
    for tupl in dictionary:
      name = tupl[0]
      typ = tupl[1]
      if name is None or len(name) == 0: continue
      name_object = VariableName(name)
      name_object.globl = True if name in global_vars else False
      name_object.pointer = True if name in ptr_vars else False
      name_object.filename = f
      name_object.type = typ

      # refactor with dictionary
      if not name_object.globl and not name_object.pointer: #11
        dict_objects[0].append(name_object)
      elif name_object.globl and not name_object.pointer: #10
        dict_objects[1].append(name_object)
      elif not name_object.globl and name_object.pointer: #01
        dict_objects[2].append(name_object)
      elif name_object.globl and name_object.pointer: #00
        dict_objects[3].append(name_object)

      if name in name_dict:
        name_dict[name].append(name_object)
      else:
        name_dict[name] = [name_object]

  for f in filenames:
    camel_case = random.choice([True, False])
    varnames = {"argc":"argc", "argv":"argv"}
    current_filename = f.strip()
    transform(folder + "/" + f)
    with open("modified_vars/" + f, 'w') as write_file:
       write_file.write(transform(sys.argv[1] + "/" + f))

def transform(filename):
    global dict_objects
    print(filename)
    # get includes and typedefs
    includes = []
    with open(filename, 'r') as f:
      content = f.readlines()
      for line in content:
        if line[0:8] == "#include":
          includes.append(line)
        elif line[0:7] == "typedef":
          if "struct" in line:
            includes.append(line.replace("{",""))
          else:
            includes.append(line)

    # parse file
    #t0 = time.time()
    ast = parse_file(filename, use_cpp=True, cpp_path='gcc', 
                      cpp_args=['-E', '-c', '-std=c99',  r'-I/usr/bin/pycparser/utils/fake_libc_include'])
    # make changes to ast

    # type decl visitor to generate new ones
    tv = TypeDeclVisitor()
    tv.visit(ast)

    # id visitor to change all other occurrences of var names
    idv = IDVisitor()
    idv.visit(ast)

    # convert ast back to c
    generator = c_generator.CGenerator()
    output = generator.visit(ast)
    mod_output = "".join(includes)
    beginning = True
    for line in output.split("\n"):
      if line[0:7] == "typedef" and beginning:
        continue
      elif line[0:7] == "typedef" and not beginning:
        mod_output += line + "\n"
      else: # line not typedef
        beginning = False
        mod_output += line + "\n"
         
    return mod_output

#------------------------------------------------------------------------------
if __name__ == "__main__":
  #_zz_test_translate()
  with open("universe.txt", "r") as f:
    universe = f.read().split("\n")
  if len(sys.argv) > 1:
    #translate_to_c(sys.argv[1])
    os.system("mkdir modified_vars")
    folder_contents = os.listdir(sys.argv[1])

    # for each file
    populate_and_transform(folder_contents, sys.argv[1])
    print(str(transformed) + " variable names transformed. " + str(kept) + " variables kept.")
 #   for f in folder_contents:
 #     with open("modified_vars/" + f, 'w') as write_file:
 #       write_file.write(transform(sys.argv[1] + "/" + f))
 #       transform(sys.argv[1] + "/" + f)
  else:
    print("please provide a filename as argument")
