#include<stdio.h>
int main()
{
	int i,t,ans,r,c,w,temp;
	scanf("%d",&t);
	for(i=1;i<=t;i++)
	{
		scanf("%d %d %d",&r,&c,&w);
		temp=c%w;
		ans=(c/w)+w-1;
		if(temp>=1)
			temp=1;
		ans+=temp;
		printf("Case #%d: %d\n",i,ans);
	}
	return 0;
}
