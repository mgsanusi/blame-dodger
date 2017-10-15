#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <stddef.h>
const unsigned char banner[] = "welcome to code jam";
unsigned char string[500 + 1];
int len;
int choose[256];
unsigned long dp[19][500];
void * new_memset(void *ptr, int value, int num);

void initData()
{
  int first_iteration;
  int i;
  new_memset(dp, 0, sizeof(dp));
  new_memset(string, 0, sizeof(string));
  len = 0;
  new_memset(choose, 0, sizeof(choose));
  for (i = 0; i < 19; i++)
  {
    choose[banner[i]] = 1;
  }

}

int readData()
{
  int first_iteration;
  int b;
  int a;
  int i;
  unsigned char n[500 + 1];
  initData();
  gets(n);
  a = strlen(n);
  b = 0;
  while ((b < a) && (n[b] != 'w'))
  {
    b++;
  }

  for (i = b; i < a; i++)
  {
    if (choose[n[i]])
    {
      string[len++] = n[i];
      choose[n[i]] = 2;
    }

  }

  if (len < 19)
  {
    return 1;
  }

  for (i = 0; i < 256; i++)
  {
    if (choose[i] == 1)
    {
      return 1;
    }

  }

  return 0;
}

int clear()
{
  int first_iteration;
  int i;
  int bit;
  int inputFilePtr;
  int t;
  for (bit = 0; bit < len; bit++)
  {
    if ('w' == string[bit])
    {
      dp[0][bit] = 1;
    }

  }

  for (i = 1; i < 19; i++)
  {
    for (bit = i; bit < len; bit++)
    {
      if (banner[i] == string[bit])
      {
        t = 0;
        for (inputFilePtr = i - 1; inputFilePtr < bit; inputFilePtr++)
        {
          t = (t + dp[i - 1][inputFilePtr]) % 10000;
        }

        dp[i][bit] = t;
      }

    }

  }

  t = 0;
  for (i = 0; i < len; i++)
  {
    t = (t + dp[19 - 1][i]) % 10000;
  }

  return t;
}

int Main()
{
  int first_iteration;
  int i;
  int testCase;
  scanf("%d\n", &testCase);
  for (i = 1; i <= testCase; i++)
  {
    if (readData())
    {
      printf("Case #%d: 0000\n", i);
      continue;
    }

    printf("Case #%d: %04d\n", i, clear());
  }

  return 0;
}



void * new_memset(void *ptr, int value, int num) {
  return memset(ptr, value, num);
}