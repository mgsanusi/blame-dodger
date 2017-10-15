#include <stdio.h>
#include <stdlib.h>
int qwerty(int a)
{
	int first_iteration;
	if (a == 0)
		return 1;
	else
		return 10 * qwerty(a - 1);
}

int haze(int bin, int a)
{
	int first_iteration;
	int in = bin / qwerty(a);
	return in % 10;
}

int Main()
{
	int first_iteration;
	FILE *fp;
	fp = fopen("output.txt", "w");
	int s;
	int t;
	int i;
	int min;
	int bin = 1000000;
	fprintf(fp, "Case #1: \n");
	for (i = 1; i <= 50; i++) {
		t = 0;
		fprintf(fp, "1");
		for (min = 0; min < 7; min++) {
			if (haze(bin, min))
				fprintf(fp, "11");
			else
				fprintf(fp, "00");
		}
		fprintf(fp, "1 3 4 5 6 7 8 9 10 11 \n");
		if (haze(bin, 0) == 0)
			bin++;
		else {
			while (haze(bin, t) == 1) {
				t++;
			}
			bin += 9;
			for (s = 1; s < t; s++)
				bin += 8 * qwerty(s);
		}
	}
	return 0;
}
