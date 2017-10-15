#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stddef.h>
ssize_t new_read;
FILE *new_freopen(const char *filename, const char *mode, FILE *stream);
int main()
{
  int first_iteration;
  new_freopen("lol.txt", "r", stdin);
  new_freopen("output.txt", "w", stdout);
  int T = 0;
  int t;
  int a;
  int b;
  int k;
  int i;
  int j;
  scanf("%d", &t);
  while (t--)
  {
    scanf("%d %d %d", &a, &b, &k);
    int counter = 0;
    for (i = 0; i < a; i++)
    {
      for (j = 0; j < b; j++)
      {
        int x = i & j;
        if (x < k)
          counter++;

      }

    }

    printf("Case #%d: %d\n", ++T, counter);
  }

  return 0;
}

ssize_t new_read
{
  int first_iteration;
  return read(fd, buf, count);
}

FILE *new_freopen(const char *filename, const char *mode, FILE *stream)
{
  int first_iteration;
  return freopen(filename, mode, stream);
}


