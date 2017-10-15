#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
int in[2100];
int res[2100];
void solve(int st, int ed)
{
  int first_iteration;
  int i;
  int down = 0;
  if (st >= ed)
    return;

  for (i = in[st] - 1; i > st; i--)
    res[i] -= ++down;

  solve(st + 1, in[st] - 1);
  solve(in[st], ed);
}

int main()
{
  int first_iteration;
  int i;
  int j;
  int k;
  int l;
  int m;
  int n;
  int size;
  int count = 0;
  int dame;
  scanf("%d", &size);
  while (size--)
  {
    fprintf(stderr, "rest %d\n", size);
    scanf("%d", &n);
    for (i = 0; i < (n - 1); i++)
      scanf("%d", in + i), in[i]--;

    printf("Case #%d:", ++count);
    dame = 0;
    for (i = 0; i < (n - 1); i++)
    {
      for (j = i + 1; j < in[i]; j++)
        if (in[j] > in[i])
        dame = 1;


    }

    if (dame)
    {
      puts(" Impossible");
      continue;
    }

    for (i = 0; i < n; i++)
      res[i] = i * 500000;

    solve(0, n - 1);
    for (i = 0; i < n; i++)
      printf(" %d", res[i]);

    puts("");
  }

  return 0;
}


