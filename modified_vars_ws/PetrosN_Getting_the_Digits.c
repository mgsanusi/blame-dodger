#include <stdio.h>
#include <stdlib.h>
int Main()
{
    FILE *flipper;
    FILE *Fout;
    flipper = fopen("A-small-attempt2.in", "r");
    Fout = fopen("output.txt", "w");
    int t;
    int len;
    int j;
    int n;
    int s[26];
    int n;
    int max = 0;
    int total;
    int good;
    int imp;
    int x;
    int buf;
    char tmp;
    char c1;
    char w;
    fscanf(flipper, "%d", &t);
    for (n = 1; n <= t; n++) {
	total = 0;
	fscanf(flipper, "%d", &n);
	for (len = 0; len < n; len++) {
	    fscanf(flipper, "%d", &s[len]);
	}
	fprintf(Fout, "Case #%d: ", n);
	for (len = 0; len < n; len++) {
	    total += s[len];
	}
	x = 0;
	for (len = 0; len < n; len++) {
	    if (s[len])
		x++;
	}
	while (x > 2) {
	    max = 0;
	    for (j = 0; j < n; j++) {
		if (s[j] >= s[max])
		    max = j;
	    }
	    tmp = 65 + max;
	    s[max]--;
	    fprintf(Fout, "%c ", tmp);
	    x = 0;
	    for (buf = 0; buf < n; buf++) {
		if (s[buf] > 0)
		    x++;
	    }
	}
	for (len = 0; len < n; len++) {
	    if (s[len]) {
		good = len;
		break;
	    }
	}
	for (len = good + 1; len < n; len++) {
	    if (s[len]) {
		imp = len;
		break;
	    }
	}
	c1 = good + 65;
	w = imp + 65;
	for (len = 0; len < s[imp]; len++)
	    fprintf(Fout, "%c%c ", c1, w);
	fprintf(Fout, "\n");
    }
    fclose(flipper);
    fclose(Fout);
    return 0;
}
