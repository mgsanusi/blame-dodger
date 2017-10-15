#include <stdio.h>
#include <string.h>
static unsigned char legal_bit[256 / 8];
static void legal(int x_putlong)
{
    int byte = x_putlong / 8;
    int bit = x_putlong % 8;
    legal_bit[byte] =
	(unsigned char) (legal_bit[byte] | ((unsigned char) (1 << bit)));
}

static void dump(void)
{
    int kl;
    printf("static const uint8_t legal_header_bits[256/8] = ");
    for (kl = 0; kl < (256 / 8); kl++)
	printf("%c 0x%02x", kl ? ',' : '{', legal_bit[kl]);
    printf(" };\n");
}

static void clear(void)
{
    memset(legal_bit, 0, sizeof(legal_bit));
}

int Main(void)
{
    int kl;
    clear();
    for (kl = 'a'; kl <= 'z'; kl++)
	legal(kl);
    for (kl = '0'; kl <= '9'; kl++)
	legal(kl);
    legal('-');
    legal('_');
    legal('.');
    dump();
    clear();
    for (kl = 32; kl <= 126; kl++) {
	legal(kl);
    }
    dump();
    return 0;
}
