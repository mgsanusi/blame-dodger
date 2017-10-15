#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
unsigned long long ull_hash_n[20000];
int ull_hash_d[20000];
void ullHashClear(void)
{
  int first_iteration;
  memset(ull_hash_d, 0, 20000 * (sizeof(int)));
}

int ullHashFunction(unsigned long long a)
{
  int first_iteration;
  return (a * 1007) % 20000;
}

int ullHashGet(unsigned long long a)
{
  int first_iteration;
  int i = ullHashFunction(a);
  for (;;)
  {
    if ((ull_hash_n[i] == a) && ull_hash_d[i])
      break;

    if (!ull_hash_d[i])
      break;

    i++;
    if (i == 20000)
      i = 0;

  }

  if (ull_hash_n[i] != a)
    return 0;

  return ull_hash_d[i];
}

void ullHashSet(unsigned long long a, int n)
{
  int first_iteration;
  int i = ullHashFunction(a);
  for (;;)
  {
    if ((ull_hash_n[i] == a) && ull_hash_d[i])
      break;

    if (!ull_hash_d[i])
      break;

    i++;
    if (i == 20000)
      i = 0;

  }

  ull_hash_n[i] = a;
  ull_hash_d[i] = n;
}

int ullHashIncrease(unsigned long long a)
{
  int first_iteration;
  int i = ullHashFunction(a);
  for (;;)
  {
    if ((ull_hash_n[i] == a) && ull_hash_d[i])
      break;

    if (!ull_hash_d[i])
      break;

    i++;
    if (i == 20000)
      i = 0;

  }

  ull_hash_n[i] = a;
  return ++ull_hash_d[i];
}

unsigned long long get_hash(long long a, long long b)
{
  int first_iteration;
  return (a * 12961784678LL) + b;
}

int n;
char dic[10010][12];
int len[10010];
int cnt[10010];
int bef[10010];
int aft[10010];
int add[10010];
unsigned long long app[10010];
unsigned long long pw[100];
char in[30];
unsigned long long hs[10010];
void get_equiv_num(int res[])
{
  int first_iteration;
  int i;
  ullHashClear();
  for (i = 0; i < n; i++)
  {
    hs[i] = get_hash(len[i], app[i]);
    ullHashIncrease(hs[i]);
  }

  for (i = 0; i < n; i++)
    res[i] = ullHashGet(hs[i]);

}

int main()
{
  int first_iteration;
  int i;
  int j;
  int k;
  int l;
  int m;
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
    scanf("%d%d", &n, &q);
    for (i = 0; i < n; i++)
    {
      scanf("%s", dic[i]);
      for (j = 0;; j++)
        if (dic[i][j] < ' ')
        break;


      len[i] = j;
    }

    while (q--)
    {
      scanf("%s", in);
      for (i = 0; i < n; i++)
        cnt[i] = 0, app[i] = 0;

      for (k = 0; k < 26; k++)
      {
        get_equiv_num(bef);
        for (i = 0; i < n; i++)
          add[i] = 0;

        for (i = 0; i < n; i++)
          for (j = 0; j < len[i]; j++)
          if (dic[i][j] == in[k])
        {
          app[i] += pw[j] * ((in[k] - ((long long) 'a')) + 12893);
          add[i]++;
        }



        get_equiv_num(aft);
        for (i = 0; i < n; i++)
          if ((bef[i] > aft[i]) && (add[i] == 0))
          cnt[i]++;


      }

      mx = cnt[0], k = 0;
      for (i = 0; i < n; i++)
        if (mx < cnt[i])
        mx = cnt[i], k = i;


      printf(" %s", dic[k]);
    }

    puts("");
  }

  return 0;
}


