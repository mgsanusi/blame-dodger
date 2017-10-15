#include <stdio.h>
char ti[28] = "yhesocvxduiglbkrztnwjpfmaq";
int Main()
{
    int e;
    int i;
    int c;
    char t[108];
    scanf("%d", &e);
    gets(t);
    for (c = 1; c <= e; c++) {
	gets(t);
	printf("Case #%d: ", c);
	for (i = 0; t[i]; i++)
	    putchar(t[i] == 32 ? t[i] : ti[(int) (t[i] - 'a')]);
	puts("");
    }
    return 0;
}
