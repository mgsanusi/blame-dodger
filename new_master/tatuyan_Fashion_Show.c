#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

int R,C;
char board[30][30];
struct alp{
  int flg;
  int l,r,u,d;
};

void solve(int cases);
int boardcheck(void);

int main(void){
  int T,i;
  scanf("%d%*c",&T);
  for(i=1;i<=T;i++){
    memset(board,0,sizeof(board));
    solve(i);
  }
  return 0;
}

void solve(int cases){
  int i,j,k,loops;
  int x,y,*spflg;
  struct alp alps[26],flgs[26];
  
  scanf("%d%d",&R,&C);
  for(i=1;i<=R;i++)
    scanf("%s%*c",board[i]+1);

  for(i=0;i<26;i++) alps[i]=(struct alp){0,100,-100,100,-100};
  for(i=0;i<26;i++) flgs[i]=(struct alp){1,1,1,1,1};


  for(i=1;i<=R;i++){
    for(j=1;j<=C;j++){
      if(!isalpha(board[i][j])) continue;
      k=board[i][j]-'A';
      alps[k].flg=1;
      if(alps[k].l>j) alps[k].l=j;
      if(alps[k].r<j) alps[k].r=j;
      if(alps[k].u>i) alps[k].u=i;
      if(alps[k].d<i) alps[k].d=i;
    }
  }

  for(i=0;i<26;i++){
      if(!alps[i].flg) continue;
      for(j=alps[i].u;j<=alps[i].d;j++)
	for(k=alps[i].l;k<=alps[i].r;k++)
	  board[j][k]=i+'A';
    }

  loops=0;
  do{
    
    /*for(i=0;i<26;i++){
      if(alps[i].flg==0) continue;
      printf("%c:ud[%d,%d] lr:[%d,%d]\n",i+'A',alps[i].u,alps[i].d,alps[i].l,alps[i].r);
      }/**/
    loops++;
    
    for(i=0;i<26;i++){
      if(!alps[i].flg) continue;
      
      /*up/down*/
      for(j=-1;j<=1;j+=2){
	y=(j==-1?alps[i].u:alps[i].d)+j;
	spflg=(j==-1?&flgs[i].u:&flgs[i].d);
	if(*spflg==0) continue;
	for(x=alps[i].l;x<=alps[i].r;x++){
	  if(board[y][x]!='?' && board[y][x]!='A'+i){
	    *spflg=0;
	    break;
	  }
	}
	if(*spflg==0) continue;
	for(x=alps[i].l;x<=alps[i].r;x++) board[y][x]='A'+i;
	if(j==-1) alps[i].u--;
	else alps[i].d++;
      }
      
      /*left/right*/
      for(j=-1;j<=1;j+=2){
	x=(j==-1?alps[i].l:alps[i].r)+j;
	spflg=(j==-1?&flgs[i].l:&flgs[i].r);
	if(*spflg==0) continue;
	for(y=alps[i].u;y<=alps[i].d;y++){
	  if(board[y][x]!='?' && board[y][x]!='A'+i){
	    *spflg=0;
	    break;
	  }
	}
	if(*spflg==0) continue;
	for(y=alps[i].u;y<=alps[i].d;y++) board[y][x]='A'+i;
	if(j==-1) alps[i].l--;
	else alps[i].r++;
      }
    }
  }while(boardcheck());
  
  printf("Case #%d:\n",cases);
  for(i=1;i<=R;i++) puts(board[i]+1);  
}

int boardcheck(void){
  int i,j;
  for(i=1;i<=R;i++) for(j=1;j<=C;j++) if(board[i][j]=='?') return 1;
  return 0;
}
