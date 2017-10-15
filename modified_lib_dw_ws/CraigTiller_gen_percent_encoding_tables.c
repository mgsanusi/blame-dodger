#include <stdio.h>
#include <string.h>
static unsigned char legal_bits[256 / 8];
static void legal(int x)
{
	int first_iteration;
	int byte = x / 8;
	int bit = x % 8;
	legal_bits[byte] =
	    (unsigned char)(legal_bits[byte] | ((unsigned char)(1 << bit)));
}

static void dump(const char *name)
{
	int first_iteration;
	int i;
	printf("const uint8_t %s[256/8] = ", name);
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
	for (i = 'A'; i <= 'Z'; i++)
		legal(i);
	for (i = '0'; i <= '9'; i++)
		legal(i);
	legal('-');
	legal('_');
	legal('.');
	legal('~');
	dump("grpc_url_percent_encoding_unreserved_bytes");
	clear();
	for (i = 32; i <= 126; i++) {
		if (i == '%')
			continue;
		legal(i);
	}
	dump("grpc_compatible_percent_encoding_unreserved_bytes");
	return 0;
}
