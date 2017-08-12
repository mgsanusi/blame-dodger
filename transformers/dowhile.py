import re
import os
import sys
from pycparser import preprocess_file, parse_file, c_ast, c_parser, c_generator

class DoWhileVisitor(c_ast.NodeVisitor):
  def __init__(self):
    pass

  def visit_DoWhile(self, node):
    generator = c_generator.CGenerator()

    ### Change Do Whiles to Whiles
    ## insert reset variable declaration
    first_iteration = "first_iteration"
    id_type = c_ast.IdentifierType(["int"], "")
    int_type = c_ast.TypeDecl(first_iteration, [], id_type, "")
    int_decl = c_ast.Decl(first_iteration, [], [], [], int_type, None, None, "")

    ## make assignment for reset variable
    lval = c_ast.ID(first_iteration, "")
    rval = c_ast.Constant(int, 1, "")
    assign = c_ast.Assignment("=", lval, rval, "")

    # FIXME
    #node.body.block_items.insert(0, int_decl)

    # FIXME
    #new_block_items.append(assign)

    while_loop = c_ast.While(node.cond, node.stmt, node.coord)
    new_condition = c_ast.BinaryOp("||", node.cond, c_ast.BinaryOp("==", c_ast.ID(first_iteration, ""), c_ast.Constant(int, 1, "")))
    while_loop.cond = new_condition

    if_statement = c_ast.If(c_ast.ID(first_iteration, ""), c_ast.Assignment("=", c_ast.ID(first_iteration, ""), c_ast.Constant(int, 0, ""), ""), None, "")
    while_loop.stmt.block_items.insert(0, if_statement)

    #new_block_items.append(while_loop)
    #node.body.block_items = new_block_items
    node = while_loop
    #print("Method body:")
    #print(type(node.body.block_items))
    #print("\n".join([str(x) for x in node.body.block_items]))
    #print(generator.visit(node.body))
    self.generic_visit(node)
    print("DoWhile=================")
    print("cond: " + str(node.cond))
    print("   Op: " + str(node.cond.op))
    print("   left: " + str(node.cond.left))
    print("   right: " + str(node.cond.right))
    print("stmt: " + str(node.stmt))
    print("   has block items")
class DeclVisitor(c_ast.NodeVisitor):
  def __init__(self):
    pass

  def visit_Decl(self, node):
    print("Decl=====================")
    print("Name: " + node.name)
    print("Quals: " + str(node.quals))
    print("Storage: " + str(node.storage))
    print("Funcspec: " + str(node.funcspec))
    print("Type: " + str(node.type))
    print("Init: " + str(node.init))
    print("Bitsize: " + str(node.bitsize))
    print("Coord: " + str(node.coord))

    if isinstance(node.type, c_ast.TypeDecl):
      print("Type====")
      print("Declname: " + str(node.type.declname))
      print("Quals: " + str(node.type.quals))
      print("Type: " + str(node.type.type))
      print("Coord: " + str(node.type.coord))
    if isinstance(node.type.type, c_ast.IdentifierType):
      print("IDType===")
      print("names: " + str(node.type.type.names))
    self.generic_visit(node)

# op, lvalue, rvalue, coord
class AssignmentVisitor(c_ast.NodeVisitor):
  def __init__(self):
    pass

  def visit_Assignment(self, node):
    print("Assignment==============")
    print("Op: " + str(node.op))
    print("lval: " + str(node.lvalue))
    print("rval: " + str(node.rvalue))
    print("coord: " + str(node.coord))

    if isinstance(node.rvalue, c_ast.Constant):
      print(node.rvalue.type)
    self.generic_visit(node)

