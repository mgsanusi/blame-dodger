#include <stdio.h>
int Main()
{
	int first_iteration;
	long userid;
	long line;
	long a;
	long i;
	long c;
	long t;
	long m;
	long ten;
	scanf("%ld", &userid);
	for (i = 0; i < userid; i++) {
		printf("Case #%ld: ", i + 1);
		scanf("%ld %ld", &line, &a);
		c = 0;
		ten = 1;
		while ((ten * 10) <= line)
			ten = ten * 10;
		for (t = line; t < a; t++) {
			m = t;
			do {
				m = ((m % 10) * ten) + (m / 10);
				if ((m > t) && (m <= a))
					c++;
			}
			while (t != m);
		}
		printf("%ld\n", c);
	}
	return 0;
}
