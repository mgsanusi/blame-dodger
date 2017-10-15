import os
import sys

filenames = os.listdir(sys.argv[1])
authors = {}
new_names = []
total_programs = 0
total_authors = 0

for f in filenames:
  if f.split(".")[-1] == "c":
    author = f.split("_")[0]
    if author in authors:
      authors[author] += 1
    else:
      authors[author] = 1
      total_authors += 1
      new_name = sys.argv[1] + "_" + author
      new_names.append(new_name)

    total_programs += 1

print(authors)
print("average num of programs/author: " + str(float(total_programs)/total_authors))
with open("authors.txt", "a+") as f:
  f.write("\n".join(new_names))

