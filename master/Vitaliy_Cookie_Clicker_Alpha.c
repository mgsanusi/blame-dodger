#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

int ok[51][51][2501];
int p[51][51][2501];

void solve (void) {
  int n, m, x;
  assert (scanf ("%d %d %d", &n, &m, &x) == 3);
  x = n * m - x;
  if (n == 1) {
    printf ("\nc");
    int i;
    for (i = 0; i < x - 1; i++) { printf ("."); }
    for (i = 0; i < m - x; i++) { printf ("*"); }
    printf ("\n");
    return;
  }	
  if (m == 1) {
    printf ("\nc\n");
    int i;
    for (i = 0; i < x - 1; i++) { printf (".\n"); }
    for (i = 0; i < n - x; i++) { printf ("*\n"); }
    return;
  }
  if (x == 1) {
    printf ("\n");
    int i, j;
    for (i = 0; i < n; i++) {
      for (j = 0; j < m; j++)
        if (i == 0 && j == 0) { printf ("c"); }
	else { printf ("*");}
      printf ("\n");
    }
    return;
  }
  memset (ok, 0, sizeof (ok));
  int i, j, k, l;
  for (i = 2; i <= m; i++) {
    ok[2][i][2 * i] = 1;
    p[2][i][2 * i] = i;
    ok[1][i][i] = 1;
    p[1][i][i] = i;
  }
  for (i = 2; i < n; i++) {
    for (j = 2; j <= m; j++) {
      for (k = 0; k < x; k ++) {
      	if (ok[i][j][k]) {
	  for (l = 2; l <= j; l++) if (l + k <= x) {
	    ok[i + 1][l][l + k] = 1;
	    p[i + 1][l][l + k] = j;
	  }
	}
      }
    }
  }
  int ii = -1;
  int jj = -1;
  for (i = 2; i <= n; i++) {
    for (j = 2; j <= m; j++) {
      if (ok[i][j][x]) {
        ii = i;
	jj = j;
      }
    }
  }
  if (ii == -1) {
    printf ("\nImpossible\n");
    return;
  }
  printf ("\n");
  for (i = 0; i < n - ii; i++) {
    for (j = 0; j < m; j++) {
      printf ("*");
    }
    printf ("\n");
  }
  while (ii > 0) {
    assert (ok[ii][jj][x]);
    if (ii >= 2) {
      printf (".");
    } else {
      printf ("c");	
    }
    for (i = 0; i < jj - 1; i++) { printf (".");}
    for (i = 0; i < m - jj; i++) { printf ("*");}
    printf ("\n");
    int x1 = x - jj;
    jj = p[ii][jj][x];
    x = x1;
    ii --;
  }
  assert (!x);
}

int main () {
  int _;
  assert (scanf ("%d", &_) == 1);
  int __ = 0;
  for (__ = 0; __ < _ ; __ ++) {
    printf ("Case #%d:", __ + 1);
    solve ();
  }
}
