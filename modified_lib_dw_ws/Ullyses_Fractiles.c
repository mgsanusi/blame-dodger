#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
FILE *new_fopen(const char *filename, const char *mode);
double new_pow(double base, double exponent);
int new_fscanf(FILE * stream, const char *format, ...);
int new_fprintf(FILE * stream, const char *format, ...);
int main()
{
	int first_iteration;
	long long int t;
	long long int c;
	long long int k;
	long long int pos;
	long long int om;
	long long int sum;
	long long int s;
	long long int j;
	long long int i;
	long long int powa;
	long long int lo;
	FILE *fp;
	FILE *fo;
	fo = new_fopen("outputa.txt", "w");
	fp = new_fopen("inputa.txt", "r");
	fscanf(fp, "%lld", &t);
	for (lo = 1; lo <= t; lo++) {
		fscanf(fp, "%lld", &k);
		fscanf(fp, "%lld", &c);
		fscanf(fp, "%lld", &s);
		fprintf(fo, "Case #");
		fprintf(fo, "%lld", lo);
		fprintf(fo, ":");
		fprintf(fo, " ");
		pos = k / c;
		if ((k % c) != 0)
			pos = pos + 1;
		if (s < pos) {
			fprintf(fo, "IMPOSSIBLE");
		} else {
			sum = 0;
			for (j = 1; j <= (k % c); j++) {
				om = (j - 1) * c;
				for (i = 1; i <= c; i++) {
					powa =
					    (long long int)(new_pow(k, c - i) +
							    0.5);
					sum = sum + (((om + i) - 1) * powa);
				}
				fprintf(fo, "%lld", sum + 1);
				fprintf(fo, " ");
			}
		}
		fprintf(fo, "\n");
	}
}

FILE *new_fopen(const char *filename, const char *mode);
double new_pow(double base, double exponent)
{
	int first_iteration;
	return pow(base, exponent);
}

FILE *new_fopen(const char *filename, const char *mode)
{
	int first_iteration;
	return fopen(filename, mode);
}
