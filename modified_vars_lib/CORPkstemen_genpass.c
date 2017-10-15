#include <stdio.h>
#include <stdlib.h>
int new_atoi(const char *str);

void Main(int argc, char **argv)
{
  int pl;
  int res;
  int p;
  char *pass[8];
  char t;
  p = new_atoi(argv[1]);
  srandom(101173);
  for (pl = 0; pl < p; pl++)
  {
    for (res = 0; res < 8; res++)
    {
      t = random() % 122;
      while (t < 48)
        t += random() % (122 - t);

      printf("%c", t);
    }

    printf("\n");
  }

}



int new_atoi(const char *str) {
  return atoi(str);
}