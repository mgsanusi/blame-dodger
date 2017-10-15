from sklearn.decomposition import PCA
from sklearn.discriminant_analysis import LinearDiscriminantAnalysis as LDA
from pandas.tools.plotting import parallel_coordinates
import pandas as pd
import matplotlib
matplotlib.use('Agg')

from mpl_toolkits.mplot3d import Axes3D
import matplotlib.pyplot as plt
from scipy import stats
import numpy as np

def get_y(true, pred):
  if true and pred:
    return 2
  elif true and not pred:
    return 1
  elif not true and pred:
    return 3
  elif not true and not pred:
    return 0

def get_domain(authors):
  author1 = authors.split("_")[0]
  author2 = authors.split("_")[1]
  if author1 == "gcj" and author2 == "gcj": # GCJ - GCJ
    return 0
  elif author1 == "gcj" or author2 == "gcj": # GCJ - GH
    return 1
  elif author1 == author2: # same GH
    return 2
  else: # GH-GH
    return 3

with open("barplot_file.csv", "r") as f:
  contents = f.read().split("\n")
  split_contents = [x.split(",") for x in contents]
  print(str(len(split_contents)) + " by " + str(len(split_contents[0])))

labels = [x[0] for x in split_contents[1:-1]]
#y_true = [int(x[-2]) for x in split_contents[1:-1]]
#y_pred = [int(x[-1]) for x in split_contents[1:-1]] # don't include column headers or empty line at bottom


#y = np.array([get_y(i, j) for i, j in zip(y_true, y_pred)])
y = np.array([get_domain(line[0]) for line in split_contents[1:-1]])

# TN: 0, FN: 1, TP: 2, FP: 3
#labels = [("True Negative", 0), ("False Negative", 1), ("True Positive", 2), ("False Positive", 3)]
labels = [("GCJ-GCJ", 0), ("GCJ-GH", 1), ("Same GH", 2), ("GH-GH", 3)]

X = []
for vector in split_contents[1:-1]:
  X.append([float(i) for i in vector[1:-1]])

X = np.array(X)
X_norm = (X - X.min())/(X.max() - X.min())

data = pd.DataFrame(X_norm)
y_data = pd.DataFrame(y)
print(data.shape)
print(y_data.shape)
#data["Name"] = pd.Series(y, index=data.index)

#plt.figure()
#parallel_coordinates(data, "Name")
pca = PCA(n_components=2)
lda = LDA(n_components=2)
transformed = pd.DataFrame(lda.fit_transform(X_norm, y))
#transformed = pd.DataFrame(pca.fit_transform(X_norm))

plt.scatter(transformed[y==0][0], transformed[y==0][1], label='GCJ-GCJ', c='red')
plt.scatter(transformed[y==1][0], transformed[y==1][1], label='GCJ-GH', c='blue')
plt.scatter(transformed[y==2][0], transformed[y==2][1], label='Same GH', c='lightgreen')
plt.scatter(transformed[y==3][0], transformed[y==3][1], label='GH-GH', c='yellow')


plt.legend()
plt.savefig("domain.png")
plt.show()
"""
fig = plt.figure(1, figsize=(40,40))
plt.clf()
ax = Axes3D(fig, rect=[0, 0, .95, 1], elev=48, azim=134)

plt.cla()
pca = PCA(n_components=3)
pca.fit(X)
X = pca.transform(X)

for name, label in labels:
  ax.text3D(X[y == label, 0].mean(),
            X[y == label, 1].mean(), # + 1.5?
            X[y == label, 2].mean(), name,
            horizontalalignment='center',
            bbox=dict(alpha=.5, edgecolor='w', facecolor='w'))

ax.scatter(X[:, 0], X[:, 1], X[:, 2], c=y)
plt.savefig("plot.png")
plt.show()
"""
