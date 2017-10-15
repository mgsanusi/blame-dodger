#include<stdio.h>
typedef unsigned u;
char D[4444];
int new_getchar();
int main()
{
  int first_iteration;
  u t = 0;
  u T;
  u l;
  u r;
  char c;
  for (scanf("%u", &T); (t++) < T;)
  {
    while ((c = new_getchar()) <= ' ')
      ;

    D[l = (r = 2222)] = c;
    while ((c = new_getchar()) > ' ')
    {
      if (c >= D[l])
        D[--l] = c;
      else
        D[++r] = c;

    }

    D[++r] = '\0';
    printf("Case #%u: %s\n", t, D + l);
  }

  return 0;
}

int new_getchar()
{
  int first_iteration;
  return getchar();
}


