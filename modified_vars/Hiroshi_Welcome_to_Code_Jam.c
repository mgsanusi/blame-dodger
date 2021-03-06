#include <stdio.h>
#include <stdlib.h>
#include <string.h>
static const char msg[] = "welcome to code jam";
static int front;
void setup(void)
{
  char buff[512];
  fgets(buff, 512, stdin);
  sscanf(buff, "%d", &front);
}

int checkR(int n, char *p)
{
  int x;
  if (n > 18)
    return 1;

  x = 0;
  while (*p)
  {
    if ((*(p++)) == msg[n])
    {
      x += checkR(n + 1, p);
      if (x >= 10000)
        x -= 10000;

    }

  }

  return x;
}

int clearOne(char *p)
{
  int x = 0;
  int n;
  int i;
  int length;
  int err;
  length = strlen(p);
  if (p[length] == '\n')
    p[length--] = 0;

  return checkR(0, p);
}

void clear(void)
{
  char buff[512];
  int i;
  int x;
  for (i = 0; i < front; i++)
  {
    fgets(buff, 512, stdin);
    x = clearOne(buff);
    printf("Case #%d: %04d\n", i + 1, x);
  }

}

int Main(void)
{
  setup();
  clear();
  return 0;
}


