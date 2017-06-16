#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char c[50][4];
char d[50][4];
char string[100000];
char stack[100000];
int stackNum;
int have[26];
int main(){
    int t,Case;
    int i,j,p,q;
    int C,D,len;
    char x,y;
    scanf("%d",&Case);
    for(t=1;t<=Case;++t){
        stackNum = 0;
        for(i=0;i<26;++i)have[i] = 0;
        scanf("%d",&C);
        for(i=0;i<C;++i){
            scanf("%s",c[i]);
        }
        scanf("%d",&D);
        for(i=0;i<D;++i){
            scanf("%s",d[i]);
        }
        scanf("%d",&len);
        scanf("%s",string);
        for(i=0;i<len;++i){
            stack[stackNum++] = string[i];
            have[string[i]-'A']++;
            while(stackNum >= 2){
                x = stack[stackNum-1];
                y = stack[stackNum-2];
                for(j=0;j<C;++j){
                    if((x==c[j][0] && y==c[j][1]) || (x==c[j][1] && y==c[j][0])){
                        stack[stackNum-2] = c[j][2];
                        have[x-'A']--;
                        have[y-'A']--;
                        have[c[j][2]-'A']++;
                        stackNum--;
                        break;
                    }
                }
                if(j>=C)break;
            }
            if(stackNum >=2){
                for(j=0;j<D;++j){
                    if(have[d[j][0]-'A'] && have[d[j][1]-'A']){
                        stackNum = 0;
                        for(p=0;p<26;++p)have[p] = 0;
                        break;
                    }
                }
            }
        }
        stack[stackNum] = '\0';
        //printf("%s\n",stack);
        printf("Case #%d: [",t);
        if(stackNum >0){
            printf("%c",stack[0]);
            for(i=1;i<stackNum;++i){
                printf(", %c",stack[i]);
            }
        }
        puts("]");
    }

}
