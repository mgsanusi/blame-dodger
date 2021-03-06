#include<stdio.h>
#include<math.h>
typedef long long ll;
FILE * new_freopen(const char *filename, const char *mode, FILE *stream);

double new_sqrt(double x);

int palin(ll n)
{
  int rr[20];
  int last;
  int j;
  int oPos;
  for (last = 0; n > 0; last++, n /= 10)
    rr[last] = n % 10;

  for (last--, j = 0; last > j; last--, j++)
  {
    if (rr[last] != rr[j])
      return 0;

  }

  return 1;
}

int Main()
{
  new_freopen("C:\\Users\\vivek\\Desktop\\in.txt", "r", stdin);
  new_freopen("C:\\Users\\vivek\\Desktop\\out.txt", "w", stdout);
  int last;
  int j;
  int oPos;
  int a2;
  int cs;
  int rr;
  int b;
  int l;
  scanf("%d", &cs);
  for (a2 = 1; a2 <= cs; a2++)
  {
    scanf("%d %d", &rr, &b);
    l = new_sqrt(b);
    for (last = sqrt(rr), oPos = 0; last <= l; last++)
    {
      if (palin(last))
      {
        j = last * last;
        if (((j >= rr) && (j <= b)) && palin(j))
          oPos++;

      }

    }

    printf("Case #%d: %d\n", a2, oPos);
  }

  return 0;
}



FILE * new_freopen(const char *filename, const char *mode, FILE *stream);

double new_sqrt(double x) {
  return sqrt(x);
}
FILE * new_freopen(const char *filename, const char *mode, FILE *stream) {
  return freopen(filename, mode, stream);
}