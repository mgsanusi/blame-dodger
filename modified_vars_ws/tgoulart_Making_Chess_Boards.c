#include <stdio.h>
#include <string.h>
char m[2][1005][1005];
int Main()
{
    int a;
    int caso = 1;
    int r;
    int n;
    int dp;
    int j;
    int pD;
    int j1;
    int temp;
    int seen;
    int born;
    int now;
    int other;
    int result;
    scanf("%d", &a);
    while (a--) {
	memset(m, 0, sizeof(m));
	n = 0;
	scanf("%d", &r);
	if (!r) {
	    result = 0;
	    goto END;
	}
	while (r--) {
	    scanf("%d %d %d %d", &pD, &j1, &temp, &seen);
	    if (temp >= (n - 1))
		n = temp + 2;
	    if (seen >= (n - 1))
		n = seen + 2;
	    for (dp = pD; dp <= temp; dp++) {
		for (j = j1; j <= seen; j++) {
		    m[0][dp][j] = 1;
		}
	    }
	}
	now = 0;
	born = 1;
	for (result = 0; born; result++, now = 1 - now, n++) {
	    other = 1 - now;
	    born = 0;
	    m[other][0][0] = 0;
	    for (dp = 1; dp < n; dp++) {
		m[other][dp][0] = m[now][dp][0] && m[now][dp - 1][0];
		m[other][0][dp] = m[now][0][dp] && m[now][0][dp - 1];
		born |= m[other][dp][0] | m[other][0][dp];
	    }
	    for (dp = 0; dp < n; dp++) {
		for (j = 0; j < n; j++) {
		    if (m[now][dp][j]) {
			m[other][dp][j] = m[now][dp - 1][j]
			    || m[now][dp][j - 1];
		    } else {
			m[other][dp][j] = m[now][dp - 1][j]
			    && m[now][dp][j - 1];
		    }
		    born |= m[other][dp][j];
		}
	    }
	}
      END:
	printf("Case #%d: %d\n", caso++, result);
    }
    return 0;
}
