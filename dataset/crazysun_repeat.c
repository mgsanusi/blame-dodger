#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
 
    int T;
    char str[101][101] = {0};
    char newstr[101][101] = {0};
    int index[101] = {0},len[101] = {0};
    scanf("%d",&T);
    int i,j,k,N;
    for(i = 0; i < T; i++){
        scanf("%d",&N);
	int lenMax = 0;
	for(j = 0; j < N; j++){
	    scanf("%s",str[j]);
	    len[j] = strlen(str[j]);
	    if(len[j] > lenMax)
	        lenMax = len[j];
	    index[j] = 0;
	}
	char tmp = str[0][0];
	int flag = 0;
	for(j = 1; j < N; j++){
	    if(str[j][0] != tmp){
		printf("Case #%d: Fegla Won\n",i+1);
		flag = 1;
		break;
	    }
	}
	if(flag == 1) continue;
    	flag = 0;
	int ans = 0;
	int mode = 0;
	while(1){
	    int same = 0, ne = 0;
	    char var = 0;
	    //printf("tmp = %c\n",tmp);
	    int flag1 = 0;
	    for(j = 0; j < N; j++){
	        if(index[j] < len[j]){
		    flag1 = 1;
		}
		else{
		    mode = 1;
		}
	    }
	    if(flag1 == 0) break;
	    for(j = 0; j < N; j++){
		if(str[j][index[j]] == tmp){
		    same++;
		}
		else{
		    ne++;
		    if(mode == 1 && index[j] < len[j]){
		         flag = 1;
			 printf("Case #%d: Fegla Won\n",i+1);
		         break;
		    }
		    if(mode == 0){
		        if(var == 0){ 
			    var = str[j][index[j]]; 
		        }
		        else{
		            if(str[j][index[j]] != var){
			        flag = 1;
			        printf("Case #%d: Fegla Won\n",i+1);
		                break;	
			    }
		        }
		    }
		}
	    }
	    //printf("%d %d\n",same,ne);
	    if(flag > 0) break;
	    if(same >= ne){
	//	    printf("s\n");
		ans += ne;
	        for(j = 0; j < N; j++){
		    if(tmp == str[j][index[j]])
		        index[j]++;
		}    
	    }
	    else{
	//	    printf("ne %d %d\n",same,ne);
	        ans += same;
		for(j = 0; j < N; j++){
		    if(tmp == str[j][index[j]])
			index[j]++;
		}
		if(mode == 0)
		tmp = var;
	    }
	   /* printf("ans = %d\n",ans);
	    for(j = 0; j < N; j++){
		    printf("index[%d] = %d\n",j,index[j]+1);
	    }*/    
	   
	}
	if(flag != 1)
	    printf("Case #%d: %d\n",i+1,ans);
    }

    return 0;
}
