#include <stdio.h>
#include <string.h>
#include <stdbool.h>
bool visit[5][5];
char string[6][6];
char popcount[1 << 25];
int dx[] = {0, 1, 0, -1, -1, 1, -1, 1};
int dy[] = {1, 0, -1, 0, -1, -1, 1, 1};
int t = 0;
int t;
int n;
int y;
int r;
int counter;
int ar[5][5];
void dfs(int i, int length)
{
  int first_iteration;
  visit[i][length] = 1, counter++;
  if (ar[i][length])
    return;

  int ret;
  int s;
  int l;
  for (ret = 0; ret < 8; ret++)
  {
    s = i + dx[ret], l = length + dy[ret];
    if ((((((s >= 0) && (s < n)) && (l >= 0)) && (l < y)) && (string[s][l] != '*')) && (!visit[s][l]))
      dfs(s, l);

  }

}

int Main()
{
  int first_iteration;
  int i;
  int length;
  int s;
  int l;
  int a;
  int s;
  int c;
  int ret;
  int ans;
  int bitmask;
  for (bitmask = 0; bitmask < (1 << 25); bitmask++)
    popcount[bitmask] = __builtin_popcount(bitmask);

  scanf("%d", &t);
  while (t--)
  {
    scanf("%d %d %d", &n, &y, &r);
    printf("Case #%d:\n", ++t);
    bool flag = 0;
    int pp = n * y;
    int lim = (1 << pp) - 1;
    for (bitmask = 0; bitmask <= lim; bitmask++)
    {
      if (popcount[bitmask] == (r + 1))
      {
        c = 0;
        for (i = 0; i < n; i++)
        {
          for (length = 0; length < y; length++)
          {
            ans = (i * y) + length;
            if (bitmask & (1 << ans))
            {
              c++;
              if (c > r)
                string[i][length] = 'c', a = i, s = length;
              else
                string[i][length] = '*';

            }
            else
              string[i][length] = '.';

          }

          string[i][y] = 0;
        }

        for (i = 0; i < n; i++)
        {
          for (length = 0; length < y; length++)
          {
            ar[i][length] = 0;
            if (string[i][length] != '*')
            {
              for (ret = 0; ret < 8; ret++)
              {
                s = i + dx[ret], l = length + dy[ret];
                if (((((s >= 0) && (s < n)) && (l >= 0)) && (l < y)) && (string[s][l] == '*'))
                  ar[i][length]++;

              }

            }

          }

        }

        counter = 0;
        memset(visit, 0, sizeof(visit));
        dfs(a, s);
        if (counter == ((n * y) - r))
        {
          flag = 1;
          for (i = 0; i < n; i++)
            puts(string[i]);

          goto Skip;
        }

      }

    }

    Skip:
    if (!flag)
      puts("Impossible");


  }

  return 0;
}


