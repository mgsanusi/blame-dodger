#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

int a[16], b[16];

void solve (void) {
  memset (a, 0, sizeof (a));
  memset (b, 0, sizeof (b));
  int x, y, i, j;
  scanf ("%d", &x);
  x --;
  for (i = 0; i < 4; i++)
    for (j = 0; j < 4; j++) {
      int t;
      scanf ("%d", &t);
      if (i == x) { a[t - 1] = 1; }
    }
  scanf ("%d", &y);
  y --;
  for (i = 0; i < 4; i++)
    for (j = 0; j < 4; j++) {
      int t;
      scanf ("%d", &t);
      if (i == y) { b[t - 1] = 1; }
    }
  x = -1;
  for (i = 0; i < 16; i ++) 
    if (a[i] && b[i]) {
      if (x != -1) {
        printf ("Bad magician!\n");
	return;
      }
      x = i;
    }
  if (x == -1) {
    printf ("Volunteer cheated!\n");
    return;
  }
  printf ("%d\n", x + 1);
}

int main () {
  int _;
  assert (scanf ("%d", &_) == 1);
  int __ = 0;
  for (__ = 0; __ < _ ; __ ++) {
    printf ("Case #%d: ", __ + 1);
    solve ();
  }
}