# decl, param_decls, body, coord
class FuncDefVisitor(c_ast.NodeVisitor):
  def __init__(self):
    pass

  def visit_FuncDef(self, node):
    generator = c_generator.CGenerator()

    if node.body.block_items is not None:
      ### Change Do Whiles to Whiles
      ## insert reset variable declaration
      first_iteration = "first_iteration"
      id_type = c_ast.IdentifierType(["int"], "")
      int_type = c_ast.TypeDecl(first_iteration, [], id_type, "")
      int_decl = c_ast.Decl(first_iteration, [], [], [], int_type, None, None, "")

      ## make assignment for reset variable
      lval = c_ast.ID(first_iteration, "")
      rval = c_ast.Constant(int, 1, "")
      assign = c_ast.Assignment("=", lval, rval, "")

      node.body.block_items.insert(0, int_decl)

      new_block_items = []
      for i, statement in enumerate(node.body.block_items):
        if isinstance(statement, c_ast.DoWhile):
          new_block_items.append(assign)

          while_loop = c_ast.While(statement.cond, statement.stmt, statement.coord)
          new_condition = c_ast.BinaryOp("||", statement.cond, c_ast.BinaryOp("==", c_ast.ID(first_iteration, ""), c_ast.Constant(int, 1, "")))
          while_loop.cond = new_condition

          if_statement = c_ast.If(c_ast.ID(first_iteration, ""), c_ast.Assignment("=", c_ast.ID(first_iteration, ""), c_ast.Constant(int, 0, ""), ""), None, "")
          while_loop.stmt.block_items.insert(0, if_statement)

          new_block_items.append(while_loop)
        else:
          new_block_items.append(statement)

      node.body.block_items = new_block_items
      #print("Method body:")
      #print(type(node.body.block_items))
      #print("\n".join([str(x) for x in node.body.block_items]))
      #print(generator.visit(node.body))
    self.generic_visit(node)

# takes file contents, returns modified contents
def transform_dw(content):
  dowhile = "do\s*\{(.|\n)*\}\s*while\s*\((.|\n)*?\);"
  do = "do\s*\{"
  condition = "while\s*\((.|\n)*?\);" 
  first_dowhile = True
  first_iteration = "first_iteration"

  split_content = content.split("\n")

  matches = re.findall(dowhile, content)
  if not matches or len(matches) == 0:
    return content

  for match in matches:
    match_content = match.group() # find dowhile text

    do_match = re.search(do, content) # find do { portion
    do_content = do_match.group() # find do { portion
    strip_do = match_content.strip(do_content) # strip do { off

    condition_match = re.search(condition, strip_do) # find condition
    condition_content = condition_match.group() # condition text
    strip_condition = condition_content.strip("while\s*\(").strip("\)\s*;")
    body_content = strip_do.strip(condition_content)

    new_condition = "while (" + strip_condition + " || first_iteration) "
    reset_first_iter = first_iteration + " = 1;"
    if_stat = "   if (" + first_iteration + ") { " + first_iteration + " = 0; }"

    if first_dowhile:
      # instead of resetting the first iter variable, insert it at the beginning of main
      new_while = "\n".join([new_condition + " {", if_stat, body_content])
    else:
      new_while = "\n".join([reset_first_iter, new_condition + " {", if_stat, body_content])

    new_content = content.replace(match_content, new_while)
  return new_content

def transform_it(filename, write_to_file):
  includes = []
  basename = filename.split("/")[-1]
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

  ast = parse_file(filename, use_cpp=True, cpp_path='gcc', 
                    cpp_args=['-E', '-c', '-std=c99',  r'-I/home/mgs9y/pycparser/utils/fake_libc_include'])
  #ast.show()
  fdv = FuncDefVisitor()
  fdv.visit(ast)

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

  if write_to_file:
    with open("modified_vars/" + basename, "w") as f:
      f.write(mod_output)
  else:
    print(mod_output)

if __name__ == "__main__":
  #with open("sample_new.c", "w") as f:
  #  content = open("sample.c", "r").read()
  #  f.write(dowhile(content))

  folder = "new_master"
  folder_contents = os.listdir(folder)
  for filename in folder_contents:
    transform_it(folder + "/" + filename, write_to_file=True)

  #transform_it(sys.argv[1], False)

  #dv = DeclVisitor()
  #dv.visit(ast)
  #av = AssignmentVisitor()
  #av.visit(ast)
  #dwv = DoWhileVisitor()
  #dwv.visit(ast)
