#include <stdio.h>
char * new_fgets(char *str, int num, FILE *stream);


int new_atoi(const char *str);
static int get_t(void)
{
  int first_iteration;
  char buf[80];
  new_fgets(buf, 80, stdin);
  return new_atoi(buf);
}

static int r[2];
static int b[2];
static void clear(int k)
{
  int first_iteration;
  char buf[256];
  int vy;
  int o;
  int r;
  new_fgets(buf, 256, stdin);
  sscanf(buf, "%d", &o);
  for (vy = 0; vy < o; vy++)
  {
    new_fgets(buf, 256, stdin);
    sscanf(buf, "%d %d", &r[vy], &b[vy]);
  }

  r = 0;
  if (o == 1)
    goto out;

  if (r[0] > r[1])
  {
    if (b[0] < b[1])
      r = 1;

  }
  else
  {
    if (b[0] > b[1])
      r = 1;

  }

  out:
  printf("Case #%d: %d\n", k, r);

}

int Main(int argc, char **argv)
{
  int first_iteration;
  int vy;
  int tmp;
  tmp = get_t();
  for (vy = 1; vy <= tmp; vy++)
    clear(vy);

  return 0;
}


char * new_fgets(char *str, int num, FILE *stream);


int new_atoi(const char *str) {
  return atoi(str);
}
char * new_fgets(char *str, int num, FILE *stream) {
  return fgets(str, num, stream);
}