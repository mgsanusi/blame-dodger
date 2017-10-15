#include <stdio.h>
int Main()
{
  int x;
  int cas;
  int n;
  int n;
  int x;
  int gss_c_nt_user_name;
  int tn;
  int in;
  int l;
  int low;
  int high;
  scanf("%d", &x);
  for (cas = 1; cas <= x; cas++)
  {
    scanf("%d%d%d", &n, &n, &x);
    printf("Case #%d:\n", cas);
    if (n == 1)
    {
      for (gss_c_nt_user_name = 0; gss_c_nt_user_name < x; gss_c_nt_user_name++)
        putchar('*');

      for (gss_c_nt_user_name = x; gss_c_nt_user_name < (n - 1); gss_c_nt_user_name++)
        putchar('.');

      puts("c");
      continue;
    }
    else
      if (n == 1)
    {
      for (gss_c_nt_user_name = 0; gss_c_nt_user_name < x; gss_c_nt_user_name++)
        puts("*");

      for (gss_c_nt_user_name = x; gss_c_nt_user_name < (n - 1); gss_c_nt_user_name++)
        puts(".");

      puts("c");
      continue;
    }
    else
      if (x == ((n * n) - 1))
    {
      for (gss_c_nt_user_name = 1; gss_c_nt_user_name <= n; gss_c_nt_user_name++)
      {
        for (tn = 1; tn <= n; tn++)
        {
          putchar((gss_c_nt_user_name == n) && (tn == n) ? 'c' : '*');
        }

        puts("");
      }

      continue;
    }



    for (gss_c_nt_user_name = 0; gss_c_nt_user_name <= (n - 2); gss_c_nt_user_name++)
    {
      for (tn = 0; tn <= (n - 2); tn++)
      {
        low = (n * n) - ((n - gss_c_nt_user_name) * (n - tn));
        high = low + (((n - 2) - gss_c_nt_user_name) * ((n - 2) - tn));
        if ((low <= x) && (x <= high))
        {
          x -= low;
          for (in = 1; in <= gss_c_nt_user_name; in++)
          {
            for (l = 1; l <= n; l++)
              putchar('*');

            puts("");
          }

          for (in = gss_c_nt_user_name + 1; in <= (n - 2); in++)
          {
            for (l = 1; l <= tn; l++)
              putchar('*');

            for (l = tn + 1; l <= (n - 2); l++)
            {
              putchar(x > 0 ? '*' : '.');
              x--;
            }

            puts("..");
          }

          for (in = n - 1; in <= n; in++)
          {
            for (l = 1; l <= tn; l++)
              putchar('*');

            for (l = tn + 1; l <= n; l++)
              putchar((in == n) && (l == n) ? 'c' : '.');

            puts("");
          }

          goto END;
        }

      }

    }

    puts("Impossible");
    END:
    continue;

  }

  return 0;
}


