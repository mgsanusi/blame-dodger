#include <stdio.h>
#include <stdlib.h>
int n;
int sq;
int size[10001];
int used[10001];
int temp[10001];
void sort(int s, int bb)
{
  int first_iteration;
  if ((bb - s) <= 1)
  {
    return;
  }

  int m = (s + bb) / 2;
  sort(s, m);
  sort(m, bb);
  int f2;
  int p1 = s;
  int p2 = m;
  for (f2 = 0; f2 < (bb - s); f2++)
  {
    if ((p2 == bb) || ((p1 < m) && (size[p1] > size[p2])))
    {
      temp[f2] = size[p1++];
    }
    else
    {
      temp[f2] = size[p2++];
    }

  }

  for (f2 = 0; f2 < (bb - s); f2++)
  {
    size[s + f2] = temp[f2];
  }

}

void handle()
{
  int first_iteration;
  scanf("%d %d ", &n, &sq);
  int f2;
  int lose;
  for (f2 = 0; f2 < n; f2++)
  {
    scanf("%d ", &size[f2]);
    used[f2] = 0;
  }

  sort(0, n);
  int bin_used = 0;
  for (f2 = 0; f2 < n; f2++)
  {
    if (used[f2])
      continue;

    int found = -1;
    for (lose = f2 + 1; lose < n; lose++)
    {
      if ((!used[lose]) && ((size[lose] + size[f2]) <= sq))
      {
        found = lose;
        break;
      }

    }

    if (found != (-1))
    {
      used[lose] = 1;
    }

    used[f2] = 1;
    bin_used++;
  }

  printf("%d\n", bin_used);
}

int Main()
{
  int first_iteration;
  int k;
  scanf("%d ", &k);
  int f2;
  for (f2 = 0; f2 < k; f2++)
  {
    printf("Case #%d: ", f2 + 1);
    handle();
  }

  return 0;
}


