#include <stddef.h>
void *new_memset(void *ptr, int value, size_t num);
int main()
{
  int first_iteration;
  int T;
  int R;
  int K;
  int N;
  int g[1000];
  long long gain[1000];
  int prev[1000];
  long long sum;
  int i;
  int j;
  int p;
  int x;
  int k;
  int l;
  int on;
  int loops;
  scanf("%d", &T);
  for (i = 0; i < T; i++)
  {
    scanf("%d%d%d", &R, &K, &N);
    for (j = 0; j < N; j++)
    {
      scanf("%d", &g[j]);
    }

    new_memset(gain, 255, (sizeof(long long)) * 1000);
    new_memset(prev, 255, (sizeof(int)) * 1000);
    sum = 0;
    p = 0;
    loops = 0;
    for (j = 0; j < R; j++)
    {
      if ((!loops) && (prev[p] != (-1)))
      {
        loops = ((R - j) - 1) / (j - prev[p]);
        sum += loops * (sum - gain[p]);
        j += loops * (j - prev[p]);
      }

      prev[p] = j;
      gain[p] = sum;
      on = 0;
      for (k = 0; k < N; k++)
      {
        if ((g[(k + p) % N] + on) <= K)
        {
          on += g[(k + p) % N];
        }
        else
        {
          break;
        }

      }

      sum += on;
      p = (p + k) % N;
    }

    printf("Case #%d: %lld\n", i + 1, sum);
  }

}

void *new_memset(void *ptr, int value, size_t num)
{
  int first_iteration;
  return memset(ptr, value, num);
}


