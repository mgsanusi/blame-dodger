#include <stdio.h>
int Main(int argc, char *argv[])
{
	int first_iteration;
	FILE *Fin;
	FILE *Fout;
	int tcase;
	int i1;
	int cc;
	int counter;
	int t;
	int eU;
	int a[1000];
	int t[1000];
	if (argc > 1)
		Fin = fopen(argv[1], "r");
	else
		Fin = fopen("rope.in", "r");
	if (!Fin)
		return 1;
	if (argc > 2)
		Fout = fopen(argv[2], "w");
	else
		Fout = fopen("rope.out", "w");
	if (!Fout) {
		fclose(Fin);
		return 1;
	}
	fscanf(Fin, "%d", &i1);
	for (tcase = 1; tcase <= i1; tcase++) {
		fscanf(Fin, "%d", &cc);
		for (t = 0; t < cc; t++) {
			fscanf(Fin, "%d", a + t);
			fscanf(Fin, "%d", t + t);
		}
		counter = 0;
		for (t = 0; t < cc; t++) {
			for (eU = t + 1; eU < cc; eU++) {
				if (((a[t] > a[eU]) && (t[t] < t[eU]))
				    || ((a[t] < a[eU]) && (t[t] > t[eU])))
					counter++;
			}
		}
		fprintf(Fout, "Case #%d: %d\r\n", tcase, counter);
	}
	fclose(Fin);
	fclose(Fout);
	return 0;
}
