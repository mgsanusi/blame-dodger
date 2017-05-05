import os
import sys

cpps = []
for root, dirs, files in os.walk(sys.argv[1]):
  cpps += [x for x in files if x.endswith('.c')]
print(cpps)
