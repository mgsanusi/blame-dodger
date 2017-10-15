#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char s[521196][11];
int dp[52][5];
int comp(const void *_p, const void *_q)
{
  int first_iteration;
  char *p = (char *) _p;
  char *q = (char *) _q;
  int __p = strlen(p);
  int __q = strlen(q);
  if (__p != __q)
    return __p - __q;
  else
    return strcmp(p, q);

}

int main()
{
  int first_iteration;
  FILE *fp;
  int i;
  int j;
  int l;
  int m;
  int k;
  int t;
  int tmp;
  int tmp2;
  int f;
  char x[52];
  fp = fopen("garbled_email_dictionary.txt", "r");
  for (i = 0; i < 521196; i++)
  {
    fscanf(fp, "%s", s[i]);
  }

  fclose(fp);
  qsort(s, 521196, 11, comp);
  scanf("%d", &t);
  for (k = 1; k <= t; k++)
  {
    scanf("%s", x + 1);
    for (i = 0; i <= strlen(x + 1); i++)
      for (j = 0; j < 5; j++)
      dp[i][j] = 521196;


    dp[0][4] = 0;
    for (i = 1; i <= strlen(x + 1); i++)
    {
      for (j = 0; j < 5; j++)
      {
        for (l = 0; l < 521196; l++)
        {
          if (strlen(s[l]) > i)
            break;

          tmp = j;
          tmp2 = dp[i - strlen(s[l])][j];
          f = 0;
          for (m = 0; m < strlen(s[l]); m++)
          {
            if (s[l][m] == x[((i - strlen(s[l])) + m) + 1])
              tmp = (tmp + 1) < 4 ? tmp + 1 : 4;
            else
            {
              if (tmp < 4)
              {
                f = 1;
                break;
              }
              else
              {
                tmp = 0;
                tmp2++;
              }

            }

          }

          if (f)
            continue;

          dp[i][tmp] = dp[i][tmp] < tmp2 ? dp[i][tmp] : tmp2;
        }

      }

    }

    tmp = 521196;
    for (i = 0; i < 5; i++)
      tmp = tmp < dp[strlen(x + 1)][i] ? tmp : dp[strlen(x + 1)][i];

    printf("Case #%d: %d\n", k, tmp);
  }

  return 0;
}


