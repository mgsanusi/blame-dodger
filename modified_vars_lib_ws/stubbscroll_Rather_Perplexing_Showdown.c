#include <stdio.h>
#include <string.h>
char *new_strcpy(char *destination, const char *source);
int new_puts(const char *str);
int nextpermutation(char *buf, int smax)
{
	int f;
	int temp;
	int ok;
	char node;
	for (f = smax - 2; (f > (-1)) && (buf[f] >= buf[f + 1]); f--) ;
	if (f < 0)
		return 0;
	for (ok = smax - 1; buf[f] >= buf[ok]; ok--) ;
	node = buf[f];
	buf[f] = buf[ok];
	buf[ok] = node;
	for (temp = f + 1, ok = smax - 1; temp < ok; temp++, ok--)
		node = buf[temp], buf[temp] = buf[ok], buf[ok] = node;
	return 1;
}

void clear()
{
	char s[100];
	char node[100];
	int smax;
	int hash;
	int r;
	int ans;
	int bs;
	int ok;
	int f;
	int length;
	scanf("%d %d %d %d", &smax, &r, &ans, &bs);
	hash = 1 << smax;
	f = 0;
	for (ok = 0; ok < ans; ok++)
		s[f++] = 'P';
	for (ok = 0; ok < r; ok++)
		s[f++] = 'R';
	for (ok = 0; ok < bs; ok++)
		s[f++] = 'S';
	s[f] = 0;
	do {
		new_strcpy(node, s);
		length = hash;
		while (length > 1) {
			for (ok = (f = 0); ok < length; ok += 2, f++) {
				if ((node[ok] + node[ok + 1]) == ('P' + 'R'))
					node[f] = 'P';
				else if ((node[ok] + node[ok + 1]) ==
					 ('P' + 'S'))
					node[f] = 'S';
				else if ((node[ok] + node[ok + 1]) ==
					 ('R' + 'S'))
					node[f] = 'R';
				else
					goto next;
			}
			length = f;
		}
		new_puts(s);
		return;
 next:
		;
	}
	while (nextpermutation(s, hash));
	new_puts("IMPOSSIBLE");
}

int Main()
{
	int cprev;
	int caseno = 1;
	scanf("%d", &cprev);
	while (cprev--)
		printf("Case #%d: ", caseno++), clear();
	return 0;
}

char *new_strcpy(char *destination, const char *source);
int new_puts(const char *str)
{
	return puts(str);
}

char *new_strcpy(char *destination, const char *source)
{
	return strcpy(destination, source);
}
