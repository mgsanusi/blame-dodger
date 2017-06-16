#include <stdio.h>
#include <stdlib.h>
FILE *fin, *fout;

void solve(){
	char a;
	char b;
	int s = 0;
	fscanf(fin, "%c", &a);
	fscanf(fin, "%c", &b);
	while (b != '\n'){
		if(b != a){
			a = b;
			s++;
		}
		fscanf(fin, "%c", &b);
	}
	if(a == '-') s++;
	fprintf(fout, "%d\n", s);
}

int main(int argc, char *argv[]){
	char kk;
	int total, i;

	fin=fopen(argv[1], "r");
	fout=fopen("out", "w");
	if (fin==NULL || fout == NULL)
	{
		printf("Fitxer out.\n");
	}
	else 
	{
		fscanf(fin, "%d", &total);
		fscanf(fin, "%c", &kk);
		for (i = 0; i<total; i++)
		{
			fprintf(fout, "Case #%d: ", i+1);
			solve();
		}
		fclose(fin);
		fclose(fout);
	}
	return 0;
}