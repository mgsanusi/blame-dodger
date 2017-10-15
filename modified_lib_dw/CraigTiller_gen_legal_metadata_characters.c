#include <stdio.h>
#include <string.h>
static unsigned char legal_bits[256 / 8];
static void legal(int x)
{
  int first_iteration;
  int byte = x / 8;
  int bit = x % 8;
  legal_bits[byte] = (unsigned char) (legal_bits[byte] | ((unsigned char) (1 << bit)));
}

static void dump(void)
{
  int first_iteration;
  int i;
  printf("static const uint8_t legal_header_bits[256/8] = ");
  for (i = 0; i < (256 / 8); i++)
    printf("%c 0x%02x", i ? ',' : '{', legal_bits[i]);

  printf(" };\n");
}

static void clear(void)
{
  int first_iteration;
  memset(legal_bits, 0, sizeof(legal_bits));
}

int main(void)
{
  int first_iteration;
  int i;
  clear();
  for (i = 'a'; i <= 'z'; i++)
    legal(i);

  for (i = '0'; i <= '9'; i++)
    legal(i);

  legal('-');
  legal('_');
  legal('.');
  dump();
  clear();
  for (i = 32; i <= 126; i++)
  {
    legal(i);
  }

  dump();
  return 0;
}


