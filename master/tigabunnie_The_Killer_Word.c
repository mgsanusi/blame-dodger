/*
problem a, google code jam 2011
coded by Jason Thong
jason.thong.86@gmail.com

insight: since Pd is an integer, can figure out minimum number of games needed to play to get exactly that percent of wins
100 is divisible by 2 and 5
any multiple of this is allowed, up to N
same idea applies to Pg, except no limit of N
solution exists if K*min_play_today <= M*min_play_global and K*min_win_today <= M*min_win_global

compiled with: gcc a.c -o a -Wall -O3
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX_CASES 100

int main(int argc, char **argv) {
	int test_cases, i, j, k, N, Pd, Pg, min_play_today, min_win_today, min_play_global, min_win_global, div_factor;
	char is_there_solution;
	FILE *fp_in, *fp_out;
	
	if (argc!=3) {
		printf("provide input and output file names as first 2 command line parameters\n");
		exit(1);
	}
	if ((fp_in=fopen(argv[1],"r"))==NULL) { printf("can't open file %s\n", argv[1]); exit(1); }
	if ((fp_out=fopen(argv[2],"w"))==NULL) { printf("can't open file %s\n", argv[2]); exit(1); }
	fscanf(fp_in, "%d\n", &test_cases);
	
	for (i=1; i<=test_cases; i++) {
		fscanf(fp_in, "%d %d %d", &N, &Pd, &Pg);
		is_there_solution = 1;
		min_win_today = Pd;
		min_play_today = 100;
		while ((min_win_today%2)==0 && (min_play_today%2)==0) {
			min_win_today /= 2;
			min_play_today /= 2;
		}
		while ((min_win_today%5)==0 && (min_play_today%5)==0) {
			min_win_today /= 5;
			min_play_today /= 5;
		}
		if (min_play_today > N) {
			is_there_solution = 0;
		}
		else {
			if (min_win_today!=min_play_today && Pg==100) is_there_solution = 0;
			if (min_win_today>0 && Pg==0) is_there_solution = 0;
			/*
			min_win_global = Pg;
			min_play_global = 100;
			while ((min_win_global%2)==0 && (min_play_global%2)==0) {
				min_win_global /= 2;
				min_play_global /= 2;
			}
			while ((min_win_global%5)==0 && (min_play_global%5)==0) {
				min_win_global /= 5;
				min_play_global /= 5;
			}
			div_factor = (min_play_global+min_play_today-1) / min_play_today;	//ceiling, M/K
			*/
		}
		fprintf(fp_out, "Case #%d: ", i);
		if (is_there_solution) fprintf(fp_out, "Possible\n");
		else fprintf(fp_out, "Broken\n");
	}
	
	fclose(fp_in);
	fclose(fp_out);
	return 0;
}



