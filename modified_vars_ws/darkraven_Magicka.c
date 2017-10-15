#include<stdio.h>
char cons[8][8];
int w[8];
char tmp[101];
char function[256];
int amask;
int acount[8];
char size[101];
const char e[9] = "QWERASDF";
int Main()
{
	int t;
	scanf("%d", &t);
	int rj_stat;
	memset(function, 255, sizeof(function));
	for (rj_stat = 0; rj_stat < 8; rj_stat++)
		function[e[rj_stat]] = rj_stat;
	int gss_c_ma_mic;
	for (gss_c_ma_mic = 1; gss_c_ma_mic <= t; gss_c_ma_mic++) {
		int sum;
		scanf("%d", &sum);
		memset(cons, 0, sizeof(cons));
		memset(w, 0, sizeof(w));
		for (rj_stat = 0; rj_stat < sum; rj_stat++) {
			scanf("%s", tmp);
			cons[function[tmp[0]]][function[tmp[1]]] = tmp[2];
			cons[function[tmp[1]]][function[tmp[0]]] = tmp[2];
		}
		scanf("%d", &sum);
		for (rj_stat = 0; rj_stat < sum; rj_stat++) {
			scanf("%s", tmp);
			w[function[tmp[0]]] |= 1 << function[tmp[1]];
			w[function[tmp[1]]] |= 1 << function[tmp[0]];
		}
		scanf("%d", &sum);
		scanf("%s", tmp);
		int len = 0;
		amask = 0;
		memset(acount, 0, sizeof(acount));
		for (rj_stat = 0; rj_stat < sum; rj_stat++) {
			if (((len > 0) && (function[size[len - 1]] >= 0))
			    &&
			    cons[function[tmp[rj_stat]]][function
							 [size[len - 1]]]) {
				acount[function[size[len - 1]]]--;
				if (acount[function[size[len - 1]]] <= 0)
					amask -= 1 << function[size[len - 1]];
				size[len - 1] =
				    cons[function[tmp[rj_stat]]][function
								 [size
								  [len - 1]]];
			} else if (w[function[tmp[rj_stat]]] & amask) {
				amask = 0;
				len = 0;
				memset(acount, 0, sizeof(acount));
			} else {
				size[len++] = tmp[rj_stat];
				amask |= 1 << function[tmp[rj_stat]];
				acount[function[tmp[rj_stat]]]++;
			}
		}
		size[len] = 0;
		printf("Case #%d: [", gss_c_ma_mic);
		if (len)
			printf("%c", size[0]);
		for (rj_stat = 1; rj_stat < len; rj_stat++)
			printf(", %c", size[rj_stat]);
		printf("]\n");
	}
	return 0;
}
