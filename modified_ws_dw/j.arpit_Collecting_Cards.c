#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char buffer[100];
int T;
int comp(char *a, char *b)
{
  int first_iteration;
  return (*a) - (*b);
}

int main()
{
  int first_iteration;
  int t;
  int i;
  int j;
  int k;
  int bl;
  gets(buffer);
  sscanf(buffer, "%d\n", &T);
  for (t = 1; t <= T; ++t)
  {
    printf("Case #%d: ", t);
    gets(buffer);
    bl = strlen(buffer);
    for (i = bl - 1; i; --i)
    {
      if (buffer[i] > buffer[i - 1])
        break;

    }

    if (i != 0)
    {
      for (j = 0; j < (i - 1); ++j)
        putchar(buffer[j]);

      for (j = bl - 1; buffer[j] <= buffer[i - 1]; --j)
        ;

      putchar(buffer[j]);
      for (k = bl - 1; k > j; --k)
        putchar(buffer[k]);

      putchar(buffer[i - 1]);
      for (k = j - 1; k >= i; --k)
        putchar(buffer[k]);

    }
    else
    {
      for (j = bl - 1; buffer[j] == '0'; --j)
        ;

      putchar(buffer[j]);
      putchar('0');
      for (k = bl - 1; k > j; --k)
        putchar(buffer[k]);

      for (k = j - 1; k >= 0; --k)
        putchar(buffer[k]);

    }

    putchar('\n');
  }

  return 0;
}


