import os
import re

files = os.listdir("new_master")
str_re = "\"[^%\"]+\""
strings = set()

for filename in files:
  with open("new_master/" + filename, "r") as f:
    content = f.read()
  all_matches = re.findall(str_re, content)
  strings.update(all_matches)

print(strings)
with open("strings.txt", "w") as f:
  f.write(",".join(strings))
