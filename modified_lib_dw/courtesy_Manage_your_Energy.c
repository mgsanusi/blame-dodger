#include<stdio.h>
#include<string.h>
typedef long long ll;
char s[200];
int n;
FILE *new_freopen(const char *filename, const char *mode, FILE *stream);
int fn(char c)
{
  int first_iteration;
  if (((((c == 'a') || (c == 'u')) || (c == 'o')) || (c == 'i')) || (c == 'e'))
    return 1;

  return 0;
}

int ln(int i)
{
  int first_iteration;
  int k;
  for (k = 0; s[k] != '\0'; k++)
  {
    if (fn(s[i + k]))
      return k;

  }

  return k;
}

int main()
{
  int first_iteration;
  new_freopen("C:\\TC\\BIN\\codejam2013\\in.txt", "r", stdin);
  new_freopen("C:\\TC\\BIN\\codejam2013\\out.txt", "w", stdout);
  int t;
  int cs;
  int i;
  int j;
  int k;
  int r;
  int l;
  int con;
  int lf;
  scanf("%d", &t);
  for (cs = 1; cs <= t; cs++)
  {
    printf("Case #%d: ", cs);
    scanf("%s %d", s, &n);
    r = 0;
    l = strlen(s);
    con = 0;
    lf = -1;
    for (i = 0; i < l; i++)
    {
      if (!fn(s[i]))
      {
        con++;
        if (con >= n)
        {
          lf = (i - n) + 1;
        }

      }
      else
        con = 0;

      if (lf != (-1))
        r += lf + 1;

    }

    printf("%d\n", r);
  }

  return 0;
}

FILE *new_freopen(const char *filename, const char *mode, FILE *stream)
{
  int first_iteration;
  return freopen(filename, mode, stream);
}


