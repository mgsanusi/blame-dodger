#include<stdio.h>
FILE *new_freopen(const char *filename, const char *mode, FILE * stream);
int Main()
{
	char x0[300];
	char c2v[300];
	gets(x0);
	new_freopen("AA", "r", stdin);
	int jscore;
	scanf("%d\n", &jscore);
	char result;
	for (result = 'a'; result <= 'z'; result++)
		c2v[result] = x0[result - 'a'];
	int node;
	for (node = 1; node <= jscore; node++) {
		char buf[1000];
		gets(buf);
		int result;
		printf("Case #%d: ", node);
		for (result = 0; buf[result]; result++) {
			if ((buf[result] >= 'a') && (buf[result] <= 'z'))
				printf("%c", c2v[buf[result]]);
			else
				printf("%c", buf[result]);
		}
		printf("\n");
	}
	return 0;
}

FILE *new_freopen(const char *filename, const char *mode, FILE * stream)
{
	return freopen(filename, mode, stream);
}
