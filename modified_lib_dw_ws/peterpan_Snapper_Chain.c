#include <stdio.h>
FILE *new_fopen(const char *filename, const char *mode);
int new_fclose(FILE * stream);
int new_fscanf(FILE * stream, const char *format, ...);
int main(int argc, char *argv[])
{
	int first_iteration;
	FILE *fin;
	FILE *fout;
	int i;
	int T;
	int K;
	int N;
	if (argc > 1)
		fin = new_fopen(argv[1], "r");
	else
		fin = new_fopen("snapperChain.in.txt", "r");
	if (!fin)
		return 1;
	if (argc > 2)
		fout = new_fopen(argv[2], "w");
	else
		fout = new_fopen("snapperChain.out.txt", "w");
	if (!fout) {
		new_fclose(fin);
		return 1;
	}
	fscanf(fin, "%d", &T);
	for (i = 1; i <= T; i++) {
		fscanf(fin, "%d", &N);
		fscanf(fin, "%d", &K);
		fprintf(fout, "Case #%d: %s\n", i,
			(K % (1 << N)) == ((1 << N) - 1) ? "ON" : "OFF");
	}
	new_fclose(fin);
	new_fclose(fout);
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
