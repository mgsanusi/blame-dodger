#include<stdio.h>
#include<stdlib.h>
#include<string.h>
 
// for qsort
/*
int compare(int *t, int *s) {
    return *t - *s;
}
*/ 
int N;
 int search(int X, int R, int C)
{
	if (X == 1)
		return 1;
	if (X == 2 && (R * C % 2 == 0))
		return 1;
	if (X == 3 && (R * C % 3 == 0) && R > 1 && C > 1)
		return 1;
	if (X == 4 && ((R == 4 && C >= 3) || (R >= 3 && C == 4)))
		return 1;
	return 0;		// otherwise RICHARD wins
}

  int main(void)
{
	int dataset_num, case_num;
	int X, R, C;
	 scanf("%d", &dataset_num);
	for (case_num = 1; case_num <= dataset_num; ++case_num) {
		 scanf("%d %d %d", &X, &R, &C);
		 printf("Case #%d: ", case_num);
		if (search(X, R, C)) {
			printf("GABRIEL\n");
		}
		
		else {
			printf("RICHARD\n");
		}
	}
	 return 0;
}


