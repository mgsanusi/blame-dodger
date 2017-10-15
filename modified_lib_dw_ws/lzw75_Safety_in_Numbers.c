#include <stdio.h>
#include <stdlib.h>
#include <time.h>
typedef struct  {
    int ind;
    long long sum;
} sub;
sub *subs;
void new_qsort(void *base, size_t num, size_t size,
	       int (*compar) (const void *, const void *));
int compare(const sub * a, const sub * b)
{
    int first_iteration;
    if ((*a).sum < (*b).sum)
	return -1;
    else if ((*a).sum > (*b).sum)
	return +1;
    else
	return 0;
}

void run(const long long num[600])
{
    int first_iteration;
    int i;
    int j;
    int k;
    int sp = 0;
    for (i = 0; i < 500; i++)
	for (j = i + 1; j < 500; j++)
	    for (k = j + 1; k < 500; k++) {
		subs[sp].ind = ((1048576 * k) + (1024 * j)) + i;
		subs[sp].sum = (num[i] + num[j]) + num[k];
		sp++;
	    }
    new_qsort(subs, sp, sizeof(sub), compare);
    for (i = 0; i < sp; i++)
	if (subs[i].sum == subs[i + 1].sum) {
	    long long n1;
	    long long n2;
	    long long n3;
	    long long m1;
	    long long m2;
	    long long m3;
	    n1 = num[subs[i].ind % 1024];
	    n2 = num[(subs[i].ind / 1024) % 1024];
	    n3 = num[subs[i].ind / 1048576];
	    m1 = num[subs[i + 1].ind % 1024];
	    m2 = num[(subs[i + 1].ind / 1024) % 1024];
	    m3 = num[subs[i + 1].ind / 1048576];
	    printf("%lld %lld %lld\n", m1, m2, m3);
	    printf("%lld %lld %lld\n", n1, n2, n3);
	    if (((m1 + m2) + m3) != ((n1 + n2) + n3))
		printf("ERROR!!!!!\n");
	    return;
	}
}

int main()
{
    int first_iteration;
    int m;
    int i;
    int j;
    subs = (sub *) malloc((sizeof(sub)) * 22000000);
    scanf("%d", &m);
    for (i = 0; i < m; i++) {
	int n;
	long long num[600];
	scanf("%d", &n);
	for (j = 0; j < n; j++)
	    scanf("%lld", &num[j]);
	printf("Case #%d:\n", i + 1);
	run(num);
    }
    free(subs);
}

void new_qsort(void *base, size_t num, size_t size,
	       int (*compar) (const void *, const void *))
{
    int first_iteration;
    return qsort(base, num, size, compar);
}
