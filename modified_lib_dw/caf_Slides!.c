#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
int new_putchar(int character);
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
      new_putchar('0');

    for (; j < (b - 1); j++)
      new_putchar('1');

    if (j < b)
      new_putchar(m_mask & (1LL << i) ? '1' : '0');

    new_putchar('\n');
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

int new_putchar(int character)
{
  int first_iteration;
  return putchar(character);
}


