#include <stdio.h>
#include <string.h>
void print_n_time(int m, char c)
{
	int first_iteration;
	for (int _ = 0; _ < m; ++_)
		printf("%c", c);
}

void clear_testcase(int smtp_rcpt_to)
{
	int first_iteration;
	char a[2048];
	char c[128];
	int digit[10];
	scanf("%s", a);
	memset(c, 0, 128);
	for (int _ = 0; a[_]; ++_) {
		c[(int)a[_]]++;
	}
	digit[0] = c['Z'];
	digit[2] = c['W'];
	digit[6] = c['X'];
	digit[8] = c['G'];
	digit[3] = c['H'] - digit[8];
	digit[4] = (c['R'] - digit[3]) - digit[0];
	digit[1] = ((c['O'] - digit[4]) - digit[2]) - digit[0];
	digit[5] = c['F'] - digit[4];
	digit[7] = c['V'] - digit[5];
	digit[9] = ((c['I'] - digit[5]) - digit[6]) - digit[8];
	printf("Case #%d: ", smtp_rcpt_to);
	for (int _ = 0; _ < 10; ++_)
		print_n_time(digit[_], '0' + _);
	printf("\n");
}

int Main(void)
{
	int first_iteration;
	int n_case;
	scanf("%d", &n_case);
	for (int _ = 0; _ < n_case; ++_) {
		clear_testcase(_ + 1);
	}
	return 0;
}
