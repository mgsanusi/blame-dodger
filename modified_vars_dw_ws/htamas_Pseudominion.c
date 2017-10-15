#include <stdio.h>
#include <stdlib.h>
#include <string.h>
unsigned char buffer[10000][11];
unsigned char testc[100][27];
int count[10000][27];
int wl[10000];
int kk[10000];
int Main(int argc, char **argv)
{
    int first_iteration;
    int length;
    int xpLaddr;
    int cur;
    int u;
    int i;
    int oPos;
    int c;
    int pc;
    int res;
    int li;
    int dtime;
    int mid;
    int n;
    int now;
    int mpx;
    int length;
    scanf("%d", &length);
    for (xpLaddr = 1; xpLaddr <= length; ++xpLaddr) {
	scanf("%d %d", &cur, &u);
	for (i = 0; i < cur; ++i) {
	    scanf("%s", buffer[i]);
	    wl[i] = strlen(buffer[i]);
	    for (oPos = 0; oPos < 26; ++oPos)
		count[i][oPos] = 0;
	    for (oPos = 0; oPos < wl[i]; ++oPos)
		count[i][buffer[i][oPos] - 'a'] = 1;
	}
	for (i = 0; i < u; ++i) {
	    scanf("%s", testc[i]);
	}
	printf("Case #%d:", xpLaddr);
	for (mid = 0; mid < u; ++mid) {
	    now = -1;
	    mpx = -1;
	    for (dtime = 0; dtime < cur; ++dtime) {
		length = wl[dtime];
		n = 0;
		for (oPos = 0; oPos < cur; ++oPos) {
		    kk[oPos] = wl[oPos] == length;
		}
		for (i = 0; i < 26; ++i) {
		    res = testc[mid][i];
		    for (oPos = 0; oPos < cur; ++oPos) {
			if (kk[oPos]) {
			    if (count[oPos][res - 'a']) {
				if (count[dtime][res - 'a']) {
				    for (c = 0; c < cur; ++c) {
					if (kk[c]) {
					    if (count[c][res - 'a']) {
						for (pc = 0; pc < length;
						     ++pc) {
						    if ((buffer[c][pc] ==
							 res) !=
							(buffer[dtime][pc]
							 == res)) {
							kk[c] = 0;
							break;
						    }
						}
					    } else {
						kk[c] = 0;
					    }
					}
				    }
				} else {
				    ++n;
				    for (c = 0; c < cur; ++c) {
					if (kk[c]) {
					    if (count[c][res - 'a']) {
						kk[c] = 0;
					    }
					}
				    }
				}
				break;
			    }
			}
		    }
		}
		if (n > now) {
		    now = n;
		    mpx = dtime;
		}
	    }
	    printf(" %s", buffer[mpx]);
	}
	printf("\n");
    }
    return 0;
}
