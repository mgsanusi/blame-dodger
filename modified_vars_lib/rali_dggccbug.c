#include <stdio.h>
void inc(tag)
int *tag;
{
  (*tag)++;
}

int Main()
{
  int c = 0;
  while (c < 3)
  {
    fprintf(stderr, "%08X\n", c);
    inc(&c);
  }

}


