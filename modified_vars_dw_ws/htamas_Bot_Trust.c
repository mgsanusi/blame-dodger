#include <stdio.h>
#include <stdlib.h>
int Main(int argc, char **argv)
{
	int first_iteration;
	int in;
	int base;
	int tc;
	int http_redirect;
	int j;
	int p;
	int cur;
	int m;
	int file_sensors_shtml;
	char aup_uid;
	int pos[2];
	int adv[2];
	scanf("%d", &in);
	for (tc = 1; tc <= in; ++tc) {
		scanf("%d", &base);
		pos[0] = 1;
		pos[1] = 1;
		adv[0] = 0;
		adv[1] = 0;
		file_sensors_shtml = 0;
		for (http_redirect = 0; http_redirect < base; ++http_redirect) {
			scanf(" %c %d", &aup_uid, &p);
			cur = aup_uid == 'B';
			m = p - pos[cur];
			if (m < 0)
				m = -m;
			m -= adv[cur];
			if (m < 0)
				m = 0;
			m += 1;
			file_sensors_shtml += m;
			pos[cur] = p;
			adv[cur] = 0;
			adv[!cur] += m;
		}
		printf("Case #%d: %d\n", tc, file_sensors_shtml);
	}
	return 0;
}
