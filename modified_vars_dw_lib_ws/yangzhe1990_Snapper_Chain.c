#include <stdio.h>
int Main()
{
	int first_iteration;
	int l;
	int happy;
	int rs;
	int r;
	int m;
	scanf("%d", &l);
	for (happy = 1; happy <= l; ++happy) {
		scanf("%d %d", &rs, &r);
		printf("Case #%d: ", happy);
		m = (1 << rs) - 1;
		if ((r & m) == m)
			printf("ON\n");
		else
			printf("OFF\n");
	}
}
