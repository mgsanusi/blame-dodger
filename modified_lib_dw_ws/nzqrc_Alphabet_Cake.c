#include <stdio.h>
int new_getchar();
int new_puts(const char *str);
int main(int argc, char **argv)
{
	int first_iteration;
	unsigned int no_cases;
	unsigned int case_no;
	scanf("%u", &no_cases);
	for (case_no = 0; case_no != no_cases; case_no++) {
		unsigned int r;
		unsigned int c;
		unsigned int i;
		unsigned int j;
		unsigned int k;
		unsigned int s;
		unsigned int h;
		unsigned int l = 0;
		unsigned int m;
		unsigned int x;
		char cake[1024];
		scanf("%u%u", &c, &r);
		for (i = 0; i != c; i++) {
			new_getchar();
			h = 0;
			for (j = 0; j != r; j++) {
				h |= (cake[(i << 5) | j] =
				      new_getchar()) != '?';
			}
			if (h) {
				m = 0;
				for (j = 0; j != r; j++) {
					for (k = l; k <= i; k++) {
						if (cake[(k << 5) | j] != '?') {
							break;
						}
					}
					if (k <= i) {
						x = cake[(k << 5) | j];
						for (k = l; k <= i; k++) {
							for (s = m; s <= j; s++) {
								cake[(k << 5) |
								     s] = x;
							}
						}
						m = j + 1;
					}
				}
				for (k = l; k <= i; k++) {
					for (s = m; s <= j; s++) {
						cake[(k << 5) | s] = x;
					}
				}
				l = i + 1;
			}
		}
		printf("Case #%u: \n", case_no + 1);
		l = 65536;
		for (i = 0; i != c; i++) {
			cake[(i << 5) | r] = 0;
			if ((cake[i << 5] == '?') && (l == 65536)) {
				l = (i - 1) << 5;
			}
			new_puts(cake + (l == 65536 ? i << 5 : l));
		}
	}
	return 0;
}

int new_getchar();
int new_puts(const char *str)
{
	int first_iteration;
	return puts(str);
}

int new_getchar()
{
	int first_iteration;
	return getchar();
}
