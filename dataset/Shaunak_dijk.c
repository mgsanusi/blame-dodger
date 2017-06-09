#include<stdio.h>
#include<string.h>
int arr[5][5];
int func(int a,int b)
{
	return arr[a][b];
}
int main()
{
	int i,t,flag,count,j,k,l,m,x,tempi,total,curr;
	scanf("%d",&t);
	
	arr[1][1]=1;arr[1][2]=2;arr[1][3]=3;arr[1][4]=4;
	arr[2][1]=2;arr[2][2]=-1;arr[2][3]=4;arr[2][4]=-3;
	arr[3][1]=3;arr[3][2]=-4;arr[3][3]=-1;arr[3][4]=2;
	arr[4][1]=4;arr[4][2]=3;arr[4][3]=-2;arr[4][4]=-1;
	   
	for(i=1;i<=t;i++)
	{
		scanf("%d %d",&l,&x);
		int str[l*x];
		char s[l];int st[l];
		getchar();
		scanf("%s",s);
		//int len=strlen(s);
		if(l*x<3)
		{
			printf("Case #%d: NO\n",i);
			continue;
		}
		else if(strcmp(s,"ijk")==0 && l*x==3)
		{
			printf("Case #%d: YES\n",i);
                        continue;

		}

		for(j=0;j<l;j++)
		{
			if(s[j]=='i')
				st[j]=2;
			else if(s[j]=='j')
				st[j]=3;
			else if(s[j]=='k')
				st[j]=4;
		}
		
		
		count=0;
		flag=0;
		for(j=0;j<x;j++)
		{
			for(k=0;k<l;k++)
			{
				str[count++]=st[k];
			}
		}
		/*	for(j=0;j<l*x;j++)
		{
			printf("%d ",str[j]);
		}*/
		curr=1;
		total=l*x;
		for(j=0;j<total;j++)
		{
			if(curr<0)
				curr=-func(-curr,str[j]);
			else
				curr=func(curr,str[j]);
			if(curr==2)
				break;
			
			
		}
		if(j==total)
		{
			printf("Case #%d: NO\n",i);
			continue;
		}
		curr=1;
		for(k=j+1;k<total;k++)
		{
			if(curr<0)
				curr=-func(-curr,str[k]);
			else
				curr=func(curr,str[k]);
			if(curr==3)
				break;
		}
		if(k==total)
		{
			printf("Case #%d: NO\n",i);
			continue;
		}
		curr=1;
		for(m=k+1;m<total;m++)
		{
			if(curr<0)
				curr=-func(-curr,str[m]);
			else
				curr=func(curr,str[m]);
			if(curr==4 && m==total-1)
				break;
		}
		if(m==total-1)
			printf("Case #%d: YES\n",i);
		else
			printf("Case #%d: NO\n",i);
	
	}
	return 0;
}
