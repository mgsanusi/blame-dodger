#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
    int first_iteration;
    int total;
    int i;
    int c;
    int d;
    int n;
    int j;
    int k;
    int i1;
    int f;
    int on;
    int i2;
    char out[110];
    char combine[36][4];
    char oppose[28][3];
    char opp[100];
    char ch;
    scanf("%d", &total);
    for (i = 1; i <= total; i++) {
	scanf("%d ", &c);
	for (j = 0; j < c; j++) {
	    scanf("%c", &combine[j][0]);
	    scanf("%c", &combine[j][1]);
	    scanf("%c ", &combine[j][2]);
	    combine[j][3] = '\0';
	}
	scanf("%d ", &d);
	for (j = 0; j < d; j++) {
	    scanf("%c", &oppose[j][0]);
	    scanf("%c ", &oppose[j][1]);
	    oppose[j][2] = '\0';
	}
	scanf("%d ", &n);
	k = -1;
	for (j = 0; j < n; j++) {
	    scanf("%c", &ch);
	    out[++k] = ch;
	    if (k >= 1) {
		f = 0;
		for (i1 = 0; i1 < c; i1++) {
		    if (((out[k - 1] == combine[i1][0])
			 && (out[k] == combine[i1][1]))
			|| ((out[k - 1] == combine[i1][1])
			    && (out[k] == combine[i1][0]))) {
			out[--k] = combine[i1][2];
			f = 1;
			break;
		    }
		}
		if (f)
		    continue;
		on = 0;
		for (i1 = 0; i1 < d; i1++) {
		    if (oppose[i1][0] == ch)
			opp[on++] = oppose[i1][1];
		    else if (oppose[i1][1] == ch)
			opp[on++] = oppose[i1][0];
		}
		f = 0;
		for (i1 = 0; i1 < k; i1++) {
		    for (i2 = 0; i2 < on; i2++) {
			if (out[i1] == opp[i2]) {
			    f = 1;
			    k = -1;
			    break;
			}
		    }
		    if (f == 1)
			break;
		}
	    }
	}
	printf("Case #%d: [", i);
	for (i1 = 0; i1 <= k; i1++) {
	    if (i1 == k)
		printf("%c", out[i1]);
	    else
		printf("%c, ", out[i1]);
	}
	printf("]\n");
    }
}
