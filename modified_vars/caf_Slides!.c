#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
void do_test(int itest)
{
  int k;
  long long m;
  long long m_mask;
  int i;
  int n;
  scanf("%d %lld", &k, &m);
  printf("Case #%d: ", itest + 1);
  if (m > (1LL << (k - 2)))
  {
    printf("IMPOSSIBLE\n");
    return;
  }

  printf("POSSIBLE\n");
  m_mask = ((m - 1) << 1) | 1;
  for (i = 0; i < k; i++)
  {
    for (n = 0; n <= i; n++)
      putchar('0');

    for (; n < (k - 1); n++)
      putchar('1');

    if (n < k)
      putchar(m_mask & (1LL << i) ? '1' : '0');

    putchar('\n');
  }

}

int Main()
{
  int itest;
  int i;
  scanf("%d", &itest);
  for (i = 0; i < itest; i++)
    do_test(i);

  return 0;
}


