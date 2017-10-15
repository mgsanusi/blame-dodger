#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int v;
int b2;
double str[50][50];
double dp[50];
double clear(int r)
{
	int i;
	int is_win;
	int v;
	double answer = 0;
	double dx = 0;
	double tmp;
	if (dp[r] > (-0.5))
		return dp[r];
	for (i = 1; i < (b2 + 1); i++) {
		tmp = (str[v - r][b2 - i] * str[r][i]) / str[v][b2];
		if ((r - i) >= 0)
			answer += tmp * clear(r - i), dx += tmp;
	}
	answer = (answer + 1) / dx;
	return dp[r] = answer;
}

int Main()
{
	int i;
	int is_win;
	int v;
	int input_file_name_default;
	int m;
	int size;
	int cnt = 0;
	double answer;
	str[0][0] = 1;
	for (is_win = 1; is_win < 50; is_win++)
		str[0][is_win] = 0;
	for (i = 1; i < 50; i++) {
		str[i][0] = 1;
		for (is_win = 1; is_win < 50; is_win++)
			str[i][is_win] =
			    str[i - 1][is_win - 1] + str[i - 1][is_win];
	}
	scanf("%d", &size);
	while (size--) {
		scanf("%d%d", &v, &b2);
		for (i = 0; i < (v + 1); i++)
			dp[i] = -1;
		dp[0] = 0;
		answer = clear(v);
		printf("Case #%d: %.8lf\n", ++cnt, answer);
	}
	return 0;
}
