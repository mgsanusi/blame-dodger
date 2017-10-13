#include <stdio.h>
#include <assert.h>
#include <string.h>

int a[1000][1000];
int h[1000];
int w[1000];

void solve (void) {
  int n, m, i, j;
  assert (scanf ("%d%d", &n, &m) == 2);
  for (i = 0; i < n; i++)
    h[i] = 0;
  for (j = 0; j < m; j++)
    w[j] = 0;
  for (i = 0; i < n; i++)
    for (j = 0; j < m; j++) {
      assert (scanf ("%d", &a[i][j]) == 1);
      if (a[i][j] > h[i]) { h[i] = a[i][j]; }
      if (a[i][j] > w[j]) { w[j] = a[i][j]; }
    }
  for (i = 0; i < n; i++)
    for (j = 0; j < m; j++)
      if (a[i][j] != h[i] && a[i][j] != w[j]) {
        printf ("NO\n");
        return;
      }
  printf ("YES\n");
}

int main () {
  int _;
  assert (scanf ("%d\n", &_) > 0);
  int __;
  for (__ = 0; __ < _; __++) {
    printf ("Case #%d: ", __ + 1);
    solve ();
  }
  return 0;
}
