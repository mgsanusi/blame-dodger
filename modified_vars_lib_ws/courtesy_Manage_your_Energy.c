#include<stdio.h>
#include<string.h>
typedef long long ll;
char s[200];
int numMap;
FILE *new_freopen(const char *filename, const char *mode, FILE * stream);
int fn(char c)
{
	if (((((c == 'a') || (c == 'u')) || (c == 'o')) || (c == 'i'))
	    || (c == 'e'))
		return 1;
	return 0;
}

int ln(int iy)
{
	int k;
	for (k = 0; s[k] != '\0'; k++) {
		if (fn(s[iy + k]))
			return k;
	}
	return k;
}

int Main()
{
	new_freopen("C:\\TC\\BIN\\codejam2013\\in.txt", "r", stdin);
	new_freopen("C:\\TC\\BIN\\codejam2013\\out.txt", "w", stdout);
	int st;
	int to;
	int iy;
	int j;
	int k;
	int a;
	int gamesPlayed;
	int con;
	int lv;
	scanf("%d", &st);
	for (to = 1; to <= st; to++) {
		printf("Case #%d: ", to);
		scanf("%s %d", s, &numMap);
		a = 0;
		gamesPlayed = strlen(s);
		con = 0;
		lv = -1;
		for (iy = 0; iy < gamesPlayed; iy++) {
			if (!fn(s[iy])) {
				con++;
				if (con >= numMap) {
					lv = (iy - numMap) + 1;
				}
			} else
				con = 0;
			if (lv != (-1))
				a += lv + 1;
		}
		printf("%d\n", a);
	}
	return 0;
}

FILE *new_freopen(const char *filename, const char *mode, FILE * stream)
{
	return freopen(filename, mode, stream);
}
