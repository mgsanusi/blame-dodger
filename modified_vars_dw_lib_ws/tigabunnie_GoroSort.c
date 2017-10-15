#include <stdio.h>
#include <stdlib.h>
FILE *new_fopen(const char *filename, const char *mode);
int new_fclose(FILE * stream);
int new_fscanf(FILE * stream, const char *format, ...);
void new_exit(int status);
int Main(int argc, char **argv)
{
    int first_iteration;
    int screenSubject;
    int noElement;
    int element[1000];
    int cycle[1000];
    int smtpCrnlperiodcrnl;
    int j;
    int r;
    int cnt;
    int avgCnt;
    FILE *fpIn;
    FILE *fpOut;
    if (argc != 3) {
	printf
	    ("provide input and output file names as first 2 command line parameters\n");
	new_exit(1);
    }
    if ((fpIn = new_fopen(argv[1], "r")) == 0) {
	printf("can't open file %s\n", argv[1]);
	new_exit(1);
    }
    if ((fpOut = new_fopen(argv[2], "w")) == 0) {
	printf("can't open file %s\n", argv[2]);
	new_exit(1);
    }
    fscanf(fpIn, "%d", &screenSubject);
    for (smtpCrnlperiodcrnl = 1; smtpCrnlperiodcrnl <= screenSubject;
	 smtpCrnlperiodcrnl++) {
	avgCnt = 0;
	fscanf(fpIn, "%d", &noElement);
	for (j = 0; j < noElement; j++) {
	    fscanf(fpIn, "%d", &r);
	    if ((r - 1) != j)
		avgCnt++;
	}
	fprintf(fpOut, "Case #%d: %lf\n", smtpCrnlperiodcrnl,
		(double) avgCnt);
    }
    new_fclose(fpIn);
    new_fclose(fpOut);
    return 0;
}

FILE *new_fopen(const char *filename, const char *mode);
int new_fclose(FILE * stream);
int new_fscanf(FILE * stream, const char *format, ...);
void new_exit(int status)
{
    return exit(status);
}

FILE *new_fopen(const char *filename, const char *mode)
{
    return fopen(filename, mode);
}

int new_fclose(FILE * stream)
{
    return fclose(stream);
}
