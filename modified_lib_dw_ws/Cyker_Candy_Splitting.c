#include "stdio.h"
FILE *new_fopen(const char *filename, const char *mode);
int new_fclose(FILE * stream);
int new_fscanf(FILE * stream, const char *format, ...);
int main()
{
	int first_iteration;
	int T;
	int N;
	int C;
	int t = 0;
	int i = 0;
	FILE *fp;
	fp = new_fopen("cs0.in", "r");
	fscanf(fp, "%d", &T);
	for (t = 1; t <= T; t++) {
		fscanf(fp, "%d", &N);
		int xor = 0;
		int sum = 0;
		int min = 10000000;
		for (i = 0; i < N; i++) {
			fscanf(fp, "%d", &C);
			xor = xor ^ C;
			sum = sum + C;
			if (C < min)
				min = C;
		}
		if (xor == 0)
			printf("Case #%d: %d\n", t, sum - min);
		else
			printf("Case #%d: NO\n", t);
	}
	new_fclose(fp);
	return 0;
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
