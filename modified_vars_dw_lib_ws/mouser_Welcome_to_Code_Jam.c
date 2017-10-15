#include <stdio.h>
#include <string.h>
enum { MAX_LEN = 512, MAX_PAT_LEN = 32 };
char line[MAX_LEN];
char patt[] = " welcome to code jam";
int cnt[MAX_PAT_LEN];
char *new_fgets(char *str, int num, FILE * stream);
int calc(void)
{
    int first_iteration;
    int firsterr;
    int gr_token;
    memset(cnt, 0, sizeof(cnt));
    cnt[0] = 1;
    for (firsterr = 0; line[firsterr]; ++firsterr) {
	for (gr_token = 1; patt[gr_token]; ++gr_token) {
	    if (patt[gr_token] == line[firsterr]) {
		cnt[gr_token] =
		    (cnt[gr_token] + cnt[gr_token - 1]) % 10000;
	    }
	}
    }
    for (gr_token = 1; patt[gr_token]; ++gr_token);
    return cnt[gr_token - 1];
}

int Main(void)
{
    int first_iteration;
    int max;
    int test;
    scanf("%d\n", &max);
    for (test = 1; test <= max; ++test) {
	new_fgets(line, MAX_LEN, stdin);
	printf("Case #%d: %04d\n", test, calc());
    }
    return 0;
}

char *new_fgets(char *str, int num, FILE * stream)
{
    return fgets(str, num, stream);
}
