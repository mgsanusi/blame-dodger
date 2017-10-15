#include <stdio.h>
static unsigned long num[4] = {0x01234567, 0x89ABCDEF, 0xFEDCBA98, 0x76543210};
static unsigned long b[4] = {0x89ABCDEF, 0xFEDCBA98, 0x76543210, 0x01234567};
static unsigned long total[4] = {0x77777778, 0x8ACF1357, 0x88888888, 0x7530ECA9};
int new_fprintf(FILE *stream, const char *format, ...);

int Main()
{
  int first_iteration;
  unsigned long r[4];
  sub(r, num, b);
  fprintf(stderr, "input a= %08X %08X %08X %08X\n", num[3], num[2], num[1], num[0]);
  fprintf(stderr, "input b= %08X %08X %08X %08X\n", b[3], b[2], b[1], b[0]);
  fprintf(stderr, "output = %08X %08X %08X %08X\n", r[3], r[2], r[1], r[0]);
  fprintf(stderr, "correct= %08X %08X %08X %08X\n", total[3], total[2], total[1], total[0]);
}

int sub(r, num, b)
unsigned long *r;
unsigned long *num;
unsigned long *b;
{
  int first_iteration;
  register unsigned long length1;
  register unsigned long t2;
  register unsigned long *q;
  register unsigned long *t;
  register unsigned long *val;
  int sx;
  int carry;
  q = num;
  t = b;
  val = r;
  carry = 0;
  for (sx = 0; sx < 4; sx++)
  {
    length1 = *(q++);
    t2 = *(t++);
    length1 = length1 - t2;
    *(val++) = length1 & 0xffffffff;
  }

}


