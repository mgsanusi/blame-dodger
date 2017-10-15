#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXH 105
 int H, W;
 char DFS(int a[MAXH][MAXH], char b[MAXH][MAXH], int x, int y, char next) 
{
	if (b[x][y] != 0)
		return b[x][y];
	int min = a[x][y];
	int minx = -1;
	int miny = -1;
	if ((x > 0) && (a[x - 1][y] < min))
		 {
		min = a[x - 1][y];
		minx = x - 1;
		miny = y;
		}
	if ((y > 0) && (a[x][y - 1] < min))
		 {
		min = a[x][y - 1];
		minx = x;
		miny = y - 1;
		}
	if ((y < (W - 1)) && (a[x][y + 1] < min))
		 {
		min = a[x][y + 1];
		minx = x;
		miny = y + 1;
		}
	if ((x < (H - 1)) && (a[x + 1][y] < min))
		 {
		min = a[x + 1][y];
		minx = x + 1;
		miny = y;
		}
	if (minx == -1)
		b[x][y] = next;
	
	else
		b[x][y] = DFS(a, b, minx, miny, next);
	return b[x][y];
}

 int main() 
{
	static int a[MAXH][MAXH];
	static char b[MAXH][MAXH];
	int T;
	scanf("%d", &T);
	int i, j, iT;
	char next;
	for (iT = 0; iT < T; iT++)
		 {
		scanf("%d %d", &H, &W);
		for (i = 0; i < H; i++)
			 {
			for (j = 0; j < W; j++)
				 {
				scanf("%d", &(a[i][j]));
				}
			}
		memset(b, 0, sizeof(b));
		next = 'a';
		for (i = 0; i < H; i++)
			 {
			for (j = 0; j < W; j++)
				 {
				if (b[i][j] == 0)
					 {
					if (DFS(a, b, i, j, next) == next)
						next++;
					}
				}
			}
		printf("Case #%d:\n", iT + 1);
		for (i = 0; i < H; i++)
			 {
			for (j = 0; j < W; j++)
				 {
				if (j > 0)
					printf(" ");
				printf("%c", b[i][j]);
				}
			printf("\n");
			}
		}
	return 0;
}


