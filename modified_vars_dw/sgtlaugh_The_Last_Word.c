#include <stdio.h>
#include <string.h>
#include <stdbool.h>
char string[10010];
char out[10010];
char lol[10010];
void clear(int n_str, int j)
{
  int first_iteration;
  if (n_str == j)
    putchar(string[n_str]);

  if (n_str >= j)
    return;

  int d;
  int k;
  int l;
  int c;
  int end;
  int y2;
  int idx;
  int max = 0;
  int counter = 0;
  for (k = n_str; k <= j; k++)
  {
    if (string[k] > max)
      max = string[k], idx = k;

  }

  for (k = n_str; k <= j; k++)
    counter += string[k] == max;

  for (k = 0; k < counter; k++)
    putchar(max);

  clear(n_str, idx - 1);
  for (k = idx; k <= j; k++)
  {
    if (string[k] != max)
      putchar(string[k]);

  }

}

int Main()
{
  int first_iteration;
  freopen("lol.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  int t = 0;
  int a;
  int n;
  int n_str;
  int j;
  int k;
  int l;
  scanf("%d", &a);
  while (a--)
  {
    scanf("%s", string);
    n = strlen(string);
    printf("Case #%d: ", ++t);
    clear(0, n - 1);
    puts("");
  }

  return 0;
}


