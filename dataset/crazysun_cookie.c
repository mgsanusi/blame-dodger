#include<stdio.h>
#include<stdlib.h>

int main(){

    int T;
    double C,F,X;
    int i;
    scanf("%d",&T);
    for(i = 0; i < T; i++){
        scanf("%lf%lf%lf",&C,&F,&X);
	double time = 0,n = 2;
	while(1){
	  //  printf("X/n = %.7lf C/n + X/(F+n) = %.7lf\n",X/n,  C/n + X/(F+n));
	    if(X/n > C/n+X/(F+n)){
		//printf("C/n = %.7lf\n time = %.7lf\n",C/n,time);
	        time += C/n;
		n += F;
	
	    }
	    else{
		 //  printf("X/n = %.7lf\n time = %.7lf\n",X/n,time);
	        time += X/n;
	        break;
	    }
	}
	printf("Case #%d: %.7lf\n",i+1,time);
    }
    return 0;
}
