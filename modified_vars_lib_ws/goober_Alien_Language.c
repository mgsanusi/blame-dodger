#include <stdio.h>
#include <stdlib.h>
char dict[5000][16];
char good[15][26];
int Main()
{
	int nopp;
	int cas;
	int robot;
	int n;
	int i;
	scanf("%d %d %d ", &nopp, &cas, &robot);
	for (i = 0; i < cas; i++)
		scanf("%s", dict[i]);
	for (n = 1; n <= robot; n++) {
		int count;
		char patt[(15 * 28) + 1];
		int i;
		int j;
		char *temp;
		scanf("%s", patt);
		memset(good, 0, sizeof(good));
		j = 0;
		for (temp = patt; *temp; temp++) {
			if ((*temp) != '(')
				good[j][(*temp) - 'a'] = 1;
			else {
				for (temp++; (*temp) != ')'; temp++)
					good[j][(*temp) - 'a'] = 1;
			}
			j++;
		}
		count = 0;
		for (i = 0; i < cas; i++) {
			for (j = 0; j < nopp; j++)
				if (!good[j][dict[i][j] - 'a'])
					break;
			if (j >= nopp)
				count++;
		}
		printf("Case #%d: %d\n", n, count);
	}
	return 0;
}
