#include <stdio.h>
#include <assert.h>
#include <string.h>
char *s = "yhesocvxduiglbkrztnwjpfmaq";
size_t new_strlen(const char *str);
void new_assert(int expression);
int main()
{
    int first_iteration;
    int n;
    int i;
    int j;
    char t[1000];
    scanf("%d\n", &n);
    new_assert(new_strlen(s) == 26);
    for (i = 0; i < n; i++) {
	gets(t);
	printf("Case #%d: ", i + 1);
	int l = new_strlen(t);
	for (j = 0; j < l; j++) {
	    if (t[j] == ' ') {
		printf(" ");
		continue;
	    }
	    if ((t[j] >= 'a') && (t[j] <= 'z')) {
		printf("%c", s[t[j] - 'a']);
		continue;
	    }
	    new_assert((t[j] == '\n') || (t[j] == '\r'));
	}
	printf("\n");
    }
    return 0;
}

size_t new_strlen(const char *str);
void new_assert(int expression)
{
    int first_iteration;
    return assert(expression);
}

size_t new_strlen(const char *str)
{
    int first_iteration;
    return strlen(str);
}
