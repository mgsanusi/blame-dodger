#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char * welcome = "welcome to code jam";
	char num[5] = {0};
	int n, i;
	fgets(num, 5, stdin);
	n = atoi(num);
	
	for(i=0;i<n;i++)
	{
		int result[19][500] = {{0}};
		char buf[600] = {0};
		fgets(buf, 600, stdin);

		if(buf[0]==welcome[0])
		{
			result[0][0] = 1;		
		}
	
		int j;
		for(j=1;j<strlen(buf);j++)
		{
			int k;
			for(k=0;k<19;k++)
			{
				result[k][j] = result[k][j-1];
				if(buf[j] == welcome[k])
				{
					if(k==0)
					{
						result[k][j] += 1;
					}
					else
					{
						result[k][j] += result[k-1][j-1];
						result[k][j] %= 10000;
					}
				}
			}
		}
		printf("Case #%d: %04d\n", i+1, result[18][strlen(buf)-1]);
	}

	return 0;
}
