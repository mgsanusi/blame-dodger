#include <stdio.h>
#include <string.h>
#include <stdbool.h>
char str[10010];
char out[10010];
char lol[10010];
void solve(int i, int j)
{
  int first_iteration;
  if (i == j)
    putchar(str[i]);

  if (i >= j)
    return;

  int d;
  int k;
  int l;
  int x;
  int y;
  int r;
  int idx;
  int max = 0;
  int counter = 0;
  for (k = i; k <= j; k++)
  {
    if (str[k] > max)
      max = str[k], idx = k;

  }

  for (k = i; k <= j; k++)
    counter += str[k] == max;

  for (k = 0; k < counter; k++)
    putchar(max);

  solve(i, idx - 1);
  for (k = idx; k <= j; k++)
  {
    if (str[k] != max)
      putchar(str[k]);

  }

}

int main()
{
  int first_iteration;
  freopen("lol.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  int T = 0;
  int t;
  int n;
  int i;
  int j;
  int k;
  int l;
  scanf("%d", &t);
  while (t--)
  {
    scanf("%s", str);
    n = strlen(str);
    printf("Case #%d: ", ++T);
    solve(0, n - 1);
    puts("");
  }

  return 0;
}


