#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int data;
int y;
long long dp[55][55][5];
long long now;
long long time;
long long add;
long long a[55][55];
long long a[55][55];
long long t[55][55];
int Main()
{
	int first_iteration;
	int i;
	int pos;
	int p;
	int l;
	int a;
	int n;
	int size;
	int count = 0;
	scanf("%d", &size);
	while (size--) {
		scanf("%d%d", &data, &y);
		for (i = 0; i < data; i++)
			for (pos = 0; pos < y; pos++)
				scanf("%lld%lld%lld", a[(data - 1) - i] + pos,
				      a[(data - 1) - i] + pos,
				      t[(data - 1) - i] + pos);
		for (i = 0; i < data; i++)
			for (pos = 0; pos < y; pos++) {
				t[i][pos] =
				    (-t[i][pos]) % (a[i][pos] + a[i][pos]);
				if (t[i][pos] < 0)
					t[i][pos] += a[i][pos] + a[i][pos];
			}
		for (i = 0; i < data; i++)
			for (pos = 0; pos < y; pos++)
				for (p = 0; p < 4; p++)
					dp[i][pos][p] = 100000000000000000LL;
		dp[0][0][0] = 0;
		for (;;) {
			int fg = 0;
			for (i = 0; i < data; i++)
				for (pos = 0; pos < y; pos++) {
					p = 0;
					now = dp[i][pos][p];
					if (i
					    && (dp[i - 1][pos][2] > (now + 2)))
						dp[i - 1][pos][2] =
						    now + 2, fg++;
					if (pos
					    && (dp[i][pos - 1][1] > (now + 2)))
						dp[i][pos - 1][1] =
						    now + 2, fg++;
					time =
					    (now + t[i][pos]) % (a[i][pos] +
								 a[i][pos]);
					if (time < a[i][pos])
						add = 1;
					else
						add =
						    ((a[i][pos] + a[i][pos]) -
						     time) + 1;
					if (dp[i][pos][2] > (now + add))
						dp[i][pos][2] = now + add, fg++;
					if (time >= a[i][pos])
						add = 1;
					else
						add = (a[i][pos] - time) + 1;
					if (dp[i][pos][1] > (now + add))
						dp[i][pos][1] = now + add, fg++;
					p = 1;
					now = dp[i][pos][p];
					if (i
					    && (dp[i - 1][pos][3] > (now + 2)))
						dp[i - 1][pos][3] =
						    now + 2, fg++;
					if (((pos + 1) < y)
					    && (dp[i][pos + 1][0] > (now + 2)))
						dp[i][pos + 1][0] =
						    now + 2, fg++;
					time =
					    (now + t[i][pos]) % (a[i][pos] +
								 a[i][pos]);
					if (time < a[i][pos])
						add = 1;
					else
						add =
						    ((a[i][pos] + a[i][pos]) -
						     time) + 1;
					if (dp[i][pos][3] > (now + add))
						dp[i][pos][3] = now + add, fg++;
					if (time >= a[i][pos])
						add = 1;
					else
						add = (a[i][pos] - time) + 1;
					if (dp[i][pos][0] > (now + add))
						dp[i][pos][0] = now + add, fg++;
					p = 2;
					now = dp[i][pos][p];
					if (((i + 1) < data)
					    && (dp[i + 1][pos][0] > (now + 2)))
						dp[i + 1][pos][0] =
						    now + 2, fg++;
					if (pos
					    && (dp[i][pos - 1][3] > (now + 2)))
						dp[i][pos - 1][3] =
						    now + 2, fg++;
					time =
					    (now + t[i][pos]) % (a[i][pos] +
								 a[i][pos]);
					if (time < a[i][pos])
						add = 1;
					else
						add =
						    ((a[i][pos] + a[i][pos]) -
						     time) + 1;
					if (dp[i][pos][0] > (now + add))
						dp[i][pos][0] = now + add, fg++;
					if (time >= a[i][pos])
						add = 1;
					else
						add = (a[i][pos] - time) + 1;
					if (dp[i][pos][3] > (now + add))
						dp[i][pos][3] = now + add, fg++;
					p = 3;
					now = dp[i][pos][p];
					if (((i + 1) < data)
					    && (dp[i + 1][pos][1] > (now + 2)))
						dp[i + 1][pos][1] =
						    now + 2, fg++;
					if (((pos + 1) < y)
					    && (dp[i][pos + 1][2] > (now + 2)))
						dp[i][pos + 1][2] =
						    now + 2, fg++;
					time =
					    (now + t[i][pos]) % (a[i][pos] +
								 a[i][pos]);
					if (time < a[i][pos])
						add = 1;
					else
						add =
						    ((a[i][pos] + a[i][pos]) -
						     time) + 1;
					if (dp[i][pos][1] > (now + add))
						dp[i][pos][1] = now + add, fg++;
					if (time >= a[i][pos])
						add = 1;
					else
						add = (a[i][pos] - time) + 1;
					if (dp[i][pos][2] > (now + add))
						dp[i][pos][2] = now + add, fg++;
				}
			if (!fg)
				break;
		}
		printf("Case #%d: %lld\n", ++count, dp[data - 1][y - 1][3]);
	}
	return 0;
}
