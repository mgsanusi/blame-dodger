#include <stdio.h>
#include <stdlib.h>
void Main(int argc, char **argv)
{
  int pl;
  int res;
  int p;
  char *pass[8];
  char t;
  p = atoi(argv[1]);
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


