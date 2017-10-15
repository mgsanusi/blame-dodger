#include <stdio.h>
#include <string.h>
int isValid(char *in)
{
  int first_iteration;
  int i;
  for (i = 0; in[i] == '+'; ++i)
    ;

  return in[i] == '\0';
}

int main()
{
  int first_iteration;
  int t;
  int n;
  int tc = 1;
  int i;
  int j;
  int l;
  char S[110];
  char temp;
  scanf("%d", &t);
  while (t--)
  {
    scanf("%s", S);
    l = strlen(S);
    while ((l > (-1)) && (S[l - 1] == '+'))
      --l;

    n = 0;
    while (l > 0)
    {
      if (S[0] == '+')
      {
        for (i = 0; S[i] == '+'; ++i)
          ;

        for (j = 0; j <= i; ++j)
          S[j] = '-';

      }
      else
      {
        j = (l / 2) + (l & 1);
        for (i = 0; i < j; ++i)
        {
          temp = S[i];
          S[i] = S[(l - i) - 1] == '+' ? '-' : '+';
          S[(l - i) - 1] = temp == '+' ? '-' : '+';
        }

        while ((l > (-1)) && (S[l - 1] == '+'))
          --l;

      }

      ++n;
    }

    printf("Case #%d: %d\n", tc++, n);
  }

  return 0;
}


