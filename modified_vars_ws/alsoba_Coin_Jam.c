#include <stdio.h>
#include <stdlib.h>
FILE *flipper;
FILE *Fout;
int mask[] = { 1, 5, 9, 17, 33, 21, 65, 129 };

int signMap = 8;
int t;
void sll(char *c)
{
	t++;
	if (t <= 50)
		fprintf(Fout, "11%s11 3 4 5 6 7 8 9 10 11\n", c);
}

void clear()
{
	int nk;
	int pG;
	sll("000000000000");
	for (nk = 0; nk < signMap; nk++) {
		long long cName = mask[nk];
		int r = 0;
		while (!r) {
			if (((cName >> 10) & 1) == 1)
				r = 1;
			char s[13];
			for (pG = 11; pG >= 0; pG--) {
				s[pG] = ((3 * cName) >> (11 - pG)) & 1;
				s[pG] += '0';
			}
			s[12] = '\0';
			sll(s);
			cName *= 2;
		}
	}
}

int Main(int argc, char *argv[])
{
	char g;
	int total;
	int nk;
	flipper = fopen(argv[1], "r");
	Fout = fopen("out", "w");
	if ((flipper == 0) || (Fout == 0)) {
		printf("Fitxer out.\n");
	} else {
		fscanf(flipper, "%d", &total);
		fscanf(flipper, "%c", &g);
		for (nk = 0; nk < total; nk++) {
			fprintf(Fout, "Case #%d: \n", nk + 1);
			clear();
		}
		fclose(flipper);
		fclose(Fout);
	}
	return 0;
}
