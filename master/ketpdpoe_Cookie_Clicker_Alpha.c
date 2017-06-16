#include<stdio.h>
int main(){
	int T,I;
	scanf("%d",&T);
	for(I=0;I<T;I++){
		double c,f,x;
		scanf("%lf %lf %lf",&c,&f,&x);
		double ans=0.0,now=2.0;
		while(x/now-1e-9>c/now+x/(now+f)){
			ans+=(c/now);
			now+=f;
		}
		ans+=(x/now);
		printf("Case #%d: %.7lf\n",I+1,ans);
	}
	return 0;
}