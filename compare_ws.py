import os
import sys
import editdistance

def lcs(X, Y):
  m = len(X)
  n = len(Y)

  L = [[None]*(n+1) for i in range(m+1)]

  for i in range(m+1):
    for j in range(n+1):
      if i == 0 or j == 0:
        L[i][j] = 0
      elif X[i-1] == Y[j-1]:
        L[i][j] = L[i-1][j-1] + 1
      else:
        L[i][j] = max(L[i-1][j], L[i][j-1])

  return L[m][n]

fname = sys.argv[1]
basename = fname.strip(".c")

gnu_name= basename + "_gnu.c"
kr_name = basename + "_kr.c"
lx_name = basename + "_lx.c"
s1_name = basename + "_s1.c"
s2_name = basename + "_s2.c"
s3_name = basename + "_s3.c"
s4_name = basename + "_s4.c"
s5_name = basename + "_s5.c"
s6_name = basename + "_s6.c"
norm_name = basename + "_norm.c"

os.system("gindent -linux " + fname + " -o " + norm_name)
os.system("gindent -kr " + norm_name)
os.system("gindent -gnu " + norm_name)
os.system("gindent -gnu " + fname + " -o " + gnu_name)
os.system("gindent -kr " + fname + " -o " + kr_name)
os.system("gindent -linux  " + fname + " -o " + lx_name)
os.system("gindent -bad -br -brf -brs " + fname + " -o " + s1_name) # braces on same line, force new line after block of declarations
os.system("gindent -nut " + fname + " -o " + s2_name) # use spaces
os.system("gindent -i2 -c2 -cd2 -nbap -cli2 " + fname + " -o " + s3_name) # indent twice
os.system("gindent -nsaf -nsai -nsaw -nlps -nprs -nbfda -nbc -ncs " + fname + " -o " + s4_name) # everything tight
os.system("gindent -orig " + fname + " -o " + s5_name)
os.system("gindent -br -brf -brs -l50 -lps -nce -ncdw " + fname + " -o " + s6_name) #braces on same line, short lines, no cuddle

orig = open(fname, 'r').read()
gnu_content = open(gnu_name, 'r').read()
kr_content = open(kr_name, 'r').read()
lx_content = open(lx_name, 'r').read()
s1_content = open(s1_name, 'r').read()
s2_content = open(s2_name, 'r').read()
s3_content = open(s3_name, 'r').read()
s4_content = open(s4_name, 'r').read()
s5_content = open(s5_name, 'r').read()
s6_content = open(s6_name, 'r').read()

orig_size = os.path.getsize(fname)
gnu = float(lcs(orig, gnu_content))/max(orig_size, os.path.getsize(gnu_name))
kr = float(lcs(orig, kr_content))/max(orig_size, os.path.getsize(kr_name))
lx = float(lcs(orig, lx_content))/max(orig_size, os.path.getsize(lx_name))
s1 = float(lcs(orig, s1_content))/max(orig_size, os.path.getsize(s1_name))
s2 = float(lcs(orig, s2_content))/max(orig_size, os.path.getsize(s2_name))
s3 = float(lcs(orig, s3_content))/max(orig_size, os.path.getsize(s3_name))
s4 = float(lcs(orig, s4_content))/max(orig_size, os.path.getsize(s4_name))
s5 = float(lcs(orig, s5_content))/max(orig_size, os.path.getsize(s5_name))
s6 = float(lcs(orig, s6_content))/max(orig_size, os.path.getsize(s6_name))

norm = open(norm_name, 'r').read()
norm_size = os.path.getsize(norm_name)
gnu_norm = float(lcs(norm, gnu_content))/max(norm_size, os.path.getsize(gnu_name))
kr_norm = float(lcs(norm, kr_content))/max(norm_size, os.path.getsize(kr_name))
lx_norm = float(lcs(norm, lx_content))/max(norm_size, os.path.getsize(lx_name))
s1_norm = float(lcs(norm, s1_content))/max(norm_size, os.path.getsize(s1_name))
s2_norm = float(lcs(norm, s2_content))/max(norm_size, os.path.getsize(s2_name))
s3_norm = float(lcs(norm, s3_content))/max(norm_size, os.path.getsize(s3_name))
s4_norm = float(lcs(norm, s4_content))/max(norm_size, os.path.getsize(s4_name))
s5_norm = float(lcs(norm, s5_content))/max(norm_size, os.path.getsize(s5_name))
s6_norm = float(lcs(norm, s6_content))/max(norm_size, os.path.getsize(s6_name))

print("%f %f %f %f %f %f %f %f %f" % (gnu, kr, lx, s1, s2, s3, s4, s5, s6))
#print("%f %f %f %f %f %f %f %f" % (gnu_norm, kr_norm, lx_norm, s1_norm, s2_norm, s3_norm, s4_norm, s5_norm))

#c = open("file.c", 'r').read()
#d = open("file.d", 'r').read()
#e = open("file.e", 'r').read()
#print(os.path.getsize("file.c") - lcs(c, d))
#print(os.path.getsize("file.c") - lcs(c, e))

#print(str(gnu_lev) + " " + str(kr_lev) + " " + str(lx_lev) + " " + str(s1_lev) + " " + str(s2_lev) + " " + str(s3_lev) + " " + str(s4_lev) + " " + str(s5_lev) + str(s5_lev))

os.system("rm " + gnu_name + " " + kr_name + " " + lx_name + " " + s1_name + " " + s2_name + " " + s3_name + " " + s4_name + " " + s5_name + " " + s6_name + " " + norm_name + " *~")


