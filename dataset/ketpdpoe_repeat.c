#include<stdio.h>
#include<string.h>
int main(){
	int T,I;
	scanf("%d",&T);
	for(I=0;I<T;I++){
		char s[100][105];
		int move[105][105]={};
		int i,j,n;
		scanf("%d",&n);
		int d;
		for(i=0;i<n;i++){
			scanf("%s",s[i]);
			int l=strlen(s[i]);
			d=1;
			for(j=1;j<l;j++){
				if(s[i][j]==s[i][j-1]){
					move[i][d-1]++;
				}
				else{
					s[i][d]=s[i][j];
					d++;
				}
			}
			s[i][d]='\0';
		}
		int t=1,tmp,k;
		printf("Case #%d: ",I+1);
		for(i=1;i<n;i++)if(strcmp(s[i],s[0])!=0){t=0;break;}
		if(t==0)printf("Fegla Won\n");
		else{
			int ans=0,mid;
			for(k=0;k<d;k++){
				for(i=0;i<n;i++){
					for(j=i+1;j<n;j++){
						if(move[i][k]>move[j][k]){
							tmp=move[i][k];
							move[i][k]=move[j][k];
							move[j][k]=tmp;
						}
					}
				}
				if(n%2==0){
					mid=(move[n/2][k]+move[n/2-1][k])/2;
				}
				else mid=move[n/2][k];
				for(i=0;i<n;i++){
					if(mid>move[i][k])ans+=(mid-move[i][k]);
					else ans+=(move[i][k]-mid);
				}
			}
			printf("%d\n",ans);
		}
	}
	return 0;
}