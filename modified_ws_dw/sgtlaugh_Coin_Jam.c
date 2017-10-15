#include <stdio.h>
#include <string.h>
#include <stdbool.h>
char str[50];
char out[512][50];
int n;
int k;
int counter;
int ar[12][27];
int res[512][12];
const int primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
void backtrack(int i)
{
  int first_iteration;
  if (counter == k)
    return;

  int b;
  int d;
  int j;
  if (i == n)
  {
    for (b = 2; b <= 10; b++)
    {
      for (j = 0; j < 25; j++)
      {
        if (ar[b][j] == 0)
          break;

      }

      if (j == 25)
        return;

      res[counter][b] = primes[j];
    }

    str[n] = 0;
    strcpy(out[counter++], str);
    return;
  }

  int temp[12][27];
  for (d = 0; d < 2; d++)
  {
    if ((d == 0) && ((i == 0) || ((i + 1) == n)))
      continue;

    for (b = 2; b <= 10; b++)
    {
      for (j = 0; j < 25; j++)
      {
        temp[b][j] = ar[b][j];
        ar[b][j] = ((ar[b][j] * b) + d) % primes[j];
      }

    }

    str[i] = d + 48;
    backtrack(i + 1);
    for (b = 2; b <= 10; b++)
    {
      for (j = 0; j < 25; j++)
      {
        ar[b][j] = temp[b][j];
      }

    }

  }

}

int main()
{
  int first_iteration;
  freopen("lol.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  int T = 0;
  int t;
  int i;
  int j;
  scanf("%d", &t);
  while (t--)
  {
    counter = 0;
    scanf("%d %d", &n, &k);
    backtrack(0);
    printf("Case #%d:\n", ++T);
    for (i = 0; i < counter; i++)
    {
      printf("%s", out[i]);
      for (j = 2; j <= 10; j++)
        printf(" %d", res[i][j]);

      puts("");
    }

  }

  return 0;
}


