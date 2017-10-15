from sklearn.cluster import KMeans
from sklearn.decomposition import PCA as sklearnPCA
import matplotlib.pyplot as plt
import numpy as np
import pandas as pd
import random
import subprocess
import sys 
import os

n = 5
files = os.listdir("../googlecodejam/minierdata")
N = len(files)
vectors = []
names = {0: "gnu", 1: "kr", 2: "lx", 3: "s1", 4: "s2", 5: "s3", 6: "s4", 7: "s5", 8:"s6"} 
for f in files:
  print("../googlecodejam/minierdata/" + f)
  size = os.path.getsize("../googlecodejam/minierdata/" + f)
  vector = [random.randint(0, 100), random.randint(0, 100)]
  vectors.append((f, [float(x) for x in vector]))

numbers = [x[1] for x in vectors]
y = [x[0] for x in vectors]
print(numbers)
X_unnorm = np.array(numbers)
X = (X_unnorm - X_unnorm.min())/float(X_unnorm.max() - X_unnorm.min())
print(X)
kmeans = KMeans(n_clusters=n) #n_clusters=n
kmeans.fit(X)
labels = kmeans.labels_
prediction = kmeans.predict(X)

colors = ['#4EACC5', '#FF9C34', '#4E9A06', '#C70039', '#C70039', '#779ECB', '#966FD6']
filenames = [x[0] for x in vectors]
plt.figure()
plt.hold(True)

pca = sklearnPCA(n_components=2)
transformed = pd.DataFrame(pca.fit_transform(X))
plt.scatter(transformed[:][0], transformed[:][1])
"""
for k, col in zip(range(n), colors[0:n]):
    my_members = labels == k
    plt.plot(X[my_members, 0], X[my_members, 1], 'w',
            markerfacecolor=col, marker='o')
"""
for label, x, y, in zip(filenames, transformed[:][0], transformed[:][1]):
  plt.annotate(label, xy=(x, y), xytext=(-5, 5), textcoords='offset points', ha='right', va='bottom')

plt.grid(True)
plt.show()
