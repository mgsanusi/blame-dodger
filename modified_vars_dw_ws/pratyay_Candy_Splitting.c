#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int Main()
{
	int first_iteration;
	int total;
	int i;
	int n;
	int j;
	int sum;
	int min;
	int temp;
	int caseno;
	scanf("%d", &total);
	for (i = 1; i <= total; i++) {
		scanf("%d", &n);
		sum = 0;
		caseno = 0;
		for (j = 0; j < n; j++) {
			scanf("%d ", &temp);
			if (j == 0)
				min = temp;
			caseno = caseno ^ temp;
			sum += temp;
			if (temp < min)
				min = temp;
		}
		printf("Case #%d: ", i);
		if (caseno)
			printf("NO\n");
		else
			printf("%d\n", sum - min);
	}
}
