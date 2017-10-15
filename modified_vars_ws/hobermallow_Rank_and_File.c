#include<stdio.h>
void clean(char *n)
{
	int total;
	for (total = 0; total < (2 * 1000); total++)
		n[total] = '\0';
	return;
}

int Main()
{
	int dy;
	int total;
	int j;
	int begin;
	int goal;
	int d;
	char s[1000 + 1];
	char n[2 * 1000];
	scanf("%d", &dy);
	for (total = 0; total < dy; total++) {
		clean(n);
		scanf("%s", s);
		begin = 1000 - 1;
		goal = 1000 - 1;
		n[1000 - 1] = s[0];
		for (j = 1; s[j] != '\0'; j++) {
			if (s[j] > n[begin])
				n[--begin] = s[j];
			else if (s[j] < n[begin])
				n[++goal] = s[j];
			else {
				for (d = begin; n[d + 1] != '\0'; d++) {
					if (n[d] != n[d + 1])
						break;
				}
				if (n[d] > n[d + 1])
					n[--begin] = s[j];
				else
					n[++goal] = s[j];
			}
		}
		s[++goal] = '\0';
		printf("Case #%d: %s\n", total + 1, n + begin);
	}
	return 0;
}
