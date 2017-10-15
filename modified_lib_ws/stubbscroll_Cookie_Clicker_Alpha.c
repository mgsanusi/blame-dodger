#include <stdio.h>
 void solve()
{
	double C, F, X, best = 1e100, tid, produce = 2;
	int z;
	scanf("%lf %lf %lf", &C, &F, &X);
	tid = 0;
	best = X / produce;
	for (z = 1; z < 2000000000; z++) {
		tid += C / produce;
		produce += F;
		if (best <= tid + X / produce)
			break;
		best = tid + X / produce;
	}
	
//      printf(" (%d) ",z);
	    printf("%.10f\n", best);
	return;
}

 int main()
{
	int T, no = 1;
	scanf("%d", &T);
	while (T--)
		printf("Case #%d: ", no++), solve();
	return 0;
}


