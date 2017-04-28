import os
import sys
import subprocess
from pycparser import preprocess_file, parse_file, c_ast, c_parser, c_generator

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

def get_features(filename):
  #ast = parse_file(filename, use_cpp=True)
  ast = parse_file(filename, use_cpp=True, cpp_path='gcc', 
                    cpp_args=['-E', '-std=c99',  r'-I/tmp/pycparser/utils/fake_libc_include'])
  av = AssignmentVisitor()
  dv = DeclVisitor()
  fdv = FuncDeclVisitor()
  av.visit(ast)
  dv.visit(ast)
  fdv.visit(ast)
  #print([x.name for x in av.assignments])
  #print([x for x in dv.declarations])

  ret = str(float(len(av.assignments))/len(dv.declarations)) if len(dv.declarations) != 0 else 0

  proc = subprocess.Popen(["wc","-l", os.path.abspath(filename)], stdout=subprocess.PIPE)
  output = proc.stdout.read().split()[0]
  #print(output)
  ret += " " + str(float(dv.methods)/int(output))
  ret += " " + str(fdv.nested)
  return ret


def translate_to_c(filename):
  ast = parse_file(filename, use_cpp=True)
  generator = c_generator.CGenerator()
  #ast.show()
  print(generator.visit(ast))

def _zz_test_translate():
  # internal use
  src = r'''
    void f(char * restrict joe){}
int main(void)
{
    unsigned int long k = 4;
    int p = - - k;
    return 0;
}
'''
  parser = c_parser.CParser()
  ast = parser.parse(src)
  ast.show()
  generator = c_generator.CGenerator()

  print(generator.visit(ast))

#------------------------------------------------------------------------------
if __name__ == "__main__":
  #_zz_test_translate()
  if len(sys.argv) > 1:
  #      translate_to_c(sys.argv[1])
    print(get_features(sys.argv[1]))
  else:
    print("Please provide a filename as argument")
