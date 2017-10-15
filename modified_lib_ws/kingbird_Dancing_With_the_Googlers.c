#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int scores[110];
FILE *new_freopen(const char *filename, const char *mode, FILE * stream);
int main() 
{
	new_freopen("out.txt", "w", stdout);
	new_freopen("B-small-attempt0.in", "r", stdin);
	int n, i, j, t, s, p, x;
	int max, cons;
	scanf("%d", &t);
	for (i = 1; i <= t; i++)
		 {
		cons = 0;
		scanf("%d%d%d", &n, &s, &p);
		for (j = 0; j < n; j++)
			 {
			scanf("%d", &x);
			
			    //surprise
			    if (x == 0)
				max = 0;
			
			else if (x % 3 != 2)
				max = x / 3 + 1;
			
			else
				max = x / 3 + 2;
			
			    //not surprise
			    x = (x + 2) / 3;
			if (x >= p)
				cons++;
			
			else if (max >= p && s)
				 {
				cons++;
				s--;
				}
			}
		printf("Case #%d: %d\n", i, cons);
		}
	return 0;
}

FILE * new_freopen(const char *filename, const char *mode, FILE * stream)
{
	return freopen(filename, mode, stream);
}
