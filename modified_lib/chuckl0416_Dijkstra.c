#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>

int TC, T;
int X, R, C;
FILE * new_freopen(const char *filename, const char *mode, FILE *stream);

int new_puts(const char *str);


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
	new_freopen("D-small-attempt1.in", "r", stdin);
	new_freopen("D-small-attempt1.out", "w", stdout);
	
	scanf("%d", &TC);
	for (T=1; T<=TC; T++){
		printf("Case #%d: ", T);
		
		scanf("%d%d%d", &X, &R, &C);
		if (Tilling()) new_puts("GABRIEL");
		else new_puts("RICHARD");
	}
	
	return 0;
}


FILE * new_freopen(const char *filename, const char *mode, FILE *stream);

int new_puts(const char *str) {
  return puts(str);
}
FILE * new_freopen(const char *filename, const char *mode, FILE *stream) {
  return freopen(filename, mode, stream);
}