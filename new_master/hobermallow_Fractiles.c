#include<stdio.h>

int main()
{
	unsigned long t, i, k, c, s, tile, j, p, tot, cnt;
	scanf("%lu",&t);
	for(i=0;i<t;i++)
	{
		scanf("%lu %lu %lu", &k, &c, &s);
		printf("Case #%lu: ",i+1);
		if(s*c<k)
			printf("IMPOSSIBLE\n");
		else
		{
			tile=0;
			p=1;
			tot=1;
			cnt=0;
			for(j=0;j<c;j++)
				tot*=k;
			for(j=0;j<k;j++)
			{
				tile+=(j%k)*p;
				p*=k;
				if(p==tot)
				{
					printf("%lu ",tile+1);
					p=1;
					tile=0;
				}									
			}
			if(p>1)
				printf("%lu",tile+1);
			printf("\n");
		}
	}
	return 0;
}
