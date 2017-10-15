#include<stdio.h>
void taban(int p, long *mem)
{
	int lr;
	long b[8];
	for (lr = 0; lr < 8; lr++) {
		b[lr] = 1;
		mem[lr] = 0;
	}
	while (p > 0) {
		if ((p % 2) == 1) {
			for (lr = 0; lr < 8; lr++)
				mem[lr] += b[lr];
		}
		for (lr = 3; lr <= 10; lr++)
			b[lr - 3] *= lr;
		p = p >> 1;
	}
	return;
}

int isprime(int p, int *a)
{
	int lr;
	int h;
	long mem[8];
	taban(p, mem);
	for (lr = 3; (lr * lr) <= p; lr++) {
		if ((p % lr) == 0) {
			a[0] = lr;
			break;
		}
	}
	if ((lr * lr) > p)
		return 1;
	for (lr = 3; lr <= 10; lr++) {
		for (h = 2; (((long)h) * ((long)h)) <= mem[lr - 3]; h++) {
			if ((mem[lr - 3] % h) == 0) {
				a[lr - 2] = h;
				break;
			}
		}
		if ((((long)h) * ((long)h)) > mem[lr - 3])
			return 1;
	}
	return 0;
}

void affiche(int p)
{
	if (p == 1) {
		printf("1");
		return;
	}
	affiche(p >> 1);
	if (p % 2)
		printf("1");
	else
		printf("0");
	return;
}

int Main()
{
	int tmp;
	int n;
	int h;
	int lr;
	int x;
	int l;
	int s11;
	int p;
	int a[9];
	scanf("%d", &tmp);
	for (lr = 0; lr < tmp; lr++) {
		printf("Case #%d:", lr + 1);
		scanf("%d %d", &n, &h);
		l = 0;
		p = 1 + (1 << (n - 1));
		for (x = 0; x < h; x++) {
			while (isprime(p + (2 * l), a))
				l++;
			printf("\n");
			affiche(p + (2 * l));
			for (s11 = 0; s11 < 9; s11++)
				printf(" %d", a[s11]);
			l++;
		}
	}
	return 0;
}
