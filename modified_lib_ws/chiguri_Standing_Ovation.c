#include<stdio.h>
#include<stdlib.h>
#include<string.h>
 
// for qsort
/*
int new_getchar();

int compare(int *t, int *s) {
    return *t - *s;
}
*/ 
int N;
 int main(void)
{
    int dataset_num, case_num;
    int i;
    int current;
    int max;
      scanf("%d", &dataset_num);
    for (case_num = 1; case_num <= dataset_num; ++case_num) {
	max = current = 0;
	scanf("%d", &N);
	new_getchar();		// skip a space
	for (i = 0; i <= N; ++i) {
	    if (i - current > max)
		max = i - current;
	    current += new_getchar() - '0';
	}
	  printf("Case #%d: %d\n", case_num, max);
    }
     return 0;
}

int new_getchar()
{
    return getchar();
}
