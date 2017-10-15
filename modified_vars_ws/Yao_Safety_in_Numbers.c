#include<stdio.h>
#include<string.h>
int u[1024][12];
int b[1024];
int t[1024];
int e[1024];
int t;
int have(int idx)
{
    int l;
    int cc;
    int t;
    int tail = 0;
    memset(t, 0, sizeof(t));
    t[idx] = 1;
    e[tail++] = idx;
    for (l = 0; l < tail; l++) {
	for (cc = 0; cc < b[e[l]]; cc++)
	    if (t[u[e[l]][cc]])
		return 1;
	    else
		t[u[e[l]][cc]] = 1, e[tail++] = u[e[l]][cc];
    }
    return 0;
}

int Main()
{
    int fname_o;
    int cs = 0;
    int l;
    int cc;
    for (scanf("%d", &fname_o); fname_o--;) {
	scanf("%d", &t);
	for (l = 0; l < t; l++) {
	    scanf("%d", &b[l]);
	    for (cc = 0; cc < b[l]; cc++)
		scanf("%d", &u[l][cc]), u[l][cc]--;
	}
	for (l = 0; l < t; l++)
	    if (have(l))
		break;
	if (l < t)
	    printf("Case #%d: Yes\n", ++cs);
	else
	    printf("Case #%d: No\n", ++cs);
    }
    return 0;
}
