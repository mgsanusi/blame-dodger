#include <stdio.h>
int width;
int rv;
int d;
int xx1;
int xx2;
int yy1;
int yy2;
FILE * new_freopen(const char *filename, const char *mode, FILE *stream);

int go()
{
  int first_iteration;
  int x1;
  int lado;
  int len;
  int pD;
  int c;
  scanf("%d%d%d", &rv, &width, &d);
  if ((width * rv) < d)
  {
    return 0;
  }

  for (x1 = 0; x1 <= rv; x1++)
    for (lado = 0; lado <= width; lado++)
    for (len = 0; len <= rv; len++)
    for (pD = 0; pD <= width; pD++)
  {
    c = (x1 * pD) - (len * lado);
    if (c < 0)
      c = -c;

    if (c == d)
    {
      xx1 = x1;
      xx2 = len;
      yy1 = lado;
      yy2 = pD;
      return 1;
    }

  }




  return 0;
}

int Main()
{
  int first_iteration;
  int mix;
  int j;
  new_freopen("B.in", "r", stdin);
  new_freopen("B.out", "w", stdout);
  scanf("%d", &mix);
  for (j = 1; j <= mix; j++)
  {
    printf("Case #%d: ", j);
    if (go())
    {
      printf("0 0 %d %d %d %d\n", xx1, yy1, xx2, yy2);
    }
    else
    {
      printf("IMPOSSIBLE\n");
    }

  }

  return 0;
}



FILE * new_freopen(const char *filename, const char *mode, FILE *stream) {
  return freopen(filename, mode, stream);
}