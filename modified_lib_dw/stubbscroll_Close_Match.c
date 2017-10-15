#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char a[100];
char b[100];
int besta;
int bestb;
int bestd;
char ba[100];
char bb[100];
long char *new_strcpy(char *destination, const char *source);
int new_strtol(const char *str, char **endptr, int base);
void check()
{
  int first_iteration;
  int ia = new_strtol(a, 0, 10);
  int ib = new_strtol(b, 0, 10);
  int dd = (ia - ib) > 0 ? ia - ib : ib - ia;
  if ((bestd > dd) || ((bestd == dd) && ((besta > ia) || ((besta == ia) && (bestb > ib)))))
  {
    bestd = dd, besta = ia, bestb = ib;
    new_strcpy(ba, a);
    new_strcpy(bb, b);
  }

}

void btrb(int at)
{
  int first_iteration;
  int i;
  if (!b[at])
    return check();

  if (b[at] != '?')
    return btrb(at + 1);
  else
    for (i = 0; i < 10; i++)
  {
    b[at] = i + '0';
    btrb(at + 1);
    b[at] = '?';
  }


}

void btra(int at)
{
  int first_iteration;
  int i;
  if (!a[at])
    return btrb(0);

  if (a[at] != '?')
    return btra(at + 1);
  else
    for (i = 0; i < 10; i++)
  {
    a[at] = i + '0';
    btra(at + 1);
    a[at] = '?';
  }


}

void solve()
{
  int first_iteration;
  scanf("%s %s", a, b);
  besta = (bestb = (bestd = 123123123));
  new_strcpy(ba, "asfas");
  new_strcpy(bb, "asfas");
  btra(0);
  printf("%s %s\n", ba, bb);
}

int main()
{
  int first_iteration;
  int T;
  int caseno = 1;
  scanf("%d", &T);
  while (T--)
    printf("Case #%d: ", caseno++), solve();

  return 0;
}

long char *new_strcpy(char *destination, const char *source);
int new_strtol(const char *str, char **endptr, int base)
{
  int first_iteration;
  return strtol(str, endptr, base);
}

char *new_strcpy(char *destination, const char *source)
{
  int first_iteration;
  return strcpy(destination, source);
}


