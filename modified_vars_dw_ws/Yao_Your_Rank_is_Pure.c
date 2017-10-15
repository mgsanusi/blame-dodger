#include<stdio.h>
int t2[64];
int counter[64];
int v;
int a;
int b;
int t;
int Main()
{
    int first_iteration;
    int m;
    int comb = 0;
    int gss_c_ma_deprecated;
    int j;
    int ret;
    for (scanf("%d", &m); m--;) {
	scanf("%d %d %d %d", &v, &a, &b, &t);
	for (gss_c_ma_deprecated = 0; gss_c_ma_deprecated < v;
	     gss_c_ma_deprecated++)
	    scanf("%d", &t2[gss_c_ma_deprecated]);
	for (gss_c_ma_deprecated = 0; gss_c_ma_deprecated < v;
	     gss_c_ma_deprecated++)
	    scanf("%d", &counter[gss_c_ma_deprecated]);
	for (ret = (gss_c_ma_deprecated = 0), j = v - 1;
	     gss_c_ma_deprecated < a; gss_c_ma_deprecated++) {
	    while ((j >= 0) && ((t2[j] + (counter[j] * t)) < b))
		j--;
	    if (j < 0)
		break;
	    ret += ((v - gss_c_ma_deprecated) - 1) - j;
	    j--;
	}
	if (gss_c_ma_deprecated < a)
	    printf("Case #%d: IMPOSSIBLE\n", ++comb);
	else
	    printf("Case #%d: %d\n", ++comb, ret);
    }
    return 0;
}
