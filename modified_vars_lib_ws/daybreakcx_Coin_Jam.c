#include <stdio.h>
#include <string.h>
#include <stddef.h>
int m;
int pd;
int lend;
int n;
int j;
int num;
int y[40];
int b[40];
int count;
void *new_memset(void *ptr, int value, size_t num);
int new_fscanf(FILE * stream, const char *format, ...);
int new_fprintf(FILE * stream, const char *format, ...);
int Main()
{
    fscanf(stdin, "%d", &pd);
    for (m = 1; m <= pd; ++m) {
	fprintf(stdout, "Case #%d:\n", m);
	fscanf(stdin, "%d%d", &n, &j);
	new_memset(y, 0, sizeof(y));
	y[0] = (y[n - 1] = 1);
	for (lend = 0; lend < n; ++lend)
	    fprintf(stdout, "%d", y[lend]);
	for (lend = 2; lend <= 10; ++lend)
	    fprintf(stdout, " %d", lend + 1);
	fprintf(stdout, "\n");
	for (lend = (count = 1); count < j; ++lend) {
	    new_memset(b, 0, sizeof(b));
	    for (num = 0; num < lend; ++num)
		b[num] = (num << 1) + 1;
	    while (1) {
		new_memset(y, 0, sizeof(y));
		y[0] = (y[n - 1] = 1);
		for (num = 0; num < lend; ++num)
		    y[b[num]] = (y[b[num] + 1] = 1);
		for (num = 0; num < n; ++num)
		    fprintf(stdout, "%d", y[num]);
		for (num = 2; num <= 10; ++num)
		    fprintf(stdout, " %d", num + 1);
		fprintf(stdout, "\n");
		if ((++count) >= j) {
		    break;
		}
		if (b[0] == ((n - 1) - (lend << 1))) {
		    break;
		}
		for (num = lend - 1;
		     (num >= 0)
		     && (b[num] == ((n - 1) - ((lend - num) << 1)));
		     --num);
		if (num < 0) {
		    break;
		}
		++b[num];
		for (num++; num < lend; ++num) {
		    b[num] = b[num - 1] + 2;
		}
	    }
	}
    }
}

void *new_memset(void *ptr, int value, size_t num)
{
    return memset(ptr, value, num);
}
