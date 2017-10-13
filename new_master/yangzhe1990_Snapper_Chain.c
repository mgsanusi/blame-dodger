#include <stdio.h>

int main() {
  int t, i;
  int n, k, m;

  scanf("%d", &t);
  for (i = 1; i <= t; ++i) {
    scanf("%d %d", &n, &k);
    printf("Case #%d: ", i);
    m = (1 << n) - 1;
    if ((k & m) == m)
      printf("ON\n");
    else
      printf("OFF\n");
  }
}
