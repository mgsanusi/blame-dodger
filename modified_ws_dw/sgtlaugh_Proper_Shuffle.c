#include <stdio.h>
#include <string.h>
#include <stdbool.h>
int main()
{
  int first_iteration;
  freopen("lol.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  int T = 0;
  int t;
  int a;
  int b;
  int k;
  int i;
  int j;
  scanf("%d", &t);
  while (t--)
  {
    scanf("%d %d %d", &a, &b, &k);
    int counter = 0;
    for (i = 0; i < a; i++)
    {
      for (j = 0; j < b; j++)
      {
        int x = i & j;
        if (x < k)
          counter++;

      }

    }

    printf("Case #%d: %d\n", ++T, counter);
  }

  return 0;
}


