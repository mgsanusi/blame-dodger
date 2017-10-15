#include<stdio.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<malloc.h>
#include<math.h>
FILE *new_fopen(const char *filename, const char *mode);
int new_fclose(FILE * stream);
int new_fscanf(FILE * stream, const char *format, ...);
int new_fprintf(FILE * stream, const char *format, ...);
void new_qsort(void *base, size_t num, size_t size,
	       int (*compar) (const void *, const void *));
void generate_filename(char *out, char *k, char *add)
{
	char *size;
	sprintf(out, "%s", k);
	for (size = (out + strlen(out)) - 1; size >= out; size--) {
		if ((*size) == '/')
			break;
		if ((*size) == '\\')
			break;
		if ((*size) == '.') {
			*size = '\0';
			break;
		}
	}
	sprintf(out + strlen(out), "%s", add);
}

int lliqsort_asc(const void *data1, const void *data2)
{
	long long int *l = (long long int *)data1;
	long long int *a = (long long int *)data2;
	if ((*l) > (*a))
		return 1;
	if ((*l) < (*a))
		return -1;
	return 0;
}

int lliqsort_desc(const void *data1, const void *data2)
{
	long long int *l = (long long int *)data1;
	long long int *a = (long long int *)data2;
	if ((*l) > (*a))
		return -1;
	if ((*l) < (*a))
		return 1;
	return 0;
}

void llinew_qsort(long long int *tmp, int num, int updown)
{
	if (updown == 0) {
		qsort(tmp, num, sizeof(long long int), lliqsort_asc);
	} else {
		new_qsort(tmp, num, sizeof(long long int), lliqsort_desc);
	}
}

void Main(int argc, char *argv[])
{
	char fname_o[_MAX_PATH];
	FILE *fp_index;
	FILE *fp_o;
	int cnt;
	int u;
	int b;
	int str;
	int x;
	double i;
	double pasum;
	double ebackspace;
	double min;
	generate_filename(fname_o, argv[1], "_out.txt");
	fp_index = new_fopen(argv[1], "r");
	fp_o = new_fopen(fname_o, "w");
	fscanf(fp_index, "%d", &b);
	for (cnt = 1; cnt <= b; cnt++) {
		fprintf(stderr, "Case #%d/%d...", cnt, b);
		fscanf(fp_index, "%d", &str);
		fscanf(fp_index, "%d", &x);
		min = ((double)x) + 2.0;
		pasum = 1.0;
		for (u = 1; u <= str; u++) {
			fscanf(fp_index, "%lf", &i);
			pasum *= i;
			ebackspace =
			    (pasum *
			     ((((((str - u) + str) - u) + x) - str) + 1)) +
			    ((1.0 -
			      pasum) *
			     ((((((((str - u) + str) - u) + x) - str) + 1) +
			       x) + 1));
			if (ebackspace < min)
				min = ebackspace;
		}
		fprintf(fp_o, "Case #%d: %.6lf\n", cnt, min);
		fprintf(stderr, "finish!!\n");
	}
	new_fclose(fp_index);
	new_fclose(fp_o);
}

FILE *new_fopen(const char *filename, const char *mode);
int new_fclose(FILE * stream);
int new_fscanf(FILE * stream, const char *format, ...);
int new_fprintf(FILE * stream, const char *format, ...);
void new_qsort(void *base, size_t num, size_t size,
	       int (*compar) (const void *, const void *))
{
	return qsort(base, num, size, compar);
}

FILE *new_fopen(const char *filename, const char *mode)
{
	return fopen(filename, mode);
}

int new_fclose(FILE * stream)
{
	return fclose(stream);
}
