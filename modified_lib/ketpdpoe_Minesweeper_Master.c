#include<stdio.h>
int ans[100],d,t;
void find_ans(int r,int c,int max,int now,int re){
	int i;
	if(re<=max){
		if(re==0){
			t=1;
			d=now;
		}
		else if(re!=1){
			ans[now]=re;
			d=now+1;
			t=1;
		}
		return ;
	}
	for(i=max;i>1;i--){
		if(t==1)return;
		if(re>i*(r-now))return;
		ans[now]=i;
		find_ans(r,c,i,now+1,re-i);
	}
	return ;
}
int main(){
	int T,I;
	scanf("%d",&T);
	for(I=0;I<T;I++){
		int r,c,m;
		t=0;
		d=0;
		scanf("%d %d %d",&r,&c,&m);
		m=r*c-m;
		int i,j;
		if(r!=1&&c!=1){
			for(i=c;i>1;i--){
				if(t==1)break;
				if(m>=2*i&&m<=i*r){
					ans[0]=ans[1]=i;
					find_ans(r,c,i,2,m-2*i);
				}
			}
			printf("Case #%d:\n",I+1);
			if(t==0){
				if(m!=1)printf("Impossible\n");
				else{
					printf("c");
					for(i=1;i<c;i++)printf("*");
					printf("\n");
					for(i=1;i<r;i++){
						for(j=0;j<c;j++)printf("*");
						printf("\n");
					}
				}
			}
			else{
				printf("c");
				for(i=1;i<ans[0];i++)printf(".");
				for(i=ans[0];i<c;i++)printf("*");
				printf("\n");
				for(i=1;i<d;i++){
					for(j=0;j<ans[i];j++)printf(".");
					for(j=ans[i];j<c;j++)printf("*");
					printf("\n");
				}
				for(i=d;i<r;i++){
					for(j=0;j<c;j++)printf("*");
					printf("\n");
				}
			}
		}
		else{
			printf("Case #%d:\n",I+1);
			if(r==1){
				printf("c");
				for(i=1;i<m;i++)printf(".");
				for(i=m;i<c;i++)printf("*");
				printf("\n");
			}
			else{
				printf("c\n");
				for(i=1;i<m;i++)printf(".\n");
				for(i=m;i<r;i++)printf("*\n");
			}
		}
	}
	return 0;
}