#include <stdio.h>
#include <string.h>
#include <malloc.h>
void main()
{
	int cases;
	scanf("%d",&cases);
	int n = 0;
	int len;
	char *str = (char *)malloc(sizeof(char)*102);
	char *tmp;
	int ans;
	while(n<cases)
	{
		ans = 0;
		n++;
		printf("Case #%d: ",n);
		scanf("%s",str);
		len = (int)strlen(str);
		tmp = &str[len-1];
		if(*tmp == '-')
		{
			ans++;
		}
		while(tmp > str)
		{
			tmp--;
			if(*tmp != *(tmp+1))
			{
				ans++;
			}
		}
		printf("%d\n",ans);
	}
}
