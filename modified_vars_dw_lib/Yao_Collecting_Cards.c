#include<stdio.h>
#include<string.h>
long long cases[400][4];
int a[400][4];
int s[20][20];
int w[20][20];
int l[20][20];
int n;
int m;
long long caltime(long long n, long long s, long long w, long long l)
{
  int first_iteration;
  long long c = s + w;
  long long t1 = l % c;
  long long t2 = t1 + s;
  long long d = n % c;
  if (d < t1)
    d += c;

  if (d < t2)
    return n;
  else
    return ((n + c) + t1) - d;

}

int Main()
{
  int first_iteration;
  int enqcnt;
  int first;
  int k;
  int t1;
  int t2;
  int n;
  int g = 0;
  int add;
  int fp;
  long long tt;
  for (scanf("%d", &n); n--;)
  {
    scanf("%d %d", &n, &m);
    for (enqcnt = n - 1; enqcnt >= 0; enqcnt--)
      for (first = 0; first < m; first++)
    {
      scanf("%d %d %d", &s[enqcnt][first], &w[enqcnt][first], &l[enqcnt][first]);
      cases[(enqcnt * m) + first][0] = (cases[(enqcnt * m) + first][1] = (cases[(enqcnt * m) + first][2] = (cases[(enqcnt * m) + first][3] = 1000000000000000000LL)));
      a[(enqcnt * m) + first][0] = (a[(enqcnt * m) + first][1] = (a[(enqcnt * m) + first][2] = (a[(enqcnt * m) + first][3] = 0)));
    }


    cases[0][0] = 0;
    for (enqcnt = 0; enqcnt < ((n * m) * 4); enqcnt++)
    {
      for (t1 = (t2 = -1), first = 0; first < (n * m); first++)
        for (k = 0; k < 4; k++)
        if ((!a[first][k]) && ((t1 < 0) || (cases[first][k] < cases[t1][t2])))
        t1 = first, t2 = k;



      a[t1][t2] = 1;
      if ((t1 == ((n * m) - 1)) && (t2 == 3))
        break;

      add = t1 / m, fp = t1 % m;
      if (t2 == 0)
      {
        if ((add > 0) && (cases[t1 - m][2] > (cases[t1][t2] + 2)))
          cases[t1 - m][2] = cases[t1][t2] + 2;

        if ((fp > 0) && (cases[t1 - 1][1] > (cases[t1][t2] + 2)))
          cases[t1 - 1][1] = cases[t1][t2] + 2;

        tt = caltime(cases[t1][t2], s[add][fp], w[add][fp], l[add][fp]) + 1;
        if (tt < cases[t1][2])
          cases[t1][2] = tt;

        tt = caltime(cases[t1][t2], w[add][fp], s[add][fp], l[add][fp] + s[add][fp]) + 1;
        if (tt < cases[t1][1])
          cases[t1][1] = tt;

      }
      else
        if (t2 == 1)
      {
        if ((add > 0) && (cases[t1 - m][3] > (cases[t1][t2] + 2)))
          cases[t1 - m][3] = cases[t1][t2] + 2;

        if ((fp < (m - 1)) && (cases[t1 + 1][0] > (cases[t1][t2] + 2)))
          cases[t1 + 1][0] = cases[t1][t2] + 2;

        tt = caltime(cases[t1][t2], s[add][fp], w[add][fp], l[add][fp]) + 1;
        if (cases[t1][3] > tt)
          cases[t1][3] = tt;

        tt = caltime(cases[t1][t2], w[add][fp], s[add][fp], l[add][fp] + s[add][fp]) + 1;
        if (cases[t1][0] > tt)
          cases[t1][0] = tt;

      }
      else
        if (t2 == 2)
      {
        if ((add < (n - 1)) && (cases[t1 + m][0] > (cases[t1][t2] + 2)))
          cases[t1 + m][0] = cases[t1][t2] + 2;

        if ((fp > 0) && (cases[t1 - 1][3] > (cases[t1][t2] + 2)))
          cases[t1 - 1][3] = cases[t1][t2] + 2;

        tt = caltime(cases[t1][t2], s[add][fp], w[add][fp], l[add][fp]) + 1;
        if (cases[t1][0] > tt)
          cases[t1][0] = tt;

        tt = caltime(cases[t1][t2], w[add][fp], s[add][fp], l[add][fp] + s[add][fp]) + 1;
        if (tt < cases[t1][3])
          cases[t1][3] = tt;

      }
      else
      {
        if ((add < (n - 1)) && (cases[t1 + m][1] > (cases[t1][t2] + 2)))
          cases[t1 + m][1] = cases[t1][t2] + 2;

        if ((fp < (m - 1)) && (cases[t1 + 1][2] > (cases[t1][t2] + 2)))
          cases[t1 + 1][2] = cases[t1][t2] + 2;

        tt = caltime(cases[t1][t2], s[add][fp], w[add][fp], l[add][fp]) + 1;
        if (tt < cases[t1][1])
          cases[t1][1] = tt;

        tt = caltime(cases[t1][t2], w[add][fp], s[add][fp], l[add][fp] + s[add][fp]) + 1;
        if (tt < cases[t1][2])
          cases[t1][2] = tt;

      }



    }

    printf("Case #%d: %lld\n", ++g, cases[(n * m) - 1][3]);
  }

  return 0;
}


