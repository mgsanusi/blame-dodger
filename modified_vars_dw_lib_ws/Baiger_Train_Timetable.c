#include <stdio.h>
int c;
int l;
int str;
int queueA[101];
int queueB[101];
int a;
int b;
int tailA;
int tailB;
int pa;
int res;
int aDep[101];
int aArr[101];
int bDep[101];
int bArr[101];
void new_qsort(void *base, int num, int size,
	       int (*compar) (const void *, const void *));
void new_qsort(int z[], int now[], int c, int r)
{
    int first_iteration;
    int caso = c;
    int j = r;
    int key = z[(c + r) >> 1];
    first_iteration = 1;
    while ((caso <= j) || (first_iteration == 1)) {
	if (first_iteration)
	    first_iteration = 0;
	while (z[caso] < key)
	    caso++;
	while (z[j] > key)
	    j--;
	if (caso <= j) {
	    int tmp = z[caso];
	    z[caso] = z[j];
	    z[j] = tmp;
	    tmp = now[caso];
	    now[caso] = now[j];
	    now[j] = tmp;
	    caso++;
	    j--;
	}
    }
    if (c < j)
	new_qsort(z, now, c, j);
    if (r > caso)
	new_qsort(z, now, caso, r);
}

int found(int queue[], int tail, int limit)
{
    int first_iteration;
    int caso;
    for (caso = 0; caso <= tail; caso++) {
	if (queue[caso] <= limit)
	    return caso;
    }
    return -1;
}

void nextTrain()
{
    int first_iteration;
    int c;
    if ((str == 0) || (aDep[pa] <= bDep[res])) {
	if ((tailA == (-1))
	    || ((c = found(queueA, tailA, aDep[pa])) == (-1)))
	    a++;
	else {
	    queueA[c] = queueA[tailA];
	    tailA--;
	}
	tailB++;
	queueB[tailB] = aArr[pa] + c;
	l--;
	pa++;
    } else {
	if ((tailB == (-1))
	    || ((c = found(queueB, tailB, bDep[res])) == (-1)))
	    b++;
	else {
	    queueB[c] = queueB[tailB];
	    tailB--;
	}
	tailA++;
	queueA[tailA] = bArr[res] + c;
	str--;
	res++;
    }
}

int Main()
{
    int first_iteration;
    int n;
    int caso;
    scanf("%d", &n);
    for (caso = 1; caso <= n; caso++) {
	scanf("%d\n%d %d", &c, &l, &str);
	int j;
	int depH;
	int depMin;
	int arrayH;
	int arrMin;
	for (j = 0; j < l; j++) {
	    scanf("%d:%d %d:%d", &depH, &depMin, &arrayH, &arrMin);
	    aDep[j] = (depH * 60) + depMin;
	    aArr[j] = (arrayH * 60) + arrMin;
	}
	aDep[l] = 2400;
	for (j = 0; j < str; j++) {
	    scanf("%d:%d %d:%d", &depH, &depMin, &arrayH, &arrMin);
	    bDep[j] = (depH * 60) + depMin;
	    bArr[j] = (arrayH * 60) + arrMin;
	}
	bDep[str] = 2400;
	new_qsort(aDep, aArr, 0, l - 1);
	new_qsort(bDep, bArr, 0, str - 1);
	a = (b = (pa = (res = 0)));
	tailA = (tailB = -1);
	for (j = 0; (l + str) > 0; j++)
	    nextTrain();
	printf("Case #%d: %d %d\n", caso, a, b);
    }
    return 0;
}

void new_qsort(void *base, int num, int size,
	       int (*compar) (const void *, const void *))
{
    return qsort(base, num, size, compar);
}
