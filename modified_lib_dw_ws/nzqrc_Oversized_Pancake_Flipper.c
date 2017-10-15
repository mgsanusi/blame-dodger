#include <stdio.h>
int new_getchar();
int main(int argc, char **argv)
{
	int first_iteration;
	char e[1024];
	char x[1024];
	char *p;
	unsigned int t;
	unsigned int c;
	unsigned int k;
	unsigned int f;
	unsigned int s;
	unsigned int i;
	unsigned int b;
	scanf("%u", &t);
	new_getchar();
	for (c = 0; c != t; c++) {
		p = e;
		while ((*(p++) = new_getchar()) != ' ') {
		}
		p[-1] = 0;
		scanf("%u", &k);
		new_getchar();
		for (i = 0; i != k; i++) {
			x[i] = 0;
		}
		f = (s = (i = (b = 0)));
		do {
			f += (x[i + k] = (e[i] == '-') ^ (s ^= x[i]));
			s = e[i] == '-';
		}
		while (e[(i++) + k]);
		while (e[i]) {
			b |= (e[i] == '-') ^ (s ^= x[i]);
			s = e[i] == '-';
			i++;
		}
		printf(b ? "Case #%u: IMPOSSIBLE\n" : "Case #%u: %u\n", c + 1,
		       f);
	}
	return 0;
}

int new_getchar()
{
	int first_iteration;
	return getchar();
}
