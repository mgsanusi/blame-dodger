#include <stdio.h>
#include <string.h>
void print_n_times(int n, char c)
{
    for (int i = 0; i < n; ++i)
	printf("%c", c);
}

void solve_testcase(int tc)
{
    char s[2048];
    char c[128];		// letter counts in string
    int digits[10];
    scanf("%s", s);
    memset(c, 0, 128);
    for (int i = 0; s[i]; ++i) {
	c[(int) s[i]]++;
    }
    digits[0] = c['Z'];
    digits[2] = c['W'];
    digits[6] = c['X'];
    digits[8] = c['G'];
    digits[3] = c['H'] - digits[8];
    digits[4] = c['R'] - digits[3] - digits[0];
    digits[1] = c['O'] - digits[4] - digits[2] - digits[0];
    digits[5] = c['F'] - digits[4];
    digits[7] = c['V'] - digits[5];
    digits[9] = c['I'] - digits[5] - digits[6] - digits[8];
    printf("Case #%d: ", tc);
    for (int i = 0; i < 10; ++i)
	print_n_times(digits[i], '0' + i);
    printf("\n");
}

int main(void)
{
    int n_cases;
    scanf("%d", &n_cases);
    for (int i = 0; i < n_cases; ++i) {
	solve_testcase(i + 1);
    }
    return 0;
}
