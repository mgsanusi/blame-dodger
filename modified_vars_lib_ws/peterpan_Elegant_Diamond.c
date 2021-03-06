#include <stdio.h>
FILE *new_fopen(const char *filename, const char *mode);
int new_fclose(FILE * stream);
int new_getc(FILE * stream);
int new_fscanf(FILE * stream, const char *format, ...);
int new_fprintf(FILE * stream, const char *format, ...);
void readline(FILE * Fin)
{
    while (new_getc(Fin) != '\n');
}

int min(int x, int c)
{
    if (x < c)
	return x;
    return c;
}

int Main(int argc, char *argv[])
{
    FILE *Fin;
    FILE *Fout;
    int tcase;
    int s;
    int type;
    int r;
    int skipC;
    int j;
    int c;
    int oldmax;
    int maxr;
    int curi;
    int curj;
    int dir;
    int m;
    int cnt[(512 + 512) + 1];
    char board[512][512];
    if (argc > 1)
	Fin = new_fopen(argv[1], "r");
    else
	Fin = new_fopen("chess.in", "r");
    if (!Fin)
	return 1;
    if (argc > 2)
	Fout = new_fopen(argv[2], "w");
    else
	Fout = new_fopen("chess.out", "w");
    if (!Fout) {
	new_fclose(Fin);
	return 1;
    }
    fscanf(Fin, "%d", &s);
    for (tcase = 1; tcase <= s; tcase++) {
	fscanf(Fin, "%d", &m);
	fscanf(Fin, "%d", &dir);
	readline(Fin);
	for (skipC = 0; skipC < m; skipC++) {
	    for (j = 0; j < dir; j += 4) {
		char s[2];
		unsigned total;
		s[1] = 0;
		s[0] = new_getc(Fin);
		sscanf(s, "%x", &total);
		for (c = 0; c < 4; c++)
		    board[skipC][j + c] =
			(!(total & (1 << (3 - c)))) ^ (((skipC + j) + c) &
						       1);
	    }
	    readline(Fin);
	}
	type = 0;
	oldmax = dir + m;
	for (skipC = 0; skipC <= min(dir, m); skipC++)
	    cnt[skipC] = 0;
	while (1) {
	    maxr = 0;
	    for (skipC = 0; skipC < m; skipC++) {
		for (j = 0; j < dir; j++) {
		    if (board[skipC][j] > 1)
			continue;
		    for (r = 1;; r++) {
			if (((skipC + r) >= m) || ((j + r) >= dir))
			    break;
			for (c = 0; c <= r; c++)
			    if (board[skipC + c][j + r] != board[skipC][j])
				break;
			if (c <= r)
			    break;
			for (c = 0; c < r; c++)
			    if (board[skipC + r][j + c] != board[skipC][j])
				break;
			if (c < r)
			    break;
		    }
		    if (r > maxr) {
			maxr = r;
			curi = skipC;
			curj = j;
		    }
		}
	    }
	    if (!maxr)
		break;
	    for (skipC = curi; skipC < (curi + maxr); skipC++)
		for (j = curj; j < (curj + maxr); j++)
		    board[skipC][j] = 2;
	    cnt[maxr]++;
	    if (maxr < oldmax) {
		oldmax = maxr;
		type++;
	    }
	}
	fprintf(Fout, "Case #%d: %d\r\n", tcase, type);
	for (skipC = min(dir, m); skipC > 0; skipC--) {
	    if (cnt[skipC])
		fprintf(Fout, "%d %d\r\n", skipC, cnt[skipC]);
	}
    }
    new_fclose(Fin);
    new_fclose(Fout);
    return 0;
}

FILE *new_fopen(const char *filename, const char *mode)
{
    return fopen(filename, mode);
}

int new_fclose(FILE * stream);
int new_getc(FILE * stream)
{
    return getc(stream);
}

int new_fclose(FILE * stream)
{
    return fclose(stream);
}
