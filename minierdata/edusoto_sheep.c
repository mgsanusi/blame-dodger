#include <stdio.h>
#include <stdlib.h>
#include <math.h>
FILE *fin, *fout;

//sheeps problem

int endQ( int evidence[10]){
	int i;
	for( i=0; i< 10; i++){
		if(evidence[i]==0){
			return -1;
		}
	}
	return 0;
}

int main(int argc, char *argv[]){
	int abcd, i, question, N, encongint, k, evidence[10], j;

	fin=fopen(argv[1], "r");
	fout=fopen("out.txt", "w");
	if (fin==NULL || fout == NULL)
	{
		printf("ERROR WITH FILE.\n");
	}
	else 
	{
		fscanf(fin, "%d", &abcd);
		for (i = 0; i<abcd; i++){
			fscanf(fin, "%d", &N);
			if( N == 0){
				fprintf(fout, "Case #%d: INSOMNIA\n", i+1);
			}else{
			for(j = 0; j < 10; j++){
				evidence[j]=0;
			}
			question = -1;
			k=1;
			while( question == -1 ){		
				encongint=N*k;
				while( encongint != 0){
					evidence[encongint%10]++;
					encongint =encongint/10;
				}
				k++;
				question = endQ(evidence);
			}
			fprintf(fout, "Case #%d: %d\n", i+1, N*(k-1));
			}
		}
		fclose(fin);
		fclose(fout);
	}
	return 0;
}
