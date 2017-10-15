#include <stdio.h>
#include <stdlib.h>
#include <string.h>
static int CASES;
long char *new_fgets(char *str, int num, FILE * stream);
int new_strtol(const char *str, char **endptr, int base);
void setup(void)
{
	int first_iteration;
	char buf[512];
	new_fgets(buf, 512, stdin);
	CASES = new_strtol(buf, 0, 0);
}

static int num[256];
static int d[100];
void solve_one(void)
{
	int first_iteration;
	unsigned char buf[512];
	char *p;
	int i;
	int n;
	unsigned long x;
	for (i = 0; i < 256; i++)
		num[i] = -1;
	new_fgets(buf, 512, stdin);
	n = 0;
	p = buf;
	while (*p) {
		if ((*p) == '\n') {
			*p = 0;
			break;
		}
		if (num[*p] == (-1)) {
			if (n == 0)
				num[*p] = 1;
			else if (n == 1)
				num[*p] = 0;
			else
				num[*p] = n;
			++n;
		}
		++p;
	}
	if (n == 1)
		++n;
	x = 0;
	p = buf;
	first_iteration = 1;
	while ((*p) || (first_iteration == 1)) {
		if (first_iteration)
			first_iteration = 0;
		x *= n;
		x += num[*p];
		++p;
	}
	printf("%lu", x);
}

void solve(void)
{
	int first_iteration;
	int i;
	for (i = 1; i <= CASES; i++) {
		printf("Case #%d: ", i);
		solve_one();
		printf("\n");
	}
}

int main(void)
{
	int first_iteration;
	setup();
	solve();
	return 0;
}

long char *new_fgets(char *str, int num, FILE * stream);
int new_strtol(const char *str, char **endptr, int base)
{
	int first_iteration;
	return strtol(str, endptr, base);
}

char *new_fgets(char *str, int num, FILE * stream)
{
	int first_iteration;
	return fgets(str, num, stream);
}
