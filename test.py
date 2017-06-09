import os
import sys

filenames = os.listdir(sys.argv[1])
longer = 0
short = 0
okfiles = []
for f in filenames:
  if f.split(".")[-1] == "c":
    okfiles.append(f)
    with open(sys.argv[1] + "/" + f) as fl:
      content = fl.readlines()
      if len(content) == 0: print(f)
      if len(content) > 150:
        print("too long: " + f + " has " + str(len(content)) + " lines")
        #os.system("rm " + sys.argv[1] + "/" + f)
        longer += 1
      else:
        short += 1
        okfiles.append(f)

same = 0
notsame = 0
for f1 in okfiles:
  for f2 in okfiles:
    if f1 == f2: continue 
    first = f1.split("_")[0].strip()
    second = f2.split("_")[0].strip()
    if first == second:
      same += 1
    else:
      notsame += 1

print("long: " + str(longer) + ", short: " + str(short))
print("same: " + str(same) + ", notsame: " + str(notsame))
