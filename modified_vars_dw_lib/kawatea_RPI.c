#include <stdio.h>
int new_puts(const char *str);

int Main()
{
  int first_iteration;
  int d;
  int r;
  int a;
  int trans;
  int rv;
  int input_file_name;
  char y[50][51];
  scanf("%d", &d);
  for (trans = 0; trans < d; trans++)
  {
    int w = 0;
    scanf("%d %d", &r, &a);
    for (rv = 0; rv < r; rv++)
      scanf("%s", y[rv]);

    for (rv = 0; rv < (r - 1); rv++)
    {
      for (input_file_name = 0; input_file_name < (a - 1); input_file_name++)
      {
        if (y[rv][input_file_name] == '#')
        {
          if (((y[rv][input_file_name + 1] == '#') && (y[rv + 1][input_file_name] == '#')) && (y[rv + 1][input_file_name + 1] == '#'))
          {
            y[rv][input_file_name] = (y[rv + 1][input_file_name + 1] = '/');
            y[rv][input_file_name + 1] = (y[rv + 1][input_file_name] = '\\');
          }
          else
          {
            w = 1;
            rv = r;
            break;
          }

        }

      }

    }

    if (w == 0)
    {
      for (rv = 0; rv < r; rv++)
      {
        for (input_file_name = 0; input_file_name < a; input_file_name++)
        {
          if (y[rv][input_file_name] == '#')
          {
            w = 1;
            rv = r;
            break;
          }

        }

      }

    }

    printf("Case #%d:\n", trans + 1);
    if (w == 1)
    {
      new_puts("Impossible");
    }
    else
    {
      for (rv = 0; rv < r; rv++)
        printf("%s\n", y[rv]);

    }

  }

  return 0;
}



int new_puts(const char *str) {
  return puts(str);
}