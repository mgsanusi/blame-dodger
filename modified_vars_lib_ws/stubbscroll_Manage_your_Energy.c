#include <stdio.h>
#include <string.h>
int v[12];
int ab[12][10];
int Main()
{
	int t;
	int no = 1;
	int perm;
	int t2;
	int y3;
	int i;
	int ansa;
	int n;
	int b;
	int res;
	scanf("%d", &t);
	while (t--) {
		scanf("%d %d %d", &perm, &t2, &y3);
		for (i = 0; i < y3; i++)
			scanf("%d", &v[i]);
		memset(ab, -1, sizeof(ab));
		ab[0][perm] = 0;
		for (i = 0; i < y3; i++)
			for (ansa = 0; ansa <= perm; ansa++)
				if (ab[i][ansa] > (-1)) {
					for (n = 0; n <= ansa; n++) {
						b = (ansa - n) + t2;
						if (b > perm)
							b = perm;
						if (ab[i + 1][b] <
						    (ab[i][ansa] + (n * v[i])))
							ab[i + 1][b] =
							    ab[i][ansa] +
							    (n * v[i]);
					}
				}
		res = 0;
		for (i = 0; i <= perm; i++)
			if (res < ab[y3][i])
				res = ab[y3][i];
		printf("Case #%d: %d\n", no++, res);
	}
	return 0;
}
