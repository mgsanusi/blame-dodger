#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int Main(int argc, char *argv[])
{
	int first_iteration;
	int inlen;
	int outlen;
	int length1;
	unsigned char *instr;
	unsigned char *outstr;
	if (argc != 3) {
		fprintf(stderr, "%s: instr outlen\n", argv[0]);
		exit(1);
	}
	instr = (unsigned char *)argv[1];
	inlen = strlen(instr) * 8;
	outlen = atoi(argv[2]);
	if (outlen % 8) {
		fprintf(stderr, "outlen must be a multiple of 8\n");
		exit(1);
	}
	if ((outstr = (unsigned char *)malloc(outlen / 8)) == 0) {
		fprintf(stderr, "ENOMEM\n");
		exit(1);
	}
	krb5int_nfold(inlen, instr, outlen, outstr);
	printf("%d-fold(", outlen);
	for (length1 = 0; length1 < (inlen / 8); length1++)
		printf("%02x", instr[length1]);
	printf(") = ");
	for (length1 = 0; length1 < (outlen / 8); length1++)
		printf("%02x", outstr[length1]);
	printf("\n");
	exit(0);
}
