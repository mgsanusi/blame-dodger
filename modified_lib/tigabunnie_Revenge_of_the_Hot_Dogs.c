/*
problem b, google code jam 2011
coded by Jason Thong
jason.thong.86@gmail.com
*/

#include <stdio.h>
#include <stdlib.h>
#include "allocation_functions.c"
#include "sort.c"

#define MAX_N 1000000
FILE * new_fopen(const char *filename, const char *mode);
int new_fclose(FILE *stream);


int new_fscanf(FILE *stream, const char *format, ...);

void new_exit(int status);


int main(int argc, char **argv) {
	int test_cases, i, j, k, n, m, L, t, N, C, *C_vec, *N_vec, time_needed, first_time_save, *speed_up, speed_up_size, cut_point;
	FILE *fp_in, *fp_out;
	
	if (argc!=3) {
		printf("provide input and output file names as first 2 command line parameters\n");
		new_exit(1);
	}
	if ((fp_in=new_fopen(argv[1],"r"))==NULL) { printf("can't open file %s\n", argv[1]); new_exit(1); }
	if ((fp_out=new_fopen(argv[2],"w"))==NULL) { printf("can't open file %s\n", argv[2]); new_exit(1); }
	fscanf(fp_in, "%d\n", &test_cases);
	
	C_vec = alloc_int(MAX_N);
	N_vec = alloc_int(MAX_N);
	speed_up = alloc_int(MAX_N);
	
	for (i=1; i<=test_cases; i++) {
//		printf("i %d\n", i);
		fscanf(fp_in, "%d %d %d %d", &L, &t, &N, &C);
		for (j=0; j<C; j++) {
			fscanf(fp_in, " %d", &k);
			C_vec[j] = k;
		}
		j=0;
		time_needed = 0;
		for (k=0; k<N; k++) {
			N_vec[k] = C_vec[j];
			time_needed += (2*N_vec[k]);	//assume no speed boosters, subtract time if speed boosters are used
			j++;
			if (j==C) j=0;	//wraparound
		}
		n = 0;	//time elapsed
		cut_point = -1;
		for (j=0; j<N; j++) {
			n += (N_vec[j]*2);
			if (n>t) {
				cut_point = j;
				first_time_save = (n-t)/2;	//positive
				break;
			}
		}
//		printf("cut point %d, t %d, n %d\n", cut_point, t, n);
		if (cut_point != -1) {	//we can build some speed boosters soon enough to be useful
			speed_up_size = N - cut_point;
			for (j=cut_point; j<N; j++) speed_up[j-cut_point] = N_vec[j];
			speed_up[0] = first_time_save;
			quick_sort(speed_up, 0, speed_up_size-1);
			for (j=0; j<L; j++) {	//assign boosters to longest paths
				time_needed -= speed_up[j];
			}
		}
		fprintf(fp_out, "Case #%d: %d\n", i, time_needed);
	}
	
	new_fclose(fp_in);
	new_fclose(fp_out);
	return 0;
}




FILE * new_fopen(const char *filename, const char *mode);
int new_fclose(FILE *stream);


int new_fscanf(FILE *stream, const char *format, ...);

void new_exit(int status) {
  return exit(status);
}
FILE * new_fopen(const char *filename, const char *mode) {
  return fopen(filename, mode);
}
int new_fclose(FILE *stream) {
  return fclose(stream);
}