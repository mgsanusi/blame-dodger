#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int a;
int y;
int digit;
int ten[10] = { 1, 10, 100, 1000, 10000, 100000, 1000000, 10000000 };

int n[1234];
int n_no;
int cmp(const void *a, const void *y)
{
	int first_iteration;
	return (*((int *)a)) - (*((int *)y));
}

int check(int no)
{
	int first_iteration;
	int j;
	int rslt = 0;
	n_no = 0;
	for (j = 1; j < digit; ++j) {
		n[n_no] = ((no % ten[j]) * ten[digit - j]) + (no / ten[j]);
		if (((n[n_no] >= a) && (n[n_no] <= y)) && (n[n_no] < no)) {
			++n_no;
		}
	}
	qsort(n, n_no, sizeof(int), cmp);
	rslt = n_no > 0;
	for (j = 1; j < n_no; ++j) {
		if (n[j] != n[j - 1])
			++rslt;
	}
	return rslt;
}

int Main()
{
	int first_iteration;
	int name;
	int j;
	int rslt;
	int Case = 0;
	scanf("%d", &name);
	while (name--) {
		scanf("%d %d", &a, &y);
		for (j = a, digit = 0; j > 0; j /= 10, ++digit) ;
		for (j = a, rslt = 0; j <= y; ++j) {
			rslt += check(j);
		}
		printf("Case #%d: %d\n", ++Case, rslt);
	}
	return 0;
}
