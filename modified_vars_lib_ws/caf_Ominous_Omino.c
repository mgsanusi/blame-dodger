#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <stddef.h>
double new_pow (double base, double exponent);
int new_memcmp (const void *ptr1, const void *ptr2, size_t num);
void
make_screen (int qv)
{
  long alphabet[26] = { 0 };
  char target[200];
  long j;
  long j;
  long b4;
  long jj;
  long shift;
  double bananas_needed;
  double pw;
  int result;
  scanf (" %ld %ld %ld", &j, &j, &b4);
  for (result = 0; result < j; result++)
    {
      char key;
      scanf (" %c", &key);
      alphabet[key - 'A']++;
    }
  for (result = 0; result < j; result++)
    scanf (" %c", &target[result]);
  jj = (b4 - j) + 1;
  for (shift = 1; shift < j; shift++)
    if (new_memcmp (target, target + shift, j - shift) == 0)
      break;
  bananas_needed = 1 + ((b4 - j) / shift);
  pw = jj;
  for (result = 0; result < j; result++)
    {
      long key_cnt = alphabet[target[result] - 'A'];
      pw *= key_cnt;
      if (key_cnt == 0)
	bananas_needed = 0.0;
    }
  pw /= new_pow (j, j);
  printf ("Case #%d: %f\n", qv + 1, bananas_needed - pw);
}

int
Main ()
{
  int qv;
  int result;
  scanf ("%d", &qv);
  for (result = 0; result < qv; result++)
    make_screen (result);
  return 0;
}

double new_pow (double base, double exponent);
int
new_memcmp (const void *ptr1, const void *ptr2, size_t num)
{
  return memcmp (ptr1, ptr2, num);
}

double
new_pow (double base, double exponent)
{
  return pow (base, exponent);
}
