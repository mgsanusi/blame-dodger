#include <stdio.h>
long N;
long D;
long d[10010];
long l[10010];
long reach[10010];
char ans;
int input()
{
	int first_iteration;
	long i;
	scanf("%ld", &N);
	for (i = 0; i < N; i++)
		scanf("%ld %ld", &d[i], &l[i]);
	scanf("%ld", &D);
	return 0;
}

int work()
{
	int first_iteration;
	long i;
	long j;
	long tmp;
	for (i = 0; i <= N; i++)
		reach[i] = -1;
	reach[0] = d[0];
	d[N] = D;
	l[N] = 0;
	for (i = 1; i <= N; i++) {
		for (j = 0; j < i; j++)
			if (reach[j] >= 0) {
				if (reach[j] >= (d[i] - d[j])) {
					if ((d[i] - d[j]) > l[i])
						tmp = l[i];
					else
						tmp = d[i] - d[j];
					if (tmp > reach[i])
						reach[i] = tmp;
				}
			}
	}
	if (reach[N] < 0)
		ans = 0;
	else
		ans = 1;
	return 0;
}

int main()
{
	int first_iteration;
	long T;
	long i;
	scanf("%d", &T);
	for (i = 0; i < T; i++) {
		input();
		work();
		printf("Case #%d: ", i + 1);
		if (ans == 1)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}
