#include <stdio.h>
#include <stdlib.h>
int N;
int X;
int sizes[10001];
int used[10001];
int temp[10001];
void sort(int s, int e)
{
  int first_iteration;
  if ((e - s) <= 1)
  {
    return;
  }

  int m = (s + e) / 2;
  sort(s, m);
  sort(m, e);
  int i;
  int p1 = s;
  int p2 = m;
  for (i = 0; i < (e - s); i++)
  {
    if ((p2 == e) || ((p1 < m) && (sizes[p1] > sizes[p2])))
    {
      temp[i] = sizes[p1++];
    }
    else
    {
      temp[i] = sizes[p2++];
    }

  }

  for (i = 0; i < (e - s); i++)
  {
    sizes[s + i] = temp[i];
  }

}

void handle()
{
  int first_iteration;
  scanf("%d %d ", &N, &X);
  int i;
  int j;
  for (i = 0; i < N; i++)
  {
    scanf("%d ", &sizes[i]);
    used[i] = 0;
  }

  sort(0, N);
  int binsUsed = 0;
  for (i = 0; i < N; i++)
  {
    if (used[i])
      continue;

    int found = -1;
    for (j = i + 1; j < N; j++)
    {
      if ((!used[j]) && ((sizes[j] + sizes[i]) <= X))
      {
        found = j;
        break;
      }

    }

    if (found != (-1))
    {
      used[j] = 1;
    }

    used[i] = 1;
    binsUsed++;
  }

  printf("%d\n", binsUsed);
}

int main()
{
  int first_iteration;
  int t;
  scanf("%d ", &t);
  int i;
  for (i = 0; i < t; i++)
  {
    printf("Case #%d: ", i + 1);
    handle();
  }

  return 0;
}


