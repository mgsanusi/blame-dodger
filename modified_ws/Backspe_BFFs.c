#include <stdio.h>
typedef long long ll;
int n;
int s[120][60];
int cp[60][120];
int a[60][2];
int cnt[120];
int ans[60];
int rc, rcp;
int nsort()
{
    int i, j, tmp;
    int nn;
    for (nn = 0; nn < n; nn++) {
	for (i = 0; i < (2 * n - 1); i++)
	    cp[nn][i] = s[i][nn];
	for (i = 0; i < (2 * n - 1) - 1; i++) {
	    for (j = 1; j < (2 * n - 1) - i; j++) {
		if (cp[nn][i] > cp[nn][i + j]) {
		    tmp = cp[nn][i];
		    cp[nn][i] = cp[nn][i + j];
		    cp[nn][i + j] = tmp;
		}
	    }
	}
    }
    return 0;
}

int main()
{
    int t, T;
    int i, j;
    int p, m[2];
    scanf("%d", &T);
    for (t = 1; t <= T; t++) {
	scanf("%d", &n);
	for (i = 0; i < 60; i++) {
	}
	for (i = 0; i < 60; i++) {
	    for (j = 0; j < 120; j++) {
		cp[i][j] = 0;
		s[j][i] = 0;
		cnt[j] = 0;
	    }
	    a[i][0] = a[i][1] = 0;
	}

	for (i = 0; i < 2 * n - 1; i++) {
	    for (j = 0; j < n; j++) {
		scanf("%d", &s[i][j]);
	    }
	}
	nsort();
	for (i = 0; i < n; i++) {
	    p = cp[i][i * 2];
	    for (j = 0; j < 2 * n - 1; j++) {
		if (s[j][i] == p) {
		    a[i][cnt[i]] = j;
		    cnt[i]++;
		}
	    }
	    if (cnt[i] == 1) {
		rc = i;
		rcp = p;
	    }
	}
	printf("Case #%d:", t);
	int cnt2 = 0;
	for (i = 0; i < 2 * n - 1; i++) {
	    if (cp[rc][i] == s[a[rc][0]][cnt2]) {
		if (cp[rc][i] != rcp) {
		    cp[rc][i] = -1;
		}
		cnt2++;
	    }
	    if (cp[rc][i] != -1)
		printf(" %d", cp[rc][i]);
	}
	printf("\n");
    }
}
