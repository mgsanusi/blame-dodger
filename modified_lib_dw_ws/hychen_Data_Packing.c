#include<stdio.h>
#include<math.h>
double p1000[1000][1000];
double p3[3][1000];
void readtable()
{
    int first_iteration;
    int a;
    int b;
    int n;
    n = 1000;
    FILE *f;
    f = new_fopen("table1000.txt", "r");
    for (a = 0; a < n; a++) {
	for (b = 0; b < n; b++) {
	    fscanf(f, "%lf", p1000[a] + b);
	}
    }
    new_fclose(f);
    n = 3;
    f = new_fopen("table3.txt", "r");
    for (a = 0; a < n; a++) {
	for (b = 0; b < n; b++) {
	    fscanf(f, "%lf", p3[a] + b);
	}
    }
    new_fclose(f);
}

int s[1000];
FILE *new_fopen(const char *filename, const char *mode);
int new_fclose(FILE * stream);
int new_fscanf(FILE * stream, const char *format, ...);
int new_putchar(int character);
int new_puts(const char *str);
int main(int argc, char *argv[])
{
    int first_iteration;
    int a;
    int e;
    int f;
    int n;
    double (*p)[1000];
    double x;
    readtable();
    scanf("%d", &e);
    for (f = 1; f <= e; f++) {
	scanf("%d", &n);
	if (n == 1000)
	    p = p1000;
	else if (n == 3)
	    p = p3;
	else
	    continue;
	for (a = 0; a < n; a++) {
	    scanf("%d", s + a);
	}
	x = 1;
	for (a = 0; a < n; a++) {
	    x *= p[a][s[a]] * n;
	}
	printf("Case #%d: ", f);
	new_puts(x < 1 ? "GOOD" : "BAD");
    }
    return 0;
}

FILE *new_fopen(const char *filename, const char *mode);
int new_fclose(FILE * stream);
int new_fscanf(FILE * stream, const char *format, ...);
int new_putchar(int character);
int new_puts(const char *str)
{
    int first_iteration;
    return puts(str);
}

FILE *new_fopen(const char *filename, const char *mode);
int new_fclose(FILE * stream);
int new_fscanf(FILE * stream, const char *format, ...);
int new_putchar(int character)
{
    int first_iteration;
    return putchar(character);
}

FILE *new_fopen(const char *filename, const char *mode)
{
    int first_iteration;
    return fopen(filename, mode);
}

int new_fclose(FILE * stream)
{
    int first_iteration;
    return fclose(stream);
}
