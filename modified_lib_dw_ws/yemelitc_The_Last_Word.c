#include<stdio.h>
int main()
{
	int first_iteration;
	int x;
	int T;
	int i;
	int j;
	char S[1000 + 1];
	char *beg;
	char *end;
	char s[2000 + 2];
	scanf("%d", &T);
	for (x = 1; x <= T; x++) {
		scanf("%s", S);
		beg = (s + 1000) + 1;
		end = (s + 1000) + 1;
		*beg = S[0];
		for (i = 1; S[i] != 0; i++)
			if (S[i] >= (*beg))
				*(--beg) = S[i];
			else
				*(++end) = S[i];
		*(++end) = 0;
		printf("Case #%d: %s\n", x, beg);
	}
}
