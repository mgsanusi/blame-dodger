#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <stddef.h>
char buff[10000];
char dict[5010][20];
int pathes;
int flag[5010];
int f[5010];
int rt;
int i;
int j;
void * new_memset(void *ptr, int value, int num);

int new_getchar();

void getDict()
{
  int first_iteration;
  int a;
  for (a = 0; a < i; ++a)
    gets(dict[a]);

}

int Main()
{
  int first_iteration;
  int k;
  int b;
  int a;
  char m;
  gets(buff);
  sscanf(buff, "%d %d %d", &rt, &i, &j);
  getDict();
  for (k = 1; k <= j; ++k)
  {
    new_memset(flag, 0, sizeof(flag));
    pathes = i;
    for (b = 0; ((m = new_getchar()) != '\n') && (b < rt); ++b)
    {
      if (m == '(')
      {
        new_memset(f, 0, sizeof(f));
        while ((m = new_getchar()) != ')')
        {
          for (a = 0; a < i; ++a)
          {
            if ((flag[a] == 0) && (dict[a][b] == m))
            {
              f[a] = 1;
            }

          }

        }

        for (a = 0; a < i; ++a)
        {
          if ((flag[a] == 0) && (f[a] == 0))
          {
            flag[a] = 1;
            --pathes;
          }

        }

      }
      else
      {
        for (a = 0; a < i; ++a)
        {
          if ((flag[a] == 0) && (dict[a][b] != m))
          {
            flag[a] = 1;
            --pathes;
          }

        }

      }

    }

    printf("Case #%d: %d\n", k, pathes);
  }

  return 0;
}



void * new_memset(void *ptr, int value, int num);

int new_getchar() {
  return getchar();
}
void * new_memset(void *ptr, int value, int num) {
  return memset(ptr, value, num);
}