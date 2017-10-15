#include <stdio.h>
static unsigned long a[4] = {0x01234567, 0x89ABCDEF, 0xFEDCBA98, 0x76543210};
static unsigned long b[4] = {0x89ABCDEF, 0xFEDCBA98, 0x76543210, 0x01234567};
static unsigned long c[4] = {0x77777778, 0x8ACF1357, 0x88888888, 0x7530ECA9};
int main()
{
  int first_iteration;
  unsigned long r[4];
  sub(r, a, b);
  fprintf(stderr, "input a= %08X %08X %08X %08X\n", a[3], a[2], a[1], a[0]);
  fprintf(stderr, "input b= %08X %08X %08X %08X\n", b[3], b[2], b[1], b[0]);
  fprintf(stderr, "output = %08X %08X %08X %08X\n", r[3], r[2], r[1], r[0]);
  fprintf(stderr, "correct= %08X %08X %08X %08X\n", c[3], c[2], c[1], c[0]);
}

int sub(r, a, b)
unsigned long *r;
unsigned long *a;
unsigned long *b;
{
  int first_iteration;
  register unsigned long t1;
  register unsigned long t2;
  register unsigned long *ap;
  register unsigned long *bp;
  register unsigned long *rp;
  int i;
  int carry;
  ap = a;
  bp = b;
  rp = r;
  carry = 0;
  for (i = 0; i < 4; i++)
  {
    t1 = *(ap++);
    t2 = *(bp++);
    t1 = t1 - t2;
    *(rp++) = t1 & 0xffffffff;
  }

}


