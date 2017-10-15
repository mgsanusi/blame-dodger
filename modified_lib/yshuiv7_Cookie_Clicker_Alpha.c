#include <stdio.h>
double c,f,x;
int main(){
	int cases;
	scanf("%d", &cases);
	int p;
	for(p=1; p<=cases; p++){
		scanf("%lf%lf%lf", &c, &f, &x);
		double best = x/2.0;
		double now=2.0;
		double elapsed=0;
		while(x/(now+f)+c/now+elapsed < best){
			best = x/(now+f)+c/now+elapsed;
			elapsed+=c/now;
			now+=f;
		}
		printf("Case #%d: %.7lf\n", p, best);
	}
	return 0;
}
