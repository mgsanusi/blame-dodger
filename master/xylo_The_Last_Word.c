#include <stdio.h>
#include <limits.h>

void solve_testcase(int tc) {
	int i;
	char s[2000];
	char latest_letter_so_far[2000];
	char buf[4000];
	char *lastword_start = &(buf[2000]);
	char *lastword_end = &(buf[2000]);
	scanf("%s", s);
	latest_letter_so_far[0] = s[0];
	for (i = 1; s[i]; ++i) {
		latest_letter_so_far[i] = latest_letter_so_far[i-1];
		if (s[i] > latest_letter_so_far[i])
			latest_letter_so_far[i] = s[i];
	}
	i = 0;
	while (1) {
		char c = s[i];
		if (c == 0) {
			*lastword_end = '\0';
			break;
		} else if (c < latest_letter_so_far[i]) {
			*(lastword_end++) = c;
		} else {
			*(--lastword_start) = c;
		}
		i++;
	}
	printf("Case #%d: %s\n", tc, lastword_start);
}

int main(void) {
	int n_cases;
	scanf("%d", &n_cases);
	for (int i = 0; i < n_cases; ++i) {
		solve_testcase(i+1);
	}
	return 0;
}
