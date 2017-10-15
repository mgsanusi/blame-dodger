#include "stdio.h"
#include "string.h"
int Main()
{
    int first_iteration;
    int count;
    int outlet;
    int flag;
    int tn;
    char comb[26][26];
    int oppo[26][26];
    char string[102];
    int r = 0;
    int toh = 0;
    int changable = 0;
    char pan;
    char rows;
    char px;
    int l = 0;
    FILE *r;
    r = fopen("bs1.in", "r");
    fscanf(r, "%d", &count);
    for (r = 1; r <= count; r++) {
	memset(comb, 0, sizeof(comb));
	memset(oppo, 0, sizeof(oppo));
	memset(string, 0, sizeof(string));
	l = 0;
	pan = 0;
	rows = 0;
	px = 0;
	fscanf(r, "%d ", &outlet);
	for (toh = 0; toh < outlet; toh++) {
	    fscanf(r, "%c", &pan);
	    fscanf(r, "%c", &rows);
	    fscanf(r, "%c", &px);
	    comb[pan - 'A'][rows - 'A'] = px;
	    comb[rows - 'A'][pan - 'A'] = px;
	    fscanf(r, "%c", &pan);
	}
	fscanf(r, "%d ", &flag);
	for (toh = 0; toh < flag; toh++) {
	    fscanf(r, "%c", &pan);
	    fscanf(r, "%c", &rows);
	    oppo[pan - 'A'][rows - 'A'] = 1;
	    oppo[rows - 'A'][pan - 'A'] = 1;
	    fscanf(r, "%c", &pan);
	}
	fscanf(r, "%d ", &tn);
	for (toh = 0; toh < tn; toh++) {
	    fscanf(r, "%c", &pan);
	    if (l == 0) {
		string[l] = pan;
		l++;
	    } else if (comb[string[l - 1] - 'A'][pan - 'A'] != 0) {
		string[l - 1] = comb[string[l - 1] - 'A'][pan - 'A'];
	    } else if (comb[pan - 'A'][string[l - 1] - 'A'] != 0) {
		string[l - 1] = comb[pan - 'A'][string[l - 1] - 'A'];
	    } else {
		int arrNew = 0;
		for (changable = 0; changable < l; changable++) {
		    if ((oppo[string[changable] - 'A'][pan - 'A'] == 1)
			|| (oppo[pan - 'A'][string[changable] - 'A'] ==
			    1)) {
			arrNew = 1;
			break;
		    }
		}
		if (arrNew)
		    l = 0;
		else {
		    string[l] = pan;
		    l++;
		}
	    }
	}
	printf("Case #%d: [", r);
	if (l != 0) {
	    for (toh = 0; toh < (l - 1); toh++) {
		printf("%c, ", string[toh]);
	    }
	    printf("%c", string[toh]);
	}
	printf("]\n");
    }
    fclose(r);
    return 0;
}
