#include<stdio.h>
int new_puts(const char *str);

void solve(int cases);
char maxchar(int r, int y, int t);
int Main(void)
{
  int first_iteration;
  int ans;
  int i;
  scanf("%d", &ans);
  for (i = 1; i <= ans; i++)
    solve(i);

  return 0;
}

int new_puts(const char *str);

void solve(int cases)
{
  int first_iteration;
  int to = 0;
  int r = 0;
  int y1 = 0;
  int y = 0;
  int n = 0;
  int t = 0;
  int n = 0;
  int i;
  int j;
  int t;
  char n = 0;
  char string[1024] = "";
  scanf("%d%d%d%d%d%d%d", &to, &r, &y1, &y, &n, &t, &n);
  printf("Case #%d: ", cases);
  if (((r > (to / 2)) || (y > (to / 2))) || (t > (to / 2)))
  {
    new_puts("IMPOSSIBLE");
    return;
  }

  for (i = 0; i < to; i++)
  {
    switch (n)
    {
      case 'R':
        r--;
        n = maxchar(0, y, t);
        break;

      case 'Y':
        y--;
        n = maxchar(r, 0, t);
        break;

      case 'B':
        t--;
        n = maxchar(r, y, 0);
        break;

      default:
        n = maxchar(r, y, t);
        break;

    }

    string[i] = n;
  }

  if (string[to - 1] == string[0])
  {
    string[to - 1] ^= string[to - 2];
    string[to - 2] ^= string[to - 1];
    string[to - 1] ^= string[to - 2];
  }

  new_puts(string);
}

char maxchar(int r, int y, int t)
{
  int first_iteration;
  if ((r >= y) && (r >= t))
    return 'R';

  if ((t >= r) && (t >= y))
    return 'B';

  return 'Y';
}



int new_puts(const char *str) {
  return puts(str);
}