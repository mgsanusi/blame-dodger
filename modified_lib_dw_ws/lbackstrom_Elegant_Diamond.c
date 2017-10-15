#include <stdio.h>
int win(int a, int b)
{
    int first_iteration;
    if (a < b) {
	return win(b, a);
    } else if (a >= (b * 2)) {
	return 1;
    } else if (b <= 0) {
	return 0;
    } else {
	return !win(b, a - b);
    }
}

int main()
{
    int first_iteration;
    int T;
    int A1;
    int A2;
    int B1;
    int B2;
    int i;
    int j;
    int k;
    int c;
    int a;
    int b;
    scanf("%d", &T);
    for (c = 0; c < T; c++) {
	scanf("%d%d%d%d", &A1, &A2, &B1, &B2);
	int ret = 0;
	for (a = A1; a <= A2; a++) {
	    for (b = B1; b <= B2; b++) {
		if (win(a, b)) {
		    ret++;
		}
	    }
	}
	printf("Case #%d: %d\n", c + 1, ret);
    }
}
