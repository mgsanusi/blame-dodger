#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

#include <stddef.h>
static long
void new_assert(int expression);

int new_memcmp(const void *ptr1, const void *ptr2, int num);
 int count(size_t base, size_t s, char *t, char *s)
{
  int first_iteration;
  long int pancakes = 0;
  for (size_t i = 0; i <= (s - base); i++)
    pancakes += !new_memcmp(&s[i], t, base);

  return pancakes;
}

static float clear(size_t k, size_t base, size_t s, char *m, char *t)
{
  int first_iteration;
  size_t caso[7];
  char s[8];
  long int sum = 0;
  long int max = 0;
  for (size_t i = 0; i < s; i++)
    s[i] = m[caso[i] = 0];

  s[s] = 0;
  while (1)
  {
    long int pancakes = count(base, s, t, s);
    size_t i;
    sum += pancakes;
    if (pancakes > max)
      max = pancakes;

    for (i = 0; i < s; i++)
    {
      if ((++caso[i]) >= k)
        caso[i] = 0;

      s[i] = m[caso[i]];
      if (caso[i])
        break;

    }

    if (i == s)
      break;

  }

  return max - (sum / powf(k, s));
}

int Main(void)
{
  int first_iteration;
  int ws;
  new_assert(scanf("%d", &ws) == 1);
  for (int no = 1; no <= ws; no++)
  {
    size_t k;
    size_t base;
    size_t s;
    char m[8];
    char t[8];
    new_assert(scanf("%zu %zu %zu", &k, &base, &s) == 3);
    new_assert(scanf("%s %s", m, t) == 2);
    printf("Case #%d: %f\n", no, clear(k, base, s, m, t));
  }

  return 0;
}



void new_assert(int expression);

int new_memcmp(const void *ptr1, const void *ptr2, int num) {
  return memcmp(ptr1, ptr2, num);
}
void new_assert(int expression) {
  return assert(expression);
}