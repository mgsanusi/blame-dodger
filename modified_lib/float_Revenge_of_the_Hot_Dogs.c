#include <stdio.h>
#include <stdlib.h>

char map[100][100];
int R, C;
int new_puts(const char *str);


int rep()
{
	int i, j;
	for(i=0; i<R; i++)
	{
		for(j=0; j<C; j++)
		{
			if(map[i][j] == '#' && map[i+1][j] == '#' && map[i][j+1] == '#' && map[i+1][j+1] == '#')
			{
				map[i][j] = '/';
				map[i+1][j] = '\\';
				map[i][j+1] = '\\';
				map[i+1][j+1] = '/';
			}
		}
	}
}

int check()
{
	int i, j;
	for(i=0; i<R; i++)
		for(j=0; j<C; j++)
			if(map[i][j] == '#')
				return 0;
	return 1;
}

int main()
{
	int cas, c, i;
	scanf("%d", &cas);
	for(c=1; c<=cas; c++)
	{
		scanf("%d %d", &R, &C);
		for(i=0; i<R; i++)
			scanf("%s", map[i]);
		rep();
		printf("Case #%d:\n", c);
		if(check())
		{
			for(i=0; i<R; i++)
				new_puts(map[i]);
		}
		else
			new_puts("Impossible");
	}
}

int new_puts(const char *str) {
  return puts(str);
}