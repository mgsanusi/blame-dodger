#include<stdio.h>
char *encry =
    "ejp mysljylc kd kxveddknmc re jsicpdrysi rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd de kr kd eoya kw aej tysr re ujdr lkgc jv";
char *decry =
    "our language is impossible to understand there are twenty six factorial possibilities so it is okay if you want to just give up";
int Main(int argc, char *argv[])
{
    int x[128];
    int data;
    int b;
    int c;
    char s[128];
    for (data = 0; data < 128; data++)
	x[data] = 0;
    for (data = 0; encry[data] != '\0'; data++)
	x[(int) encry[data]] = decry[data];
    x['q'] = 'z';
    x['z'] = 'q';
    gets(s);
    sscanf(s, "%d", &c);
    for (data = 1; data <= c; data++) {
	gets(s);
	for (b = 0; s[b] != '\0'; b++)
	    s[b] = x[(int) s[b]];
	printf("Case #%d: %s\n", data, s);
    }
    return 0;
}
