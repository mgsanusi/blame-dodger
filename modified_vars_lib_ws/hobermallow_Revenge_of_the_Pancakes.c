#include<stdio.h>
#include<string.h>
int rp(char *s)
{
    int j;
    int cha = 0;
    char mem = s[0];
    for (j = 1; s[j] != '\0'; j++) {
	if (s[j] != mem) {
	    mem = s[j];
	    cha++;
	}
    }
    if (s[j - 1] == '+')
	return cha;
    return cha + 1;
}

int Main()
{
    int fileNameOut;
    int j;
    char s[101];
    scanf("%d", &fileNameOut);
    for (j = 0; j < fileNameOut; j++) {
	scanf("%s", s);
	printf("Case #%d: %d\n", j + 1, rp(s));
    }
    return 0;
}
