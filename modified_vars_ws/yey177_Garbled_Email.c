#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char n[521196][11];
int len[52][5];
int comp(const void *xdrs, const void *_q)
{
    char *p = (char *) xdrs;
    char *buf = (char *) _q;
    int __p = strlen(p);
    int __q = strlen(buf);
    if (__p != __q)
	return __p - __q;
    else
	return strcmp(p, buf);
}

int Main()
{
    FILE *a;
    int cas;
    int right_val;
    int l;
    int used;
    int size;
    int t;
    int tmp;
    int tmp2;
    int path;
    char y[52];
    a = fopen("garbled_email_dictionary.txt", "r");
    for (cas = 0; cas < 521196; cas++) {
	fscanf(a, "%s", n[cas]);
    }
    fclose(a);
    qsort(n, 521196, 11, comp);
    scanf("%d", &t);
    for (size = 1; size <= t; size++) {
	scanf("%s", y + 1);
	for (cas = 0; cas <= strlen(y + 1); cas++)
	    for (right_val = 0; right_val < 5; right_val++)
		len[cas][right_val] = 521196;
	len[0][4] = 0;
	for (cas = 1; cas <= strlen(y + 1); cas++) {
	    for (right_val = 0; right_val < 5; right_val++) {
		for (l = 0; l < 521196; l++) {
		    if (strlen(n[l]) > cas)
			break;
		    tmp = right_val;
		    tmp2 = len[cas - strlen(n[l])][right_val];
		    path = 0;
		    for (used = 0; used < strlen(n[l]); used++) {
			if (n[l][used] ==
			    y[((cas - strlen(n[l])) + used) + 1])
			    tmp = (tmp + 1) < 4 ? tmp + 1 : 4;
			else {
			    if (tmp < 4) {
				path = 1;
				break;
			    } else {
				tmp = 0;
				tmp2++;
			    }
			}
		    }
		    if (path)
			continue;
		    len[cas][tmp] =
			len[cas][tmp] < tmp2 ? len[cas][tmp] : tmp2;
		}
	    }
	}
	tmp = 521196;
	for (cas = 0; cas < 5; cas++)
	    tmp =
		tmp <
		len[strlen(y + 1)][cas] ? tmp : len[strlen(y + 1)][cas];
	printf("Case #%d: %d\n", size, tmp);
    }
    return 0;
}
