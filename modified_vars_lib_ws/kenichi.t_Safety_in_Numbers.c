#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<malloc.h>
#include<math.h>
FILE *new_fopen(const char *filename, const char *mode);
int new_fclose(FILE * stream);
int new_fscanf(FILE * stream, const char *format, ...);
int new_fprintf(FILE * stream, const char *format, ...);
void generate_filename(char *out, char *in, char *add)
{
    char *y;
    sprintf(out, "%s", in);
    for (y = (out + strlen(out)) - 1; y >= out; y--) {
	if ((*y) == '/')
	    break;
	if ((*y) == '\\')
	    break;
	if ((*y) == '.') {
	    *y = '\0';
	    break;
	}
    }
    sprintf(out + strlen(out), "%s", add);
}

long long int s[500];
int flg[500];
int i;
long long int b;
long long int k;
void solver(int lx)
{
    int key;
    if (b == k)
	return;
    for (key = lx + 1; key < i; key++) {
	if (flg[key] != 0)
	    continue;
	if (b < k) {
	    flg[key] = 1;
	    b += s[key];
	    solver(key);
	    if (b == k)
		break;
	    flg[key] = 0;
	    b -= s[key];
	    flg[key] = 2;
	    k += s[key];
	    solver(key);
	    if (b == k)
		break;
	    flg[key] = 0;
	    k -= s[key];
	    solver(key);
	    if (b == k)
		break;
	} else {
	    flg[key] = 2;
	    k += s[key];
	    solver(key);
	    if (b == k)
		break;
	    flg[key] = 0;
	    k -= s[key];
	    flg[key] = 1;
	    b += s[key];
	    solver(key);
	    if (b == k)
		break;
	    flg[key] = 0;
	    b -= s[key];
	    solver(key);
	    if (b == k)
		break;
	}
    }
}

void Main(int argc, char *argv[])
{
    char fname_o[_MAX_PATH];
    FILE *fp_i;
    FILE *fp_o;
    int j;
    int key;
    int r;
    generate_filename(fname_o, argv[1], "_out.txt");
    fp_i = new_fopen(argv[1], "r");
    fp_o = new_fopen(fname_o, "w");
    fscanf(fp_i, "%d", &r);
    for (j = 1; j <= r; j++) {
	fprintf(stderr, "Case #%d/%d...", j, r);
	fscanf(fp_i, "%d", &i);
	for (key = 0; key < i; key++) {
	    fscanf(fp_i, "%lld", &s[key]);
	    flg[key] = 0;
	}
	b = 0;
	k = 0;
	for (key = 0; key < i; key++) {
	    flg[key] = 1;
	    b += s[key];
	    solver(key);
	    if (b == k)
		break;
	    flg[key] = 0;
	    b -= s[key];
	}
	fprintf(fp_o, "Case #%d:\n", j);
	if (key == i) {
	    fprintf(fp_o, "Impossible\n");
	} else {
	    for (key = 0; key < i; key++) {
		if (flg[key] == 1)
		    fprintf(fp_o, "%d ", s[key]);
	    }
	    fprintf(fp_o, "\n");
	    for (key = 0; key < i; key++) {
		if (flg[key] == 2)
		    fprintf(fp_o, "%d ", s[key]);
	    }
	    fprintf(fp_o, "\n");
	}
	fprintf(stderr, "finish!!\n");
    }
    new_fclose(fp_i);
    new_fclose(fp_o);
}

FILE *new_fopen(const char *filename, const char *mode)
{
    return fopen(filename, mode);
}

int new_fclose(FILE * stream)
{
    return fclose(stream);
}
