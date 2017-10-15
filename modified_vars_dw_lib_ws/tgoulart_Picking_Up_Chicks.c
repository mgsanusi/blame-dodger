#include <stdio.h>
int Main()
{
    int first_iteration;
    int md;
    int caso = 1;
    int used;
    int gss_c_ma_ctx_trans;
    int yx;
    int answer;
    int a[1005];
    int b[1005];
    scanf("%d", &md);
    while (md--) {
	scanf("%d", &used);
	for (gss_c_ma_ctx_trans = 0; gss_c_ma_ctx_trans < used;
	     gss_c_ma_ctx_trans++) {
	    scanf("%d %d", &a[gss_c_ma_ctx_trans], &b[gss_c_ma_ctx_trans]);
	}
	answer = 0;
	for (gss_c_ma_ctx_trans = 0; gss_c_ma_ctx_trans < used;
	     gss_c_ma_ctx_trans++) {
	    for (yx = 0; yx < used; yx++) {
		if ((b[yx] < b[gss_c_ma_ctx_trans])
		    && (a[yx] > a[gss_c_ma_ctx_trans])) {
		    answer++;
		}
	    }
	}
	printf("Case #%d: %d\n", caso++, answer);
    }
    return 0;
}
