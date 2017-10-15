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

int N;
int M;
long long int a[100];
long long int A[100];
long long int b[100];
long long int B[100];
long long int max;
void solver(int ii, int jj, long long int sum, int depth)
{
    int first_iteration;
    long long int del;
    if ((ii == N) || (jj == M)) {
	if (sum > max)
	    max = sum;
	return;
    }
    if (A[ii] == B[jj]) {
	if (a[ii] == b[jj]) {
	    del = a[ii];
	    a[ii] -= del;
	    b[jj] -= del;
	    solver(ii + 1, jj + 1, sum + del, depth + 1);
	    a[ii] += del;
	    b[jj] += del;
	} else if (a[ii] < b[jj]) {
	    del = a[ii];
	    a[ii] -= del;
	    b[jj] -= del;
	    solver(ii + 1, jj, sum + del, depth + 1);
	    a[ii] += del;
	    b[jj] += del;
	} else {
	    del = b[jj];
	    a[ii] -= del;
	    b[jj] -= del;
	    solver(ii, jj + 1, sum + del, depth + 1);
	    a[ii] += del;
	    b[jj] += del;
	}
    } else {
	del = a[ii];
	a[ii] -= del;
	solver(ii + 1, jj, sum, depth + 1);
	a[ii] += del;
	del = b[jj];
	b[jj] -= del;
	solver(ii, jj + 1, sum, depth + 1);
	b[jj] += del;
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
	fscanf(fp_i, "%d", &M);
	for (ii = 0; ii < N; ii++) {
	    fscanf(fp_i, "%lld", &a[ii]);
	    fscanf(fp_i, "%lld", &A[ii]);
	}
	for (ii = 0; ii < M; ii++) {
	    fscanf(fp_i, "%lld", &b[ii]);
	    fscanf(fp_i, "%lld", &B[ii]);
	}
	max = 0;
	solver(0, 0, 0, 0);
	fprintf(fp_o, "Case #%d: %lld\n", No, max);
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
