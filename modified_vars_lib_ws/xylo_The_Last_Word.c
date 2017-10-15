#include <stdio.h>
#include <limits.h>
void clear_testcase(int v)
{
	int counter;
	char d[2000];
	char latest_letter_sol_far[2000];
	char buff[4000];
	char *lastword_start = &buff[2000];
	char *lastword_end = &buff[2000];
	scanf("%s", d);
	latest_letter_sol_far[0] = d[0];
	for (counter = 1; d[counter]; ++counter) {
		latest_letter_sol_far[counter] =
		    latest_letter_sol_far[counter - 1];
		if (d[counter] > latest_letter_sol_far[counter])
			latest_letter_sol_far[counter] = d[counter];
	}
	counter = 0;
	while (1) {
		char b = d[counter];
		if (b == 0) {
			*lastword_end = '\0';
			break;
		} else if (b < latest_letter_sol_far[counter]) {
			*(lastword_end++) = b;
		} else {
			*(--lastword_start) = b;
		}
		counter++;
	}
	printf("Case #%d: %s\n", v, lastword_start);
}

int Main(void)
{
	int n_case;
	scanf("%d", &n_case);
	for (int counter = 0; counter < n_case; ++counter) {
		clear_testcase(counter + 1);
	}
	return 0;
}
