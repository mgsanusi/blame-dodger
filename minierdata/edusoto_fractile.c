#include <stdio.h>
#include <stdlib.h>
FILE *fin, *fout;


int main(int argc, char *argv[]){
	int abcd, i, C, S, j;
	long long int position, cons, K;
	fin=fopen(argv[1], "r");
	fout=fopen("out.txt", "w");
	if (fin==NULL || fout == NULL)
	{
		printf("ERROR WITH FILE.\n");
	}
	else 
	{
	fscanf(fin, "%d", &abcd);
	for( i=0; i < abcd; i++ ){
		fscanf(fin, "%lld", &K);
		fscanf(fin, "%d", &C);
		fscanf(fin, "%d", &S);
		fprintf(fout, "Case #%d: ", i+1);
		position=1;
		cons=1;
		for(j = 0; j < C-1; j++){
			cons*= K;
		}

		for(j = 0; j < K; j++){
			fprintf(fout, "%lld ", position);			
			position +=cons;

		}
		fprintf(fout, "\n");			
	}
	fclose(fin);
	fclose(fout);
	}
	return 0;
}