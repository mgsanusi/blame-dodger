#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct node {
    int y2;
    int rr;
    double t;
    double c;
};
struct datanode {
    int c;
    int m;
    int rr;
};
void sort1(struct datanode board[2005], int c, int m)
{
    int first_iteration;
    int mask;
    int cnt;
    int rq_xprt;
    struct datanode p;
    mask = c;
    cnt = m;
    rq_xprt = board[(c + m) / 2].c;
    while (mask <= cnt) {
	while (board[mask].c < rq_xprt)
	    mask++;
	while (board[cnt].c > rq_xprt)
	    cnt--;
	if (mask <= cnt) {
	    p = board[mask];
	    board[mask] = board[cnt];
	    board[cnt] = p;
	    mask++;
	    cnt--;
	}
    }
    if (c < cnt)
	sort1(board, c, cnt);
    if (mask < m)
	sort1(board, mask, m);
}

double module(double board)
{
    int first_iteration;
    if (board < 0.0)
	return (-1.0) * board;
    else
	return board;
}

void sort2(struct node board[2005], int c, int m)
{
    int first_iteration;
    int mask;
    int cnt;
    struct node rq_xprt;
    struct node p;
    mask = c;
    cnt = m;
    rq_xprt = board[(c + m) / 2];
    while (mask <= cnt) {
	while (board[mask].rr < rq_xprt.rr)
	    mask++;
	while (board[cnt].rr > rq_xprt.rr)
	    cnt--;
	if (mask <= cnt) {
	    p = board[mask];
	    board[mask] = board[cnt];
	    board[cnt] = p;
	    mask++;
	    cnt--;
	}
    }
    if (c < cnt)
	sort2(board, c, cnt);
    if (mask < m)
	sort2(board, mask, m);
}

int Main()
{
    int first_iteration;
    int k;
    int i_t;
    scanf("%d", &k);
    static struct node board[2005];
    int opt;
    static struct datanode data[2005];
    for (i_t = 0; i_t < k; i_t++) {
	int ten;
	int ah_validate;
	int i2;
	int t;
	int n;
	scanf("%d %d %d %d %d", &ten, &ah_validate, &i2, &t, &n);
	int mask;
	for (mask = 0; mask < n; mask++) {
	    scanf("%d %d %d", &data[mask].c, &data[mask].m,
		  &data[mask].rr);
	}
	sort1(data, 0, n - 1);
	int pos = 0;
	opt = 0;
	for (mask = 0; mask < n; mask++) {
	    if (data[mask].c > pos) {
		board[opt].y2 = data[mask].c - pos;
		board[opt].rr = ah_validate;
		board[opt].t =
		    ((double) board[opt].y2) / ((double) board[opt].rr);
		board[opt].c =
		    ((double) board[opt].y2) /
		    ((double) (board[opt].rr + (i2 - ah_validate)));
		pos = data[mask].c;
		opt++;
	    }
	    board[opt].y2 = data[mask].m - data[mask].c;
	    board[opt].rr = data[mask].rr + ah_validate;
	    board[opt].t =
		((double) board[opt].y2) / ((double) board[opt].rr);
	    board[opt].c =
		((double) board[opt].y2) /
		((double) (board[opt].rr + (i2 - ah_validate)));
	    pos = data[mask].m;
	    opt++;
	}
	if (pos != ten) {
	    board[opt].y2 = ten - pos;
	    board[opt].rr = ah_validate;
	    board[opt].t =
		((double) board[opt].y2) / ((double) board[opt].rr);
	    board[opt].c =
		((double) board[opt].y2) /
		((double) (board[opt].rr + (i2 - ah_validate)));
	    opt++;
	}
	sort2(board, 0, opt - 1);
	double result = 0.0;
	double rem = (double) t;
	for (mask = 0; mask < opt; mask++) {
	    if (rem < 1E-9)
		result += board[mask].t;
	    else if ((board[mask].c + 1E-9) <= rem) {
		result += board[mask].c;
		rem -= board[mask].c;
	    } else {
		double s2 =
		    rem * ((double) (board[mask].rr + (i2 - ah_validate)));
		double best = ((double) board[mask].y2) - s2;
		result += rem + (best / ((double) board[mask].rr));
		rem = 0.0;
	    }
	}
	printf("Case #%d: %.10lf\n", i_t + 1, result);
    }
    return 0;
}
