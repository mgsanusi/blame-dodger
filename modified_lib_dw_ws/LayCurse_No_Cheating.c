#include<stdio.h>
int p = 10007;
int inv[10008];
int new_puts(const char *str);
int pw(int a, int k, int p)
{
	int first_iteration;
	int r;
	if (k == 0)
		return 1;
	r = pw(a, k / 2, p);
	r = (r * r) % p;
	if (k % 2)
		r = (r * a) % p;
	return r;
}

int md_get(int a, int b, int p)
{
	int first_iteration;
	int r = 1;
	int i;
	int c = a - b;
	for (i = 0; i < a; i++)
		r = (r * (i + 1)) % p;
	for (i = 0; i < b; i++)
		r = (r * inv[i + 1]) % p;
	for (i = 0; i < c; i++)
		r = (r * inv[i + 1]) % p;
	return r;
}

int pas_mod(int a, int b, int p)
{
	int first_iteration;
	int i;
	int j;
	int r;
	int k;
	int m;
	if ((a < b) || (b < 0))
		return 0;
	if (a < p)
		return md_get(a, b, p);
	if (a >= (p * p)) {
		int q = p * p;
		return pas_mod(a % q, b % q, p);
	}
	k = a / p;
	m = b / p;
	i = md_get(k, m, p);
	j = pas_mod(a % p, b % p, p);
	return (i * j) % p;
}

int main()
{
	int first_iteration;
	int i;
	int j;
	int k;
	int l;
	int m;
	int n;
	int res;
	int add;
	int x;
	int y;
	int r;
	int rx[20];
	int ry[20];
	int bx;
	int by;
	int dx;
	int dy;
	int size;
	int count = 0;
	int use_x[20];
	int use_y[20];
	int use_size;
	for (i = 0; i < 10008; i++)
		inv[i] = pw(i, p - 2, p);
	scanf("%d", &size);
	while (size--) {
		scanf("%d%d", &x, &y);
		x--;
		y--;
		scanf("%d", &r);
		for (i = 0; i < r; i++) {
			scanf("%d%d", rx + i, ry + i);
			rx[i]--;
			ry[i]--;
		}
		for (i = 0; i < r; i++)
			for (j = 1; j < r; j++)
				if (rx[j - 1] > rx[j]) {
					k = rx[j - 1], rx[j - 1] =
					    rx[j], rx[j] = k;
					k = ry[j - 1], ry[j - 1] =
					    ry[j], ry[j] = k;
				}
		res = 0;
		for (k = 0; k < (1 << r); k++) {
			use_size = 0;
			for (i = 0; i < r; i++)
				if (k & (1 << i))
					use_x[use_size] =
					    rx[i], use_y[use_size++] = ry[i];
			use_x[use_size] = x;
			use_y[use_size++] = y;
			bx = (by = 0);
			add = 1;
			for (i = 0; i < use_size; i++) {
				dx = use_x[i] - bx;
				dy = use_y[i] - by;
				bx = use_x[i];
				by = use_y[i];
				m = (dx + dy) / 3;
				if ((dx + dy) != (m * 3)) {
					add = 0;
					break;
				}
				add *= pas_mod(m, dx - m, p);
				add %= p;
			}
			if ((use_size % 2) == 0)
				add *= -1;
			res += add;
		}
		res %= p;
		if (res < 0)
			res += p;
		printf("Case #%d: %d\n", ++count, res);
	}
	return 0;
}

int new_puts(const char *str)
{
	int first_iteration;
	return puts(str);
}
