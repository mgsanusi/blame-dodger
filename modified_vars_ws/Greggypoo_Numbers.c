#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
int take_int(void)
{
    char s[1000];
    if (!fgets(s, 1000, stdin)) {
	perror("fgets");
	exit(-1);
    }
    return atoi(s);
}

char *read_string(void)
{
    char s[1000];
    if (!fgets(s, 1000, stdin)) {
	perror("fgets");
	exit(-1);
    }
    s[strcspn(s, "\r\n")] = 0;
    return strdup(s);
}

void read_int2(int *x, int *t)
{
    char s[1000];
    char *p;
    if (!fgets(s, 1000, stdin)) {
	perror("fgets");
	exit(-1);
    }
    p = s;
    *x = strtoul(p, &p, 10);
    p++;
    *t = strtoul(p, &p, 10);
}

void read_int4(int *x, int *t, int *t, int *a)
{
    char s[1000];
    char *p;
    if (!fgets(s, 1000, stdin)) {
	perror("fgets");
	exit(-1);
    }
    p = s;
    *x = strtoul(p, &p, 10);
    p++;
    *t = strtoul(p, &p, 10);
    p++;
    *t = strtoul(p, &p, 10);
    p++;
    *a = strtoul(p, &p, 10);
}

void read_double5(double *a, double *b, double *c, double *d, double *e)
{
    char s[1000];
    char *p;
    if (!fgets(s, 1000, stdin)) {
	perror("fgets");
	exit(-1);
    }
    p = s;
    *a = strtod(p, &p);
    p++;
    *b = strtod(p, &p);
    p++;
    *c = strtod(p, &p);
    p++;
    *d = strtod(p, &p);
    p++;
    *e = strtod(p, &p);
}

int read_intx(char **s)
{
    char *p = *s;
    int ret;
    while (isspace(*p)) {
	p++;
    }
    ret = strtoul(p, &p, 10);
    *s = p;
    return ret;
}

int Main(void)
{
    int pi = take_int();
    int test_case;
    int tid;
    int p2;
    int str;
    int t;
    int space_frequency;
    int x2;
    int best;
    int ill_act;
    int y2;
    int num_cities;
    int ix;
    int tnum;
    int word;
    for (test_case = 0; test_case < pi; test_case++) {
	char buff[1000];
	char *s = buff;
	fgets(s, 1000, stdin);
	ix = read_intx(&s);
	tnum = read_intx(&s);
	word = read_intx(&s);
	for (tid = 0; tid <= ix; tid++) {
	    space_frequency = tid;
	    ill_act = 0;
	    for (p2 = 0; p2 <= tnum; p2++) {
		x2 = 0;
		y2 = p2;
		for (str = 0; str <= ix; str++) {
		    best = str;
		    for (t = 0; t <= tnum; t++) {
			num_cities = t;
			if ((((best - space_frequency) * (y2 - ill_act)) -
			     ((x2 - space_frequency) * (num_cities -
							ill_act))) ==
			    word) {
			    printf("Case #%d: %d %d %d %d %d %d\n",
				   test_case + 1, space_frequency, ill_act,
				   x2, y2, best, num_cities);
			    goto done;
			}
		    }
		}
	    }
	}
	printf("Case #%d: IMPOSSIBLE\n", test_case + 1);
      done:
	;
    }
    return 0;
}
