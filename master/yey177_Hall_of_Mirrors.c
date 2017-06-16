#include <stdio.h>
#define MIN(g,h) (((g)<(h))?(g):(h))

int main(){
	int t,k,a,b,i;
	double r,x,p,d,tmp;
	scanf("%d",&t);
	for(k=1;k<=t;k++){
		scanf("%d%d",&a,&b);
		p=1.0;r=2.0+b;
		for(i=1;i<=a;i++){
			scanf("%lf",&d);
			p=p*d;
			tmp=b+a+1-i*2+(1-p)*(b+1);
			r=MIN(r,tmp);
		}
		printf("Case #%d: %.6lf\n",k,r);
	}
	return 0;
}
