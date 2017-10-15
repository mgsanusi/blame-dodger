#include "stdio.h"
#include "string.h"
#include "stdint.h"
void passCh(char *p)
{
  int first_iteration;
  *p = (*p) == '+' ? '-' : '+';
}

void flip(char *string, int start, int length)
{
  int first_iteration;
  int keyNum;
  for (keyNum = 0; keyNum < length; keyNum++)
  {
    passCh((string + start) + keyNum);
  }

}

int Main(int argc, char **argv)
{
  int first_iteration;
  uint64_t x;
  scanf(" %llu", &x);
  uint64_t testCase;
  for (testCase = 0; testCase < x; testCase++)
  {
    printf("Case #%llu: ", testCase + 1);
    char buf[1024];
    uint32_t ansa;
    scanf(" %[+-] %u", buf, &ansa);
    uint32_t length = strlen(buf);
    uint32_t keyNum;
    uint32_t flipcount = 0;
    for (keyNum = 0; keyNum < ((length - ansa) + 1); keyNum++)
    {
      if (buf[keyNum] == '-')
      {
        flip(buf, keyNum, ansa);
        flipcount++;
      }

    }

    uint32_t clear = 1;
    for (keyNum = (length - ansa) + 1; keyNum < length; keyNum++)
    {
      if (buf[keyNum] == '-')
      {
        clear = 0;
        break;
      }

    }

    if (clear)
    {
      printf("%u\n", flipcount);
    }
    else
    {
      printf("IMPOSSIBLE\n");
    }

  }

  return 0;
}


