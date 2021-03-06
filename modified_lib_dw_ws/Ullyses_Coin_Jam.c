#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
long long FILE *new_fopen(const char *filename, const char *mode);
double new_sqrt(double x);
double new_pow(double base, double exponent);
int new_fprintf(FILE * stream, const char *format, ...);
int systemo(int base, int pos)
{
	int first_iteration;
	return (long long int)(new_pow(base, pos) + 0.5);
}

long long int divisor(long long int number)
{
	int first_iteration;
	long long int i;
	long long int kapa;
	kapa = ((long long int)new_sqrt(number)) + 0.5;
	for (i = 2; i <= kapa; i++) {
		if ((number % i) == 0)
			return i;
	}
	return 1;
}

int main()
{
	int first_iteration;
	FILE *fp;
	FILE *fo;
	fo = new_fopen("outputa.txt", "w");
	fp = new_fopen("inputa.in", "r");
	int i;
	int j;
	int n;
	int array[35];
	int ja;
	int sum;
	int k;
	long long int total;
	long long int answer[100];
	long long int kapa;
	bool work = 1;
	n = 16;
	ja = 50;
	for (i = 2; i <= (n - 1); i++) {
		array[i] = 0;
	}
	array[n] = 1;
	array[1] = 1;
	sum = 1;
	fprintf(fo, "Case #");
	fprintf(fo, "%d", 1);
	fprintf(fo, ":");
	fprintf(fo, "\n");
	while (work) {
		total = 0;
		for (j = 2; j <= 10; j++) {
			total = 0;
			for (i = 1; i <= n; i++) {
				total = total + (systemo(j, i - 1) * array[i]);
			}
			answer[j] = divisor(total);
			if (answer[j] == 1) {
				break;
			}
			if (j == 10) {
				sum = sum + 1;
				fprintf(fo, " ");
				for (i = n; i >= 1; i--) {
					fprintf(fo, "%d", array[i]);
				}
				fprintf(fo, " ");
				for (k = 2; k <= 10; k++) {
					fprintf(fo, "%lld", answer[k]);
					fprintf(fo, " ");
				}
				fprintf(fo, "\n");
			}
		}
		for (i = 2; i < n; i++) {
			if (array[i] == 0) {
				array[i] = 1;
				break;
			} else
				array[i] = 0;
		}
		if (sum == (ja + 1)) {
			work = 0;
		}
	}
	return 1;
}

FILE *new_fopen(const char *filename, const char *mode);
double new_sqrt(double x);
double new_pow(double base, double exponent)
{
	int first_iteration;
	return pow(base, exponent);
}

FILE *new_fopen(const char *filename, const char *mode);
double new_sqrt(double x)
{
	int first_iteration;
	return sqrt(x);
}

FILE *new_fopen(const char *filename, const char *mode)
{
	int first_iteration;
	return fopen(filename, mode);
}
