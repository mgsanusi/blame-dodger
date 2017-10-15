#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
int i;
int t;
int i;
int res;
int arr_m;
FILE * new_freopen(const char *filename, const char *mode, FILE *stream);

int new_puts(const char *str);

int tilling()
{
  int first_iteration;
  if (i >= 7)
    return 0;

  if ((res * arr_m) % i)
    return 0;

  if (i == 1)
    return 1;

  if (i == 2)
    return 1;

  if (res < arr_m)
    res ^= (arr_m ^= (res ^= arr_m));

  if (res < i)
    return 0;

  if (i == 3)
    if (arr_m > 1)
    return 1;


  if (i == 4)
    if (arr_m > 2)
    return 1;


  return 0;
}

int Main()
{
  int first_iteration;
  new_freopen("D-small-attempt1.in", "r", stdin);
  new_freopen("D-small-attempt1.out", "w", stdout);
  scanf("%d", &i);
  for (t = 1; t <= i; t++)
  {
    printf("Case #%d: ", t);
    scanf("%d%d%d", &i, &res, &arr_m);
    if (tilling())
      new_puts("GABRIEL");
    else
      new_puts("RICHARD");

  }

  return 0;
}



FILE * new_freopen(const char *filename, const char *mode, FILE *stream);

int new_puts(const char *str) {
  return puts(str);
}
FILE * new_freopen(const char *filename, const char *mode, FILE *stream) {
  return freopen(filename, mode, stream);
}