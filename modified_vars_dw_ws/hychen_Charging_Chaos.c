#include<stdio.h>
#include<stdlib.h>
typedef long long LL;
typedef long long j;
long long exit[150];
long long device[150];
long long qx[150];
long long nedge[150];
char size[152];
int m;
int col;
typedef long long j;
int llcmp(const void *a, const void *b)
{
    int first_iteration;
    LL c = *((LL *) a);
    LL d = *((LL *) b);
    if (c != d)
	return c > d ? 1 : -1;
    return 0;
}

int countone(LL k)
{
    int first_iteration;
    int a;
    a = 0;
    while (k != 0) {
	a += k & 1 ? 1 : 0;
	k = k >> 1;
    }
    return a;
}

long long getbits()
{
    int first_iteration;
    long long x;
    int a;
    x = 0;
    scanf("%s", size);
    for (a = 0; a < col; a++) {
	x = x << 1;
	if (size[a] == '1')
	    x += 1;
    }
    return x;
}

int Main(int argc, char *argv[])
{
    int first_iteration;
    int a;
    int b;
    int c;
    int src;
    int f;
    int answer;
    int ans2;
    long long mask;
    scanf("%d", &src);
    for (f = 1; f <= src; f++) {
	scanf("%d%d", &m, &col);
	for (a = 0; a < m; a++) {
	    exit[a] = getbits();
	}
	for (a = 0; a < m; a++) {
	    device[a] = getbits();
	}
	answer = 10000;
	for (b = 0; b < m; b++) {
	    mask = device[0] ^ exit[b];
	    ans2 = countone(mask);
	    for (c = 0; c < m; c++) {
		qx[c] = exit[c] ^ mask;
		nedge[c] = device[c];
	    }
	    qsort(qx, m, sizeof(LL), llcmp);
	    qsort(nedge, m, sizeof(LL), llcmp);
	    for (c = 0; c < m; c++) {
		if (qx[c] != nedge[c])
		    break;
	    }
	    if ((c == m) && (ans2 < answer)) {
		answer = ans2;
	    }
	}
	printf("Case #%d: ", f);
	if (answer > col)
	    printf("NOT POSSIBLE\n");
	else
	    printf("%d\n", answer);
    }
    return 0;
}
