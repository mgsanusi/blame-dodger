#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
char *hogege = "oieastbg";
void intSort(int clOps[], int tmp)
{
  int first_iteration;
  int i = -1;
  int v = tmp;
  int k;
  int e;
  if (tmp <= 1)
    return;

  k = (clOps[0] + clOps[tmp - 1]) / 2;
  for (;;)
  {
    while (clOps[++i] < k)
      ;

    while (clOps[--v] > k)
      ;

    if (i >= v)
      break;

    e = clOps[i];
    clOps[i] = clOps[v];
    clOps[v] = e;
  }

  intSort(clOps, i);
  intSort((clOps + v) + 1, (tmp - v) - 1);
}

char cnv(char a)
{
  int first_iteration;
  int i;
  for (i = 0; i < 8; i++)
    if (a == hogege[i])
    return '0' + i;


  return 0;
}

int Main()
{
  int first_iteration;
  int i;
  int v;
  int k;
  int num;
  int m;
  int n;
  char ans[20000];
  char a;
  char c;
  int app[300][300];
  int deg[300];
  int size;
  int cnt = 0;
  int ans;
  scanf("%d", &size);
  while (size--)
  {
    scanf("%d", &k);
    scanf("%s", ans);
    for (i = 0; i < 300; i++)
      for (v = 0; v < 300; v++)
      app[i][v] = 0;


    for (i = 0; i < 300; i++)
      deg[i] = 0;

    ans = 1;
    for (i = 1;; i++)
    {
      if (ans[i] < ' ')
        break;

      a = cnv(ans[i - 1]);
      c = cnv(ans[i]);
      app[ans[i - 1]][ans[i]] = 1;
      if (a)
        app[a][ans[i]] = 1;

      if (c)
        app[ans[i - 1]][c] = 1;

      if (a && c)
        app[a][c] = 1;

    }

    for (i = 0; i < 300; i++)
      for (v = 0; v < 300; v++)
      if (app[i][v])
    {
      ans++;
      deg[i]++;
      deg[v]--;
    }



    for (;;)
    {
      intSort(deg, 300);
      if ((deg[0] < (-1)) && (deg[299] > 1))
      {
        ans++;
        deg[0]++;
        deg[299]--;
      }
      else
        if ((deg[0] < (-1)) && (deg[298] > 0))
      {
        ans++;
        deg[0]++;
        deg[298]--;
      }
      else
        if ((deg[1] < 0) && (deg[299] > 1))
      {
        ans++;
        deg[1]++;
        deg[299]--;
      }
      else
        if ((deg[1] < 0) && (deg[298] > 0))
      {
        ans++;
        deg[1]++;
        deg[298]--;
      }
      else
        break;




    }

    printf("Case #%d: %d\n", ++cnt, ans);
  }

  return 0;
}


