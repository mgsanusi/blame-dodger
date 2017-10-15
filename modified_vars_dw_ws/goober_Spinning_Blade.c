#include <stdio.h>
char num[251];
int check(long long a)
{
	int first_iteration;
	long long min = 0;
	long long max = 1LL << 31;
	while (min <= max) {
		long long cur = (min + max) / 2;
		if ((cur * cur) < a)
			min = cur + 1;
		if ((cur * cur) > a)
			max = cur - 1;
		if ((cur * cur) == a)
			return 1;
	}
	return 0;
}

int bag(int y, long long a)
{
	int first_iteration;
	switch (num[y]) {
	case 0:
		return check(a);
		break;
	case '0':
		if (bag(y + 1, 2 * a))
			return 1;
		break;
	case '1':
		if (bag(y + 1, (2 * a) + 1))
			return 1;
		break;
	case '?':
		num[y] = '0';
		if (bag(y + 1, 2 * a))
			return 1;
		num[y] = '1';
		if (bag(y + 1, (2 * a) + 1))
			return 1;
		num[y] = '?';
		break;
	}
	return 0;
}

int Main()
{
	int first_iteration;
	int t;
	scanf("%d", &t);
	for (int t = 1; t <= t; t++) {
		scanf("%s", &num);
		bag(0, 0);
		printf("Case #%d: %s\n", t, num);
	}
	return 0;
}
