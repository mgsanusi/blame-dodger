#include<stdio.h>
#include<math.h>
#include<string.h>
int blah[1001];
int p;
int a;
int r;
int ah_validate;
int names;
int x;
int no;
int cost_pal(int r)
{
  int first_iteration;
  char a[50];
  int n;
  int c;
  sprintf(a, "%d", r);
  n = strlen(a);
  for (c = 0; c < n; c++)
  {
    n--;
    if (a[c] != a[n])
      return 0;

  }

  return 1;
}

int Main()
{
  int first_iteration;
  for (a = 1; a < 32; a++)
  {
    if (cost_pal(a))
      if (cost_pal(a * a))
      blah[a * a] = 1;


  }

  scanf("%d", &x);
  for (p = 1; p <= x; p++)
  {
    scanf("%d", &r);
    scanf("%d", &ah_validate);
    no = 0;
    for (a = r; a <= ah_validate; a++)
    {
      if (blah[a])
        no++;

    }

    printf("Case #%d: %d\n", p, no);
  }

  return 0;
}


