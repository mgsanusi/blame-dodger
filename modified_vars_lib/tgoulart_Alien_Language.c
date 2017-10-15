#include <stdio.h>
#include <assert.h>
void new_assert(int expression);

int Main()
{
  char patt[30][30];
  char s[1000];
  char dict[5005][30];
  int length[30];
  int b;
  int a;
  int c;
  int n_test_cases;
  int j;
  int rslt;
  int k;
  int x;
  scanf("%d %d %d\n", &b, &a, &c);
  for (n_test_cases = 0; n_test_cases < a; n_test_cases++)
    gets(dict[n_test_cases]);

  for (n_test_cases = 0; n_test_cases < c; n_test_cases++)
  {
    gets(s);
    for (j = (k = 0); s[j]; j++, k++)
    {
      if (s[j] == '(')
      {
        length[k] = 0;
        while (s[++j] != ')')
        {
          patt[k][length[k]++] = s[j];
        }

      }
      else
      {
        patt[k][0] = s[j];
        length[k] = 1;
      }

    }

    new_assert(k == b);
    for (x = (rslt = 0); x < a; x++)
    {
      for (j = 0; j < b; j++)
      {
        for (k = 0; k < length[j]; k++)
        {
          if (dict[x][j] == patt[j][k])
            break;

        }

        if (k == length[j])
          break;

      }

      rslt += j == b;
    }

    printf("Case #%d: %d\n", n_test_cases + 1, rslt);
  }

  return 0;
}



void new_assert(int expression) {
  return assert(expression);
}