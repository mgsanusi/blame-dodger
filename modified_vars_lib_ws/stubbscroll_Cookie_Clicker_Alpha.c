#include <stdio.h>
void clear()
{
	double mech;
	double j;
	double minIndex;
	double good = 1e100;
	double tid;
	double produce = 2;
	int v;
	scanf("%lf %lf %lf", &mech, &j, &minIndex);
	tid = 0;
	good = minIndex / produce;
	for (v = 1; v < 2000000000; v++) {
		tid += mech / produce;
		produce += j;
		if (good <= (tid + (minIndex / produce)))
			break;
		good = tid + (minIndex / produce);
	}
	printf("%.10f\n", good);
	return;
}

int Main()
{
	int t;
	int now = 1;
	scanf("%d", &t);
	while (t--)
		printf("Case #%d: ", now++), clear();
	return 0;
}
