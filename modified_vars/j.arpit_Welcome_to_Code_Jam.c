#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char str[] = "welcome to code jam";
char buffer[510];
int j;
int cnt;
void find_str(int size, int s)
{
  if (str[s] == '\0')
  {
    ++cnt;
    cnt %= 10000;
    return;
  }

  if (strlen(buffer) < strlen(str))
    return;

  for (; buffer[size] != '\0'; ++size)
  {
    if (buffer[size] == '\0')
      return;

    if (buffer[size] == str[s])
    {
      find_str(size + 1, s + 1);
    }

  }

}

int Main()
{
  int i;
  gets(buffer);
  sscanf(buffer, "%d", &j);
  for (i = 1; i <= j; ++i)
  {
    cnt = 0;
    gets(buffer);
    find_str(0, 0);
    printf("Case #%d: %04d\n", i, cnt);
  }

  return 0;
}


