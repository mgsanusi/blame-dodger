#include <stdio.h>
#include <string.h>
char r[] = "ejp mysljylc kd kxveddknmc re jsicpdrysi";
char b[] = "rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd";
char l[] = "de kr kd eoya kw aej tysr re ujdr lkgc jv";
char q[] = "our language is impossible to understand";
char k[] = "there are twenty six factorial possibilities";
char fo[] = "so it is okay if you want to just give up";
int map[256];
void makemap(char *s, char *k)
{
	while (*s)
		map[(int)(*(s++))] = *(k++);
}

char s[16384];
int Main()
{
	int caseno = 1;
	int t;
	int ans;
	memset(map, 0, sizeof(map));
	makemap(r, q);
	makemap(b, k);
	makemap(l, fo);
	map['q'] = 'z';
	map['z'] = 'q';
	gets(s);
	sscanf(s, "%d", &t);
	while (t--) {
		gets(s);
		for (ans = 0; s[ans]; ans++)
			s[ans] = map[(int)s[ans]];
		printf("Case #%d: %s\n", caseno++, s);
	}
	return 0;
}
