import os
import javalang
import re
import sys
import math
import numpy as np

class Program:
  def __init__(self, author, percent_ops_with_spaces, avg_comment, width_space, percent_blank, avg_id_length):
    self.author = author
    self.perc_ops_space = percent_ops_with_spaces
    self.avg_comment = avg_comment
    self.width_space = width_space
    self.percent_blank = percent_blank
    self.avg_id_length = avg_id_length

def distance(p1, p2):
  author_var = (p1.author - p2.author)**2
  percent_ops = (p1.perc_ops_space - p2.perc_ops_space)**2
  avg_comm = (p1.avg_comment - p2.avg_comment)**2
  width_space = (p1.width_space - p2.width_space)**2
  perc_blank = (p1.percent_blank - p2.percent_blank)**2
  avg_id = (p1.avg_id_length - p2.avg_id_length)**2
  return round(math.sqrt(author_var + percent_ops + avg_comm + width_space + perc_blank + avg_id), 2)

#regexes
op_space = r' [\+-\/\*=] '
op_no_space = r'[a-z0-9][\+-\/\*=][a-z0-9]'
space = r'^[ ]+'
tab = r'^[\t]+'
single_comment = r'\/\/.*\n'
multi_comment = r'\/\*[\s\S^]*?\*\/'
irregular_spacing = False

filename = "rosetta.c"

with open(filename) as f:
  contents = f.read()

  lines = contents.split("\n")

  # find the ratio of operators padded by spaces to those that are not
  #sent = "sentence includes 3 + 4 - 2*2 * 1 / 3+1 + 3"

  ops_with_spaces = re.findall(op_space, contents)
  ops_without_spaces = re.findall(op_no_space, contents)
  single_comments = re.findall(single_comment, contents)
  multi_comments = re.findall(multi_comment, contents)

  # get average comment length
  total_len = 0
  comm_num = 0
  for c in single_comments:
    total_len += len(c)
    comm_num += 1
  for m in multi_comments:
    total_len += len(m)
    comm_num += 1

  average_len = 0
  if comm_num != 0:
    average_len = float(total_len)/comm_num

  percent_ops_with_spaces = 0
  if len(ops_with_spaces) != 0 or len(ops_without_spaces) != 0: 
    percent_ops_with_spaces = float(len(ops_with_spaces))/(len(ops_with_spaces) + len(ops_without_spaces))

  # then look at spacing before we tokenize
  # find tabs/spaces, #tabs/spaces
  total_spaces = 0
  total_tabs = 0
  width_space = 0
  space_lines = 0

  for line in lines:
    has_space = re.match(space, line)
    has_tab = re.match(tab, line)
    if line.strip() == "":
      space_lines += 1
    if has_space:
      total_spaces += len(has_space.group())
      if len(has_space.group()) < width_space or width_space == 0:
        width_space = len(has_space.group())
    if has_tab:
      total_tabs += len(has_tab.group())

  # use javalang to get average length of identifiers
  tokens = list(javalang.tokenizer.tokenize(contents))
  tree = javalang.parse.parse(contents)


  total_length = 0
  total_num = 0
  for path, node in tree.filter(javalang.tree.LocalVariableDeclaration):
    declarators = node.declarators
    for dec in declarators:
      total_length += len(dec.name)
      total_num += 1

  avg_id_length = 0
  if total_num != 0:
    avg_id_length = float(total_length)/total_num

  # X = nxd matrix where n = # samples, d = # features
  X.append([average_len, percent_ops_with_spaces, avg_id_length])
  Y.append(author)
  out_content += str(average_len) + "," + str(percent_ops_with_spaces) + "," + str(avg_id_length) + "\n"

  p = Program(author, percent_ops_with_spaces, average_len, width_space, float(space_lines)/len(lines), avg_id_length)
  progs.append(p)

  out_str = filename + "\n" \
    + " average length of comment: " + str(average_len) + "\n" \
    + " percent ops with spaces/total: " + str(percent_ops_with_spaces) + "\n" \
    + " width of space tab: " + str(width_space) + "\n" \
    + " percent blank lines: " + str(float(space_lines)/len(lines)) + "\n" \
    + " average identifier length: " + str(avg_id_length) + "\n"

  print(out_str)

with open(out_file, 'w') as out:
  out.write(out_content)
"""

#prog_names = ["P" + str(i) for i, p in enumerate(progs)]
prog_names = [x[1].replace("person", "p") for x in files]
row_fmt = "{:>20}" * (len(prog_names) + 1)
table = []

for p in progs:
  new_row = []
  for compare in progs:
    if p is compare:
      new_row.append(0)
    else:
      new_row.append(distance(p, compare))
  table.append(new_row)

print(row_fmt.format("", *prog_names))
for name, row in zip(prog_names, table):
  print(row_fmt.format(name, *row))


print("====================================================================")
X = np.array(X)

# use PCA to plot multidimensional data
# it's not ideal 'cause it'll plot them in such a way to maximize variance
pca = sklearnPCA(n_components=2)
transformed = pca.fit_transform(X)
plt.scatter(transformed[:,0], transformed[:,1], c=Y)

for label, x, y in zip(files, transformed[:0], transformed[:1]):
  plt.annotate(label, xy=(x, y))

plt.show()
"""
