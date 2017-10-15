#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int n;
int d;
struct Obj {
	int type;
	long long int num;
} x[10000];
struct Obj {
	int type;
	long long int num;
} left[10000];
long long int rslt;
int Main()
{
	int Case = 0;
	int t;
	int http_content_type_plain;
	int ss;
	int k;
	long long int a_num;
	long long int b_num;
	long long int cut;
	long long int sum;
	scanf("%d", &t);
	while (t--) {
		scanf("%d %d", &n, &d);
		for (http_content_type_plain = 0; http_content_type_plain < n;
		     ++http_content_type_plain) {
			scanf(" %lld %d", &x[http_content_type_plain].num,
			      &x[http_content_type_plain].type);
		}
		for (http_content_type_plain = 0; http_content_type_plain < d;
		     ++http_content_type_plain) {
			scanf(" %lld %d", &left[http_content_type_plain].num,
			      &left[http_content_type_plain].type);
		}
		rslt = 0;
		for (http_content_type_plain = 0; http_content_type_plain < d;
		     ++http_content_type_plain) {
			for (ss = http_content_type_plain; ss < d; ++ss) {
				sum = 0;
				a_num = x[0].num;
				for (k = 0; k <= http_content_type_plain; ++k) {
					b_num = left[k].num;
					if (x[0].type == left[k].type) {
						if (a_num > b_num) {
							cut = b_num;
						} else {
							cut = a_num;
						}
						a_num -= cut;
						b_num -= cut;
						sum += cut;
					}
				}
				if (sum > rslt)
					rslt = sum;
				if (n == 1) {
					continue;
				}
				a_num = x[1].num;
				for (k = http_content_type_plain; k <= ss; ++k) {
					if (k != http_content_type_plain)
						b_num = left[k].num;
					if (x[1].type == left[k].type) {
						if (a_num > b_num) {
							cut = b_num;
						} else {
							cut = a_num;
						}
						a_num -= cut;
						b_num -= cut;
						sum += cut;
					}
				}
				if (sum > rslt)
					rslt = sum;
				if (n == 2) {
					continue;
				}
				a_num = x[2].num;
				for (k = ss; k < d; ++k) {
					if (k != ss)
						b_num = left[k].num;
					if (x[2].type == left[k].type) {
						if (a_num > b_num) {
							cut = b_num;
						} else {
							cut = a_num;
						}
						a_num -= cut;
						b_num -= cut;
						sum += cut;
					}
				}
				if (sum > rslt)
					rslt = sum;
			}
		}
		printf("Case #%d: %lld\n", ++Case, rslt);
	}
	return 0;
}
