#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>

int TC, T;
double C, F, X;
double i, x, y, Produce, Time, Ans;
FILE * new_freopen(const char *filename, const char *mode, FILE *stream);


int main(){
	new_freopen("B-small-attempt0.in", "r", stdin);
	new_freopen("B-small-attempt0.out", "w", stdout);
	
	scanf("%d", &TC);
	for (T=1; T<=TC; T++){
		printf("Case #%d: ", T);
		scanf("%lf%lf%lf", &C, &F, &X);
		Produce = 2;
		Ans = X/Produce;
		Time = 0;
		
		while(1){
			if ((Time+C/Produce+X/(Produce+F))>=Ans) break;
			Ans = Time+C/Produce+X/(Produce+F);
			
			Time += C/Produce;
			Produce += F;
		}
		
		printf("%.7lf\n", Ans);
	}
	
	return 0;
}


FILE * new_freopen(const char *filename, const char *mode, FILE *stream) {
  return freopen(filename, mode, stream);
}