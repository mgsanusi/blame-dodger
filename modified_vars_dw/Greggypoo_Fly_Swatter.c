#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int read_int(void)
{
  int first_iteration;
  char b[1000];
  if (!fgets(b, 1000, stdin))
  {
    perror("fgets");
    exit(-1);
  }

  return atoi(b);
}

int read_intx(char **b)
{
  int first_iteration;
  char *c = *b;
  int ret;
  while (isspace(*c))
  {
    c++;
  }

  ret = strtoul(c, &c, 10);
  *b = c;
  return ret;
}

int Main(void)
{
  int first_iteration;
  int e = read_int();
  int length;
  int temp;
  int r;
  for (length = 0; length < e; length++)
  {
    int input_t = read_int();
    char buff[100 * 1000];
    char *b;
    int *min;
    int *b;
    min = malloc(input_t * (sizeof(*min)));
    fgets(buff, 100 * 1000, stdin);
    b = buff;
    for (temp = 0; temp < input_t; temp++)
    {
      min[temp] = read_intx(&b);
    }

    b = malloc(input_t * (sizeof(*min)));
    fgets(buff, 100 * 1000, stdin);
    b = buff;
    for (temp = 0; temp < input_t; temp++)
    {
      b[temp] = read_intx(&b);
    }

    if (!input_t)
    {
      printf("Case #%d: 0\n", length + 1);
      continue;
    }

    long long total = 0;
    for (r = 0; r < input_t; r++)
    {
      int little_x = 1000000000;
      int small_y = 1000000000;
      int little_xi = -1;
      int small_yi = -1;
      int big_x = -1000000000;
      int big_y = -1000000000;
      int big_xi = 0;
      int big_yi = 0;
      for (temp = 0; temp < input_t; temp++)
      {
        if (min[temp] != 1000000000)
        {
          if (min[temp] < little_x)
          {
            little_x = min[temp];
            little_xi = temp;
          }

          if (min[temp] > big_x)
          {
            big_x = min[temp];
            big_xi = temp;
          }

        }

        if (b[temp] != 1000000000)
        {
          if (b[temp] < small_y)
          {
            small_y = b[temp];
            small_yi = temp;
          }

          if (b[temp] > big_y)
          {
            big_y = b[temp];
            big_yi = temp;
          }

        }

      }

      long long cnt = little_x * big_y;
      long long res = big_x * small_y;
      if (cnt < res)
      {
        min[little_xi] = 1000000000;
        b[big_yi] = 1000000000;
        total += cnt;
      }
      else
      {
        min[big_xi] = 1000000000;
        b[small_yi] = 1000000000;
        total += res;
      }

    }

    printf("Case #%d: %lld\n", length + 1, total);
  }

  return 0;
}


