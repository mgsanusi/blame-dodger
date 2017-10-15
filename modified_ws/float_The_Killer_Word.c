#include <stdio.h>
#include <stdlib.h>
 int main() 
{
	int cas, i, j, k, pd, pg, n, todayW;
	scanf("%d", &cas);
	for (i = 1; i <= cas; i++)
		 {
		scanf("%d %d %d", &n, &pd, &pg);
		if (pd == 0 && pg <= 99)
			printf("Case #%d: Possible\n", i);
		
		else if ((pd == 0 && pg == 100) || (pd != 0 && pg == 0)
			 || (pd != 100 && pg == 100))
			printf("Case #%d: Broken\n", i);
		
		else
			 {
			k = 1;
			j = pd;
			while (j % 100)
				 {
				j += pd;
				k++;
				}
			if (n < k)
				printf("Case #%d: Broken\n", i);
			
			else
				printf("Case #%d: Possible\n", i);
			}
		}
	return 0;
}


