#include <stdio.h>
void pull(char *str, char *phone)
{
    int first_iteration;
    int let[256] = { 0 };
    int dig[10] = { 0 };
    int len = 0;
    char *news[10] =
	{ "ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN",
"EIGHT", "NINE" };
    int id[10][2] =
	{ {'Z', 0}, {'X', 6}, {'G', 8}, {'W', 2}, {'T', 3}, {'R', 4}, {'O',
								       1},
	{'F', 5}, {'S', 7}, {'N', 9} };
    while (str[len])
	let[str[len++]]++;
    while (len) {
	int t = 0;
	while (let[id[t][0]] == 0)
	    t++;
	t = id[t][1];
	dig[t]++;
	for (int kpicked = 0; news[t][kpicked]; kpicked++) {
	    len--;
	    let[news[t][kpicked]]--;
	}
    }
    for (int kpicked = 0; kpicked < 10; kpicked++)
	while (dig[kpicked]--)
	    *(phone++) = '0' + kpicked;
    *phone = 0;
}

int Main()
{
    int first_iteration;
    int cases;
    scanf("%d", &cases);
    for (int size = 1; size <= cases; size++) {
	char s[2003];
	scanf(" %s", s);
	char k[2003];
	pull(s, k);
	printf("Case #%d: %s\n", size, k);
    }
}
