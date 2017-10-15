#include<stdio.h>
void clean(char *y)
{
    int i;
    for (i = 0; i < 30; i++)
	y[i] = '\0';
    return;
}

int main()
{
    int t, i, j, begin, end, k;
    char s[16], y[30];
    scanf("%d", &t);
    for (i = 0; i < t; i++) {
	clean(y);
	scanf("%s", s);
	begin = 14;
	end = 14;
	y[14] = s[0];
	for (j = 1; s[j] != '\0'; j++) {
	    if (s[j] > y[begin])
		y[--begin] = s[j];
	    else if (s[j] < y[begin])
		y[++end] = s[j];
	    else {
		for (k = begin; y[k + 1] != '\0'; k++) {
		    if (y[k] != y[k + 1])
			break;
		}
		if (y[k] > y[k + 1])
		    y[--begin] = s[j];
		else
		    y[++end] = s[j];
	    }
	}
	s[++end] = '\0';
	printf("Case #%d: %s\n", i + 1, y + begin);
    }
    return 0;
}
