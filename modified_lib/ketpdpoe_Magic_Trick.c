#include<stdio.h>
int  main(){
	int T,I;
	scanf("%d",&T);
	for(I=0;I<T;I++){
		int a[4][4],d[8],ans[5],da=0,i,j,k,an;
		scanf("%d",&an);
		for(i=0;i<4;i++){
			for(j=0;j<4;j++){
				scanf("%d",&a[i][j]);
				if(i==an-1)d[j]=a[i][j];
			}
		}
		scanf("%d",&an);
		for(i=0;i<4;i++){
			for(j=0;j<4;j++){
				scanf("%d",&a[i][j]);
				if(i==an-1){
					for(k=0;k<4;k++)if(d[k]==a[i][j]){
						ans[da]=d[k];
						da++;
					}
				}
			}
		}
		printf("Case #%d: ",I+1);
		if(da==0)printf("Volunteer cheated!\n");
		else if(da==1)printf("%d\n",ans[0]);
		else printf("Bad magician!\n");
	}
	return 0;
}