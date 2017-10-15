#include <stdio.h>
#include <stdlib.h>
typedef struct 
{
  double tmp;
  int k;
} dist;
int cmp(const void *v, const void *b)
{
  if (((dist *) v)->tmp < ((dist *) b)->tmp)
  {
    return 1;
  }
  else
    if (((dist *) v)->tmp == ((dist *) b)->tmp)
  {
    return 0;
  }
  else
  {
    return -1;
  }


}

int Main()
{
  int ans;
  int l;
  int k;
  int c;
  int h;
  int itest;
  long long t;
  dist v[1001];
  scanf("%d", &ans);
  for (h = 0; h < ans; h++)
  {
    double p = 0;
    int flag = 0;
    scanf("%d %lld %d %d", &l, &t, &k, &c);
    for (itest = 0; itest < c; itest++)
    {
      int right;
      scanf("%d", &right);
      v[itest].tmp = (double) right;
      v[itest].k = k / c;
      if (itest < (k % c))
        v[itest].k++;

    }

    for (itest = 0; itest < c; itest++)
    {
      if (v[itest].k == 0)
      {
        printf("Case #%d: %lld\n", h + 1, (long long) p);
        flag = 1;
        break;
      }

      if ((p + (v[itest].tmp * 2)) <= t)
      {
        p += v[itest].tmp * 2;
        v[itest].k--;
      }
      else
      {
        v[c].tmp = v[itest].tmp - ((t - p) / 2.0);
        v[c].k = 1;
        v[itest].k--;
        p = t;
        ;
        c++;
        break;
      }

      if (itest == (c - 1))
        itest = -1;

    }

    if (flag == 0)
    {
      qsort(v, c, sizeof(dist), cmp);
      for (itest = 0; itest < c; itest++)
      {
        if (v[itest].k == 0)
          continue;

        if (l >= v[itest].k)
        {
          p += v[itest].k * v[itest].tmp;
          l -= v[itest].k;
        }
        else
        {
          p += l * v[itest].tmp;
          p += ((v[itest].k - l) * v[itest].tmp) * 2;
          l = 0;
        }

      }

      printf("Case #%d: %lld\n", h + 1, (long long) p);
    }

  }

  return 0;
}


