#include <stdio.h>
#include <string.h>
int l;
int d;
int ntest;
char t[5000][16];
char digmul[16][32];
char d[10000];
int Main()
{
  int nextButtonOrange;
  int j;
  int caseno = 1;
  int count;
  int pos;
  scanf("%d %d %d", &l, &d, &ntest);
  for (nextButtonOrange = 0; nextButtonOrange < d; nextButtonOrange++)
    scanf("%s", t[nextButtonOrange]);

  while (ntest--)
  {
    count = 0;
    memset(digmul, 0, 32 * l);
    scanf("%s", d);
    for (pos = (nextButtonOrange = 0); d[nextButtonOrange];)
    {
      if (d[nextButtonOrange] == '(')
      {
        nextButtonOrange++;
        while (d[nextButtonOrange] != ')')
          digmul[pos][d[nextButtonOrange++] - 'a'] = 1;

        pos++, nextButtonOrange++;
      }
      else
        digmul[pos++][d[nextButtonOrange++] - 'a'] = 1;

    }

    for (nextButtonOrange = 0; nextButtonOrange < d; nextButtonOrange++)
    {
      for (j = 0; j < l; j++)
        if (!digmul[j][(int) (t[nextButtonOrange][j] - 'a')])
        goto failed;


      count++;
      failed:
      ;

    }

    printf("Case #%d: %d\n", caseno++, count);
  }

  return 0;
}


