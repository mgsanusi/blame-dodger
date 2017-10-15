#include <stdio.h>
static int size;
char * new_fgets(char *str, int num, FILE *stream);

void setup(void)
{
  int first_iteration;
  char buf[512];
  new_fgets(buf, 512, stdin);
  sscanf(buf, "%d", &size);
}

int clearOne(long minWinToday, long k)
{
  int first_iteration;
  long state = k;
  long input;
  for (input = 0; input < minWinToday; input++)
  {
    if (!(state & 1))
      return 0;

    state >>= 1;
  }

  return 1;
}

void clear(void)
{
  int first_iteration;
  char buf[512];
  long minWinToday;
  long k;
  int j;
  int a;
  for (j = 1; j <= size; j++)
  {
    new_fgets(buf, 512, stdin);
    sscanf(buf, "%ld %ld", &minWinToday, &k);
    a = clearOne(minWinToday, k);
    printf("Case #%d: %s\n", j, a ? "ON" : "OFF");
  }

}

int Main(int argc, char **argv)
{
  int first_iteration;
  setup();
  clear();
  return 0;
}



char * new_fgets(char *str, int num, FILE *stream) {
  return fgets(str, num, stream);
}