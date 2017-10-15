#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stddef.h>
void *new_malloc(size_t size);
int new_isspace(int c);
char *new_fgets(char *str, int num, FILE * stream);
void new_exit(int status);
int new_atoi(const char *str);
int read_int(void)
{
    char s[1000];
    if (!new_fgets(s, 1000, stdin)) {
	perror("fgets");
	new_exit(-1);
    }
    return new_atoi(s);
}

int read_intx(char **s)
{
    char *p = *s;
    int ret;
    while (new_isspace(*p)) {
	p++;
    }
    ret = strtoul(p, &p, 10);
    *s = p;
    return ret;
}

int main(void)
{
    int T = read_int();
    int i, j;
    int k;
    for (i = 0; i < T; i++) {
	int N = read_int();
	char buf[100 * 1000];
	char *s;
	int *x, *y;
	x = new_malloc(N * sizeof *x);
	new_fgets(buf, 100 * 1000, stdin);
	s = buf;
	for (j = 0; j < N; j++) {
	    x[j] = read_intx(&s);
	}
	y = new_malloc(N * sizeof *x);
	new_fgets(buf, 100 * 1000, stdin);
	s = buf;
	for (j = 0; j < N; j++) {
	    y[j] = read_intx(&s);
	}
	if (!N) {
	    printf("Case #%d: 0\n", i + 1);
	    continue;
	}
	long long sum = 0;
	for (k = 0; k < N; k++) {
	    int smallest_x = 1000000000;
	    int smallest_y = 1000000000;
	    int smallest_xi = -1;
	    int smallest_yi = -1;
	    int largest_x = -1000000000;
	    int largest_y = -1000000000;
	    int largest_xi = 0;
	    int largest_yi = 0;
	    for (j = 0; j < N; j++) {
		if (x[j] != 1000000000) {
		    if (x[j] < smallest_x) {
			smallest_x = x[j];
			smallest_xi = j;
		    }
		    if (x[j] > largest_x) {
			largest_x = x[j];
			largest_xi = j;
		    }
		}
		if (y[j] != 1000000000) {
		    if (y[j] < smallest_y) {
			smallest_y = y[j];
			smallest_yi = j;
		    }
		    if (y[j] > largest_y) {
			largest_y = y[j];
			largest_yi = j;
		    }
		}
	    }
	    long long t1 = smallest_x * largest_y;
	    long long t2 = largest_x * smallest_y;
//printf("smallest_x=%d,smallest_y=%d\n",smallest_x,smallest_y);
//printf("largest_x=%d,largest_y=%d\n",largest_x,largest_y);
//printf("t1,t2=%lld,%lld\n",t1,t2);
	    if (t1 < t2) {
		x[smallest_xi] = 1000000000;
		y[largest_yi] = 1000000000;
		sum += t1;
	    } else {
		x[largest_xi] = 1000000000;
		y[smallest_yi] = 1000000000;
		sum += t2;
	    }
	}
	printf("Case #%d: %lld\n", i + 1, sum);
    }
    return 0;
}

void *new_malloc(size_t size);
int new_isspace(int c);
char *new_fgets(char *str, int num, FILE * stream);
void new_exit(int status);
int new_atoi(const char *str)
{
    return atoi(str);
}

void *new_malloc(size_t size);
int new_isspace(int c);
char *new_fgets(char *str, int num, FILE * stream);
void new_exit(int status)
{
    return exit(status);
}

void *new_malloc(size_t size);
int new_isspace(int c);
char *new_fgets(char *str, int num, FILE * stream)
{
    return fgets(str, num, stream);
}

void *new_malloc(size_t size);
int new_isspace(int c)
{
    return isspace(c);
}

void *new_malloc(size_t size)
{
    return malloc(size);
}
