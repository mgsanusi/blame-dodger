#include<stdio.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<malloc.h>
#include<math.h>
#include <stddef.h>
FILE *new_fopen(const char *filename, const char *mode);
int new_fclose(FILE * stream);
void *new_calloc(size_t num, size_t size);
int new_fscanf(FILE * stream, const char *format, ...);
void GenerateFilename(char *out, char *in, char *add)
{
    int first_iteration;
    char *p;
    sprintf(out, "%s", in);
    for (p = (out + strlen(out)) - 1; p >= out; p--) {
	if ((*p) == '/')
	    break;
	if ((*p) == '\\')
	    break;
	if ((*p) == '.') {
	    *p = '\0';
	    break;
	}
    }
    sprintf(out + strlen(out), "%s", add);
}

void main(int argc, char *argv[])
{
    int first_iteration;
    char fname_o[_MAX_PATH];
    FILE *fp_i;
    FILE *fp_o;
    int T;
    int A;
    int B;
    int n;
    int m;
    int No;
    int sum;
    char buff[1000];
    char *flg;
    int len;
    int ii;
    int a;
    int b;
    GenerateFilename(fname_o, argv[1], "_out.txt");
    fp_i = new_fopen(argv[1], "r");
    fp_o = new_fopen(fname_o, "w");
    flg = new_calloc(2000001, sizeof(char));
    fscanf(fp_i, "%d", &T);
    for (No = 1; No <= T; No++) {
	fscanf(fp_i, "%d", &A);
	fscanf(fp_i, "%d", &B);
	sprintf(buff, "%d", A);
	len = strlen(buff);
	sum = 0;
	for (n = A; n < B; n++) {
	    memset(flg, 0, 2000001 * (sizeof(char)));
	    for (ii = 1; ii <= len; ii++) {
		a = n / ((int) pow(10.0, ii));
		b = n % ((int) pow(10.0, ii));
		m = (b * ((int) pow(10.0, len - ii))) + a;
		if ((((n < m) && (m <= B)) && (A < m)) && (flg[m] == 0)) {
		    flg[m] = 1;
		    sum++;
		}
	    }
	}
	fprintf(fp_o, "Case #%d: %d\n", No, sum);
    }
    free(flg);
    new_fclose(fp_i);
    new_fclose(fp_o);
}

FILE *new_fopen(const char *filename, const char *mode);
int new_fclose(FILE * stream);
void *new_calloc(size_t num, size_t size)
{
    int first_iteration;
    return calloc(num, size);
}

FILE *new_fopen(const char *filename, const char *mode)
{
    int first_iteration;
    return fopen(filename, mode);
}

int new_fclose(FILE * stream)
{
    int first_iteration;
    return fclose(stream);
}
