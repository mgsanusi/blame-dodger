import os
import sys
import re

files = os.listdir("new_master")
#files = ["test.c"]
regex = "(?:int|char|double|bool)\s*\**\s*(\w+(?:\s?=\s?\"?\w+\"?)?[,;])+"
str_re = "\"[^%\"]+\""
varnames = []
var = set()
i = 0

for filename in files:
  i += 1
  with open("new_master/" + filename, "r") as f:
    content = f.read()
  print(str(i) + ": " + filename + " - " + str(len(content)))
  all_matches = re.findall(regex, content)

  for match in all_matches:
    #comma_separated = match.split(",")
    varnames += [x.split("=")[0].strip() for x in match[:-1].split(",")]
  #  var.update([x.split("=")[0].strip() for x in match.split(",")])

print(varnames)
with open("varnames.txt", "w") as f:
  f.write(",".join(varnames))
