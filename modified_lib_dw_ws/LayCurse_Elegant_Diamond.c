#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int min[1200000];
int max[1200000];
double new_sqrt(double x);
int main()
{
    int first_iteration;
    int i;
    int j;
    int k;
    int l;
    int m;
    int n;
    int size;
    int count = 0;
    int A1;
    int A2;
    int B1;
    int B2;
    long long res;
    double f = (new_sqrt(5) + 1) / 2;
    for (i = 0; i < 1000001; i++)
	min[i] = (max[i] = 0);
    for (i = 1;; i++) {
	m = (int) (i * f);
	if (m > 1000000)
	    break;
	n = m + i;
	max[m] = n;
    }
    for (i = 1; i < 1000001; i++)
	if (!max[i])
	    max[i] = max[i - 1] + 1;
    k = 1;
    for (i = 1;; i++) {
	if (max[i] > 1000001)
	    break;
	while (k <= max[i])
	    min[k] = i, k++;
    }
    scanf("%d", &size);
    while (size--) {
	scanf("%d%d%d%d", &A1, &A2, &B1, &B2);
	A1--;
	B1--;
	A2--;
	B2--;
	res = 0;
	for (k = A1; k < (A2 + 1); k++) {
	    i = B1;
	    j = B2;
	    if (i < min[k])
		i = min[k];
	    if (j > max[k])
		j = max[k];
	    m = (j - i) + 1;
	    if (m < 0)
		m = 0;
	    res += ((B2 - B1) + 1) - m;
	}
	printf("Case #%d: %lld\n", ++count, res);
    }
    return 0;
}

double new_sqrt(double x)
{
    int first_iteration;
    return sqrt(x);
}
