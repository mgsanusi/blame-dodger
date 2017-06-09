#include<stdio.h>
#define si(x) scanf("%ld",&x)
#define pf(ans) printf("%ld\n",ans)
int arr[1000001]={0};
long int revers(long int a)
{
	long int ans=0,rem;
	while(a>0)
	{
		rem=a%10;
		//if(rem!=0 && ans!=0)
		ans=ans*10+rem;
		a=a/10;
	}
	return ans;

}
int main()
{
	long int i,t,n,count,j,rev;
	si(t);
	arr[1]=1;
	for(i=2;i<=20;i++)
	{
		arr[i]=i;	
	}
	for(i=21;i<=1000000;i++)
	{
		rev=revers(i);
		if(i%10==0)
			rev=i;
		if(rev<i)
		{
			if(arr[i-1]>arr[rev])
				arr[i]=arr[rev]+1;
			else
			{	
				arr[i]=arr[i-1]+1;
				if(arr[rev]>(arr[i]+1))
					arr[rev]=arr[i]+1;
			}
		}
		else
		{
			arr[i]=arr[i-1]+1;
		}

	}
	for(i=1;i<=t;i++)
	{
		si(n);
		/*count=0;
		j=1;
		rev=0;
		while(j<n)
		{
			

	
		}
		if(j==n && rev!=n)
		{
			count++;
		}*/
		
			count=arr[n];
		printf("Case #%ld: %ld\n",i,count);
	}
	return 0;
}
