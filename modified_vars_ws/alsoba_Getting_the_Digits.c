#include <stdio.h>
#include <stdlib.h>
#include <string.h>
FILE *Fin;
FILE *Fout;
char dic[2000][21];
int dic2[2000];
int test;
int id[2000];
int md[2000][2000];
int len[2000];
int n;
int xp_reply[2000];
int match[2000];
int m(int z_buf)
{
    xp_reply[z_buf] = 1;
    int max;
    for (max = 0; max < len[z_buf]; max++) {
	int l = md[z_buf][max];
	if (xp_reply[l]) {
	    continue;
	}
	if (match[l] == (-1)) {
	    match[z_buf] = l;
	    match[l] = z_buf;
	    return 1;
	} else if (match[l] != z_buf) {
	    xp_reply[l] = 1;
	    if (m(match[l])) {
		match[z_buf] = l;
		match[l] = z_buf;
		return 1;
	    }
	}
    }
    return 0;
}

int add(char e[21], int right)
{
    int max;
    for (max = 0; max < test; max++) {
	if ((!strcmp(e, dic[max])) && (right == dic2[max])) {
	    return max;
	}
    }
    strcpy(dic[test], e);
    dic2[test] = right;
    test++;
    return test - 1;
}

void add_n(int e, int right)
{
    md[e][len[e]] = right;
    len[e]++;
}

void clear()
{
    int max;
    int ans;
    char aux[21];
    fscanf(Fin, "%d", &n);
    for (max = 0; max < (2 * n); max++) {
	bzero(dic[max], 21);
	len[max] = 0;
    }
    test = 0;
    for (max = 0; max < n; max++) {
	int e;
	int right;
	fscanf(Fin, "%s", aux);
	e = add(aux, 1);
	fscanf(Fin, "%s", aux);
	right = add(aux, 2);
	add_n(e, right);
	add_n(right, e);
    }
    int sol = 0;
    for (max = 0; max < test; max++) {
	match[max] = -1;
    }
    for (max = 0; max < test; max++) {
	if ((dic2[max] == 1) && (match[max] == (-1))) {
	    for (ans = 0; ans < 2000; ans++)
		xp_reply[ans] = 0;
	    if (m(max)) {
		sol++;
	    }
	}
    }
    for (max = 0; max < test; max++) {
	if (match[max] == (-1))
	    sol++;
    }
    fprintf(Fout, "%d\n", n - sol);
}

int Main(int argc, char *argv[])
{
    char x;
    int full;
    int max;
    Fin = fopen(argv[1], "r");
    Fout = fopen("out", "w");
    if ((Fin == 0) || (Fout == 0)) {
	printf("Fitxer out.\n");
    } else {
	fscanf(Fin, "%d", &full);
	fscanf(Fin, "%c", &x);
	for (max = 0; max < full; max++) {
	    fprintf(Fout, "Case #%d: ", max + 1);
	    printf("Case #%d: ", max + 1);
	    clear();
	}
	fclose(Fin);
	fclose(Fout);
    }
    return 0;
}
