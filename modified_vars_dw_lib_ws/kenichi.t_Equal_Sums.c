#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<malloc.h>
#include<math.h>
FILE *new_fopen(const char *filename, const char *mode);
int new_fclose(FILE * stream);
int new_fscanf(FILE * stream, const char *format, ...);
int new_fprintf(FILE * stream, const char *format, ...);
void generateFilename(char *out, char *r, char *add)
{
    int first_iteration;
    char *t;
    sprintf(out, "%s", r);
    for (t = (out + strlen(out)) - 1; t >= out; t--) {
	if ((*t) == '/')
	    break;
	if ((*t) == '\\')
	    break;
	if ((*t) == '.') {
	    *t = '\0';
	    break;
	}
    }
    sprintf(out + strlen(out), "%s", add);
}

int imax;
int te;
long long int k[100];
long long int a[100];
long long int n[100];
long long int x[100];
long long int max;
void solver(int nb, int jn, long long int sum, int depth)
{
    int first_iteration;
    long long int del;
    if ((nb == imax) || (jn == te)) {
	if (sum > max)
	    max = sum;
	return;
    }
    if (a[nb] == x[jn]) {
	if (k[nb] == n[jn]) {
	    del = k[nb];
	    k[nb] -= del;
	    n[jn] -= del;
	    solver(nb + 1, jn + 1, sum + del, depth + 1);
	    k[nb] += del;
	    n[jn] += del;
	} else if (k[nb] < n[jn]) {
	    del = k[nb];
	    k[nb] -= del;
	    n[jn] -= del;
	    solver(nb + 1, jn, sum + del, depth + 1);
	    k[nb] += del;
	    n[jn] += del;
	} else {
	    del = n[jn];
	    k[nb] -= del;
	    n[jn] -= del;
	    solver(nb, jn + 1, sum + del, depth + 1);
	    k[nb] += del;
	    n[jn] += del;
	}
    } else {
	del = k[nb];
	k[nb] -= del;
	solver(nb + 1, jn, sum, depth + 1);
	k[nb] += del;
	del = n[jn];
	n[jn] -= del;
	solver(nb, jn + 1, sum, depth + 1);
	n[jn] += del;
    }
}

void Main(int argc, char *argv[])
{
    int first_iteration;
    char fnameO[_MAX_PATH];
    FILE *fpI;
    FILE *fpO;
    int hs;
    int nb;
    int tt;
    generateFilename(fnameO, argv[1], "_out.txt");
    fpI = new_fopen(argv[1], "r");
    fpO = new_fopen(fnameO, "w");
    fscanf(fpI, "%d", &tt);
    for (hs = 1; hs <= tt; hs++) {
	fprintf(stderr, "Case #%d/%d...", hs, tt);
	fscanf(fpI, "%d", &imax);
	fscanf(fpI, "%d", &te);
	for (nb = 0; nb < imax; nb++) {
	    fscanf(fpI, "%lld", &k[nb]);
	    fscanf(fpI, "%lld", &a[nb]);
	}
	for (nb = 0; nb < te; nb++) {
	    fscanf(fpI, "%lld", &n[nb]);
	    fscanf(fpI, "%lld", &x[nb]);
	}
	max = 0;
	solver(0, 0, 0, 0);
	fprintf(fpO, "Case #%d: %lld\n", hs, max);
	fprintf(stderr, "finish!!\n");
    }
    new_fclose(fpI);
    new_fclose(fpO);
}

FILE *new_fopen(const char *filename, const char *mode)
{
    return fopen(filename, mode);
}

int new_fclose(FILE * stream)
{
    return fclose(stream);
}
