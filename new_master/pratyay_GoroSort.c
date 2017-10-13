#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int alo(int);

int fact[11];
int c[11][11];
int ALO[11];

main()
{
	int total,i,n,j,k,i1,i2,temp;
	long double sum;
	int a[1001];
	memset(ALO,0,sizeof(ALO));
	
	/*calculate factorial*/
	fact[0]=1;
	for(i=1;i<=10;i++)
		fact[i]=fact[i-1]*i;
	
	/*calculate binomial coef*/
	memset(c,0,sizeof(c));
	c[0][0]=1;
	for(i=0;i<=10;i++)
	{
		for(j=0;j<=10;j++)
		{
			c[i + 1][j + 1]+=c[i][j];
			c[i + 1][j]+=c[i][j];
		}
	}
		
	scanf("%d",&total);
	
	for(i=1;i<=total;i++)
	{
		scanf("%d",&n);
		
		for(j=1;j<=n;j++)
			scanf("%d",&a[j]);		
			
			
		sum=0.0;
		
		for(j=1;j<=n;j++)
			if(a[j]!=j)
				sum=sum+1;

		/*for(j=2;j<=n;j++)
		{
			for(k=1;k<=n;k++)
			{
				if(a[k]==k)
					continue;
				i2=k;
				for(i1=1;i1<=j;i1++)
					i2=a[i2];
				if(k==i2)
				{
					for(i1=1;i1<=j;i1++)
					{
						temp=a[i2];
						a[i2]=i2+1;
						i2=temp;
					}
					sum+=(long double)fact[j]/(long double)alo(j);
					//sum+=(long double)fact[j];
				}
			}
		}*/
		printf("Case #%d: %Lf\n",i,sum);

	}
}

int alo(int n)
{
	if(ALO[n]!=0)
		return ALO[n];
	int sum=0;
	int i;
	int term;
	for(i=1;i<=n;i++)
	{
		term=c[n][i]*fact[n-i];
		term=(i%2)?term:(0-term);
		sum+=term;
	}
	ALO[n]=sum;
	return sum;
}
