#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#define BUFLEN 8192
char buf[BUFLEN];
char combine[26][26];
int opposed[26][26];
char stack[100];
int main()
{
    int T, caseNum, C, D, N, i, j, x, y, top;
    char a, b, c;
    scanf(" %d", &T);
    for (caseNum = 1; caseNum <= T; caseNum++) {
	for (i = 0; i < 26; i++)
	    for (j = 0; j < 26; j++)
		combine[i][j] = opposed[i][j] = 0;
	scanf(" %d", &C);
	for (i = 0; i < C; i++) {
	    scanf(" %c%c%c", &a, &b, &c);
	    combine[a - 'A'][b - 'A'] = c;
	    combine[b - 'A'][a - 'A'] = c;
	}
	scanf(" %d", &D);
	for (i = 0; i < D; i++) {
	    scanf(" %c%c", &a, &b);
	    opposed[a - 'A'][b - 'A'] = 1;
	    opposed[b - 'A'][a - 'A'] = 1;
	}
	top = -1;
	scanf(" %d ", &N);
	for (i = 0; i < N; i++) {
	    scanf("%c", &a);
	    if (top == -1) {
		stack[++top] = a;
		continue;
	    }
	    b = stack[top];
	    c = combine[a - 'A'][b - 'A'];
	    if (c) {
		stack[top] = c;
		continue;
	    }
	    for (j = top; j >= 0; j--)
		if (opposed[stack[j] - 'A'][a - 'A']) {
		    top = -1;
		    break;
		}
	    if (j < 0)
		stack[++top] = a;
	}
	printf("Case #%d: [", caseNum);
	if (top >= 0) {
	    printf("%c", stack[0]);
	    for (i = 1; i <= top; i++)
		printf(", %c", stack[i]);
	}
	printf("]\n");
    }
}
