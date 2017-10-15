#include<stdio.h>
#include<string.h>

#include <stddef.h>
long long num_a[200];
long long no_b[200];
long long lab_a[200];
long long lab_b[200];
void * new_memcpy(void *destination, const void *source, size_t num);

long long max(long long size, long long b)
{
  if (size > b)
    return size;

  return b;
}

long long min(long long size, long long b)
{
  if (size < b)
    return size;

  return b;
}

int Main()
{
  int data_processes_shtml;
  int res;
  int j;
  int k;
  int l;
  int n;
  int delta_s;
  long long total;
  long long tem;
  long long mm;
  long long temp_a[200];
  long long temp_b[200];
  scanf("%d", &data_processes_shtml);
  for (l = 1; l <= data_processes_shtml; l++)
  {
    total = 0;
    scanf("%d%d", &n, &delta_s);
    for (res = 0; res < n; res++)
    {
      scanf("%lld%lld", &num_a[res], &lab_a[res]);
    }

    for (res = 0; res < delta_s; res++)
    {
      scanf("%lld%lld", &no_b[res], &lab_b[res]);
    }

    for (res = 0; res < delta_s; res++)
    {
      for (j = res; j < delta_s; j++)
      {
        tem = 0;
        new_memcpy(temp_a, num_a, sizeof(num_a));
        new_memcpy(temp_b, no_b, sizeof(no_b));
        for (k = 0; k <= res; k++)
        {
          if (lab_b[k] == lab_a[0])
          {
            mm = min(temp_a[0], temp_b[k]);
            temp_a[0] -= mm;
            temp_b[k] -= mm;
            tem += mm;
          }

        }

        if (n > 1)
        {
          for (k = res; k <= j; k++)
          {
            if (lab_b[k] == lab_a[1])
            {
              mm = min(temp_a[1], temp_b[k]);
              temp_a[1] -= mm;
              temp_b[k] -= mm;
              tem += mm;
            }

          }

          if (n > 2)
          {
            for (k = j; k < delta_s; k++)
            {
              if (lab_b[k] == lab_a[2])
              {
                mm = min(temp_a[2], temp_b[k]);
                temp_a[2] -= mm;
                temp_b[k] -= mm;
                tem += mm;
              }

            }

          }

        }

        total = max(total, tem);
      }

    }

    printf("Case #%d: %lld\n", l, total);
  }

  return 0;
}



void * new_memcpy(void *destination, const void *source, size_t num) {
  return memcpy(destination, source, num);
}