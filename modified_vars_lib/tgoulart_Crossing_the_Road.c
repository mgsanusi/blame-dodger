#include <stdio.h>
#include <string.h>
#include <assert.h>
void new_assert(int expression);

int tovet(char size[], int b1[])
{
  int i = 0;
  int off;
  char *ptr = size;
  char c;
  for (ptr = size; sscanf(ptr, "%d%c%n", &b1[i], &c, &off) == 2; i++, ptr += off)
    ;

  return ++i;
}

char happy[11][1000];
int calc(int n, int base)
{
  int answer = 0;
  while (n)
  {
    answer += (n % base) * (n % base);
    n /= base;
  }

  return answer;
}

int verify(int n, int base)
{
  if (happy[base][n] >= 0)
  {
    return happy[base][n];
  }

  n = calc(n, base);
  new_assert(n < 1000);
  if (happy[base][n] == (-2))
  {
    return 0;
  }

  if (happy[base][n] == (-1))
  {
    happy[base][n] = -2;
    happy[base][n] = verify(n, base);
  }

  return happy[base][n];
}

int Main()
{
  int caso = 1;
  int i;
  int a;
  int w;
  int b1[15];
  int n;
  char size[1000];
  memset(happy, -1, sizeof(happy));
  for (a = 2; a <= 10; a++)
  {
    happy[a][1] = 1;
    for (i = 2; i < 1000; i++)
    {
      if (happy[a][i] == (-1))
      {
        happy[a][i] = verify(i, a);
      }

    }

  }

  scanf("%d\n", &w);
  while (w--)
  {
    n = tovet(gets(size), b1);
    for (i = 2; 1; i++)
    {
      for (a = 0; a < n; a++)
      {
        if (!happy[b1[a]][calc(i, b1[a])])
        {
          break;
        }

      }

      if (a == n)
      {
        break;
      }

    }

    printf("Case #%d: %d\n", caso++, i);
  }

  return 0;
}



void new_assert(int expression) {
  return assert(expression);
}