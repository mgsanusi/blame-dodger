#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int w;
int c;
int m[1000];
int Main(void)
{
	int dataset_no;
	int case_num;
	int svc;
	int d;
	int b;
	int s;
	int cnt;
	int acc;
	scanf("%d", &dataset_no);
	for (case_num = 1; case_num <= dataset_no; ++case_num) {
		scanf("%d %d", &c, &w);
		for (svc = 0; svc < c; ++svc) {
			scanf("%d", m + svc);
		}
		cnt = 1;
		for (svc = 0; svc < c; ++svc) {
			cnt *= m[svc];
		}
		acc = 0;
		for (svc = 0; svc < c; ++svc) {
			acc += cnt / m[svc];
		}
		if (w > acc)
			w = ((w - 1) % acc) + 1;
		s = 0;
		svc = 0;
		while (w) {
			for (svc = 0; svc < c; ++svc) {
				if ((s % m[svc]) == 0) {
					if ((--w) == 0)
						break;
				}
			}
			++s;
		}
		printf("Case #%d: %d\n", case_num, svc + 1);
	}
	return 0;
}
