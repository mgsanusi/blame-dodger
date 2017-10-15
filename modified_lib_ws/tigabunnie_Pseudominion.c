/*
problem a, google code jam 2011
coded by Jason Thong
jason.thong.86@gmail.com
*/
#include <stdio.h>
#include <stdlib.h>
#define MAX_N 100
FILE *new_fopen(const char *filename, const char *mode);
int new_fclose(FILE * stream);
int new_fscanf(FILE * stream, const char *format, ...);
int new_fprintf(FILE * stream, const char *format, ...);
void new_exit(int status);
int main(int argc, char **argv)
{
	int test_cases, i, j, k, n, m, N, wins, games_played, count;
	double wp[MAX_N], owp[MAX_N], oowp[MAX_N], rpi[MAX_N];
	char read_char, match_table[MAX_N][MAX_N];
	FILE *fp_in, *fp_out;

	if (argc != 3) {
		printf
		    ("provide input and output file names as first 2 command line parameters\n");
		new_exit(1);
	}
	if ((fp_in = new_fopen(argv[1], "r")) == NULL) {
		printf("can't open file %s\n", argv[1]);
		new_exit(1);
	}
	if ((fp_out = new_fopen(argv[2], "w")) == NULL) {
		printf("can't open file %s\n", argv[2]);
		new_exit(1);
	}
	fscanf(fp_in, "%d\n", &test_cases);

	for (i = 1; i <= test_cases; i++) {
		fscanf(fp_in, "%d\n", &N);
		for (j = 0; j < N; j++) {
			for (k = 0; k < N; k++) {
				fscanf(fp_in, "%c", &read_char);
				match_table[j][k] = read_char;
			}
			fscanf(fp_in, "\n");
		}
		for (j = 0; j < N; j++) {
			games_played = 0;
			wins = 0;
			for (k = 0; k < N; k++)
				if (match_table[j][k] != '.') {
					games_played++;
					if (match_table[j][k] == '1')
						wins++;
				}
			wp[j] = ((double)wins) / games_played;
		}
		for (j = 0; j < N; j++) {
			count = 0;
			owp[j] = 0;
			for (k = 0; k < N; k++)
				if (match_table[j][k] != '.') {	//team j played against team k, find team k's avg win percentage excluding game with team j
					wins = 0;
					games_played = 0;
					for (n = 0; n < N; n++)
						if (n != j
						    && match_table[k][n] !=
						    '.') {
							games_played++;
							if (match_table[k][n] ==
							    '1')
								wins++;
						}
					owp[j] += (((double)wins) / games_played);	//running sum of team k's avg win percentage excluding game with team j
					count++;
				}
			owp[j] /= count;
		}
		for (j = 0; j < N; j++) {
			count = 0;
			oowp[j] = 0;
			for (k = 0; k < N; k++)
				if (match_table[j][k] != '.') {
					oowp[j] += owp[k];
					count++;
				}
			oowp[j] /= count;
		}
		for (j = 0; j < N; j++) {
			rpi[j] = 0.25 * wp[j] + 0.5 * owp[j] + 0.25 * oowp[j];
		}
		fprintf(fp_out, "Case #%d:\n", i);
		for (j = 0; j < N; j++) {
			fprintf(fp_out, "%lf\n", rpi[j]);
		}
	}

	new_fclose(fp_in);
	new_fclose(fp_out);
	return 0;
}

FILE *new_fopen(const char *filename, const char *mode);
int new_fclose(FILE * stream);
int new_fscanf(FILE * stream, const char *format, ...);
int new_fprintf(FILE * stream, const char *format, ...);
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
