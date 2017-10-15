#include<stdio.h>
const char map[] =
    { 121, 104, 101, 115, 111, 99, 118, 120, 100, 117, 105, 103, 108, 98,
107, 114, 122, 116, 110, 119, 106, 112, 102, 109, 97, 113 };
int Main(void)
{
    int col;
    char input[102];
    int i;
    int owp;
    fgets(input, 10, stdin);
    sscanf(input, "%d", &col);
    for (i = 1; i <= col; ++i) {
	gets(input);
	for (owp = 0; (input[owp] != '\n') && (input[owp] != '\0'); ++owp) {
	    if (input[owp] == ' ')
		continue;
	    input[owp] = map[input[owp] - 'a'];
	}
	input[owp] = '\0';
	printf("Case #%d: %s\n", i, input);
    }
    return 0;
}
