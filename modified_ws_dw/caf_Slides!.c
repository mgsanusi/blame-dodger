#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
void do_test(int t)
{
  int first_iteration;
  int b;
  long long m;
  long long m_mask;
  int i;
  int j;
  scanf("%d %lld", &b, &m);
  printf("Case #%d: ", t + 1);
  if (m > (1LL << (b - 2)))
  {
    printf("IMPOSSIBLE\n");
    return;
  }

  printf("POSSIBLE\n");
  m_mask = ((m - 1) << 1) | 1;
  for (i = 0; i < b; i++)
  {
    for (j = 0; j <= i; j++)
      putchar('0');

    for (; j < (b - 1); j++)
      putchar('1');

    if (j < b)
      putchar(m_mask & (1LL << i) ? '1' : '0');

    putchar('\n');
  }

}

int main()
{
  int first_iteration;
  int t;
  int i;
  scanf("%d", &t);
  for (i = 0; i < t; i++)
    do_test(i);

  return 0;
}


