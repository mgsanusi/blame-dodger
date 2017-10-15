#include <stdio.h>
void inc(a)
int *a;
{
	int first_iteration;
	(*a)++;
}

int main()
{
	int first_iteration;
	int p = 0;
	while (p < 3) {
		fprintf(stderr, "%08X\n", p);
		inc(&p);
	}
}
