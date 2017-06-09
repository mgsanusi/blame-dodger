#include<stdio.h>
int main()
{
	int i,t,n,ans,max,j,ans1;
	scanf("%d",&t);
	for(i=1;i<=t;i++)
	{
		scanf("%d",&n);
		int arr[n];
		max=0;
		for(j=0;j<n;j++)
		{
			scanf("%d",&arr[j]);
			if(j!=0)
			{
				if((arr[j-1]-arr[j])>max)
				{
					max=arr[j-1]-arr[j];
				}
			}
		}
		ans=0;
		for(j=1;j<n;j++)
		{
			if(arr[j-1]-arr[j]>0)
			{
				ans+=(arr[j-1]-arr[j]);
			}
		}
		ans1=0;
		if(max>0)
		{	
			for(j=0;j<n-1;j++)
			{
				if(arr[j]<=max)
					ans1+=arr[j];
				else
					ans1+=max;
			}
		}
		 printf("Case #%d: %d %d\n",i,ans,ans1);

		
	}
	return 0;
}
