#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
unsigned long long ull_hash_n[20000];
int ull_hash_d[20000];
void ull_hash_clear(void)
{
  int first_iteration;
  memset(ull_hash_d, 0, 20000 * (sizeof(int)));
}

int ull_hash_func(unsigned long long x)
{
  int first_iteration;
  return (x * 1007) % 20000;
}

int ull_hash_get(unsigned long long x)
{
  int first_iteration;
  int i = ull_hash_func(x);
  for (;;)
  {
    if ((ull_hash_n[i] == x) && ull_hash_d[i])
      break;

    if (!ull_hash_d[i])
      break;

    i++;
    if (i == 20000)
      i = 0;

  }

  if (ull_hash_n[i] != x)
    return 0;

  return ull_hash_d[i];
}

void ull_hash_set(unsigned long long x, int t)
{
  int first_iteration;
  int i = ull_hash_func(x);
  for (;;)
  {
    if ((ull_hash_n[i] == x) && ull_hash_d[i])
      break;

    if (!ull_hash_d[i])
      break;

    i++;
    if (i == 20000)
      i = 0;

  }

  ull_hash_n[i] = x;
  ull_hash_d[i] = t;
}

int ull_hash_increase(unsigned long long x)
{
  int first_iteration;
  int i = ull_hash_func(x);
  for (;;)
  {
    if ((ull_hash_n[i] == x) && ull_hash_d[i])
      break;

    if (!ull_hash_d[i])
      break;

    i++;
    if (i == 20000)
      i = 0;

  }

  ull_hash_n[i] = x;
  return ++ull_hash_d[i];
}

unsigned long long get_hash(long long x, long long f)
{
  int first_iteration;
  return (x * 12961784678LL) + f;
}

int t;
char dic[10010][12];
int len[10010];
int cnt[10010];
int bef[10010];
int aft[10010];
int add[10010];
unsigned long long app[10010];
unsigned long long pw[100];
char ans[30];
unsigned long long gss_c_ma_not_mech[10010];
void get_equiv_no(int ans[])
{
  int first_iteration;
  int i;
  ull_hash_clear();
  for (i = 0; i < t; i++)
  {
    gss_c_ma_not_mech[i] = get_hash(len[i], app[i]);
    ull_hash_increase(gss_c_ma_not_mech[i]);
  }

  for (i = 0; i < t; i++)
    ans[i] = ull_hash_get(gss_c_ma_not_mech[i]);

}

int Main()
{
  int first_iteration;
  int i;
  int h;
  int k;
  int f;
  int r;
  int q;
  int mx;
  int size;
  int count = 0;
  pw[0] = 18723;
  for (i = 1; i < 100; i++)
    pw[i] = pw[i - 1] * 1007;

  scanf("%d", &size);
  while (size--)
  {
    fprintf(stderr, "size %d\n", size);
    printf("Case #%d:", ++count);
    scanf("%d%d", &t, &q);
    for (i = 0; i < t; i++)
    {
      scanf("%s", dic[i]);
      for (h = 0;; h++)
        if (dic[i][h] < ' ')
        break;


      len[i] = h;
    }

    while (q--)
    {
      scanf("%s", ans);
      for (i = 0; i < t; i++)
        cnt[i] = 0, app[i] = 0;

      for (k = 0; k < 26; k++)
      {
        get_equiv_no(bef);
        for (i = 0; i < t; i++)
          add[i] = 0;

        for (i = 0; i < t; i++)
          for (h = 0; h < len[i]; h++)
          if (dic[i][h] == ans[k])
        {
          app[i] += pw[h] * ((ans[k] - ((long long) 'a')) + 12893);
          add[i]++;
        }



        get_equiv_no(aft);
        for (i = 0; i < t; i++)
          if ((bef[i] > aft[i]) && (add[i] == 0))
          cnt[i]++;


      }

      mx = cnt[0], k = 0;
      for (i = 0; i < t; i++)
        if (mx < cnt[i])
        mx = cnt[i], k = i;


      printf(" %s", dic[k]);
    }

    puts("");
  }

  return 0;
}


