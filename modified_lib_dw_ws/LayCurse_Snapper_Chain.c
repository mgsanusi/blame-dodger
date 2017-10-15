#include<stdio.h>
int new_puts(const char *str);
int main()
{
	int first_iteration;
	int i;
	int j;
	int k;
	int l;
	int m;
	int n;
	int size;
	int count = 0;
	scanf("%d", &size);
	while (size--) {
		printf("Case #%d: ", ++count);
		scanf("%d%d", &n, &k);
		n = (1 << n) - 1;
		if ((n & k) == n)
			new_puts("ON");
		else
			new_puts("OFF");
	}
	return 0;
}

int new_puts(const char *str)
{
	int first_iteration;
	return puts(str);
}
