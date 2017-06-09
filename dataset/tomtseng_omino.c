#include <stdio.h>

int main() {
  int T, X, R, C, gabWin, i;
  FILE *fin = fopen("D-omino.in", "r");
  FILE *fout = fopen("D-omino.out", "w");
  fscanf(fin, "%d\n", &T);
  for (i = 1; i <= T; i++) {
    gabWin = 0;
    fscanf(fin, "%d %d %d\n", &X, &R, &C);
    if (X == 1) gabWin = 1;
    else if (X == 2 && !((R*C)%2)) gabWin = 1;
    else if (X == 3 && !((R*C)%3) && R>1 && C>1) gabWin = 1;
    else if (X == 4 && R>1 && C>1 && (R==4 || C==4)
             && (R*C) != 8) gabWin = 1;
    fprintf(fout, "Case #%d: ", i);
    if (gabWin) fprintf(fout, "GABRIEL\n");
    else fprintf(fout, "RICHARD\n");
  }
  fclose(fin);
  fclose(fout);
  return 0;
}
