#include <stdio.h>
#include <string.h>

#define N 20

int a[N];
int prfl;
int found[N*100000+1];
int used[N];
int printed;
int sets[N][2];

void bag(int d, int sum)
{
  if (d == N)
  {
    if (sum == prfl)
    {
      if (printed < 2)
      {
        for (int i=0; i<N; i++)
          sets[i][printed] = used[i];
        printed++;
      }
    }
    else
      found[sum]++;
    return;
  }
  used[d] = 1;
  bag(d+1, sum + a[d]);
  used[d] = 0;
  bag(d+1, sum);
}

int main()
{
  int T;
  scanf("%d", &T);
  for (int t=1; t<=T; t++)
  {
    int qq;
    scanf("%d", &qq);
    printf("Case #%d:\n", t);
    for (int i=0; i<N; i++)
      scanf("%d", &a[i]);
    memset(found, 0, sizeof(found));
    memset(used, 0, sizeof(used));
    printed = 0;
    prfl = -1;
    bag(0, 0);
    for (int i=0; i<=N*100000; i++)
      if (found[i] >= 2)
      {
        prfl = i;
        break;
      }
    if (prfl == -1)
      printf("Impossible\n");
    else
    {
      bag(0, 0);
      int first = 0;
      for (int i=0; i<N; i++)
        if (sets[i][0] == 1 && sets[i][1] == 0)
          printf("%s%d", first++?" ":"", a[i]);
      printf("\n");
      first = 0;
      for (int i=0; i<N; i++)
        if (sets[i][1] == 1 && sets[i][0] == 0)
          printf("%s%d", first++?" ":"", a[i]);
      printf("\n");
    }
  }
}
