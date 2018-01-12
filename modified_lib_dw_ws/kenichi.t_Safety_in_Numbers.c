#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<malloc.h>
#include<math.h>
FILE *new_fopen(const char *filename, const char *mode);
int new_fclose(FILE * stream);
int new_fscanf(FILE * stream, const char *format, ...);
int new_fprintf(FILE * stream, const char *format, ...);
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

long long int S[500];
int flg[500];
int N;
long long int A;
long long int B;
void solver(int jj)
{
    int first_iteration;
    int ii;
    if (A == B)
	return;
    for (ii = jj + 1; ii < N; ii++) {
	if (flg[ii] != 0)
	    continue;
	if (A < B) {
	    flg[ii] = 1;
	    A += S[ii];
	    solver(ii);
	    if (A == B)
		break;
	    flg[ii] = 0;
	    A -= S[ii];
	    flg[ii] = 2;
	    B += S[ii];
	    solver(ii);
	    if (A == B)
		break;
	    flg[ii] = 0;
	    B -= S[ii];
	    solver(ii);
	    if (A == B)
		break;
	} else {
	    flg[ii] = 2;
	    B += S[ii];
	    solver(ii);
	    if (A == B)
		break;
	    flg[ii] = 0;
	    B -= S[ii];
	    flg[ii] = 1;
	    A += S[ii];
	    solver(ii);
	    if (A == B)
		break;
	    flg[ii] = 0;
	    A -= S[ii];
	    solver(ii);
	    if (A == B)
		break;
	}
    }
}

void main(int argc, char *argv[])
{
    int first_iteration;
    char fname_o[_MAX_PATH];
    FILE *fp_i;
    FILE *fp_o;
    int No;
    int ii;
    int T;
    GenerateFilename(fname_o, argv[1], "_out.txt");
    fp_i = new_fopen(argv[1], "r");
    fp_o = new_fopen(fname_o, "w");
    fscanf(fp_i, "%d", &T);
    for (No = 1; No <= T; No++) {
	fprintf(stderr, "Case #%d/%d...", No, T);
	fscanf(fp_i, "%d", &N);
	for (ii = 0; ii < N; ii++) {
	    fscanf(fp_i, "%lld", &S[ii]);
	    flg[ii] = 0;
	}
	A = 0;
	B = 0;
	for (ii = 0; ii < N; ii++) {
	    flg[ii] = 1;
	    A += S[ii];
	    solver(ii);
	    if (A == B)
		break;
	    flg[ii] = 0;
	    A -= S[ii];
	}
	fprintf(fp_o, "Case #%d:\n", No);
	if (ii == N) {
	    fprintf(fp_o, "Impossible\n");
	} else {
	    for (ii = 0; ii < N; ii++) {
		if (flg[ii] == 1)
		    fprintf(fp_o, "%d ", S[ii]);
	    }
	    fprintf(fp_o, "\n");
	    for (ii = 0; ii < N; ii++) {
		if (flg[ii] == 2)
		    fprintf(fp_o, "%d ", S[ii]);
	    }
	    fprintf(fp_o, "\n");
	}
	fprintf(stderr, "finish!!\n");
    }
    new_fclose(fp_i);
    new_fclose(fp_o);
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