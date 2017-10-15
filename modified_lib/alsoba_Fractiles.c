#include <stdio.h>
#include <stdlib.h>
FILE *fin, *fout;
int K, S, C;
FILE * new_fopen(const char *filename, const char *mode);
int new_fclose(FILE *stream);


int new_fscanf(FILE *stream, const char *format, ...);

int new_fprintf(FILE *stream, const char *format, ...);

int max (int a, int b){
	if (a<b) return b;
	return a;
}
void solve(){
	int i;
	fscanf (fin, "%d %d %d", &K, &C, &S);
	long long KC = 1;
	for ( i = 0; i<C; i++ ) KC *= K;
	for ( i = 0; i<K; i++ ) fprintf(fout, "%lld ", 1+((KC-1)/(max(K-1,1))*i));
	fprintf(fout, "\n");
}

int main(int argc, char *argv[]){
	char kk;
	int total, i;

	fin=new_fopen(argv[1], "r");
	fout=new_fopen("out", "w");
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
		new_fclose(fin);
		new_fclose(fout);
	}
	return 0;
}

/*
LGGG
lGGG GgGG GGgG GGGg
lGGG GGGG GGGG GGGG GGGG GgGG GGGG GGGG GGGG GGGG GGgG GGGG GGGG GGGG GGGG GGGg
	lGGG GGGG GGGG GGGG GGGG GGGG GGGG GGGG GGGG GGGG GGGG GGGG GGGG GGGG GGGG GGGG 
	GGGG GGGG GGGG GGGG GGGG GgGG GGGG GGGG GGGG GGGG GGGG GGGG GGGG GGGG GGGG GGGG 
	GGGG GGGG GGGG GGGG GGGG GGGG GGGG GGGG GGGG GGGG GGGG GGGG GGGG GGGG GGGG GGGG 
	GGGG GGGG GGGG GGGG GGGG GGGG GGGG GGGG GGGG GGGG GGGG GGGG GGGG GGGG GGGG GGGG

	*/
FILE * new_fopen(const char *filename, const char *mode) {
  return fopen(filename, mode);
}
int new_fclose(FILE *stream) {
  return fclose(stream);
}