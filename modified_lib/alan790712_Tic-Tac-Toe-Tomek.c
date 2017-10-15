#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char board[123][123];
int X,O;
int x,o;
int new_puts(const char *str);


void check(int i,int j){
    if(board[i][j] == 'O'){
        ++o,x=-1000;
    }else if(board[i][j] == 'X'){
        ++x,o=-1000;
    }else if(board[i][j] == 'T'){
        ++x,++o;
    }
}
void cnt(){
    if(x==4)X=2;
    if(o==4)O=2;
    if(x>=0)X |= 1;
    if(o>=0)O |= 1;
}
int main(){
    int t,T;
    int i,j;
    scanf("%d",&T);
    for(t=1;t<=T;++t){
        for(i=0;i<4;++i){
            scanf("%s",board[i]);
        }
        X=O=0;
        for(i=0;i<4;++i){
            for(j=x=o=0;j<4;++j){
                check(i,j);
            }
            cnt();
        }
        for(i=0;i<4;++i){
            for(j=x=o=0;j<4;++j){
                check(j,i);
            }
            cnt();
        }
        for(i=j=x=o=0;i<4;++i,++j){
            check(j,i);
        }
        cnt();
        for(i=3,j=x=o=0;j<4;--i,++j){
            check(j,i);
        }
        cnt();
        printf("Case #%d: ",t);
        if(X>=2) new_puts("X won");
        if(O>=2) new_puts("O won");
        if(X==1 && O==1)new_puts("Game has not completed");
        if(X==0 && O==0)new_puts("Draw");
    }
    return 0;
}

int new_puts(const char *str) {
  return puts(str);
}