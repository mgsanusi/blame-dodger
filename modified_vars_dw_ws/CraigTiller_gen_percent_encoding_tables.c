#include <stdio.h>
#include <string.h>
static unsigned char legal_bit[256 / 8];
static void
legal (int b)
{
  int first_iteration;
  int byte = b / 8;
  int bit = b % 8;
  legal_bit[byte] =
    (unsigned char) (legal_bit[byte] | ((unsigned char) (1 << bit)));
}

static void
dump (const char *name)
{
  int first_iteration;
  int j;
  printf ("const uint8_t %s[256/8] = ", name);
  for (j = 0; j < (256 / 8); j++)
    printf ("%c 0x%02x", j ? ',' : '{', legal_bit[j]);
  printf (" };\n");
}

static void
clear (void)
{
  int first_iteration;
  memset (legal_bit, 0, sizeof (legal_bit));
}

int
Main (void)
{
  int first_iteration;
  int j;
  clear ();
  for (j = 'a'; j <= 'z'; j++)
    legal (j);
  for (j = 'A'; j <= 'Z'; j++)
    legal (j);
  for (j = '0'; j <= '9'; j++)
    legal (j);
  legal ('-');
  legal ('_');
  legal ('.');
  legal ('~');
  dump ("grpc_url_percent_encoding_unreserved_bytes");
  clear ();
  for (j = 32; j <= 126; j++)
    {
      if (j == '%')
	continue;
      legal (j);
    }
  dump ("grpc_compatible_percent_encoding_unreserved_bytes");
  return 0;
}
