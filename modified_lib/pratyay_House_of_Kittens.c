#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char tiles[60][60];
main()
{
	int total,i,j,k,r,c,flag;
	scanf("%d",&total);
	for(i=1;i<=total;i++)
	{
		printf("Case #%d:\n",i);
		scanf("%d %d",&r,&c);
		for(j=0;j<r;j++)
			scanf("%s",tiles[j]);
		for(j=0;j<r;j++)
		{
			for(k=0;k<c;k++)
			{
				flag=0;
				if(tiles[j][k]=='#')
				{
					if(j+1>=r || k+1>=c)
					{
						flag=1;
						break;
					}
					tiles[j][k]='/';
					if(tiles[j][k+1]=='#')
						tiles[j][k+1]='\\';
					else
					{
						flag=1;
						break;
					}
					if(tiles[j+1][k]=='#')
						tiles[j+1][k]='\\';
					else
					{
						flag=1;
						break;
					}
					if(tiles[j+1][k+1]=='#')
						tiles[j+1][k+1]='/';
					else
					{
						flag=1;
						break;
					}
				}
			}
			if(flag==1)
				break;
		}
		if(flag==1)
		{
			printf("Impossible\n");
		}
		else
		{
			for(j=0;j<r;j++)
			{
				printf("%s\n",tiles[j]);
			}
		}
	}
}
