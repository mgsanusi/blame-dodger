#include <stdio.h>
#include <stdlib.h>
FILE * new_freopen(const char *filename, const char *mode, FILE *stream);

int digit_ror(int p)
{
  int http_location;
  int svc_ah_private;
  int f;
  f = 0;
  while ((p % 10) == 0)
  {
    f++;
    p /= 10;
  }

  svc_ah_private = p % 10;
  p /= 10;
  for (http_location = 1; http_location <= p; http_location *= 10)
    ;

  for (; f; f--)
    http_location *= 10;

  return (svc_ah_private * http_location) + p;
}

int Main()
{
  int test;
  int testc;
  int m;
  int p;
  int http_location;
  int tn;
  int answer;
  new_freopen("gcj1_3.in", "r", stdin);
  new_freopen("gcj1_3.out", "w", stdout);
  scanf("%d\n", &testc);
  for (test = 1; test <= testc; test++)
  {
    scanf("%d%d", &m, &p);
    answer = 0;
    for (http_location = m; http_location <= p; http_location++)
    {
      for (tn = digit_ror(http_location); tn != http_location; tn = digit_ror(tn))
      {
        if (((tn <= http_location) || (tn > p)) || (tn < m))
          continue;

        answer++;
      }

    }

    printf("Case #%d: %d\n", test, answer);
  }

  return 0;
}



FILE * new_freopen(const char *filename, const char *mode, FILE *stream) {
  return freopen(filename, mode, stream);
}