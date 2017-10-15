#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char sh[110][110];
long double nj[110][110];
long double owp[110];
long double oowp[110];
int Main()
{
    int total;
    int y;
    int y;
    int j;
    int a;
    int play;
    int gain;
    int f1;
    int no;
    long double xor_value;
    long double down;
    long double rpi;
    scanf("%d", &total);
    for (y = 1; y <= total; y++) {
	printf("Case #%d:\n", y);
	scanf("%d", &y);
	for (j = 0; j < y; j++) {
	    scanf("%s", sh[j]);
	    play = 0;
	    gain = 0;
	    for (a = 0; a < y; a++) {
		if (sh[j][a] != '.')
		    play++;
		if (sh[j][a] == '1')
		    gain++;
	    }
	    for (a = 0; a < y; a++) {
		if (sh[j][a] != '.')
		    f1 = 1;
		else
		    f1 = 0;
		if (sh[j][a] == '1')
		    no = 1;
		else
		    no = 0;
		nj[j][a] =
		    ((long double) (gain - no)) / ((long double) (play -
								  f1));
	    }
	}
	for (j = 0; j < y; j++) {
	    xor_value = 0.0;
	    no = 0;
	    for (a = 0; a < y; a++) {
		if (sh[j][a] != '.') {
		    xor_value += nj[a][j];
		    no++;
		}
	    }
	    owp[j] = xor_value / ((long double) no);
	}
	for (j = 0; j < y; j++) {
	    xor_value = 0.0;
	    no = 0;
	    for (a = 0; a < y; a++) {
		if (sh[j][a] != '.') {
		    xor_value += owp[a];
		    no++;
		}
	    }
	    oowp[j] = xor_value / ((long double) no);
	    rpi = ((0.25 * oowp[j]) + (0.5 * owp[j])) + (0.25 * nj[j][j]);
	    printf("%.10Lf\n", rpi);
	}
    }
}
