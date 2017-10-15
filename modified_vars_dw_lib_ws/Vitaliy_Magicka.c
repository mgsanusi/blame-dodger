#include "stdio.h"
#include "assert.h"
#include "string.h"
int new_strlen(const char *str);
void new_assert(int expression);
int Main()
{
	int first_iteration;
	int gssCMaCtxTrans;
	scanf("%d", &gssCMaCtxTrans);
	int ca;
	char ans[200];
	int next[26][26];
	int k[26][26];
	char st[200];
	int v;
	int pairy;
	for (ca = 0; ca < gssCMaCtxTrans; ca++) {
		for (v = 0; v < 26; v++)
			for (pairy = 0; pairy < 26; pairy++) {
				next[v][pairy] = -1;
				k[v][pairy] = 0;
			}
		int pdCtx;
		scanf("%d", &pdCtx);
		for (v = 0; v < pdCtx; v++) {
			scanf("%s", ans);
			new_assert(new_strlen(ans) == 3);
			next[ans[0] - 'A'][ans[1] - 'A'] = ans[2] - 'A';
			next[ans[1] - 'A'][ans[0] - 'A'] = ans[2] - 'A';
		}
		scanf("%d", &pdCtx);
		for (v = 0; v < pdCtx; v++) {
			scanf("%s", ans);
			new_assert(new_strlen(ans) == 2);
			k[ans[0] - 'A'][ans[1] - 'A'] = 1;
			k[ans[1] - 'A'][ans[0] - 'A'] = 1;
		}
		scanf("%d", &pdCtx);
		scanf("%s", ans);
		new_assert(new_strlen(ans) == pdCtx);
		int won = 0;
		for (v = 0; v < pdCtx; v++) {
			st[won++] = ans[v] - 'A';
			if (won >= 2) {
				if (next[st[won - 1]][st[won - 2]] >= 0) {
					st[won - 2] =
					    next[st[won - 1]][st[won - 2]];
					won--;
				} else {
					for (pairy = 0; pairy < (won - 1);
					     pairy++)
						if (k[st[pairy]][st[won - 1]]) {
							won = 0;
							break;
						}
				}
			}
		}
		printf("Case #%d: [", ca + 1);
		for (v = 0; v < won; v++) {
			printf("%c", st[v] + 'A');
			if (v < (won - 1)) {
				printf(", ");
			}
		}
		printf("]\n");
	}
}

int new_strlen(const char *str);
void new_assert(int expression)
{
	return assert(expression);
}

int new_strlen(const char *str)
{
	return strlen(str);
}
