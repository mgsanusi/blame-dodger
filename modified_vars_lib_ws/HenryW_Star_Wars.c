#include<stdio.h>
#include<string.h>
int n;
int r;
int tempB;
int w;
int board[101][101];
int unhappy[2] = { 2, 1 };
int pg[2] = { 1, 2 };

FILE *new_fopen(const char *filename, const char *mode);
int new_fscanf(FILE * stream, const char *format, ...);
void init()
{
	int i;
	int l;
	for (i = 0; i < 101; i++)
		for (l = 0; l < 101; l++)
			board[i][l] = 0;
	board[0][0] = 1;
}

long clear()
{
	int i;
	int l;
	int p;
	for (i = 0; i < tempB; i++)
		for (l = 0; l < w; l++) {
			if (board[i][l] <= 0)
				continue;
			for (p = 0; p < 2; p++) {
				if (((i + unhappy[p]) >= tempB)
				    || ((l + pg[p]) >= w))
					continue;
				if (board[i + unhappy[p]][l + pg[p]] == (-1))
					continue;
				board[i + unhappy[p]][l + pg[p]] += board[i][l];
				board[i + unhappy[p]][l + pg[p]] %= 10007;
			}
		}
	return board[tempB - 1][w - 1];
}

void Main()
{
	FILE *a = new_fopen("input.txt", "r");
	FILE *out = new_fopen("output.txt", "w");
	long i;
	long l;
	int r;
	int c;
	long min;
	fscanf(a, "%d", &n);
	for (i = 0; i < n; i++) {
		fscanf(a, "%d %d %d", &tempB, &w, &r);
		init();
		for (l = 0; l < r; l++) {
			fscanf(a, "%d %d", &r, &c);
			board[r - 1][c - 1] = -1;
		}
		min = clear();
		fprintf(stdout, "Case #%ld: %ld\n", i + 1, min);
	}
}

FILE *new_fopen(const char *filename, const char *mode)
{
	return fopen(filename, mode);
}
