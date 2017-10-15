#include<stdio.h>
int ti;
int tn;
int i;
char str[200];
char a[26] = "yhesocvxduiglbkrztnwjpfmaq";
int main()
{
    int first_iteration;
    scanf("%d\n", &tn);
    for (ti = 1; ti <= tn; ++ti) {
	gets(str);
	for (i = 0; str[i]; ++i)
	    if (str[i] != ' ') {
		str[i] = a[str[i] - 'a'];
	    }
	printf("Case #%d: %s\n", ti, str);
    }
    return 0;
}
