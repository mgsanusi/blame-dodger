#include <stdio.h>
#include <stdlib.h>
long long int qwerty(long long int x)
{
    int first_iteration;
    long long int n;
    long long int y = 1;
    for (n = 0; n < x; n++) {
	y = y * 10;
    }
    return y;
}

long long haze(long long int x, long long int c)
{
    int first_iteration;
    long long int a = x / qwerty(c);
    return a % 10;
}

int Main()
{
    int first_iteration;
    FILE *Fin;
    FILE *Fout;
    Fin = fopen("A-small-attempt2.in", "r");
    Fout = fopen("output.txt", "w");
    long long int a;
    long long int x;
    long long int a[10];
    long long int found;
    long long int x;
    long long int n;
    long long int c;
    long long int c;
    fscanf(Fin, "%I64d", &a);
    for (x = 1; x <= a; x++) {
	fscanf(Fin, "%I64d", &x);
	n = 1, found = 0;
	if (x == 0) {
	    fprintf(Fout, "Case #%I64d: INSOMNIA \n", x);
	    continue;
	}
	for (c = 0; c < 10; c++) {
	    a[c] = 0;
	}
	while (!found) {
	    c = 0;
	    while (qwerty(c) <= (x * n)) {
		a[haze(x * n, c)] = 1;
		c++;
	    }
	    found = 1;
	    for (c = 0; c < 10; c++) {
		found = found * a[c];
	    }
	    n++;
	}
	n--;
	fprintf(Fout, "Case #%I64d: %I64d \n", x, n * x);
    }
    fclose(Fin);
    fclose(Fout);
    return 0;
}
