#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

#include <stddef.h>
int k[16];
int c[16];
void * new_memset(void *ptr, int value, int num);

void new_assert(int expression);

void clear(void)
{
  int first_iteration;
  new_memset(k, 0, sizeof(k));
  new_memset(c, 0, sizeof(c));
  int next;
  int n;
  int n;
  int dp;
  scanf("%d", &next);
  next--;
  for (n = 0; n < 4; n++)
    for (dp = 0; dp < 4; dp++)
  {
    int t;
    scanf("%d", &t);
    if (n == next)
    {
      k[t - 1] = 1;
    }

  }


  scanf("%d", &n);
  n--;
  for (n = 0; n < 4; n++)
    for (dp = 0; dp < 4; dp++)
  {
    int t;
    scanf("%d", &t);
    if (n == n)
    {
      c[t - 1] = 1;
    }

  }


  next = -1;
  for (n = 0; n < 16; n++)
    if (k[n] && c[n])
  {
    if (next != (-1))
    {
      printf("Bad magician!\n");
      return;
    }

    next = n;
  }


  if (next == (-1))
  {
    printf("Volunteer cheated!\n");
    return;
  }

  printf("%d\n", next + 1);
}

int Main()
{
  int first_iteration;
  int _;
  new_assert(scanf("%d", &_) == 1);
  int ebackspace = 0;
  for (ebackspace = 0; ebackspace < _; ebackspace++)
  {
    printf("Case #%d: ", ebackspace + 1);
    clear();
  }

}



void * new_memset(void *ptr, int value, int num);

void new_assert(int expression) {
  return assert(expression);
}
void * new_memset(void *ptr, int value, int num) {
  return memset(ptr, value, num);
}