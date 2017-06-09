#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>

int TC, T;
int L, X;
char InputT[12000];
int Input[220000];
int StateTable[10][10] = { {0, 1, 2, 3}, {1, 4, 3, 6}, {2, 7, 4, 1}, {3, 2, 5, 4} };
int i, x, y;

int XMod(int In){
	int x = ((In-1)%4)+1;
	if ((x+12)<=In) return (x+12);
	if ((x+8)<=In) return (x+8);
	if ((x+4)<=In) return (x+4);
	return x;
}

int Check(int Level){
	int State = 0;
	if (Level==3){
		while(x<L){
			State = StateTable[State][Input[x]];
			x++;
		}
		if (State==0) return 1;
		return 0;
	}
	
	while(x<L){
		State = StateTable[State][Input[x]];
		x++;
		if (State==Level+1) break;
	}
	if (State==Level+1) return Check(Level+1);
	return 0;
}

int Transform(char ch){
	if (ch=='1') return 0;
	if (ch=='i') return 1;
	if (ch=='j') return 2;
	if (ch=='k') return 3;
}

int main(){
	freopen("C-small-attempt0.in", "r", stdin);
	freopen("C-small-attempt0.out", "w", stdout);
	
	
	for (y=0; y<4; y++) for (x=0; x<4; x++) StateTable[y][x+4] = (StateTable[y][x]+4)%8;
	for (y=0; y<4; y++) for (x=0; x<8; x++) StateTable[y+4][x] = (StateTable[y][x]+4)%8;
	
	scanf("%d", &TC);
	for (T=1; T<=TC; T++){
		printf("Case #%d: ", T);
		
		scanf("%d%d", &L, &X);
		scanf("%s", InputT);
		
		X = XMod(X);
		
		for (i=0; i<L; i++) Input[i] = Transform(InputT[i]);
		for (i=1; i<X; i++){
			int LT = L*i;
			for (x=0; x<L; x++) Input[LT+x] = Input[x];
		}
		
		L *= X;
		
		x = 0;
		if (Check(0)) puts("YES");
		else puts("NO");
		
		
	}
	
	return 0;
}

