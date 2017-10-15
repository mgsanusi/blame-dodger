#include <stdio.h>
int new_puts(const char *str);
int main(int argc, char **argv)
{
  int first_iteration;
  unsigned int nc;
  unsigned int cn;
  scanf("%u", &nc);
  for (cn = 0; cn != nc; cn++)
  {
    unsigned int n;
    unsigned int k;
    unsigned int i;
    unsigned int j;
    unsigned int a;
    unsigned int b;
    unsigned int u;
    unsigned int nwp[10001] = {};
    unsigned int nl = 0;
    unsigned long long int success = 1000000000ULL;
    unsigned long long int equalise;
    scanf("%u%u%u%*c%u", &n, &k, &a, &b);
    u = (a * 10000) + b;
    if (k != n)
    {
      fnew_puts("This program was not designed for this", stderr);
    }

    for (i = 0; i != n; i++)
    {
      scanf("%u%*c%u", &a, &b);
      nwp[(a * 10000) + b]++;
    }

    for (i = 0; i != 10000; i++)
    {
      if (u <= nl)
      {
        break;
      }

      u -= nl;
      nl += nwp[i];
    }

    if (nl == 0)
    {
      goto ne;
    }

    equalise = ((i - 1) * 100000ULL) + ((u * 100000ULL) / nl);
    for (j = nl; j--;)
    {
      success *= equalise;
      success /= 1000000000ULL;
    }

    ne:
    for (; i <= 10000; i++)
    {
      while (nwp[i]--)
      {
        success *= i;
        success /= 10000ULL;
      }

    }


    printf("Case #%u: ", cn + 1);
    if (success == 1000000000ULL)
    {
      new_puts("1.000000000");
    }
    else
    {
      printf("0.%09llu\n", success);
    }

    fflush(stdout);
  }

  return 0;
}

int new_puts(const char *str)
{
  int first_iteration;
  return puts(str);
}


