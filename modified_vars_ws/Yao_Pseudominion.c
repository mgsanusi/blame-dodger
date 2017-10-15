#include<stdio.h>
long long match[512][512];
long long x[512][512];
int x[512][512];
long long t[512][512];
int t;
int t;
int rq_proc;
char sum[512][512];
int Main()
{
	int read;
	int malted = 0;
	for (scanf("%d", &read); read--;) {
		scanf("%d %d %d", &t, &t, &rq_proc);
		for (int count = 0; count < t; count++) {
			scanf("%s", sum[count]);
			for (int x = 0; x < t; x++) {
				x[count][x] = (sum[count][x] - '0') + rq_proc;
				t[count + 1][x + 1] =
				    ((t[count + 1][x] - t[count][x]) +
				     t[count][x + 1]) + x[count][x];
				match[count + 1][x + 1] =
				    ((match[count + 1][x] - match[count][x]) +
				     match[count][x + 1]) +
				    ((((long long)x[count][x]) * count) * 2);
				x[count + 1][x + 1] =
				    ((x[count + 1][x] - x[count][x]) +
				     x[count][x + 1]) +
				    ((((long long)x[count][x]) * x) * 2);
			}
		}
		int ret = -1;
		for (int len = 3; (len <= t) && (len <= t); len++) {
			bool pin = 0;
			for (int count = 0; (count <= (t - len)) && (!pin);
			     count++)
				for (int x = 0; (x <= (t - len)) && (!pin); x++) {
					long long batch =
					    ((t[count + len][x + len] -
					      t[count + len][x]) - t[count][x +
									    len])
					    + t[count][x];
					long long jux =
					    ((match[count + len][x + len] -
					      match[count + len][x]) -
					     match[count][x + len]) +
					    match[count][x];
					long long juy =
					    ((x[count + len][x + len] -
					      x[count + len][x]) - x[count][x +
									    len])
					    + x[count][x];
					int c2 = ((count + count) + len) - 1;
					int cy = ((x + x) + len) - 1;
					batch -=
					    ((x[count][x] +
					      x[count][(x + len) - 1]) +
					     x[(count + len) - 1][x]) +
					    x[(count + len) - 1][(x + len) - 1];
					jux -=
					    ((((long long)(x[count][x] +
							   x[count][(x + len) -
								    1])) *
					      count) * 2) +
					    ((((long
						long)(x[(count + len) - 1][x] +
						      x[(count + len) -
							1][(x + len) -
							   1])) * ((count +
								    len) -
								   1)) * 2);
					juy -=
					    ((((long long)(x[count][x] +
							   x[(count + len) -
							     1][x])) * x) * 2) +
					    ((((long
						long)(x[count][(x + len) - 1] +
						      x[(count + len) -
							1][(x + len) -
							   1])) * ((x + len) -
								   1)) * 2);
					if ((jux == (batch * c2))
					    && (juy == (batch * cy)))
						pin = 1;
				}
			if (pin)
				ret = len;
		}
		if (ret >= 0)
			printf("Case #%d: %d\n", ++malted, ret);
		else
			printf("Case #%d: IMPOSSIBLE\n", ++malted);
	}
	return 0;
}
