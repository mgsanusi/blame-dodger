#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <stddef.h>

char opp[26][26], com[26][26];
void * new_memset(void *ptr, int value, size_t num);


void ini()
{
	new_memset(opp, 0, sizeof(opp));
	new_memset(com, 0, sizeof(com));
}

void beopp(char a, char b)
{
	a -= 'A';
	b -= 'A';
	opp[a][b] = 1;
	opp[b][a] = 1;
}

char isopp(char a, char b)
{
	a -= 'A';
	b -= 'A';
	return opp[a][b];
}

void becom(char a, char b, char c)
{
	a -= 'A';
	b -= 'A';
	com[a][b] = c;
	com[b][a] = c;
}

char iscom(char a, char b)
{
	a -= 'A';
	b -= 'A';
	return com[a][b];
}

int main()
{
	int cas, n, i, k, j, ansn;
	char str[110], ans[110];
	scanf("%d", &cas);
	for(i=1; i<=cas; i++)
	{
		ini();
		ansn = 0;
		scanf("%d", &n);
		for(j=0; j<n; j++)
		{
			scanf("%s", str);
			becom(str[0], str[1], str[2]);
		}
		scanf("%d", &n);
		for(j=0; j<n; j++)
		{
			scanf("%s", str);
			beopp(str[0], str[1]);
		}
		scanf("%d %s", &n, str);
		for(j=0; j<n; j++)
		{
			if(ansn == 0)
			{
				ans[ansn++] = str[j];
				continue;
			}
			if(iscom(str[j], ans[ansn-1]))
			{
				ans[ansn-1] = iscom(str[j], ans[ansn-1]);
				continue;
			}
			for(k=ansn-1; k>=0; k--)
				if(isopp(str[j], ans[k]))
					break;
			if(k >= 0)
				ansn = 0;
			else
				ans[ansn++] = str[j];
		}
		printf("Case #%d: [", i);
		if(ansn)
			printf("%c", ans[0]);
		for(j=1; j<ansn; j++)
			printf(", %c", ans[j]);
		printf("]\n");
	}
	return 0;
}

void * new_memset(void *ptr, int value, size_t num) {
  return memset(ptr, value, num);
}