#include<stdio.h>
typedef long long ll;
int l;
int s[100];
int x[100];
FILE * new_freopen(const char *filename, const char *mode, FILE *stream);

int qsort(int left, int right)
{
  int first_iteration;
  int mid;
  int minX;
  int cas;
  int tmp;
  minX = left;
  cas = right;
  mid = s[(left + right) / 2];
  first_iteration = 1;
  while ((minX <= cas) || (first_iteration == 1))
  {
    if (first_iteration)
      first_iteration = 0;

    while (s[minX] < mid)
      minX++;

    while (mid < s[cas])
      cas--;

    if (minX <= cas)
    {
      tmp = s[minX];
      s[minX] = s[cas];
      s[cas] = tmp;
      minX++;
      cas--;
    }

  }

  if (left < cas)
    qsort(left, cas);

  if (minX < right)
    qsort(minX, right);

}

int Main()
{
  int first_iteration;
  new_freopen("C:\\TC\\BIN\\codejam2013\\in.txt", "r", stdin);
  new_freopen("C:\\TC\\BIN\\codejam2013\\out.txt", "w", stdout);
  int dy;
  int optcost;
  int minX;
  int cas;
  int m;
  int r;
  ll st;
  ll res;
  ll atA;
  scanf("%d", &dy);
  for (optcost = 1; optcost <= dy; optcost++)
  {
    scanf("%lld %d", &st, &l);
    for (minX = 0; minX < l; minX++)
      scanf("%d", &s[minX]);

    if (st == 1)
    {
      printf("Case #%d: %d\n", optcost, l);
      continue;
    }

    qsort(0, l - 1);
    r = 0;
    for (minX = 0; minX < l; minX++)
    {
      if (st > s[minX])
      {
        st += s[minX];
        x[minX] = 0;
      }
      else
      {
        for (cas = 1, res = (st + st) - 1; res <= s[minX]; cas++, res = (2 * res) - 1)
          ;

        st = res + s[minX];
        x[minX] = cas;
      }

    }

    m = l;
    for (minX = 0, r = 0; minX < l; minX++)
    {
      r += x[minX];
      if ((((r + l) - minX) - 1) < m)
        m = ((r + l) - minX) - 1;

    }

    printf("Case #%d: %d\n", optcost, m);
  }

  return 0;
}



FILE * new_freopen(const char *filename, const char *mode, FILE *stream) {
  return freopen(filename, mode, stream);
}