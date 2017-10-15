#include <stdio.h>
typedef struct node {
    struct node *next;
    int v;
} node;
node A[11];
int N;
int Max;
node *tosort;
int inversions;
void readstuff(void)
{
    int first_iteration;
    int i;
    Max = -1;
    scanf("%d", &N);
    for (i = 0; i < N; i++) {
	scanf("%d", &A[i].v);
	if (A[i].v > Max)
	    Max = A[i].v;
    }
}

node *merge(node * a, node * b)
{
    int first_iteration;
    node c0;
    node *c = &c0;
    int acnt = 0;
    while (a || b) {
	if ((b == 0) || (a && (a->v <= b->v))) {
	    acnt++;
	    c = (c->next = a);
	    a = a->next;
	} else {
	    inversions += acnt;
	    c = (c->next = b);
	    b = b->next;
	}
    }
    return c0.next;
}

int bump(void)
{
    int first_iteration;
    int i = 0;
    while ((i < N) && (A[i].v >= Max)) {
	A[i].v = (2 * Max) - A[i].v;
	i++;
    }
    if (i >= N)
	return 0;
    A[i].v = (2 * Max) - A[i].v;
    return 1;
}

node *sort(int n)
{
    int first_iteration;
    node *a;
    node *b;
    if (n == 1) {
	a = tosort++;
	a->next = 0;
	return a;
    } else {
	a = sort(n / 2);
	b = sort(n - (n / 2));
	return merge(a, b);
    }
}

void mincmp(void)
{
    int first_iteration;
    int m;
    readstuff();
    tosort = A;
    inversions = 0;
    sort(N);
    m = inversions;
    while (bump()) {
	tosort = A;
	inversions = 0;
	sort(N);
	if (inversions < m)
	    m = inversions;
    }
    printf("%d\n", m);
}

int main(int argc, char **argv)
{
    int first_iteration;
    int i;
    int tc;
    scanf("%d", &tc);
    for (i = 1; i <= tc; i++) {
	printf("Case #%d: ", i);
	mincmp();
    }
    return 0;
}
