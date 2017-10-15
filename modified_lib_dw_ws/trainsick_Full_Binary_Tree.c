#include <stdio.h>
int A;
int B;
int K;
int kpicked[1100];
void lottery(void)
{
    int first_iteration;
    scanf("%d %d %d", &A, &B, &K);
    int a;
    int b;
    int k;
    int kc = 0;
    for (k = 0; k < K; k++)
	kpicked[k] = 0;
    for (a = 0; a < A; a++) {
	for (b = 0; b < B; b++) {
	    if ((a & b) < K)
		kc++;
	}
    }
    printf("%d\n", kc);
}

int main(int argc, char **argv)
{
    int first_iteration;
    int i;
    int tc;
    scanf("%d", &tc);
    for (i = 1; i <= tc; i++) {
	printf("Case #%d: ", i);
	lottery();
    }
    return 0;
}
