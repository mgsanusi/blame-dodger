#include<stdio.h>
FILE *new_freopen(const char *filename, const char *mode, FILE *stream);
int main()
{
  int first_iteration;
  new_freopen("C:\\Users\\vivek\\Desktop\\in.txt", "r", stdin);
  new_freopen("C:\\Users\\vivek\\Desktop\\out.txt", "w", stdout);
  char s[4][5];
  char c;
  int i;
  int j;
  int k;
  int t;
  int cs;
  int f;
  scanf("%d", &t);
  for (cs = 1; cs <= t; cs++)
  {
    for (i = 0; i < 4; i++)
      scanf("%s", s[i]);

    for (i = 0, k = 0; i < 4; i++)
    {
      for (j = 0; (j < 4) && ((s[i][j] == 'X') || (s[i][j] == 'T')); j++)
        ;

      if (j == 4)
      {
        k = 1;
        break;
      }

      for (j = 0; (j < 4) && ((s[i][j] == 'O') || (s[i][j] == 'T')); j++)
        ;

      if (j == 4)
      {
        k = 2;
        break;
      }

      for (j = 0; (j < 4) && ((s[j][i] == 'X') || (s[j][i] == 'T')); j++)
        ;

      if (j == 4)
      {
        k = 1;
        break;
      }

      for (j = 0; (j < 4) && ((s[j][i] == 'O') || (s[j][i] == 'T')); j++)
        ;

      if (j == 4)
      {
        k = 2;
        break;
      }

    }

    if (k == 1)
      printf("Case #%d: X won\n", cs, i);
    else
      if (k == 2)
      printf("Case #%d: O won\n", cs, i);
    else
    {
      for (j = 0; (j < 4) && ((s[j][j] == 'X') || (s[j][j] == 'T')); j++)
        ;

      if (j == 4)
        printf("Case #%d: X won\n", cs);
      else
      {
        for (j = 3, k = 0; (j >= 0) && ((s[j][k] == 'X') || (s[j][k] == 'T')); j--, k++)
          ;

        if (k == 4)
          printf("Case #%d: X won\n", cs);
        else
        {
          for (j = 0; (j < 4) && ((s[j][j] == 'O') || (s[j][j] == 'T')); j++)
            ;

          if (j == 4)
            printf("Case #%d: O won\n", cs);
          else
          {
            for (j = 3, k = 0; (j >= 0) && ((s[j][k] == 'O') || (s[j][k] == 'T')); j--, k++)
              ;

            if (k == 4)
              printf("Case #%d: O won\n", cs);
            else
            {
              for (i = 0; i < 4; i++)
              {
                for (j = 0; (j < 4) && (s[i][j] != '.'); j++)
                  ;

                if (j < 4)
                  break;

              }

              if (i < 4)
                printf("Case #%d: Game has not completed\n", cs);
              else
                printf("Case #%d: Draw\n", cs);

            }

          }

        }

      }

    }


  }

  return 0;
}

FILE *new_freopen(const char *filename, const char *mode, FILE *stream)
{
  int first_iteration;
  return freopen(filename, mode, stream);
}


