#include <stdio.h>
#include <assert.h>
#include <string.h>
char *s = "yhesocvxduiglbkrztnwjpfmaq";
int new_strlen(const char *str);
void new_assert(int expression);
int Main()
{
    int first_iteration;
    int k;
    int proc;
    int cn;
    char auth[1000];
    scanf("%d\n", &k);
    new_assert(new_strlen(s) == 26);
    for (proc = 0; proc < k; proc++) {
	gets(auth);
	printf("Case #%d: ", proc + 1);
	int tmp = new_strlen(auth);
	for (cn = 0; cn < tmp; cn++) {
	    if (auth[cn] == ' ') {
		printf(" ");
		continue;
	    }
	    if ((auth[cn] >= 'a') && (auth[cn] <= 'z')) {
		printf("%c", s[auth[cn] - 'a']);
		continue;
	    }
	    new_assert((auth[cn] == '\n') || (auth[cn] == '\r'));
	}
	printf("\n");
    }
    return 0;
}

int new_strlen(const char *str);
void new_assert(int expression)
{
    return assert(expression);
}

int new_strlen(const char *str)
{
    return strlen(str);
}
