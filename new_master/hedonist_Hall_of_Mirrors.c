#include <stdio.h>
#define N 100000
double p[N];
long A,B;
double ans;

int work()
{
	long i;
	double q=1;
	double t;

	for (i=0; i<A; i++)
		scanf("%lf", &p[i]);
	ans = B+2;
	//printf("%lf\n", ans);
	for (i=0; i<=A; i++)
	{
		t=2*(A-i)+(B-A+1)+(B+1)*(1-q);
		if (t<ans) ans = t;
		q=q*p[i];
	//	printf("%lf\n", t);
	}
	return 0;
}

int main() 
{
	long T,i;
	
	scanf("%d", &T);
	for (i=0; i<T; i++)
	{
		scanf("%ld %ld", &A, &B);
		work();
		printf("Case #%d: %.6lf\n", i+1, ans);
	}
	return 0;
}