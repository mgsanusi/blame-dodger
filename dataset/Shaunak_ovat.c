#include<stdio.h>
int main()
{
	int t,i,n,count,j,total,temp;
	scanf("%d",&t);
	for(i=0;i<t;i++)
	{
		scanf("%d",&n);
		char str[n+1];
		count=0;
		total=0;
		scanf("%s",str);
		for(j=0;j<=n;j++)
		{
			if(str[j]!='0')
			{
				
				
				temp=j-total;
			
				if(temp>=0)
				{
					count+=temp;
					total=total+temp+(str[j]-'0');
				}
				else
				{
					total+=(str[j]-'0');	
				}	
			}
		}
		printf("Case #%d: %d\n",(i+1),count);
	}
	return 0;
}
