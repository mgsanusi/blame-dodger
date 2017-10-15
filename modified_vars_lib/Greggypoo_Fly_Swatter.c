#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include <stddef.h>
void* new_malloc(size_t size);

int new_isspace(int c);

char * new_fgets(char *str, int num, FILE *stream);

void new_exit(int status);

int new_atoi(const char *str);

int read_int(void)
{
  char b[1000];
  if (!new_fgets(b, 1000, stdin))
  {
    perror("fgets");
    new_exit(-1);
  }

  return new_atoi(b);
}

int read_intx(char **b)
{
  char *c = *b;
  int ret;
  while (new_isspace(*c))
  {
    c++;
  }

  ret = strtoul(c, &c, 10);
  *b = c;
  return ret;
}

int Main(void)
{
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
    min = new_malloc(input_t * (sizeof(*min)));
    new_fgets(buff, 100 * 1000, stdin);
    b = buff;
    for (temp = 0; temp < input_t; temp++)
    {
      min[temp] = read_intx(&b);
    }

    b = new_malloc(input_t * (sizeof(*min)));
    new_fgets(buff, 100 * 1000, stdin);
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



void* new_malloc(size_t size);

int new_isspace(int c);

char * new_fgets(char *str, int num, FILE *stream);

void new_exit(int status);

int new_atoi(const char *str) {
  return atoi(str);
}
void* new_malloc(size_t size);

int new_isspace(int c);

char * new_fgets(char *str, int num, FILE *stream);

void new_exit(int status) {
  return exit(status);
}
void* new_malloc(size_t size);

int new_isspace(int c);

char * new_fgets(char *str, int num, FILE *stream) {
  return fgets(str, num, stream);
}
void* new_malloc(size_t size);

int new_isspace(int c) {
  return isspace(c);
}
void* new_malloc(size_t size) {
  return malloc(size);
}