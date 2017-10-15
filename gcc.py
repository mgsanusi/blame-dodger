import subprocess
import sys
import os

folder = os.listdir(sys.argv[1])
for filename in folder:
  try:
    subprocess.call(["gcc", folder + "/" + filename])
  except:
    print(filename + " doesn't compile")
