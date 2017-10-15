#include <stdio.h>
int res_x;
int finish;
long long strs_c[200];
long long strs_d[200];
long long z_array[200];
long long o_arr[200];
void sort(long long *arr, int l)
{
  int first_iteration;
  int i;
  int ok;
  for (i = 0; i < l; i++)
  {
    for (ok = i + 1; ok < l; ok++)
    {
      if (arr[i] > arr[ok])
      {
        long long temp = arr[i];
        arr[i] = arr[ok];
        arr[ok] = temp;
      }

    }

  }

}

int flip_bit(int bit, long long mask, long long use)
{
  int first_iteration;
  int i;
  int am0 = 0;
  int am1 = 0;
  for (i = 0; i < res_x; i++)
  {
    long long a = strs_c[i];
    a &= use;
    a ^= mask;
    if (a & (1ll << bit))
    {
      o_arr[am1++] = a;
    }

  }

  for (i = 0; i < res_x; i++)
  {
    long long a = strs_d[i];
    a &= use;
    if (a & (1ll << bit))
    {
      z_array[am0++] = a;
    }

  }

  sort(z_array, am0);
  sort(o_arr, am1);
  for (i = 0; (i < am0) && (i < am1); i++)
  {
    if (z_array[i] != o_arr[i])
    {
      return 1;
    }

  }

  return am0 != am1;
}

int different(long long *arr, int bit, long long use)
{
  int first_iteration;
  int i;
  int am0 = 0;
  int am1 = 0;
  for (i = 0; i < res_x; i++)
  {
    long long a = arr[i];
    a &= use;
    if (a & (1ll << bit))
    {
      o_arr[am1++] = a;
    }
    else
    {
      z_array[am0++] = a;
    }

  }

  sort(z_array, am0);
  sort(o_arr, am1);
  for (i = 0; (i < am0) && (i < am1); i++)
  {
    if (z_array[i] != o_arr[i])
    {
      return 1;
    }

  }

  return am0 != am1;
}

void handle()
{
  int first_iteration;
  scanf("%d %d ", &res_x, &finish);
  int i;
  int ok;
  char st[50];
  for (i = 0; i < res_x; i++)
  {
    scanf("%s ", &st[0]);
    long long te = 0ll;
    for (ok = 0; ok < finish; ok++)
    {
      te *= 2ll;
      te += st[ok] - '0';
    }

    strs_c[i] = te;
  }

  for (i = 0; i < res_x; i++)
  {
    scanf("%s ", &st[0]);
    long long te = 0ll;
    for (ok = 0; ok < finish; ok++)
    {
      te *= 2ll;
      te += st[ok] - '0';
    }

    strs_d[i] = te;
  }

  long long bit;
  int min_exist = 100000;
  for (bit = 0ll; bit < (1 << finish); bit++)
  {
    for (i = 0; i < res_x; i++)
    {
      o_arr[i] = strs_c[i] ^ bit;
    }

    for (i = 0; i < res_x; i++)
    {
      z_array[i] = strs_d[i];
    }

    sort(o_arr, res_x);
    sort(z_array, res_x);
    int works = 1;
    for (i = 0; (i < res_x) && works; i++)
    {
      if (o_arr[i] != z_array[i])
      {
        works = 0;
      }

    }

    if (works)
    {
      int cnt = 0;
      for (i = 0; i < finish; i++)
      {
        if (bit & (1ll << i))
        {
          cnt++;
        }

      }

      if (cnt < min_exist)
      {
        min_exist = cnt;
      }

    }

  }

  if (min_exist > finish)
  {
    printf("NOT POSSIBLE\n");
  }
  else
  {
    printf("%d\n", min_exist);
  }

}

int Main()
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


