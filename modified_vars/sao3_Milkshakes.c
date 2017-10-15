#include <stdio.h>
#include <stdlib.h>
#include <string.h>
long long t[100];
long long seq[1001];
long long len[1001];
long long ans;
void pot()
{
  int k;
  int m;
  long long star1;
  long long bs;
  long long tot;
  int i;
  int rec_amo;
  ans = 0;
  scanf("%d%d%I64d%I64d%I64d", &k, &m, &star1, &bs, &tot);
  for (i = 0; i < m; i++)
    scanf("%I64d", &t[i]);

  for (i = 0; i < k; i++)
  {
    seq[i] = t[i % m];
    t[i % m] = ((star1 * t[i % m]) + (bs * (i + 1))) % tot;
    len[i] = 1;
    for (rec_amo = 0; rec_amo < i; rec_amo++)
    {
      if (seq[rec_amo] < seq[i])
        len[i] = (len[i] + len[rec_amo]) % 1000000007;

    }

    ans = (ans + len[i]) % 1000000007;
  }

}

int Main()
{
  int t;
  int t;
  freopen("B.in", "r", stdin);
  freopen("B.out", "w", stdout);
  scanf("%d", &t);
  for (t = 1; t <= t; t++)
  {
    pot();
    printf("Case #%d: %I64d\n", t, ans);
  }

  return 0;
}


