#include <stdio.h>

int main()
{
	int cases;scanf("%d",&cases);
	for (int cs=1;cs<=cases;cs++)
	{
		int l,d,s;scanf("%d%d%d",&l,&d,&s);
		printf("Case #%d:",cs);
		if (!d || s<(l+d-1)/d) {printf(" IMPOSSIBLE\n");continue;}
		for (int i=0;i<l;i+=d)
		{
			int r=l-i;
			r=r<d?r:d;
			unsigned long long p=0;
			for (int j=0;j<r;j++) p=p*l+i+j;
			printf(" %llu",p+1);
		}
		printf("\n");
	}
}