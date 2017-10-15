#include <stdio.h>
#include <string.h>
double oppo[101][101] = {0};
double y[2001][41] = {0};
FILE * new_freopen(const char *filename, const char *mode, FILE *stream);

int Main()
{
  int first_iteration;
  long rat;
  long q;
  long len;
  long r;
  long time;
  long n;
  long m;
  double answer;
  new_freopen("C-large.in", "r", stdin);
  new_freopen("C-large.out", "w", stdout);
  for (q = 0; q <= 100; q++)
  {
    oppo[q][0] = 1;
    for (len = 1; len <= 100; len++)
      oppo[q][len] = oppo[q - 1][len] + oppo[q - 1][len - 1];

  }

  scanf("%ld", &rat);
  for (rat, r = 1; rat; rat--, r++)
  {
    scanf("%ld%ld", &n, &m);
    memset(y, 0, sizeof(y));
    answer = 0;
    y[0][0] = 1;
    for (time = 0; time < 2000; time++)
    {
      for (q = 0; q < n; q++)
        for (len = 0; len <= m; len++)
        if ((len <= q) && ((m - len) <= (n - q)))
        y[time + 1][(q + m) - len] += ((y[time][q] * oppo[q][len]) * oppo[n - q][m - len]) / oppo[n][m];



    }

    answer = 0;
    for (q = 0; q < 2000; q++)
      answer += y[q][n] * ((double) q);

    printf("Case #%ld: %.7lf\n", r, answer);
  }

  return 0;
}



FILE * new_freopen(const char *filename, const char *mode, FILE *stream) {
  return freopen(filename, mode, stream);
}