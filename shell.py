import os
f1 = set(os.listdir("new_master"))
f2 = set(os.listdir("modified_vars_lib"))

for f in f2:
  if f not in f1:
    print(f)
for f in f1:
  if f not in f2:
    print(f)
