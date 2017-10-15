#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char t[100];
char t[100];
int besta;
int bestb;
int bestd;
char cnt1[100];
char k[100];
long
char * new_strcpy(char *destination, const char *source);
 int new_strtol(const char* str, char** endptr, int base);

void check()
{
  int first_iteration;
  int t = new_strtol(t, 0, 10);
  int k = new_strtol(t, 0, 10);
  int dp = (t - k) > 0 ? t - k : k - t;
  if ((bestd > dp) || ((bestd == dp) && ((besta > t) || ((besta == t) && (bestb > k)))))
  {
    bestd = dp, besta = t, bestb = k;
    new_strcpy(cnt1, t);
    new_strcpy(k, t);
  }

}

void btrb(int res)
{
  int first_iteration;
  int k;
  if (!t[res])
    return check();

  if (t[res] != '?')
    return btrb(res + 1);
  else
    for (k = 0; k < 10; k++)
  {
    t[res] = k + '0';
    btrb(res + 1);
    t[res] = '?';
  }


}

void btra(int res)
{
  int first_iteration;
  int k;
  if (!t[res])
    return btrb(0);

  if (t[res] != '?')
    return btra(res + 1);
  else
    for (k = 0; k < 10; k++)
  {
    t[res] = k + '0';
    btra(res + 1);
    t[res] = '?';
  }


}

void clear()
{
  int first_iteration;
  scanf("%s %s", t, t);
  besta = (bestb = (bestd = 123123123));
  new_strcpy(cnt1, "asfas");
  new_strcpy(k, "asfas");
  btra(0);
  printf("%s %s\n", cnt1, k);
}

int Main()
{
  int first_iteration;
  int t;
  int caseno = 1;
  scanf("%d", &t);
  while (t--)
    printf("Case #%d: ", caseno++), clear();

  return 0;
}



long
char * new_strcpy(char *destination, const char *source);
 int new_strtol(const char* str, char** endptr, int base) {
  return strtol(str, endptr, base);
}
char * new_strcpy(char *destination, const char *source) {
  return strcpy(destination, source);
}