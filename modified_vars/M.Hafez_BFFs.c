#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int my_cmp(const void *k, const void *b)
{
  const char *ia = (const char *) k;
  const char *y2 = (const char *) b;
  return (*ia) > (*y2);
}

int Main()
{
  int fd;
  int tc = 1;
  char result[2010];
  char output[2010];
  int dat[300];
  int i;
  int len;
  scanf("%d", &fd);
  while (fd--)
  {
    memset(dat, 0, 300 * (sizeof(int)));
    scanf("%s", result);
    len = strlen(result);
    for (i = 0; i < len; ++i)
    {
      ++dat[result[i]];
    }

    i = 0;
    while (dat['Z'])
    {
      output[i] = '0';
      --dat['Z'];
      --dat['E'];
      --dat['R'];
      --dat['O'];
      ++i;
    }

    while (dat['W'])
    {
      output[i] = '2';
      --dat['T'];
      --dat['W'];
      --dat['O'];
      ++i;
    }

    while (dat['U'])
    {
      output[i] = '4';
      --dat['F'];
      --dat['O'];
      --dat['U'];
      --dat['R'];
      ++i;
    }

    while (dat['F'])
    {
      output[i] = '5';
      --dat['F'];
      --dat['I'];
      --dat['V'];
      --dat['E'];
      ++i;
    }

    while (dat['X'])
    {
      output[i] = '6';
      --dat['S'];
      --dat['I'];
      --dat['X'];
      ++i;
    }

    while (dat['S'])
    {
      output[i] = '7';
      --dat['S'];
      --dat['E'];
      --dat['V'];
      --dat['E'];
      --dat['N'];
      ++i;
    }

    while (dat['G'])
    {
      output[i] = '8';
      --dat['E'];
      --dat['I'];
      --dat['G'];
      --dat['H'];
      --dat['T'];
      ++i;
    }

    while (dat['O'])
    {
      output[i] = '1';
      --dat['O'];
      --dat['N'];
      --dat['E'];
      ++i;
    }

    while (dat['N'])
    {
      output[i] = '9';
      --dat['N'];
      --dat['I'];
      --dat['N'];
      --dat['E'];
      ++i;
    }

    while (dat['H'])
    {
      output[i] = '3';
      --dat['T'];
      --dat['H'];
      --dat['R'];
      --dat['E'];
      --dat['E'];
      ++i;
    }

    output[i] = '\0';
    qsort(output, i, sizeof(char), my_cmp);
    printf("Case #%d: %s\n", tc++, output);
  }

  return 0;
}


