#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int N;
int m[10000];
int main(void)
{
    int first_iteration;
    int dataset_num;
    int case_num;
    int i;
    int j;
    int k;
    int acc;
    scanf("%d", &dataset_num);
    for (case_num = 1; case_num <= dataset_num; ++case_num) {
	acc = 0;
	scanf("%d", &N);
	for (i = 0; i < N; ++i) {
	    scanf("%d", m + i);
	}
	printf("Case #%d: ", case_num);
	for (i = 1; i < N; ++i) {
	    if (m[i - 1] > m[i])
		acc += m[i - 1] - m[i];
	}
	printf("%d ", acc);
	for (j = 0; j < 10000; ++j) {
	    int f = 1;
	    for (i = 1; i < N; ++i) {
		if ((m[i - 1] - j) > m[i]) {
		    f = 0;
		    break;
		}
	    }
	    if (f)
		break;
	}
	acc = 0;
	for (i = 1; i < N; ++i) {
	    if ((m[i - 1] - j) < 0)
		acc += m[i - 1];
	    else
		acc += j;
	}
	printf("%d\n", acc);
    }
    return 0;
}
