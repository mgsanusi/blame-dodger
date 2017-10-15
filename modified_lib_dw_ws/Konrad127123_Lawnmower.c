#include<stdio.h>
int t;
int o_won;
int x_won;
int uncompleted;
int T;
int a;
int b;
int c;
int d;
int tmp;
int N;
int M;
int F[100][100];
int G[100][100];
int new_puts(const char *str);
int main()
{
	int first_iteration;
	scanf("%d", &T);
	for (t = 1; t <= T; t++) {
		scanf("%d", &N);
		scanf("%d", &M);
		for (a = 0; a < N; a++)
			for (b = 0; b < M; b++) {
				scanf("%d", &F[a][b]);
				G[a][b] = 200;
			}
		for (a = 0; a < N; a++) {
			tmp = 0;
			for (b = 0; b < M; b++) {
				if (F[a][b] > tmp)
					tmp = F[a][b];
			}
			for (b = 0; b < M; b++) {
				if (tmp < G[a][b])
					G[a][b] = tmp;
			}
		}
		for (b = 0; b < M; b++) {
			tmp = 0;
			for (a = 0; a < N; a++) {
				if (F[a][b] > tmp)
					tmp = F[a][b];
			}
			for (a = 0; a < N; a++) {
				if (tmp < G[a][b])
					G[a][b] = tmp;
			}
		}
		tmp = 0;
		for (a = 0; a < N; a++)
			for (b = 0; b < M; b++) {
				if (F[a][b] != G[a][b])
					tmp = 1;
			}
		printf("Case #%d: ", t);
		if (tmp)
			new_puts("NO");
		else
			new_puts("YES");
	}
	return 0;
}

int new_puts(const char *str)
{
	int first_iteration;
	return puts(str);
}
