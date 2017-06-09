#include<stdio.h>
#include<stdlib.h>
#define SIZE 1001

int compare(const void *a, const void *b){
    double *A = (double*)a;
    double *B = (double*)b;
    if(*A > *B) return 1;
    if(*A == *B) return 0;
    return -1;
}

int main(){

    int T,N;
    double block[2][SIZE] = {0};

    scanf("%d",&T);

    int i,j,k;
    for(i = 0; i < T; i++){
        scanf("%d",&N);
	for(j = 0; j < 2; j++){
	    for(k = 0; k < N; k++){
	        scanf("%lf",&block[j][k]);
	    }
	}
	qsort(block[0], N, sizeof(double), compare);
	qsort(block[1], N, sizeof(double), compare);
	int winW= 0, winD = 0;
        int pa = 0,pb = 0;
	while(pa < N && pb < N){
	    if(block[1][pb] > block[0][pa]){
	        pa++;
		pb++;
	    }
	    else{
	        pb++;
	    }
	}
	winW = N-pa;
	pa = 0;
	pb = 0;
	while(pa < N && pb < N){
	    if(block[0][pa] > block[1][pb]){
	        pa++;
		pb++;
	    }
	    else{
	        pa++;
	    }
	}
	winD = pb;
	printf("Case #%d: %d %d\n",i+1,winD, winW);

    }
    return 0;
}
