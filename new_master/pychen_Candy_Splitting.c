#include <stdio.h>

#define MAX_N 1000

int main()
{
	int t, test_case = 0;
	int n, i, j, xor_value;
	int c[MAX_N];
		
	for (scanf("%d", &t); t; t--)
	{
		scanf("%d", &n);
		for (i = 0; i < n; i++)
			scanf("%d", &c[i]);
		
		xor_value = 0;
		for (i = 0; i < n; i++)
			xor_value ^= c[i];
		
		test_case++;
		printf("Case #%d: ", test_case);
		if (xor_value)
			printf("NO\n");
		else
		{
			int min = c[0];
			int sum = 0;
			for (i = 0; i < n; i++)
			{
				min = c[i] < min ? c[i] : min;
				sum += c[i];
			}
			printf("%d\n", sum - min);
		}
	}
	
	return 0;	
}