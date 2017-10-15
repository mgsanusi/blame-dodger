#include<stdio.h>

int f(int lambda, int n, int d)
{
	int i, nc=lambda*n;
	while(nc>0)
	{
		i=nc%10;
		nc/=10;
		if((d>>i)%2==0)
			d+=1<<i;
	}
	if(d==(1<<10)-1)
		return lambda*n;
	return f(lambda+1,n,d);	
}

int main()
{
	int t, i, n, d;
	scanf("%d",&t);
	for(i=0;i<t;i++)
	{
		d=0;
		scanf("%d", &n);
		printf("Case #%d: ",i+1);
		if(n==0)
			printf("INSOMNIA\n");
		else
			printf("%d\n",f(1,n,d));
	}
	return 0;
}
