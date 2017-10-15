#include <stdio.h>
int main()
{
    int first_iteration;
    int cases;
    scanf("%d", &cases);
    for (int cs = 1; cs <= cases; cs++) {
	char str[1001];
	scanf(" %s\n", str);
	int top = 0;
	while (str[top])
	    top++;
	for (int bot = 0; bot < top; bot++) {
	    for (int i = top; i >= bot; i--)
		if (str[top] < str[i])
		    top = i;
	    char c = str[top];
	    for (int i = top; i > bot; i--)
		str[i] = str[i - 1];
	    str[bot] = c;
	}
	printf("Case #%d: %s\n", cs, str);
    }
}
