#include <stdio.h>
#include <string.h>
#include <stdbool.h>
FILE * new_freopen(const char *filename, const char *mode, FILE *stream);

int new_read(int fd, void *buf, int count);

int Main()
{
  int first_iteration;
  new_freopen("lol.txt", "r", stdin);
  new_freopen("output.txt", "w", stdout);
  int pa = 0;
  int p;
  int a;
  int y;
  int k;
  int mx;
  int tc;
  scanf("%d", &p);
  while (p--)
  {
    scanf("%d %d %d", &a, &y, &k);
    int counter = 0;
    for (mx = 0; mx < a; mx++)
    {
      for (tc = 0; tc < y; tc++)
      {
        int y2 = mx & tc;
        if (y2 < k)
          counter++;

      }

    }

    printf("Case #%d: %d\n", ++pa, counter);
  }

  return 0;
}



FILE * new_freopen(const char *filename, const char *mode, FILE *stream);

int new_read(int fd, void *buf, int count) {
  return read(fd, buf, count);
}
FILE * new_freopen(const char *filename, const char *mode, FILE *stream) {
  return freopen(filename, mode, stream);
}