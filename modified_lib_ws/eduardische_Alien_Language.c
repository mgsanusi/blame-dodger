#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXL 20
#define MAXD 5005
 int main() 
{
	int L, D, N;
	scanf("%d %d %d\n", &L, &D, &N);
	static char data[MAXD][MAXL];
	static char str[27 * MAXL];
	int i;
	for (i = 0; i < D; i++)
		 {
		scanf("%s\n", data[i]);
		}
	int iN, res, j, k;
	for (iN = 0; iN < N; iN++)
		 {
		scanf("%s\n", str);
		res = 0;
		 for (i = 0; i < D; i++)
			 {
			k = 0;
			for (j = 0; j <= L; j++)
				 {
				if (j == L)
					 {
					res++;
					break;
					}
				if (str[k] == '(')
					 {
					while ((str[k] != ')')
						&& (str[k] != data[i][j]))
						k++;
					if (str[k] == ')')
						break;
					while (str[k] != ')')
						k++;
					k++;
					}
				
				else
					 {
					if (str[k] != data[i][j])
						break;
					k++;
					}
				}
			}
		 printf("Case #%d: %d\n", iN + 1, res);
		}
	 return 0;
}


