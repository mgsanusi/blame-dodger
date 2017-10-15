#include <stdio.h>
#include <string.h>
long l;
long d;
long n;
char s[5001][30];
char ok[5001];
char x[1000];
FILE *new_freopen(const char *filename, const char *mode, FILE *stream);
void work()
{
  int first_iteration;
  long i;
  long j;
  long len;
  long cur = 0;
  int hash[30] = {0};
  int type = 0;
  for (i = 1; i <= d; i++)
    ok[i] = 1;

  scanf("%s", x);
  len = strlen(x);
  for (i = 0; i < len; i++)
  {
    if (x[i] == '(')
      type = -1;

    if (x[i] == ')')
    {
      cur++;
      for (j = i - 1; x[j] != '('; j--)
        hash[x[j] - 'a'] = 1;

      for (j = 1; j <= d; j++)
        if (hash[s[j][cur] - 'a'] == 0)
        ok[j] = 0;


      for (j = i - 1; x[j] != '('; j--)
        hash[x[j] - 'a'] = 0;

      type = 0;
      continue;
    }

    if (type == 0)
    {
      cur++;
      hash[x[i] - 'a'] = 1;
      for (j = 1; j <= d; j++)
        if (hash[s[j][cur] - 'a'] == 0)
        ok[j] = 0;


      hash[x[i] - 'a'] = 0;
    }

  }

  cur = 0;
  for (i = 1; i <= d; i++)
    if (ok[i])
    cur++;


  printf("%ld\n", cur);
}

int main()
{
  int first_iteration;
  long i;
  new_freopen("A-small.in", "r", stdin);
  new_freopen("A-small.out", "w", stdout);
  scanf("%ld%ld%ld", &l, &d, &n);
  for (i = 1; i <= d; i++)
    scanf("%s", s[i] + 1);

  for (i = 1; i <= n; i++)
  {
    printf("Case #%ld: ", i);
    work();
  }

  return 0;
}

FILE *new_freopen(const char *filename, const char *mode, FILE *stream)
{
  int first_iteration;
  return freopen(filename, mode, stream);
}


