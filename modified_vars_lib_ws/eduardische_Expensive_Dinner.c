#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stddef.h>
long long
void *new_memset(void *ptr, int value, size_t num);
int get_value(long long int a[505][505], int x, int t)
{
	if ((x < 0) || (t < 0))
		return 0LL;
	else
		return a[x][t];
}

int Main()
{
	int n;
	int mask;
	scanf("%d", &n);
	static char s[505];
	static int m[505][505];
	static long long int n[505][505];
	static long long int map[505][505];
	static long long int lasti[505][505];
	static long long int oowp[505][505];
	for (mask = 0; mask < n; mask++) {
		new_memset(n, 0, sizeof(n));
		new_memset(map, 0, sizeof(map));
		new_memset(lasti, 0, sizeof(lasti));
		new_memset(oowp, 0, sizeof(oowp));
		int n;
		int ca;
		int cache;
		scanf("%d %d %d\n", &n, &ca, &cache);
		int length;
		int zip;
		for (length = 0; length < n; length++) {
			scanf("%s\n", s);
			for (zip = 0; zip < ca; zip++) {
				m[length][zip] = cache + ((int)(s[zip] - '0'));
			}
		}
		for (length = 0; length < n; length++) {
			for (zip = 0; zip < ca; zip++) {
				n[length][zip] =
				    (((((long long int)length) *
				       ((long long int)m[length][zip])) +
				      get_value(n, length - 1,
						zip)) + get_value(n, length,
								  zip - 1)) -
				    get_value(n, length - 1, zip - 1);
				map[length][zip] =
				    ((((long long int)m[length][zip]) +
				      get_value(map, length - 1,
						zip)) + get_value(map, length,
								  zip - 1)) -
				    get_value(map, length - 1, zip - 1);
				lasti[length][zip] =
				    (((((long long int)zip) *
				       ((long long int)m[length][zip])) +
				      get_value(lasti, length - 1,
						zip)) + get_value(lasti, length,
								  zip - 1)) -
				    get_value(lasti, length - 1, zip - 1);
				oowp[length][zip] =
				    ((((long long int)m[length][zip]) +
				      get_value(oowp, length - 1,
						zip)) + get_value(oowp, length,
								  zip - 1)) -
				    get_value(oowp, length - 1, zip - 1);
			}
		}
		printf("Case #%d: ", mask + 1);
		char flag = 0;
		int s;
		if (n < ca)
			s = n;
		else
			s = ca;
		while (s >= 3) {
			for (length = 0; ((length + s) - 1) < n; length++) {
				for (zip = 0; ((zip + s) - 1) < ca; zip++) {
					long long int n =
					    ((get_value
					      (n, (length + s) - 1,
					       (zip + s) - 1) - get_value(n,
									  length
									  - 1,
									  (zip +
									   s) -
									  1)) -
					     get_value(n, (length + s) - 1,
						       zip - 1)) + get_value(n,
									     length
									     -
									     1,
									     zip
									     -
									     1);
					long long int output_str_size =
					    ((get_value
					      (map, (length + s) - 1,
					       (zip + s) - 1) - get_value(map,
									  length
									  - 1,
									  (zip +
									   s) -
									  1)) -
					     get_value(map, (length + s) - 1,
						       zip - 1)) +
					    get_value(map, length - 1, zip - 1);
					long long int o_won =
					    ((get_value
					      (lasti, (length + s) - 1,
					       (zip + s) - 1) - get_value(lasti,
									  length
									  - 1,
									  (zip +
									   s) -
									  1)) -
					     get_value(lasti, (length + s) - 1,
						       zip - 1)) +
					    get_value(lasti, length - 1,
						      zip - 1);
					long long int loss =
					    ((get_value
					      (oowp, (length + s) - 1,
					       (zip + s) - 1) - get_value(oowp,
									  length
									  - 1,
									  (zip +
									   s) -
									  1)) -
					     get_value(oowp, (length + s) - 1,
						       zip - 1)) +
					    get_value(oowp, length - 1,
						      zip - 1);
					int x;
					int t;
					x = length;
					t = zip;
					n -= ((long long int)x) *
					    ((long long int)m[x][t]);
					output_str_size -=
					    (long long int)m[x][t];
					o_won -=
					    ((long long int)t) *
					    ((long long int)m[x][t]);
					loss -= (long long int)m[x][t];
					x = length;
					t = (zip + s) - 1;
					n -= ((long long int)x) *
					    ((long long int)m[x][t]);
					output_str_size -=
					    (long long int)m[x][t];
					o_won -=
					    ((long long int)t) *
					    ((long long int)m[x][t]);
					loss -= (long long int)m[x][t];
					x = (length + s) - 1;
					t = zip;
					n -= ((long long int)x) *
					    ((long long int)m[x][t]);
					output_str_size -=
					    (long long int)m[x][t];
					o_won -=
					    ((long long int)t) *
					    ((long long int)m[x][t]);
					loss -= (long long int)m[x][t];
					x = (length + s) - 1;
					t = (zip + s) - 1;
					n -= ((long long int)x) *
					    ((long long int)m[x][t]);
					output_str_size -=
					    (long long int)m[x][t];
					o_won -=
					    ((long long int)t) *
					    ((long long int)m[x][t]);
					loss -= (long long int)m[x][t];
					n *= 2LL;
					o_won *= 2LL;
					if (((n % output_str_size) == 0LL)
					    && ((o_won % loss) == 0LL)) {
						long long int nx;
						long long int dp;
						nx = n / output_str_size;
						dp = o_won / loss;
						if (((length +
						      ((length + s) - 1)) == nx)
						    && ((zip + ((zip + s) - 1))
							== dp)) {
							printf("%d\n", s);
							flag = 1;
							break;
						}
					}
				}
				if (flag)
					break;
			}
			if (flag)
				break;
			s--;
		}
		if (!flag)
			printf("IMPOSSIBLE\n");
	}
	return 0;
}

void *new_memset(void *ptr, int value, size_t num)
{
	return memset(ptr, value, num);
}
