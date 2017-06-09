#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>

int TC, T;
int Row;
int Map[10][10];
int Ans[20];
int i, x, y, FAns;

int Check(){
	FAns = 0;
	for (i=1; i<=16; i++){
		if (Ans[i]==2){
			if (FAns) return 0;
			FAns = i;
		}
	}
	return 1;
}

int main(){
	freopen("A-small-attempt0.in", "r", stdin);
	freopen("A-small-attempt0.out", "w", stdout);
	
	scanf("%d", &TC);
	for (T=1; T<=TC; T++){
		printf("Case #%d: ", T);
		
		memset(Ans, 0, sizeof(Ans));
		for (i=0; i<2; i++){
			scanf("%d", &Row);
			for (y=1; y<=4; y++) for (x=0; x<4; x++) scanf("%d", &Map[y][x]);
			for (x=0; x<4; x++) Ans[Map[Row][x]]++;
		}
		
		if (!Check()) puts("Bad magician!");
		else{
			if (FAns) printf("%d\n", FAns);
			else puts("Volunteer cheated!");
		}
		
	}
	
	return 0;
}

