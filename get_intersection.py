
with open("feature_importances.txt") as f:
  content = f.read().split("\n")
  top = set()
  i = 0
  while len(top) < 200:
    line = content[i].split(" ")
    if line[0] == "VAR:":
      top.add(line[1])
    i += 1

with open("github_feature_importances.txt") as f:
  content = f.read().split("\n")
  top_gh = set()
  i = 0
  while len(top_gh) < 200:
    line = content[i].split(" ")
    if line[0] == "VAR:":
      top_gh.add(line[1])
    i += 1

with open("gcj_feature_importances.txt") as f:
  content = f.read().split("\n")
  top_gcj = set()
  i = 0
  while len(top_gcj) < 200:
    line = content[i].split(" ")
    if line[0] == "VAR:":
      top_gcj.add(line[1])
    i += 1

print("\n".join(top.intersection(top_gcj, top_gh)))
