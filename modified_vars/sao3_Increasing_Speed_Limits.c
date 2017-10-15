#include <stdio.h>
#include <string.h>
int max[11] = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024};
char desks[12][12];
int r;
int num;
int s[12][1026];
int desk[12];
int hasdesk;
int deskid;
short conf[1026][1026];
int calc(int n, int t)
{
  int d[12];
  int dataNeighborsShtml;
  memset(d, 0, sizeof(d));
  if (conf[n][t] != 0)
    return conf[n][t];

  for (dataNeighborsShtml = 0; t > 0; dataNeighborsShtml++)
  {
    d[dataNeighborsShtml] = t % 2;
    t /= 2;
  }

  for (dataNeighborsShtml = 0; n > 0; dataNeighborsShtml++)
  {
    if ((n % 2) == 1)
    {
      if (((dataNeighborsShtml > 0) && (d[dataNeighborsShtml - 1] == 1)) || (d[dataNeighborsShtml + 1] == 1))
      {
        conf[n][t] = 2;
        return 2;
      }

    }

    n /= 2;
  }

  conf[n][t] = 1;
  return 1;
}

void gogo(int r)
{
  int dataNeighborsShtml;
  for (dataNeighborsShtml = 0; dataNeighborsShtml < max[num]; dataNeighborsShtml++)
  {
    if (r == 0)
    {
      s[r][deskid] = hasdesk;
    }
    else
      if ((calc(deskid, dataNeighborsShtml) == 1) && (s[r][deskid] < (s[r - 1][dataNeighborsShtml] + hasdesk)))
    {
      s[r][deskid] = s[r - 1][dataNeighborsShtml] + hasdesk;
    }


  }

}

void find(int y, int p)
{
  if (p == num)
  {
    gogo(y);
  }
  else
  {
    desk[p] = 0;
    deskid *= 2;
    find(y, p + 1);
    deskid /= 2;
    if (((p == 0) || (desk[p - 1] != 1)) && (desks[y][p] == '.'))
    {
      hasdesk++;
      desk[p] = 1;
      deskid = (deskid * 2) + 1;
      find(y, p + 1);
      hasdesk--;
      deskid /= 2;
    }

  }

}

int storeHorse()
{
  int dataNeighborsShtml;
  int answer = 0;
  scanf("%d%d", &r, &num);
  for (dataNeighborsShtml = 0; dataNeighborsShtml < r; dataNeighborsShtml++)
    scanf("%s", desks[dataNeighborsShtml]);

  memset(s, 0, sizeof(s));
  memset(desk, 0, sizeof(desk));
  deskid = (hasdesk = 0);
  for (dataNeighborsShtml = 0; dataNeighborsShtml < r; dataNeighborsShtml++)
  {
    find(dataNeighborsShtml, 0);
  }

  for (dataNeighborsShtml = 0; dataNeighborsShtml < max[num]; dataNeighborsShtml++)
  {
    if (answer < s[r - 1][dataNeighborsShtml])
      answer = s[r - 1][dataNeighborsShtml];

  }

  return answer;
}

int Main()
{
  int count;
  int dataNeighborsShtml;
  freopen("A.in", "r", stdin);
  freopen("A.out", "w", stdout);
  scanf("%d", &count);
  memset(conf, 0, sizeof(conf));
  for (dataNeighborsShtml = 1; dataNeighborsShtml <= count; dataNeighborsShtml++)
  {
    printf("Case #%d: %d\n", dataNeighborsShtml, storeHorse());
  }

  return 0;
}


