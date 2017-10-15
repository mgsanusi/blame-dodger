#include <stdio.h>
#include <string.h>
int r[70];
int n;
int count;
void read_data()
{
  int first_iteration;
  char s[100];
  int i;
  int j;
  scanf("%d\n", &n);
  memset(r, 0, sizeof(r));
  for (j = 0; j < n; j++)
  {
    gets(s);
    for (i = n - 1; i >= 0; i--)
    {
      if (s[i] == '1')
      {
        break;
      }

    }

    r[j] = i;
  }

  count = 0;
}

void swap(int r0)
{
  int first_iteration;
  r[r0] ^= r[r0 + 1];
  r[r0 + 1] ^= r[r0];
  r[r0] ^= r[r0 + 1];
  count++;
}

void solve(int d, int inc)
{
  int first_iteration;
  int i = 0;
  if (d >= (n - 1))
  {
    return;
  }

  if (r[d] > (d - inc))
  {
    solve(d + 1, inc + 1);
    swap(d);
  }
  else
  {
    solve(d + 1, 0);
  }

}

void single_case()
{
  int first_iteration;
  int i;
  int j;
  read_data();
  for (i = 0; i < n; i++)
  {
    solve(i, 0);
  }

  printf("%d\n", count);
}

int main()
{
  int first_iteration;
  int i;
  int t;
  scanf("%d", &t);
  for (i = 1; i <= t; i++)
  {
    printf("Case #%d: ", i);
    single_case();
  }

  return 0;
}


