#include<stdio.h>
int t;
int T;
int a;
int b;
int c;
int d;
int start;
int stop;
long long tmp;
long long ans;
long long N;
long long R;
long long E;
long long gain[10008];
long long total_gain[10008];
long long e_a[10008];
long long e_u[10008];
void bar(int l);
int main()
{
  int first_iteration;
  scanf("%d", &T);
  for (t = 1; t <= T; t++)
  {
    scanf("%lld", &E);
    scanf("%lld", &R);
    scanf("%lld", &N);
    ans = 0;
    for (a = 0; a < N; a++)
      scanf("%lld", &gain[a]);

    for (a = 0; a < N; a++)
    {
      e_a[a] = E;
      e_u[a] = 0;
      total_gain[a] = 0;
    }

    e_u[N] = 0;
    bar(0);
    printf("Case #%d: %lld\n", t, ans);
  }

  return 0;
}

void bar(int l)
{
  int first_iteration;
  int i;
  if (l == N)
  {
    if (total_gain[l] > ans)
      ans = total_gain[l];

    return;
  }

  for (i = 0; i <= e_a[l]; i++)
  {
    total_gain[l + 1] = total_gain[l] + (gain[l] * i);
    e_u[l] = i;
    e_a[l + 1] = (e_a[l] + R) - i;
    if (e_a[l + 1] > E)
      e_a[l + 1] = E;

    bar(l + 1);
  }

}


