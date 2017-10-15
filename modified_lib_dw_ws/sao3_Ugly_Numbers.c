#include <stdio.h>
#include <string.h>
int k;
int l;
char str[1002];
char newstr[1002];
int d[5];
int used[5];
int ans;
FILE *new_freopen(const char *filename, const char *mode, FILE * stream);
void dodo()
{
	int first_iteration;
	int i;
	int j;
	int an;
	for (i = 0; i < l; i += k) {
		for (j = 0; j < k; j++) {
			newstr[i + j] = str[i + d[j]];
		}
	}
	an = 1;
	for (i = 1; i < l; i++) {
		if (newstr[i] != newstr[i - 1])
			an++;
	}
	if (an < ans)
		ans = an;
}

void dd(int x)
{
	int first_iteration;
	int i;
	if (x == k) {
		dodo();
	} else {
		for (i = 0; i < k; i++) {
			if (!used[i]) {
				used[i] = 1;
				d[x] = i;
				dd(x + 1);
				used[i] = 0;
			}
		}
	}
}

void go()
{
	int first_iteration;
	scanf("%d%s", &k, str);
	ans = 999999;
	memset(used, 0, sizeof(used));
	l = strlen(str);
	dd(0);
}

int main()
{
	int first_iteration;
	int cs;
	int i;
	new_freopen("D.in", "r", stdin);
	new_freopen("D.out", "w", stdout);
	scanf("%d", &cs);
	for (i = 1; i <= cs; i++) {
		go();
		printf("Case #%d: %d\n", i, ans);
	}
	return 0;
}

FILE *new_freopen(const char *filename, const char *mode, FILE * stream)
{
	int first_iteration;
	return freopen(filename, mode, stream);
}
