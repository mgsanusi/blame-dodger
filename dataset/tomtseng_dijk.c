#include <stdio.h>
#include <string.h>

char combiVal[10001][10001];
char combiNeg[10001][10001];
char str[10001];

char vals[4][4] = {{0, 1, 2, 3},
                  {1, 0, 3, 2},
                  {2, 3, 0, 1},
                  {3, 2, 1, 0}};
char neg[4][4] = {{0,0,0,0},
                 {0,1,0,1},
                 {0,1,1,0},
                 {0,0,1,1}};

// n is len of string
void calcCombi(int n) {
  int i, j;
  for (i = 0; i < n; i++) {
    combiVal[i][i] = str[i];
  }
  for (i = 0; i < n; i++) {
    for (j = i+1; j < n; j++) {
      combiVal[i][j] = vals[combiVal[i][j-1]][str[j]];
      combiNeg[i][j] = combiNeg[i][j-1] ^ neg[combiVal[i][j-1]][str[j]];
    }
  }
}

int main() {
  int T, L, X, possible, i, a, b;
  char c;
  FILE *fin = fopen("C-djik.in", "r");
  FILE *fout = fopen("C-djik.out", "w");
  fscanf(fin, "%d\n", &T);
  for (i = 1; i <= T; i++) {
    fscanf(fin, "%d %d\n", &L, &X);
    possible = 0;
    for (a = 0; a < L; a++) {
      fscanf(fin, "%c", &c);
      switch (c) {
        case 'i': str[a] = 1; break;
        case 'j': str[a] = 2; break;
        case 'k': str[a] = 3; break;
      }
    }
    fscanf(fin, "\n");

    for (b = 1; b < X; b++) {
      strncpy(&str[L*b],str,sizeof(char[L]));
    }

    calcCombi(L*X);

    for (a = 0; a < L*X-2 && !possible ; a++) {
      for (b = a+1; b < L*X-1; b++) {
        if ((combiVal[0][a] == 1) && (!combiNeg[0][a]) &&
            (combiVal[a+1][b] == 2) && (!combiNeg[a+1][b]) &&
            (combiVal[b+1][L*X-1] == 3) && (!combiNeg[b+1][L*X-1])) {
          possible = 1;
          break;
        }
      }
    }
    fprintf(fout, "Case #%d: ", i);
    if (possible) fprintf(fout, "YES\n");
    else fprintf(fout, "NO\n");
  }
  fclose(fin);
  fclose(fout);
  return 0;
}
