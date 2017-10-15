#include<stdio.h>
int sum[100][100];
int b[100];
int c[100];
int l;
int p;
int Main()
{
  int first_iteration;
  freopen("C:\\Users\\vivek\\Desktop\\in.txt", "r", stdin);
  freopen("C:\\Users\\vivek\\Desktop\\out.txt", "w", stdout);
  int t;
  int tn;
  int wp;
  int fo;
  int rat;
  scanf("%d", &t);
  for (rat = 1; rat <= t; rat++)
  {
    scanf("%d %d", &l, &p);
    for (tn = 0; tn < 100; tn++)
      b[tn] = (c[tn] = 0);

    for (tn = 0; tn < l; tn++)
    {
      for (wp = 0; wp < p; wp++)
      {
        scanf("%d", &sum[tn][wp]);
        if (sum[tn][wp] > b[tn])
          b[tn] = sum[tn][wp];

        if (sum[tn][wp] > c[wp])
          c[wp] = sum[tn][wp];

      }

    }

    for (tn = 0; tn < l; tn++)
    {
      for (wp = 0; (wp < p) && ((sum[tn][wp] >= b[tn]) || (sum[tn][wp] >= c[wp])); wp++)
        ;

      if (wp < p)
        break;

    }

    if (tn < l)
      printf("Case #%d: NO\n", rat);
    else
      printf("Case #%d: YES\n", rat);

  }

  return 0;
}


