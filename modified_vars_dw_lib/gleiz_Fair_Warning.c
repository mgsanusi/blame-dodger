#include  <stdio.h>
#include  <stdlib.h>
#include  <string.h>

#include <stddef.h>
int grp[1024] = {0};
char tag[1024] = {0};
int next[1024] = {0};
int cont[1024] = {0};
unsigned long long py[1024] = {0};
FILE * new_freopen(const char *filename, const char *mode, FILE *stream);
void * new_memset(void *ptr, int value, int num);


int Main(int argc, char *argv[])
{
  int first_iteration;
  int total = 0;
  int j = 0;
  long long k = 0;
  long long now = 0;
  int tot = 0;
  int n = 0;
  int cas = 1;
  int hs = 0;
  unsigned long long gain = 0;
  int body = 0;
  scanf("%d", &hs);
  while (hs--)
  {
    new_memset(tag, -1, sizeof(tag));
    new_memset(grp, 0, sizeof(grp));
    new_memset(next, -1, sizeof(next));
    new_memset(cont, 0, sizeof(cont));
    new_memset(py, 0, sizeof(py));
    scanf("%d %lld %d", &tot, &k, &n);
    for (total = 0; total < n; total++)
    {
      scanf("%d", &grp[total]);
    }

    for (total = 0; total < n; total++)
    {
      now = grp[total];
      for (j = (total + 1) % n; (j != total) && ((now + grp[j]) <= k); j = (j + 1) % n)
      {
        now += grp[j];
      }

      cont[total] = now;
      next[total] = j;
    }

    total = 0;
    j = -1;
    now = 0;
    gain = 0;
    while (tot)
    {
      if (tag[total] != (-1))
      {
        if (tag[total] != 0)
        {
          body = tot / (j - (tag[total] - 1));
          if (body != 0)
            gain += body * (py[j] - py[tag[total] - 1]);

          tot %= (j - tag[total]) + 1;
          while (tot)
          {
            gain += cont[total];
            tot--;
            total = next[total];
          }

        }
        else
        {
          body = tot / (j + 1);
          if (body != 0)
            gain += body * (py[j] - py[tag[total] - 1]);

          tot %= j + 1;
          while (tot)
          {
            gain += cont[total];
            tot--;
            total = next[total];
          }

        }

        break;
      }

      j++;
      now += cont[total];
      gain += cont[total];
      tag[total] = j;
      py[j] = now;
      tot--;
      total = next[total];
    }

    printf("Case #%d: $lld\b", cas++, gain);
  }

  return 0;
}



FILE * new_freopen(const char *filename, const char *mode, FILE *stream) {
  return freopen(filename, mode, stream);
}
void * new_memset(void *ptr, int value, int num) {
  return memset(ptr, value, num);
}