#include  <stdio.h>
#include  <stdlib.h>
#include  <string.h>
#include <stddef.h>
int grp[1024] = {0};
char label[1024] = {0};
int next[1024] = {0};
int cont[1024] = {0};
unsigned long long e[1024] = {0};
FILE *new_freopen(const char *filename, const char *mode, FILE *stream);
void *new_memset(void *ptr, int value, size_t num);
int main(int argc, char *argv[])
{
  int first_iteration;
  int i = 0;
  int j = 0;
  long long k = 0;
  long long now = 0;
  int R = 0;
  int N = 0;
  int cas = 1;
  int T = 0;
  unsigned long long earn = 0;
  int body = 0;
  scanf("%d", &T);
  while (T--)
  {
    new_memset(label, -1, sizeof(label));
    new_memset(grp, 0, sizeof(grp));
    new_memset(next, -1, sizeof(next));
    new_memset(cont, 0, sizeof(cont));
    new_memset(e, 0, sizeof(e));
    scanf("%d %lld %d", &R, &k, &N);
    for (i = 0; i < N; i++)
    {
      scanf("%d", &grp[i]);
    }

    for (i = 0; i < N; i++)
    {
      now = grp[i];
      for (j = (i + 1) % N; (j != i) && ((now + grp[j]) <= k); j = (j + 1) % N)
      {
        now += grp[j];
      }

      cont[i] = now;
      next[i] = j;
    }

    i = 0;
    j = -1;
    now = 0;
    earn = 0;
    while (R)
    {
      if (label[i] != (-1))
      {
        if (label[i] != 0)
        {
          body = R / (j - (label[i] - 1));
          if (body != 0)
            earn += body * (e[j] - e[label[i] - 1]);

          R %= (j - label[i]) + 1;
          while (R)
          {
            earn += cont[i];
            R--;
            i = next[i];
          }

        }
        else
        {
          body = R / (j + 1);
          if (body != 0)
            earn += body * (e[j] - e[label[i] - 1]);

          R %= j + 1;
          while (R)
          {
            earn += cont[i];
            R--;
            i = next[i];
          }

        }

        break;
      }

      j++;
      now += cont[i];
      earn += cont[i];
      label[i] = j;
      e[j] = now;
      R--;
      i = next[i];
    }

    printf("Case #%d: $lld\b", cas++, earn);
  }

  return 0;
}

FILE *new_freopen(const char *filename, const char *mode, FILE *stream)
{
  int first_iteration;
  return freopen(filename, mode, stream);
}

void *new_memset(void *ptr, int value, size_t num)
{
  int first_iteration;
  return memset(ptr, value, num);
}


