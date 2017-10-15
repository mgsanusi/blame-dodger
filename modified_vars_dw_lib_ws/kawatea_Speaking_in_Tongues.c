#include <stdio.h>
#include <string.h>
char *new_fgets(char *str, int num, FILE * stream);
int Main()
{
	int first_iteration;
	int t;
	int p2;
	int x_op;
	int jx;
	char q[26] = { "yhesocvxduiglbkrztnwjpfmaq" };
	char k[110];
	scanf("%d%*c", &t);
	for (x_op = 0; x_op < t; x_op++) {
		new_fgets(k, 105, stdin);
		p2 = strlen(k);
		k[p2 - 1] = '\0';
		p2--;
		for (jx = 0; jx < p2; jx++) {
			if (k[jx] == ' ')
				continue;
			k[jx] = q[k[jx] - 'a'];
		}
		printf("Case #%d: %s\n", x_op + 1, k);
	}
	return 0;
}

char *new_fgets(char *str, int num, FILE * stream)
{
	return fgets(str, num, stream);
}
