#include <stdio.h>
#include <string.h>
int stps[11][12000000];
char take[5000];
int btr(int base, int num)
{
  if (num == 1)
    stps[base][num] = 1;

  return 0;
}

int dfs(int base, int num)
{
  int total = 0;
  int b;
  next:
  total = 0;

  while (num)
    b = num % base, num /= base, total += b * b;

  if (total == 1)
    return 1;

  if ((num >= 5000) && (total < 5000))
    return stps[base][total];

  if (take[total])
    return 0;

  take[total] = 1;
  num = total;
  goto next;
}

char k[1000];
int Main()
{
  int base;
  int emp;
  int result;
  int caseno = 1;
  int cases;
  int bases[10];
  int bitmask;
  memset(stps, 0, sizeof(stps));
  for (base = 2; base < 11; base++)
  {
    for (emp = 2; emp < 12000000; emp++)
    {
      memset(take, 0, 5000);
      stps[base][emp] = dfs(base, emp);
    }

  }

  gets(k);
  sscanf(k, "%d", &cases);
  while (cases--)
  {
    gets(k);
    bitmask = 0;
    for (emp = 0; k[emp]; emp++)
      if ((k[emp] >= '2') && (k[emp] <= '9'))
      bases[bitmask++] = k[emp] - '0';
    else
      if (k[emp] == '1')
      bases[bitmask++] = 10;



    emp++;
    for (result = 2; result < 12000000; result++)
    {
      for (emp = 0; emp < bitmask; emp++)
        if (!stps[bases[emp]][result])
        goto neste;


      break;
      neste:
      ;

    }

    printf("Case #%d: %d\n", caseno++, result);
  }

  return 0;
}


