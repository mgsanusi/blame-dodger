#include <stdio.h>
#include <string.h>

char se[100][101];
char now[101];
int canuse[100];
FILE *fin, *fout;

void readstring(char *str){
	int i;
	for(i = 0; fscanf(fin, "%c", &str[i]), str[i] != '\n'; i++);
	str[i] = 0;
}

int main(){
	int n, x;
	int s, q;
	int i, j;
	int ans, ava;
	
	fin = fopen("A-small.in", "r");
	fout = fopen("A-small.out", "w");
	fscanf(fin, "%d", &n);
	x = n;
	while(n-- > 0){
		fscanf(fin, "%d", &s);
		fscanf(fin, "%c", &now[100]);
		memset(canuse, 0, sizeof(canuse));
		ans = 0;
		ava = s;
		for(i = 0; i < s; i++){
			readstring(se[i]);
		}
		fscanf(fin, "%d", &q);
		fscanf(fin, "%c", &now[100]);
		
		for(i = 0; i < q; i++){
			readstring(now);
			for(j = 0; j < s && strcmp(now, se[j]) != 0; j++);
			if(canuse[j] != 1){
				canuse[j] = 1;
				if(--ava == 0){
					memset(canuse, 0, sizeof(canuse));
					ans++;
					canuse[j] = 1;
					ava = s - 1;
				}
			}
		}
		fprintf(fout, "Case #%d: %d\n", x - n, ans);
	}
	return 0;
}
