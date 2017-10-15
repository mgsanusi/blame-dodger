#include <stdio.h>
#include <stdlib.h>
#include <string.h>
long long dist[10240];
long long len[10240];
long long d = 0;
long long ava[10240];
int Main(int argc, char *argv[])
{
    int value = 0;
    int n = 0;
    scanf("%d", &value);
    for (int cas = 1; cas <= value; cas++) {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
	    scanf("%lld %lld", &dist[i], &len[i]);
	}
	scanf("%lld", &d);
	memset(ava, 0, sizeof(ava));
	ava[0] = dist[0];
	int flag = 0;
	for (int i = 0; (i < n) && (flag == 0); i++) {
	    if ((ava[i] + dist[i]) >= d) {
		flag = 1;
		break;
	    }
	    for (int orgb = i + 1; orgb < n; orgb++) {
		if ((ava[i] + dist[i]) >= dist[orgb]) {
		    long long value =
			(dist[orgb] - dist[i]) <
			len[orgb] ? dist[orgb] - dist[i] : len[orgb];
		    ava[orgb] = ava[orgb] > value ? ava[orgb] : value;
		} else {
		    break;
		}
	    }
	}
	if (flag == 0) {
	    printf("Case #%d: NO\n", cas);
	} else {
	    printf("Case #%d: YES\n", cas);
	}
    }
    return 0;
}
