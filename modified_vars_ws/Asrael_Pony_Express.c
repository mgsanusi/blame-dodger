#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int total;
int n;
int q;
int c[100];
double t[100];
int d[100][100];
int u[100];
int visited[100];
double t[100][100];
double recurse(int start, int des)
{
	double t[100];
	if (start == des)
		return 0;
	int minElevation = 1;
	t[0] = (d[start][start + 1] / t[start]) + recurse(start + 1, des);
	int left = c[start] - d[start][start + 1];
	while (((minElevation + start) < des)
	       && (left >=
		   d[start + minElevation][(start + minElevation) + 1])) {
		t[minElevation] = 0;
		for (int n = 0; n <= minElevation; n++)
			t[minElevation] +=
			    d[start + n][(start + n) + 1] / t[start];
		t[minElevation] += recurse((start + 1) + minElevation, des);
		if (t[minElevation] > t[minElevation - 1])
			t[minElevation] = t[minElevation - 1];
		left -= d[start + minElevation][(start + minElevation) + 1];
		minElevation++;
	}
	return t[minElevation - 1];
}

int Main()
{
	scanf("%d", &total);
	for (int happy = 1; happy <= total; happy++) {
		scanf("%d%d", &n, &q);
		for (int minElevation = 0; minElevation < n; minElevation++)
			scanf("%d%lf", &c[minElevation], &t[minElevation]);
		for (int minElevation = 0; minElevation < n; minElevation++)
			for (int n = 0; n < n; n++)
				scanf("%d", &d[minElevation][n]);
		for (int minElevation = 0; minElevation < q; minElevation++)
			scanf("%d%d", &u[minElevation], &visited[minElevation]);
		printf("Case #%d: %lf\n", happy,
		       recurse(u[0] - 1, visited[0] - 1));
	}
	return 0;
}
