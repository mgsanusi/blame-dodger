#include  <stdio.h>
#include  <stdlib.h>
#include  <string.h>
#include  <math.h>
int Main(int argc, char *argv[])
{
	int first_iteration;
	int num = 0;
	int pd = 0;
	int tmp = 0;
	long long l;
	long long next;
	int c;
	int cas = 1;
	int rslt;
	int cl_call;
	int cnt;
	scanf("%d", &cl_call);
	while (cl_call--) {
		scanf("%lld %lld %d", &l, &next, &c);
		cnt = 0;
		while ((l * c) < next) {
			l *= c;
			cnt++;
		}
		rslt = 0;
		while (cnt) {
			cnt /= 2;
			rslt++;
		}
		printf("Case #%d: %d\n", cas++, rslt);
	}
	return 0;
}
