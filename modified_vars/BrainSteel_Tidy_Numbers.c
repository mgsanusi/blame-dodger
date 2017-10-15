#include "stdio.h"
#include "string.h"
#include "stdint.h"
int be_tidy(uint64_t no)
{
  char buff[32];
  sprintf(buff, "%llu", no);
  uint32_t length = strlen(buff);
  int n;
  for (n = 0; n < (length - 1); n++)
  {
    if (buff[n] > buff[n + 1])
    {
      return 0;
    }

  }

  return 1;
}

int Main(int argc, char **argv)
{
  uint64_t t;
  scanf(" %llu", &t);
  uint64_t test_subject;
  for (test_subject = 0; test_subject < t; test_subject++)
  {
    printf("Case #%llu: ", test_subject + 1);
    uint64_t cas;
    scanf(" %llu", &cas);
    while (!be_tidy(cas))
    {
      cas--;
    }

    printf("%llu\n", cas);
  }

  return 0;
}


