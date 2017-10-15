
with open("feature_vectors_master.csv", "r") as f:
  content = f.read().split("\n")
  vectors = [x.split(",") for x in content]

author_dataset = {}
with open("authors.txt", "r") as f:
  content = f.read().split("\n")
  for line in content:
    folder_author = line.split("_") 
    if len(folder_author) < 2: continue
    author_dataset[folder_author[1]] = folder_author[0]

fname = "project_vector.csv"
output_str = ""

for vector in vectors:
  if len(vector) < 2: continue
  author = vector[1]
  if not author in author_dataset:
    project = "unknown"
    print(author)
  else:
    project = author_dataset[author]
  output_str += vector[0] + "," + author + "," + project + "," + ",".join(vector[2:]) + "\n"

with open(fname, "w") as f:
  f.write(output_str)
