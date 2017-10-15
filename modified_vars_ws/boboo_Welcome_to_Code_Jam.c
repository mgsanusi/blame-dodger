#include <stdio.h>
#include <string.h>
char aa[20] = "welcome to code jam";
int Main()
{
	FILE *Fin = fopen("c1.in", "r");
	FILE *Fout = fopen("c1.out", "w");
	int time2;
	int tc;
	int msg;
	int l;
	int r;
	int n;
	int result;
	int now;
	fscanf(Fin, "%d\n", &n);
	char s[510];
	int e[510];
	int star[510];
	for (r = 1; r <= n; r++) {
		fgets(s, 505, Fin);
		l = strlen(s);
		for (time2 = 0; time2 < l; time2++)
			e[time2] = s[time2] == 'w';
		for (time2 = 1; time2 < 19; time2++) {
			now = 0;
			for (tc = 0; tc < l; tc++) {
				if (s[tc] == aa[time2])
					star[tc] = now;
				else
					star[tc] = 0;
				if (s[tc] == aa[time2 - 1]) {
					now += e[tc];
					if (now > 9999)
						now = now % 10000;
				}
			}
			for (tc = 0; tc < l; tc++)
				e[tc] = star[tc];
		}
		result = 0;
		for (time2 = 0; time2 < l; time2++)
			result = (result + e[time2]) % 10000;
		fprintf(Fout, "Case #%d: ", r);
		if (result < 1000)
			fprintf(Fout, "0");
		if (result < 100)
			fprintf(Fout, "0");
		if (result < 10)
			fprintf(Fout, "0");
		fprintf(Fout, "%d\n", result);
	}
	return 0;
}
