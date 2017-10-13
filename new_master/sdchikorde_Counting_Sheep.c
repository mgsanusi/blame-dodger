#include <stdio.h>
#include <string.h>
void main()
{
	int cases;
	scanf("%d",&cases);
	int n = 0;
	int num;
	int numcpy;
	int arr[10];
	int arrcpy[10] = {0,0,0,0,0,0,0,0,0,0};
	int i;
	while(n<cases)
	{
		n++;
		printf("Case #%d: ",n);
		scanf("%d",&num);
		if(num==0)
		{
			printf("INSOMNIA\n");
			continue;
		}
		memcpy(arr, arrcpy, sizeof arrcpy);
		i = 1;
		while(1)
		{
			numcpy = num * i;
			while(numcpy)
			{
				arr[numcpy%10] = 1;
				numcpy /= 10;
			}
			if(arr[0]==1&&arr[1]==1&&arr[2]==1&&arr[3]==1&&arr[4]==1&&arr[5]==1&&arr[6]==1&&arr[7]==1&&arr[8]==1&&arr[9]==1)
			{
				break;
			}
			i++;
		}
		printf("%d\n",num*i);
	}
}
