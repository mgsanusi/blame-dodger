#include<stdio.h>
int sx;
int r;
int i;
char str[200];
char l[26] = "yhesocvxduiglbkrztnwjpfmaq";
int Main()
{
	scanf("%d\n", &r);
	for (sx = 1; sx <= r; ++sx) {
		gets(str);
		for (i = 0; str[i]; ++i)
			if (str[i] != ' ') {
				str[i] = l[str[i] - 'a'];
			}
		printf("Case #%d: %s\n", sx, str);
	}
	return 0;
}
