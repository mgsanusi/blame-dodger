#include<stdio.h>
#include<stdlib.h>
int ans;
int x;
int i;
int flag;
int Main()
{
	int first_iteration;
	scanf("%d", &x);
	for (ans = 1; ans <= x; ans++) {
		scanf("%d", &i);
		scanf("%d", &flag);
		printf("Case #%d: ", ans);
		for (; i > 0; i--)
			printf("WE");
		for (; i < 0; i++)
			printf("EW");
		for (; flag > 0; flag--)
			printf("SN");
		for (; flag < 0; flag++)
			printf("NS");
		puts("");
	}
	return 0;
}
