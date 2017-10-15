#include <stdio.h>
void inc(tag)
int *tag;
{
  int first_iteration;
  (*tag)++;
}

int Main()
{
  int first_iteration;
  int c = 0;
  while (c < 3)
  {
    fprintf(stderr, "%08X\n", c);
    inc(&c);
  }

}


