#include<stdio.h>
#include<string.h>
 int num;
int B;
 int rotate_check(int m)
{
    int result = 0;
    int n = m;
     while (1) {
	n = n / num + (n % num) * 10;
	if (m == n)
	    break;
	if (n > B)
	    continue;
	if (m < n)
	    ++result;
    }
     return result;
}

  int main(void)
{
    int T, A;
    int i, j;
    int result;
     scanf("%d", &T);
    for (i = 1; i <= T; ++i) {
	result = 0;
	 scanf("%d %d", &A, &B);
	num = 1;
	for (j = A / 10; j > 0; j /= 10) {
	    num *= 10;
	}
	 for (j = A; j < B; ++j) {
	    result += rotate_check(j);
	}
	 printf("Case #%d: %d\n", i, result);
    }
     return 0;
}


