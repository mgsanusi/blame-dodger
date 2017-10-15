#include <stdio.h>
#include <stdlib.h>
FILE *fin, *fout;
char m[100][100]; // m[r][c];
int R, C;
FILE * new_fopen(const char *filename, const char *mode);
int new_fclose(FILE *stream);


int new_fscanf(FILE *stream, const char *format, ...);

int new_fprintf(FILE *stream, const char *format, ...);


int goLeft(int a, int b){
	int i;
	for(i=b-1; i>=0; i--){
		if(m[a][i]!='.') return 1;
	}
	printf("NoGoLeft %d %d\n", a, b);
	return 0;
}
int goRight(int a, int b){
	int i;
	for(i=b+1; i<C; i++){
		if(m[a][i]!='.') return 1;
	}
	printf("NoGoRight %d %d\n", a, b);
	return 0;
}
int goUp(int a, int b){
	int i;
	for(i=a-1; i>=0; i--){
		if(m[i][b]!='.') return 1;
	}
	printf("NoGoUp %d %d\n", a, b);
	return 0;
}
int goDown(int a, int b){
	int i;
	for(i=a+1; i<R; i++){
		if(m[i][b]!='.') return 1;
	}
	printf("NoGoDown %d %d\n", a, b);
	return 0;
}

int check(int a, int b){
	switch(m[a][b]){
		case '<':
			if(goLeft(a, b)) return 0;
			if(goRight(a, b)) return 1;
			if(goUp(a, b)) return 1;
			if(goDown(a, b)) return 1;
			printf("%d %d\n", a, b);
			return -1;
		break;
		case '>':
			if(goRight(a, b)) return 0;
			if(goLeft(a, b)) return 1;
			if(goUp(a, b)) return 1;
			if(goDown(a, b)) return 1;
			printf("%d %d\n", a, b);
			return -1;
		break;
		case '^':
			if(goUp(a, b)) return 0;
			if(goRight(a, b)) return 1;
			if(goLeft(a, b)) return 1;
			if(goDown(a, b)) return 1;
			printf("%d %d\n", a, b);
			return -1;
		break;
		case 'v':
			if(goDown(a, b)) return 0;
			if(goUp(a, b)) return 1;
			if(goRight(a, b)) return 1;
			if(goLeft(a, b)) return 1;
			printf("%d %d\n", a, b);
			return -1;
		break;
	}
	return -1;
}

void solve(){
	int i, j;
	char kk;
	int total = 0;
	fscanf(fin, "%d %d", &R, &C);
	fscanf(fin, "%c", &kk);
	for(i=0; i<R; i++){
		for(j=0; j<C; j++){
			fscanf(fin, "%c", &m[i][j]);
		}
		fscanf(fin, "%c", &kk);
	}
	for(i=0; i<R; i++){
		for(j=0; j<C; j++){
			if(m[i][j]!='.'){
				int r = check(i, j);
				if(r == -1) {
					fprintf(fout, "IMPOSSIBLE\n");
					return;
				} else {
					total += r;
				}
			}
		}
	}
	fprintf(fout, "%d\n", total);
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
			printf("Case #%d: ", i+1);
			solve();
		}
		new_fclose(fin);
		new_fclose(fout);
	}
	return 0;
}
FILE * new_fopen(const char *filename, const char *mode) {
  return fopen(filename, mode);
}
int new_fclose(FILE *stream) {
  return fclose(stream);
}