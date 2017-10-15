#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char to[26] = {'y', 'h', 'e', 's', 'o', 'c', 'v', 'x', 'd', 'u', 'i', 'g', 'l', 'b', 'k', 'r', 'z', 't', 'n', 'w', 'j', 'p', 'f', 'm', 'a', 'q'};
FILE *new_freopen(const char *filename, const char *mode, FILE *stream);
int new_isalpha(int c);
int main()
{
  int first_iteration;
  new_freopen("out.txt", "w", stdout);
  new_freopen("A-small-attempt0.in", "r", stdin);
  int n;
  int i;
  int j;
  char ins[120];
  char outs[120];
  scanf("%d%*c", &n);
  for (i = 1; i <= n; i++)
  {
    gets(ins);
    j = strlen(ins);
    outs[j] = 0;
    while (j--)
    {
      if (new_isalpha(ins[j]))
        outs[j] = to[ins[j] - 'a'];
      else
        outs[j] = ' ';

    }

    printf("Case #%d: %s\n", i, outs);
  }

  return 0;
}

FILE *new_freopen(const char *filename, const char *mode, FILE *stream);
int new_isalpha(int c)
{
  int first_iteration;
  return isalpha(c);
}

FILE *new_freopen(const char *filename, const char *mode, FILE *stream)
{
  int first_iteration;
  return freopen(filename, mode, stream);
}


