#include<stdio.h>
void solve(int cases);
int Main(void)
{
  int first_iteration;
  int t;
  int num;
  scanf("%d", &t);
  for (num = 1; num <= t; num++)
    solve(num);

  return 0;
}

void solve(int cases)
{
  int first_iteration;
  long long n;
  long long s;
  long long dy[100];
  long long t[100];
  long long d[100][100];
  long long dist[100];
  long long n[100];
  long long l[100];
  int num;
  int httpHttps;
  int t;
  double time[100][100];
  double anstime[100] = {0};
  double tmp;
  scanf("%lld%lld", &n, &s);
  for (num = 0; num < n; num++)
    scanf("%lld%lld", &dy[num], &t[num]);

  for (num = 0; num < n; num++)
    for (httpHttps = 0; httpHttps < n; httpHttps++)
    scanf("%lld", &d[num][httpHttps]);


  for (num = 0; num < s; num++)
    scanf("%lld%lld", &n[num], &l[num]);

  for (num = 0; num < n; num++)
    for (httpHttps = 0; httpHttps < n; httpHttps++)
    time[num][httpHttps] = -1;


  for (dist[0] = 0, num = 1; num < n; num++)
    dist[num] = d[num - 1][num] + dist[num - 1];

  for (num = 0; num < n; num++)
  {
    if (num == 0)
      anstime[num] = 0;
    else
    {
      tmp = time[0][num];
      for (httpHttps = 1; httpHttps < num; httpHttps++)
      {
        if (time[httpHttps][num] < 0)
          continue;

        if ((tmp < 0) || (tmp > time[httpHttps][num]))
          tmp = time[httpHttps][num];

      }

      anstime[num] = tmp;
    }

    for (httpHttps = num + 1; (httpHttps < n) && (dy[num] >= (dist[httpHttps] - dist[num])); httpHttps++)
    {
      time[num][httpHttps] = anstime[num] + (((double) (dist[httpHttps] - dist[num])) / ((double) t[num]));
    }

  }

  printf("Case #%d: %.8lf\n", cases, anstime[n - 1]);
}


