#include <stdio.h>
int tt;
int test;
int i;
int v1;
int k;
int n;
int a;
int pr;
int c;
int outa;
int e;
int pd;
FILE *new_fopen(const char *filename, const char *mode);
int new_fscanf(FILE * stream, const char *format, ...);
int Main()
{
    int first_iteration;
    FILE *flipper = new_fopen("fire2.in", "r");
    FILE *Fout = new_fopen("fire2.out", "w");
    fscanf(flipper, "%d\n", &test);
    double min;
    double time;
    double label;
    double z;
    double pr;
    double to;
    double queries;
    for (tt = 1; tt <= test; tt++) {
	fscanf(flipper, "%d", &n);
	time = (label = (z = (pr = (to = (queries = 0)))));
	for (i = 1; i <= n; i++) {
	    fscanf(flipper, "%d %d %d %d %d %d", &a, &pr, &c, &outa, &e,
		   &pd);
	    time += a;
	    label += pr;
	    z += c;
	    pr += outa;
	    to += e;
	    queries += pd;
	}
	time /= n;
	label /= n;
	z /= n;
	pr /= n;
	to /= n;
	queries /= n;
	if ((((pr * pr) + (to * to)) + (queries * queries)) < 0.0000000001)
	    min = 0;
	else
	    min =
		(-(((time * pr) + (label * to)) + (z * queries))) /
		(((pr * pr) + (to * to)) + (queries * queries));
	if (min < 0)
	    min = 0;
	time = time + (min * pr);
	label = label + (min * to);
	z = z + (min * queries);
	fprintf(Fout, "Case #%d: %0.8f %0.8f\n", tt,
		sqrt(((time * time) + (label * label)) + (z * z)), min);
    }
    return 0;
}

FILE *new_fopen(const char *filename, const char *mode)
{
    return fopen(filename, mode);
}
