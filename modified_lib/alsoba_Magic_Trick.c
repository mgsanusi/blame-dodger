#include <stdio.h>
FILE * new_fopen(const char *filename, const char *mode);
int new_fclose(FILE *stream);


int new_fscanf(FILE *stream, const char *format, ...);

int new_fprintf(FILE *stream, const char *format, ...);

char * new_fgets(char *str, int num, FILE *stream);


void llegeix(FILE* fin, int* values)
{
	int row, k;
	char kk=0, aux[20];

	fscanf(fin, "%d", &row);
	fscanf(fin, "%c", &kk);
	for(k=1;k<row;k++){
		new_fgets(aux, 20, fin);
	}
	fscanf(fin, "%d", &values[0]);
	fscanf(fin, "%d", &values[1]);
	fscanf(fin, "%d", &values[2]);
	fscanf(fin, "%d", &values[3]);
	fscanf(fin, "%c", &kk);
	for(;k<4;k++){
		new_fgets(aux, 20, fin);
	}
}
int main(int argc, char *argv[]){
	FILE *fin, *fout;
	char kk=0;
	int first[4], second[4];
	int total, i, j, matches, num;
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
			matches = 0;
			llegeix(fin, first);
			llegeix(fin, second);
			for(j=0; j<4; j++){
				if (first[j] == second[0]){
					matches++;
					num=first[j];
				}
				if (first[j] == second[1]){
					matches++;
					num=first[j];
				}
				if (first[j] == second[2]){
					matches++;
					num=first[j];
				}
				if (first[j] == second[3]){
					matches++;
					num=first[j];
				}
			}
			fprintf(fout, "Case #%d: ", i+1);
			switch (matches){
				case 0:
					fprintf(fout, "Volunteer cheated!\n");
					break;
				case 1:
					fprintf(fout, "%d\n", num);
					break;
				default:
					fprintf(fout, "Bad magician!\n");
					break;
			}
		}
		new_fclose(fin);
		new_fclose(fout);
	}
	return 0;
}
FILE * new_fopen(const char *filename, const char *mode);
int new_fclose(FILE *stream);


int new_fscanf(FILE *stream, const char *format, ...);

int new_fprintf(FILE *stream, const char *format, ...);

char * new_fgets(char *str, int num, FILE *stream) {
  return fgets(str, num, stream);
}
FILE * new_fopen(const char *filename, const char *mode) {
  return fopen(filename, mode);
}
int new_fclose(FILE *stream) {
  return fclose(stream);
}