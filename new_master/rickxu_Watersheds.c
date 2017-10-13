#include <stdio.h>
#include <stdlib.h>

char fill(int matrix[][100], char result[][100], int h, int w, int x, int y, char b)
{
	int min_x = x, min_y = y, min = matrix[x][y];
	if(x>0 && matrix[x-1][y]<min)
	{
		min_x = x-1;
		min_y = y;
		min = matrix[min_x][min_y];
	}
	if(y>0 && matrix[x][y-1]<min)
	{
		min_x = x;
		min_y = y-1;
		min = matrix[min_x][min_y];
	}
	if(y<w-1 && matrix[x][y+1]<min)
	{
		min_x = x;
		min_y = y+1;
		min = matrix[min_x][min_y];
	}
	if(x<h-1 && matrix[x+1][y]<min)
	{
		min_x = x+1;
		min_y = y;
		min = matrix[min_x][min_y];
	}
	if(min_x == x && min_y == y)
	{
		if(!result[x][y])
		{
			result[x][y] = b;
		}
	}
	else
	{
		result[x][y] = fill(matrix, result, h, w, min_x, min_y, b);
	}
	return result[x][y];
}

int main()
{
	int t, i;
	scanf("%d", &t);
	for(i=0;i<t;i++)
	{
		int h, w, m, n;
		int matrix[100][100] = {{0}};
		char result[100][100] = {{0}};
		char b = 'a';
		scanf("%d %d", &h, &w);

		for(m=0;m<h;m++)
		{
			for(n=0;n<w;n++)
			{
				scanf("%d", &matrix[m][n]);
			}
		}
		for(m=0;m<h;m++)
		{
			for(n=0;n<w;n++)
			{
				if(fill(matrix, result, h, w, m, n, b)==b)
				{
					b++;
				}
			}
		}
		printf("Case #%d:\n", i+1);
		for(m=0;m<h;m++)
		{
			printf("%c", result[m][0]);
			for(n=1;n<w;n++)
			{
				printf(" %c", result[m][n]);
			}
			printf("\n");
		}
	}
	return 0;
}
