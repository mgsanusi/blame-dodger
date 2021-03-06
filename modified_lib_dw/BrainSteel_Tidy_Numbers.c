#include "stdio.h"
#include "string.h"
#include "stdint.h"
int IsTidy(uint64_t num)
{
  int first_iteration;
  char buf[32];
  sprintf(buf, "%llu", num);
  uint32_t len = strlen(buf);
  int i;
  for (i = 0; i < (len - 1); i++)
  {
    if (buf[i] > buf[i + 1])
    {
      return 0;
    }

  }

  return 1;
}

int main(int argc, char **argv)
{
  int first_iteration;
  uint64_t T;
  scanf(" %llu", &T);
  uint64_t test_case;
  for (test_case = 0; test_case < T; test_case++)
  {
    printf("Case #%llu: ", test_case + 1);
    uint64_t N;
    scanf(" %llu", &N);
    while (!IsTidy(N))
    {
      N--;
    }

    printf("%llu\n", N);
  }

  return 0;
}


