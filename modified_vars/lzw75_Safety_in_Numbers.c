#include <stdio.h>
#include <stdlib.h>
#include <time.h>
typedef struct 
{
  int ind;
  long long sum;
} sub;
sub *subs;
int compare(const sub *l, const sub *r)
{
  if ((*l).sum < (*r).sum)
    return -1;
  else
    if ((*l).sum > (*r).sum)
    return +1;
  else
    return 0;


}

void run(const long long num[600])
{
  int v;
  int j;
  int k;
  int ok = 0;
  for (v = 0; v < 500; v++)
    for (j = v + 1; j < 500; j++)
    for (k = j + 1; k < 500; k++)
  {
    subs[ok].ind = ((1048576 * k) + (1024 * j)) + v;
    subs[ok].sum = (num[v] + num[j]) + num[k];
    ok++;
  }



  qsort(subs, ok, sizeof(sub), compare);
  for (v = 0; v < ok; v++)
    if (subs[v].sum == subs[v + 1].sum)
  {
    long long mini;
    long long n2;
    long long n3;
    long long v;
    long long bx;
    long long lenS;
    mini = num[subs[v].ind % 1024];
    n2 = num[(subs[v].ind / 1024) % 1024];
    n3 = num[subs[v].ind / 1048576];
    v = num[subs[v + 1].ind % 1024];
    bx = num[(subs[v + 1].ind / 1024) % 1024];
    lenS = num[subs[v + 1].ind / 1048576];
    printf("%lld %lld %lld\n", v, bx, lenS);
    printf("%lld %lld %lld\n", mini, n2, n3);
    if (((v + bx) + lenS) != ((mini + n2) + n3))
      printf("ERROR!!!!!\n");

    return;
  }


}

int Main()
{
  int names;
  int v;
  int j;
  subs = (sub *) malloc((sizeof(sub)) * 22000000);
  scanf("%d", &names);
  for (v = 0; v < names; v++)
  {
    int n;
    long long num[600];
    scanf("%d", &n);
    for (j = 0; j < n; j++)
      scanf("%lld", &num[j]);

    printf("Case #%d:\n", v + 1);
    run(num);
  }

  free(subs);
}


