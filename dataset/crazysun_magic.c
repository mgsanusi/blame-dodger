#include<stdio.h>
#include<stdlib.h>
#define SIZE 4

int main(){
    int T;
    int ft[SIZE][SIZE] = {0}, st[SIZE][SIZE] = {0};
    scanf("%d",&T);
    int i,j,k;

    for(i = 0; i < T; i++){
        int fc,sc;
	scanf("%d",&fc);
	for(j = 0; j < SIZE; j++){
	    for(k = 0; k < SIZE; k++){
	        scanf("%d",&ft[j][k]);
	    }	    
	}
	scanf("%d",&sc);
	for(j = 0; j < SIZE; j++){
	    for(k = 0; k < SIZE; k++){
	        scanf("%d",&st[j][k]);
	    }	    
	}
        int num = 0,ans = 0;
	for(j = 0; j < SIZE; j++){
	    for(k = 0; k < SIZE; k++){
	        if(ft[fc-1][j] == st[sc-1][k]){
		    num++;
		    ans = ft[fc-1][j];
		    break;
		}
	    }
	}
	if(num == 0){
	    printf("Case #%d: Volunteer cheated!\n",i+1);
	}
	else if(num == 1){
	    printf("Case #%d: %d\n",i+1,ans);
	}
	else{
	    printf("Case #%d: Bad magician!\n",i+1);
	}
    }
    return 0;
}
