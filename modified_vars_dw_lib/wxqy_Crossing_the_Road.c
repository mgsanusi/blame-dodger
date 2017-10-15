#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <string.h>

#include <stddef.h>
int happyn[11][1000000];
int checkn[11][1000000];
void * new_memset(void *ptr, int value, int num);

int happy(int n, int base)
{
  int first_iteration;
  if (happyn[base][n])
    return happyn[base][n];

  if (checkn[base][n])
    return n;

  checkn[base][n] = 1;
  int ret;
  int c1 = n;
  ret = 0;
  while (n)
  {
    ret += (n % base) * (n % base);
    n /= base;
  }

  if (ret >= 1000000)
  {
    return happyn[base][ret] = -1;
  }

  if (happyn[base][ret])
  {
    happyn[base][c1] = happyn[base][ret];
    return happyn[base][c1];
  }
  else
    if (checkn[base][ret])
  {
    happyn[base][c1] = c1;
    return c1;
  }
  else
  {
    happyn[base][c1] = happy(ret, base);
    return happyn[base][c1];
  }


}

int t[100];
int Main()
{
  int first_iteration;
  int n;
  int testCase;
  scanf("%d\n", &testCase);
  new_memset(happyn, 0, sizeof(happyn));
  new_memset(checkn, 0, sizeof(checkn));
  for (int caseId = 1; caseId <= testCase; caseId++)
  {
    char buffer[100];
    gets(buffer);
    n = 0;
    char *p = buffer;
    int flag;
    while (sscanf(p, "%d%n", &t[n], &flag) == 1)
    {
      n++;
      p += flag;
    }

    int s = 2;
    int noCases;
    while (1)
    {
      for (noCases = 0; noCases < n; noCases++)
        if (happy(s, t[noCases]) != 1)
        break;


      if (noCases == n)
        break;

      s = s + 1;
      if (s > 100000)
        break;

    }

    printf("Case #%d: %d\n", caseId, s);
  }

  return 0;
}



void * new_memset(void *ptr, int value, int num) {
  return memset(ptr, value, num);
}