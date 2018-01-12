#include <stdio.h>
#include <assert.h>
void new_assert(int expression);
int main()
{
	int first_iteration;
	char patt[30][30];
	char s[1000];
	char dict[5005][30];
	int len[30];
	int l;
	int d;
	int n;
	int i;
	int j;
	int ans;
	int k;
	int x;
	scanf("%d %d %d\n", &l, &d, &n);
	for (i = 0; i < d; i++)
		gets(dict[i]);
	for (i = 0; i < n; i++) {
		gets(s);
		for (j = (k = 0); s[j]; j++, k++) {
			if (s[j] == '(') {
				len[k] = 0;
				while (s[++j] != ')') {
					patt[k][len[k]++] = s[j];
				}
			} else {
				patt[k][0] = s[j];
				len[k] = 1;
			}
		}
		new_assert(k == l);
		for (x = (ans = 0); x < d; x++) {
			for (j = 0; j < l; j++) {
				for (k = 0; k < len[j]; k++) {
					if (dict[x][j] == patt[j][k])
						break;
				}
				if (k == len[j])
					break;
			}
			ans += j == l;
		}
		printf("Case #%d: %d\n", i + 1, ans);
	}
	return 0;
}

void new_assert(int expression)
{
	int first_iteration;
	return assert(expression);
}