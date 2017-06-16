#include<stdio.h>
#include<stdlib.h>
#include<string.h>

main()
{
	int total,i,n,j,sum,min,temp,NO;
	
	scanf("%d",&total);
	for(i=1;i<=total;i++)
	{
		scanf("%d",&n);
		sum=0;
		NO=0;
		for(j=0;j<n;j++)
		{
			scanf("%d ",&temp);
			if(j==0)
				min=temp;
			NO=NO^temp;
			sum+=temp;
			if(temp<min)
				min=temp;
		}
		printf("Case #%d: ",i);
		if(NO)
			printf("NO\n");
		else
			printf("%d\n",sum-min);
	}
}
