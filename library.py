import os
import re
import sys

fname = sys.argv[1]
f = open(fname, 'r')
content = f.read().split("\n")

vector = {"stdio.h":0, "conio.h":0, "string.h":0, "stdlib.h":0, "math.h":0, "time.h":0, "ctype.h":0, "stdarg.h":0, "signal.h":0, "setjmp.h":0, "locale.h":0, "errno.h":0, "assert.h":0}

includes = ["stdio.h", "conio.h", "string.h", "stdlib.h", "math.h", "time.h", "ctype.h", "stdarg.h", "signal.h", "setjmp.h", "locale.h", "errno.h", "assert.h"]
for line in content:
  if line[0:8] == "#include":
    obj = re.search(r'[",<][a-z]*\.h[",>]', line[8:])
    name = obj.group(0).strip("<").strip(">").strip("\"")
    if name in includes:
      vector[name] += 1

print(vector)

