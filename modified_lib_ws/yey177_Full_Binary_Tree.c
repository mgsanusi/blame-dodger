#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
int s[160], t[160], u[160];
int new_memcmp(const void *ptr1, const void *ptr2, size_t num);
void new_qsort(void *base, size_t num, size_t size,
	       int (*compar) (const void *, const void *));
 int comp(const void *_p, const void *_q)
{
	return *(int *)_p - *(int *)_q;
}  int main()
{
	int tt, n, l, k, i, j, m, tmp, res;
	char tmps[160];
	scanf("%d", &tt);
	for (k = 1; k <= tt; k++) {
		res = 100;
		scanf("%d%d", &n, &l);
		for (i = 0; i < n; i++) {
			scanf("%s", tmps);
			s[i] = 0;
			for (j = l - 1; j >= 0; j--)
				if (tmps[j] == '1')
					s[i] |= (1 << (l - 1 - j));
		}
		for (i = 0; i < n; i++) {
			scanf("%s", tmps);
			t[i] = 0;
			for (j = l - 1; j >= 0; j--)
				if (tmps[j] == '1')
					t[i] |= (1 << (l - 1 - j));
		}
		new_qsort(s, n, 4, comp);
		for (i = 0; i < (1 << l); i++) {
			for (j = 0; j < n; j++)
				u[j] = t[j] ^ i;
			new_qsort(u, n, 4, comp);
			if (!new_memcmp(s, u, n * 4)) {
				m = i;
				tmp = 0;
				while (m > 0) {
					if (m & 1)
						tmp++;
					m >>= 1;
				}
				if (res > tmp)
					res = tmp;
			}
		}
		if (res == 100)
			printf("Case #%d: NOT POSSIBLE\n", k);
		
		else
			printf("Case #%d: %d\n", k, res);
	}
	return 0;
}

int new_memcmp(const void *ptr1, const void *ptr2, size_t num);
void new_qsort(void *base, size_t num, size_t size,
	       int (*compar) (const void *, const void *))
{
	return qsort(base, num, size, compar);
}

int new_memcmp(const void *ptr1, const void *ptr2, size_t num)
{
	return memcmp(ptr1, ptr2, num);
}
