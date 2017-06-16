#include<stdio.h>

void taban(int p, long* mem)
{
	int i;
	long b[8];
	for(i=0;i<8;i++)
	{
		b[i]=1;
		mem[i]=0;
	}
	while(p>0)
	{
		if(p%2==1)
		{
			for(i=0;i<8;i++)
				mem[i]+=b[i];
		}
		for(i=3;i<=10;i++)
			b[i-3]*=i;	
		p=p>>1;
	}
	return;
}

int isprime(int p, int *d)
{
	int i, j;
	long mem[8];
	taban(p,mem);
	for(i=3;i*i<=p;i++)
	{
		if(p%i==0)
		{
			d[0]=i;
			break;
		}
	}
	if(i*i>p)
		return 1;
	for(i=3;i<=10;i++)
	{
		for(j=2;(long)j*(long)j<=mem[i-3];j++)
		{
			if(mem[i-3]%j==0)
			{
				d[i-2]=j;
				break;
			}
		}
		if((long)j*(long)j>mem[i-3])
			return 1;
	}
	return 0;
}

void affiche(int p)
{
	if(p==1)
	{
		printf("1");
		return;
	}
	affiche(p>>1);
	if(p%2)
		printf("1");
	else
		printf("0");
	return;
}

int main()
{
	int t, n, j, i, k, l, m, p, d[9]; 
	scanf("%d",&t);
	for(i=0;i<t;i++)
	{
		printf("Case #%d:",i+1);
		scanf("%d %d", &n, &j);
		l=0;
		p=1+(1<<(n-1));
		for(k=0;k<j;k++)
		{
			while(isprime(p+2*l, d))
				l++;
			printf("\n");
			affiche(p+2*l);
			for(m=0;m<9;m++)
				printf(" %d", d[m]);
			l++;
		}
	}
	return 0;
}
