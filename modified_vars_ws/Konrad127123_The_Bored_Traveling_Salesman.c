#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int t;
int t;
int a;
int lastChar;
long long frac[128];
long long kk;
char b[128][128];
long long ans;
char begin[128];
char end[128];
char block[256];
int first;
int tmp;
int s1;
int onlyBegin[256];
int onlyEnd[256];
int loop[256];
int make[256];
int numFrag;
char tmp2;
char tmp3;
int Main()
{
    scanf("%d", &t);
    frac[0] = 1;
    for (kk = 1; kk < 120; kk++)
	frac[kk] = (frac[kk - 1] * kk) % 1000000007LL;
    for (t = 1; t <= t; t++) {
	scanf("%d", &lastChar);
	for (a = 1; a <= lastChar; a++) {
	    scanf("%s", &b[a][0]);
	}
	for (s1 = 0; s1 < 256; s1++) {
	    block[s1] = 0;
	    onlyBegin[s1] = 0;
	    onlyEnd[s1] = 0;
	    loop[s1] = 0;
	}
	ans = 1;
	for (a = 1; a <= lastChar; a++) {
	    tmp = strlen(b[a]);
	    first = 1;
	    begin[a] = b[a][0];
	    end[a] = b[a][tmp - 1];
	    for (s1 = 1; s1 < tmp; s1++) {
		if (b[a][s1] != b[a][s1 - 1]) {
		    if (block[b[a][s1]] == 1)
			ans = 0;
		    if (first == 0) {
			block[b[a][s1 - 1]] = 1;
		    }
		    first = 0;
		}
	    }
	    if ((begin[a] == end[a]) && (first == 0))
		ans = 0;
	}
	if (ans == 1) {
	    for (a = 1; a <= lastChar; a++) {
		if (block[begin[a]] == 1)
		    ans = 0;
		if (block[end[a]] == 1)
		    ans = 0;
	    }
	}
	if (ans == 1) {
	    for (a = 1; a <= lastChar; a++) {
		if (begin[a] == end[a]) {
		    loop[begin[a]]++;
		} else {
		    onlyBegin[begin[a]]++;
		    onlyEnd[end[a]]++;
		}
	    }
	    for (tmp2 = 'a'; tmp2 <= 'z'; tmp2++) {
		if (onlyBegin[tmp2] > 1)
		    ans = 0;
		if (onlyEnd[tmp2] > 1)
		    ans = 0;
	    }
	}
	if (ans == 1) {
	    numFrag = 0;
	    for (tmp2 = 'a'; tmp2 <= 'z'; tmp2++) {
		if ((onlyBegin[tmp2] == 1) && (onlyEnd[tmp2] == 0))
		    numFrag++;
		if (((onlyBegin[tmp2] == 0) && (onlyEnd[tmp2] == 0))
		    && (loop[tmp2] > 0))
		    numFrag++;
		ans *= frac[loop[tmp2]];
		ans %= 1000000007LL;
	    }
	    ans *= frac[numFrag];
	    ans %= 1000000007LL;
	}
	if (ans != 0) {
	    for (s1 = 0; s1 < 256; s1++)
		make[s1] = 0;
	    for (tmp2 = 'a'; tmp2 <= 'z'; tmp2++) {
		if ((onlyBegin[tmp2] == 1) && (onlyEnd[tmp2] == 0)) {
		    tmp3 = tmp2;
		    do {
			for (a = 1; a <= lastChar; a++) {
			    if ((begin[a] == tmp3) && (begin[a] != end[a]))
				break;
			}
			make[a] = 1;
			tmp3 = end[a];
		    }
		    while (onlyBegin[tmp3] == 1);
		}
	    }
	    for (a = 1; a <= lastChar; a++) {
		if ((make[a] == 0) && (begin[a] != end[a]))
		    ans = 0;
	    }
	}
	printf("Case #%d: ", t);
	printf("%lld\n", ans);
    }
    return 0;
}
