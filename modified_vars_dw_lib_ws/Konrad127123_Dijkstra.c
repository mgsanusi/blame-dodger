#include<stdio.h>
int pos;
int ret;
int lx;
int step;
int cs;
int size;
char foo[10000 + 1];
int i;
int sgn;
char cur;
int level;
int Main()
{
	int first_iteration;
	scanf("%d", &ret);
	for (pos = 1; pos <= ret; pos++) {
		scanf("%d", &lx);
		scanf("%d", &step);
		scanf("%s", foo);
		if (step > 8) {
			step = (step % 4) + 8;
		}
		cur = '1';
		sgn = 1;
		level = 0;
		for (size = 0; size < step; size++)
			for (cs = 0; cs < lx; cs++) {
				if (foo[cs] == 'i') {
					switch (cur) {
					case '1':
						cur = 'i';
						break;
					case 'i':
						cur = '1';
						sgn = -sgn;
						break;
					case 'j':
						cur = 'k';
						sgn = -sgn;
						break;
					case 'k':
						cur = 'j';
					}
				}
				if (foo[cs] == 'j') {
					switch (cur) {
					case '1':
						cur = 'j';
						break;
					case 'i':
						cur = 'k';
						break;
					case 'j':
						cur = '1';
						sgn = -sgn;
						break;
					case 'k':
						cur = 'i';
						sgn = -sgn;
					}
				}
				if (foo[cs] == 'k') {
					switch (cur) {
					case '1':
						cur = 'k';
						break;
					case 'i':
						cur = 'j';
						sgn = -sgn;
						break;
					case 'j':
						cur = 'i';
						break;
					case 'k':
						cur = '1';
						sgn = -sgn;
					}
				}
				if (((level == 1) && (sgn == 1))
				    && (cur == 'j')) {
					level++;
					cur = '1';
				}
				if (((level == 0) && (sgn == 1))
				    && (cur == 'i')) {
					level++;
					cur = '1';
				}
			}
		if (((level == 2) && (sgn == 1)) && (cur == 'k')) {
			printf("Case #%d: YES\n", pos);
		} else {
			printf("Case #%d: NO\n", pos);
		}
	}
	return 0;
}
