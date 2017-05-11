import os
import sys

months = ["Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Nov", "Dec"]
cfiles = []
for root, dirs, files in os.walk(sys.argv[1]):
  cfiles += [os.path.join(root, x) for x in files if x.endswith('.c')]

for cfile in cfiles:
  
  os.system("git log " + cfile + " > log.out")
  out = open("log.out", 'r').readlines()
  if len(out) == 0: break
  i = 1
  authors = {}
  maxauthor = ""
  maxcommits = 0
  commits = 0
  recent_year = 0
  recent_month = ""
  for line in out:
    split = line.split()
    if len(split) == 0: break
    if split[0] == "Date:":
      if recent_year == 0:
        recent_year = int(split[5])
        recent_month = split[2]
      elif int(split[5]) < recent_year and months.index(split[2]) > months.index(recent_month):
        break
    if split[0] != "Author:": continue
        
    commits += 1
    author = split[1]
    if author in authors:
      authors[author] += 1
    else:
      authors[author] = 1
    if authors[author] > maxcommits:
      maxcommits = authors[author]
      maxauthor = author
  if maxcommits >= (commits/2):
    print(maxauthor + ", " + cfile)
  else:
    print("None")

  os.system("rm log.out")
  
