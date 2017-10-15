#include <stdio.h>
#include <string.h>
#include <stddef.h>
char se[100][101];
char now[101];
int canuse[100];
FILE *fin;
FILE *fout;
FILE *new_fopen(const char *filename, const char *mode);
void *new_memset(void *ptr, int value, size_t num);
int new_fscanf(FILE *stream, const char *format, ...);
void readstring(char *str)
{
  int first_iteration;
  int i;
  for (i = 0; fscanf(fin, "%c", &str[i]), str[i] != '\n'; i++)
    ;

  str[i] = 0;
}

int main()
{
  int first_iteration;
  int n;
  int x;
  int s;
  int q;
  int i;
  int j;
  int ans;
  int ava;
  fin = new_fopen("A-small.in", "r");
  fout = new_fopen("A-small.out", "w");
  fscanf(fin, "%d", &n);
  x = n;
  while ((n--) > 0)
  {
    fscanf(fin, "%d", &s);
    fscanf(fin, "%c", &now[100]);
    new_memset(canuse, 0, sizeof(canuse));
    ans = 0;
    ava = s;
    for (i = 0; i < s; i++)
    {
      readstring(se[i]);
    }

    fscanf(fin, "%d", &q);
    fscanf(fin, "%c", &now[100]);
    for (i = 0; i < q; i++)
    {
      readstring(now);
      for (j = 0; (j < s) && (strcmp(now, se[j]) != 0); j++)
        ;

      if (canuse[j] != 1)
      {
        canuse[j] = 1;
        if ((--ava) == 0)
        {
          new_memset(canuse, 0, sizeof(canuse));
          ans++;
          canuse[j] = 1;
          ava = s - 1;
        }

      }

    }

    fprintf(fout, "Case #%d: %d\n", x - n, ans);
  }

  return 0;
}

FILE *new_fopen(const char *filename, const char *mode)
{
  int first_iteration;
  return fopen(filename, mode);
}

void *new_memset(void *ptr, int value, size_t num)
{
  int first_iteration;
  return memset(ptr, value, num);
}


