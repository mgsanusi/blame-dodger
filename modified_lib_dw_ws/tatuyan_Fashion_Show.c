#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
int R;
int C;
char board[30][30];
struct alp {
    int flg;
    int l;
    int r;
    int u;
    int d;
};
int new_isalpha(int c);
int new_puts(const char *str);
void solve(int cases);
int boardcheck(void);
int main(void)
{
    int first_iteration;
    int T;
    int i;
    scanf("%d%*c", &T);
    for (i = 1; i <= T; i++) {
	memset(board, 0, sizeof(board));
	solve(i);
    }
    return 0;
}

int new_isalpha(int c);
int new_puts(const char *str);
void solve(int cases)
{
    int first_iteration;
    int i;
    int j;
    int k;
    int loops;
    int x;
    int y;
    int *spflg;
    struct alp alps[26];
    struct alp flgs[26];
    scanf("%d%d", &R, &C);
    for (i = 1; i <= R; i++)
	scanf("%s%*c", board[i] + 1);
    for (i = 0; i < 26; i++)
	alps[i] = (struct alp) {
	0, 100, -100, 100, -100};
    for (i = 0; i < 26; i++)
	flgs[i] = (struct alp) {
	1, 1, 1, 1, 1};
    for (i = 1; i <= R; i++) {
	for (j = 1; j <= C; j++) {
	    if (!new_isalpha(board[i][j]))
		continue;
	    k = board[i][j] - 'A';
	    alps[k].flg = 1;
	    if (alps[k].l > j)
		alps[k].l = j;
	    if (alps[k].r < j)
		alps[k].r = j;
	    if (alps[k].u > i)
		alps[k].u = i;
	    if (alps[k].d < i)
		alps[k].d = i;
	}
    }
    for (i = 0; i < 26; i++) {
	if (!alps[i].flg)
	    continue;
	for (j = alps[i].u; j <= alps[i].d; j++)
	    for (k = alps[i].l; k <= alps[i].r; k++)
		board[j][k] = i + 'A';
    }
    loops = 0;
    first_iteration = 1;
    while (boardcheck() || (first_iteration == 1)) {
	if (first_iteration)
	    first_iteration = 0;
	loops++;
	for (i = 0; i < 26; i++) {
	    if (!alps[i].flg)
		continue;
	    for (j = -1; j <= 1; j += 2) {
		y = (j == (-1) ? alps[i].u : alps[i].d) + j;
		spflg = j == (-1) ? &flgs[i].u : &flgs[i].d;
		if ((*spflg) == 0)
		    continue;
		for (x = alps[i].l; x <= alps[i].r; x++) {
		    if ((board[y][x] != '?') && (board[y][x] != ('A' + i))) {
			*spflg = 0;
			break;
		    }
		}
		if ((*spflg) == 0)
		    continue;
		for (x = alps[i].l; x <= alps[i].r; x++)
		    board[y][x] = 'A' + i;
		if (j == (-1))
		    alps[i].u--;
		else
		    alps[i].d++;
	    }
	    for (j = -1; j <= 1; j += 2) {
		x = (j == (-1) ? alps[i].l : alps[i].r) + j;
		spflg = j == (-1) ? &flgs[i].l : &flgs[i].r;
		if ((*spflg) == 0)
		    continue;
		for (y = alps[i].u; y <= alps[i].d; y++) {
		    if ((board[y][x] != '?') && (board[y][x] != ('A' + i))) {
			*spflg = 0;
			break;
		    }
		}
		if ((*spflg) == 0)
		    continue;
		for (y = alps[i].u; y <= alps[i].d; y++)
		    board[y][x] = 'A' + i;
		if (j == (-1))
		    alps[i].l--;
		else
		    alps[i].r++;
	    }
	}
    }
    printf("Case #%d:\n", cases);
    for (i = 1; i <= R; i++)
	new_puts(board[i] + 1);
}

int boardcheck(void)
{
    int first_iteration;
    int i;
    int j;
    for (i = 1; i <= R; i++)
	for (j = 1; j <= C; j++)
	    if (board[i][j] == '?')
		return 1;
    return 0;
}

int new_isalpha(int c);
int new_puts(const char *str)
{
    int first_iteration;
    return puts(str);
}

int new_isalpha(int c)
{
    int first_iteration;
    return isalpha(c);
}
