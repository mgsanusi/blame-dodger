#include <stdio.h>
#include <string.h>
 int L, D, N;
 char w[5000][16];
 char lo[16][32];
char s[10000];
 int main()
{
    int i, j, caseno = 1, count, pos;
    scanf("%d %d %d", &L, &D, &N);
    for (i = 0; i < D; i++)
	scanf("%s", w[i]);
    while (N--) {
	count = 0;
	memset(lo, 0, 32 * L);
	scanf("%s", s);
	for (pos = i = 0; s[i];) {
	    if (s[i] == '(') {
		i++;
		while (s[i] != ')')
		    lo[pos][s[i++] - 'a'] = 1;
		pos++, i++;
	    } else
		lo[pos++][s[i++] - 'a'] = 1;
	}
	for (i = 0; i < D; i++) {
	    for (j = 0; j < L; j++)
		if (!lo[j][(int) (w[i][j] - 'a')])
		    goto failed;
	    count++;
	  failed:;
	}
	printf("Case #%d: %d\n", caseno++, count);
    }
    return 0;
}


