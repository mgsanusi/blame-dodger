#include<stdio.h>
#include<stdlib.h>

int main(){


    int A,B,K,T;
    scanf("%d",&T);
    int i,j,m;
    for(m = 0; m < T; m++){
	scanf("%d%d%d",&A,&B,&K);
	int sum = 0;
        for(i = 0; i < A; i++){
            for(j = 0; j < B; j++){
	        if((i&j) < K){
	            sum++;
	        }
	    }
        }
        printf("Case #%d: %d\n",m+1,sum);
    }
    return 0;

}
