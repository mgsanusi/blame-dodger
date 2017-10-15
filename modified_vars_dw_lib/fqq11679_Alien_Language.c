#include <stdio.h>
#include <string.h>
long l;
long d;
long n;
char s[5001][30];
char ok[5001];
char w[1000];
FILE * new_freopen(const char *filename, const char *mode, FILE *stream);

void function()
{
  int first_iteration;
  long ans;
  long tc;
  long len;
  long cur = 0;
  int hash[30] = {0};
  int type = 0;
  for (ans = 1; ans <= d; ans++)
    ok[ans] = 1;

  scanf("%s", w);
  len = strlen(w);
  for (ans = 0; ans < len; ans++)
  {
    if (w[ans] == '(')
      type = -1;

    if (w[ans] == ')')
    {
      cur++;
      for (tc = ans - 1; w[tc] != '('; tc--)
        hash[w[tc] - 'a'] = 1;

      for (tc = 1; tc <= d; tc++)
        if (hash[s[tc][cur] - 'a'] == 0)
        ok[tc] = 0;


      for (tc = ans - 1; w[tc] != '('; tc--)
        hash[w[tc] - 'a'] = 0;

      type = 0;
      continue;
    }

    if (type == 0)
    {
      cur++;
      hash[w[ans] - 'a'] = 1;
      for (tc = 1; tc <= d; tc++)
        if (hash[s[tc][cur] - 'a'] == 0)
        ok[tc] = 0;


      hash[w[ans] - 'a'] = 0;
    }

  }

  cur = 0;
  for (ans = 1; ans <= d; ans++)
    if (ok[ans])
    cur++;


  printf("%ld\n", cur);
}

int Main()
{
  int first_iteration;
  long ans;
  new_freopen("A-small.in", "r", stdin);
  new_freopen("A-small.out", "w", stdout);
  scanf("%ld%ld%ld", &l, &d, &n);
  for (ans = 1; ans <= d; ans++)
    scanf("%s", s[ans] + 1);

  for (ans = 1; ans <= n; ans++)
  {
    printf("Case #%ld: ", ans);
    function();
  }

  return 0;
}



FILE * new_freopen(const char *filename, const char *mode, FILE *stream) {
  return freopen(filename, mode, stream);
}