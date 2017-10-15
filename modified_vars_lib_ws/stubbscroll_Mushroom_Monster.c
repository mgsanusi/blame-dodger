#include <stdio.h>
int out;
int tid[1000];
int left[1000];
int d2;
void clear()
{
	static int caseno = 1;
	int i = -1;
	int min;
	int th2;
	int mul;
	int cycle;
	scanf("%d %d", &out, &d2);
	for (i = 0; i < out; i++)
		scanf("%d", &tid[i]), left[i] = 0;
	for (mul = 1, i = 0; i < out; i++)
		mul *= tid[i];
	for (cycle = (i = 0); i < out; i++)
		cycle += mul / tid[i];
	if (d2 > cycle) {
		d2 %= cycle;
		if (!d2)
			d2 = cycle;
	}
	for (i = (th2 = 0); th2 < d2; th2++) {
		min = 123123123;
		for (i = 0; i < out; i++)
			if (min > left[i])
				min = left[i];
		if (min)
			for (i = 0; i < out; i++)
				left[i] -= min;
		for (i = 0; left[i]; i++) ;
		left[i] = tid[i];
	}
	printf("Case #%d: %d\n", caseno++, i + 1);
}

int Main()
{
	int a;
	scanf("%d", &a);
	while (a--)
		clear();
	return 0;
}
