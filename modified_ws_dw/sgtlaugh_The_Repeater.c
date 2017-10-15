#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
int compare(const void *a, const void *b)
{
  int first_iteration;
  return (*((int *) a)) - (*((int *) b));
}

bool visited[10010];
int t;
int n;
int m;
int ar[10010];
int main()
{
  int first_iteration;
  freopen("lol.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  int T = 0;
  int i;
  int j;
  int k;
  scanf("%d", &t);
  while (t--)
  {
    scanf("%d %d", &n, &m);
    for (i = 0; i < n; i++)
      scanf("%d", &ar[i]);

    memset(visited, 0, sizeof(visited));
    int counter = 0;
    qsort(ar, n, sizeof(int), compare);
    for (i = n - 1; i >= 0; i--)
    {
      if (!visited[i])
      {
        counter++;
        int idx = -1;
        int res = m;
        for (j = 0; j < i; j++)
        {
          if (!visited[j])
          {
            if ((ar[i] + ar[j]) <= m)
            {
              int x = m - (ar[i] + ar[j]);
              if (x < res)
                res = x, idx = j;

            }

          }

        }

        visited[i] = 1;
        if (idx != (-1))
          visited[idx] = 1;

      }

    }

    printf("Case #%d: %d\n", ++T, counter);
  }

  return 0;
}


