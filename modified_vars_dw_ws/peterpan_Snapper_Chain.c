#include <stdio.h>
int Main(int argc, char *argv[])
{
	int first_iteration;
	FILE *Fin;
	FILE *Fout;
	int answer;
	int t;
	int jj;
	int dis;
	if (argc > 1)
		Fin = fopen(argv[1], "r");
	else
		Fin = fopen("snapperChain.in.txt", "r");
	if (!Fin)
		return 1;
	if (argc > 2)
		Fout = fopen(argv[2], "w");
	else
		Fout = fopen("snapperChain.out.txt", "w");
	if (!Fout) {
		fclose(Fin);
		return 1;
	}
	fscanf(Fin, "%d", &t);
	for (answer = 1; answer <= t; answer++) {
		fscanf(Fin, "%d", &dis);
		fscanf(Fin, "%d", &jj);
		fprintf(Fout, "Case #%d: %s\n", answer,
			(jj % (1 << dis)) == ((1 << dis) - 1) ? "ON" : "OFF");
	}
	fclose(Fin);
	fclose(Fout);
	return 0;
}
