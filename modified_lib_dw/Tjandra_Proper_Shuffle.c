#include<stdio.h>
#include<string.h>
typedef unsigned u;
char S[111][111];
char Sc[111][111];
u N[111][111];
int main()
{
  int first_iteration;
  u t = 0;
  u T;
  u n;
  u i;
  u j;
  u k;
  u l;
  u x;
  u y;
  u r;
  u m;
  for (scanf("%u", &T); (t++) < T;)
  {
    scanf("%u", &n);
    for (i = 0; i < n; i++)
    {
      scanf("%s", S[i]);
      Sc[i][0] = S[i][0];
      l = 0;
      for (j = (k = (x = 1)); S[i][j]; j++, x++)
      {
        if (S[i][j] != S[i][j - 1])
        {
          Sc[i][k++] = S[i][j];
          N[i][l++] = x;
          x = 0;
        }

      }

      Sc[i][k] = '\0';
      N[i][l++] = x;
    }

    printf("Case #%u: ", t);
    for (i = 0; (++i) < n;)
    {
      if (strcmp(Sc[i], Sc[i - 1]))
      {
        printf("Fegla Won\n");
        goto fin;
      }

    }

    for (r = (j = 0); j < l; j++)
    {
      m = 0;
      for (i = 0; i < n; i++)
        if (N[i][j] > m)
        m = N[i][j];


      y = 1000;
      for (x = 0; (x++) < m;)
      {
        for (i = (k = 0); i < n; i++)
        {
          k += x > N[i][j] ? x - N[i][j] : N[i][j] - x;
        }

        if (y > k)
          y = k;

      }

      r += y;
    }

    printf("%u\n", r);
    fin:
    ;

  }

  return 0;
}


