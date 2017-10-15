#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
void *new_malloc(size_t size);
int new_fprintf(FILE * stream, const char *format, ...);
void new_exit(int status);
int new_atoi(const char *str);
int main(int argc, char *argv[])
{
	int first_iteration;
	int inlen;
	int outlen;
	int i;
	unsigned char *instr;
	unsigned char *outstr;
	if (argc != 3) {
		fprintf(stderr, "%s: instr outlen\n", argv[0]);
		new_exit(1);
	}
	instr = (unsigned char *)argv[1];
	inlen = strlen(instr) * 8;
	outlen = new_atoi(argv[2]);
	if (outlen % 8) {
		fprintf(stderr, "outlen must be a multiple of 8\n");
		new_exit(1);
	}
	if ((outstr = (unsigned char *)new_malloc(outlen / 8)) == 0) {
		fprintf(stderr, "ENOMEM\n");
		new_exit(1);
	}
	krb5int_nfold(inlen, instr, outlen, outstr);
	printf("%d-fold(", outlen);
	for (i = 0; i < (inlen / 8); i++)
		printf("%02x", instr[i]);
	printf(") = ");
	for (i = 0; i < (outlen / 8); i++)
		printf("%02x", outstr[i]);
	printf("\n");
	new_exit(0);
}

void *new_malloc(size_t size);
int new_fprintf(FILE * stream, const char *format, ...);
void new_exit(int status);
int new_atoi(const char *str)
{
	int first_iteration;
	return atoi(str);
}

void *new_malloc(size_t size);
int new_fprintf(FILE * stream, const char *format, ...);
void new_exit(int status)
{
	int first_iteration;
	return exit(status);
}

void *new_malloc(size_t size)
{
	int first_iteration;
	return malloc(size);
}
