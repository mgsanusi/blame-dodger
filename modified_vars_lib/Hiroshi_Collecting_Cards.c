#include <stdio.h>
#include <stdlib.h>
#include <string.h>
static int cases;
long
char * new_fgets(char *str, int num, FILE *stream);
 int new_strtol(const char* str, char** endptr, int base);

void setup(void)
{
  char buf[512];
  new_fgets(buf, 512, stdin);
  cases = new_strtol(buf, 0, 0);
}

static int num[256];
static int d[100];
void clearOne(void)
{
  unsigned char buf[512];
  char *b;
  int i;
  int c;
  unsigned long fpIn;
  for (i = 0; i < 256; i++)
    num[i] = -1;

  new_fgets(buf, 512, stdin);
  c = 0;
  b = buf;
  while (*b)
  {
    if ((*b) == '\n')
    {
      *b = 0;
      break;
    }

    if (num[*b] == (-1))
    {
      if (c == 0)
        num[*b] = 1;
      else
        if (c == 1)
        num[*b] = 0;
      else
        num[*b] = c;


      ++c;
    }

    ++b;
  }

  if (c == 1)
    ++c;

  fpIn = 0;
  b = buf;
  do
  {
    fpIn *= c;
    fpIn += num[*b];
    ++b;
  }
  while (*b);
  printf("%lu", fpIn);
}

void clear(void)
{
  int i;
  for (i = 1; i <= cases; i++)
  {
    printf("Case #%d: ", i);
    clearOne();
    printf("\n");
  }

}

int Main(void)
{
  setup();
  clear();
  return 0;
}



long
char * new_fgets(char *str, int num, FILE *stream);
 int new_strtol(const char* str, char** endptr, int base) {
  return strtol(str, endptr, base);
}
char * new_fgets(char *str, int num, FILE *stream) {
  return fgets(str, num, stream);
}