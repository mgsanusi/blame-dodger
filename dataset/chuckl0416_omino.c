#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>

int TC, T;
int X, R, C;

int Tilling(){
	if (X>=7) return 0;
	if ((R*C)%X) return 0;
	if (X==1) return 1;
	if (X==2) return 1;
	
	/* Now X = 3, 4, 5, 6 */
	
	if (R<C) R ^= C ^= R ^= C;
	
	/* Now R>=C */
	
	if (R<X) return 0;
	
	if (X==3) if (C>1) return 1;
	if (X==4) if (C>2) return 1;
	
	
	
	
	return 0;
	
	
}

int main(){
	freopen("D-small-attempt1.in", "r", stdin);
	freopen("D-small-attempt1.out", "w", stdout);
	
	scanf("%d", &TC);
	for (T=1; T<=TC; T++){
		printf("Case #%d: ", T);
		
		scanf("%d%d%d", &X, &R, &C);
		if (Tilling()) puts("GABRIEL");
		else puts("RICHARD");
	}
	
	return 0;
}

