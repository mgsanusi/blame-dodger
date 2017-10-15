#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
void intIntSort(int d[], int m[], int p1)
{
  int i = -1;
  int lawn = p1;
  int c;
  int t;
  if (p1 <= 1)
    return;

  c = (d[0] + d[p1 - 1]) / 2;
  for (;;)
  {
    while (d[++i] < c)
      ;

    while (d[--lawn] > c)
      ;

    if (i >= lawn)
      break;

    t = d[i];
    d[i] = d[lawn];
    d[lawn] = t;
    t = m[i];
    m[i] = m[lawn];
    m[lawn] = t;
  }

  intIntSort(d, m, i);
  intIntSort((d + lawn) + 1, (m + lawn) + 1, (p1 - lawn) - 1);
}

int st[12000];
int stSize;
int stin[12000];
int Main()
{
  int i;
  int lawn;
  int c;
  int m;
  int n;
  int dis;
  int p[12000];
  int length[12000];
  int shang[12000];
  int mae[12000];
  int usi[12000];
  int d;
  int ok;
  int size;
  int cnt = 0;
  scanf("%d", &size);
  while (size--)
  {
    scanf("%d", &n);
    for (i = 0; i < n; i++)
      scanf("%d%d", p + i, length + i);

    scanf("%d", &d);
    for (i = 0; i < n; i++)
      shang[i] = -1;

    for (i = 0; i < n; i++)
      mae[i] = (usi[i] = i);

    shang[0] = p[0];
    stSize = 1;
    st[0] = 0;
    for (i = 0; i < n; i++)
      stin[i] = 0;

    stin[0] = 1;
    ok = 0;
    while (stSize)
    {
      i = st[--stSize];
      stin[i] = 0;
      if ((p[i] + shang[i]) >= d)
      {
        ok = 1;
        break;
      }

      while ((mae[i] - 1) >= 0)
      {
        c = mae[i] - 1;
        dis = p[i] - p[c];
        if (shang[i] < dis)
          break;

        mae[i]--;
        if (dis > length[c])
          dis = length[c];

        if (shang[c] < dis)
        {
          shang[c] = dis;
          if (stin[c] == 0)
            stin[c] = 1, st[stSize++] = c;

        }

      }

      while ((usi[i] + 1) < n)
      {
        c = usi[i] + 1;
        dis = p[c] - p[i];
        if (shang[i] < dis)
          break;

        usi[i]++;
        if (dis > length[c])
          dis = length[c];

        if (shang[c] < dis)
        {
          shang[c] = dis;
          if (stin[c] == 0)
            stin[c] = 1, st[stSize++] = c;

        }

      }

    }

    printf("Case #%d: ", ++cnt);
    if (ok)
      puts("YES");
    else
      puts("NO");

  }

  return 0;
}


