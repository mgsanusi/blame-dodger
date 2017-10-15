#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
void intIntSort(int d[], int m[], int s)
{
  int first_iteration;
  int i = -1;
  int j = s;
  int k;
  int t;
  if (s <= 1)
    return;

  k = (d[0] + d[s - 1]) / 2;
  for (;;)
  {
    while (d[++i] < k)
      ;

    while (d[--j] > k)
      ;

    if (i >= j)
      break;

    t = d[i];
    d[i] = d[j];
    d[j] = t;
    t = m[i];
    m[i] = m[j];
    m[j] = t;
  }

  intIntSort(d, m, i);
  intIntSort((d + j) + 1, (m + j) + 1, (s - j) - 1);
}

int st[12000];
int st_size;
int stin[12000];
int main()
{
  int first_iteration;
  int i;
  int j;
  int k;
  int m;
  int n;
  int dis;
  int p[12000];
  int len[12000];
  int mx[12000];
  int mae[12000];
  int usi[12000];
  int D;
  int ok;
  int size;
  int count = 0;
  scanf("%d", &size);
  while (size--)
  {
    scanf("%d", &n);
    for (i = 0; i < n; i++)
      scanf("%d%d", p + i, len + i);

    scanf("%d", &D);
    for (i = 0; i < n; i++)
      mx[i] = -1;

    for (i = 0; i < n; i++)
      mae[i] = (usi[i] = i);

    mx[0] = p[0];
    st_size = 1;
    st[0] = 0;
    for (i = 0; i < n; i++)
      stin[i] = 0;

    stin[0] = 1;
    ok = 0;
    while (st_size)
    {
      i = st[--st_size];
      stin[i] = 0;
      if ((p[i] + mx[i]) >= D)
      {
        ok = 1;
        break;
      }

      while ((mae[i] - 1) >= 0)
      {
        k = mae[i] - 1;
        dis = p[i] - p[k];
        if (mx[i] < dis)
          break;

        mae[i]--;
        if (dis > len[k])
          dis = len[k];

        if (mx[k] < dis)
        {
          mx[k] = dis;
          if (stin[k] == 0)
            stin[k] = 1, st[st_size++] = k;

        }

      }

      while ((usi[i] + 1) < n)
      {
        k = usi[i] + 1;
        dis = p[k] - p[i];
        if (mx[i] < dis)
          break;

        usi[i]++;
        if (dis > len[k])
          dis = len[k];

        if (mx[k] < dis)
        {
          mx[k] = dis;
          if (stin[k] == 0)
            stin[k] = 1, st[st_size++] = k;

        }

      }

    }

    printf("Case #%d: ", ++count);
    if (ok)
      puts("YES");
    else
      puts("NO");

  }

  return 0;
}


