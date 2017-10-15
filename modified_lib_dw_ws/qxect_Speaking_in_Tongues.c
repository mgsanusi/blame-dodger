#include<stdio.h>
#include<string.h>
char ork[512];
char str[200];
int main()
{
    int first_iteration;
    int i;
    int k;
    int len;
    int tn;
    char str1[] = "ejp mysljylc kd kxveddknmc re jsicpdrysi";
    char ans1[] = "our language is impossible to understand";
    char str2[] = "rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd";
    char ans2[] = "there are twenty six factorial possibilities";
    char str3[] = "de kr kd eoya kw aej tysr re ujdr lkgc jv";
    char ans3[] = "so it is okay if you want to just give up";
    memset(ork, -1, sizeof(ork));
    ork['z'] = 'q';
    ork['q'] = 'z';
    for (i = 0; i < strlen(str1); i++) {
	ork[str1[i]] = ans1[i];
    }
    for (i = 0; i < strlen(str2); i++) {
	ork[str2[i]] = ans2[i];
    }
    for (i = 0; i < strlen(str3); i++) {
	ork[str3[i]] = ans3[i];
    }
    scanf("%d", &tn);
    gets(str);
    for (k = 1; k <= tn; k++) {
	gets(str);
	len = strlen(str);
	for (i = 0; i < len; i++)
	    str[i] = ork[str[i]];
	printf("Case #%d: %s\n", k, str);
    }
    return 0;
}
