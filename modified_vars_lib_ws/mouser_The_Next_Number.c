#include <stdio.h>
char num[32];
void swap(char *f, char *b)
{
    char v;
    v = *f;
    *f = *b;
    *b = v;
}

void reverse(char *f, int length)
{
    int noCases;
    for (noCases = 0; noCases < (length / 2); noCases++) {
	swap(&f[noCases], &f[(length - noCases) - 1]);
    }
}

void increase(void)
{
    int noCases;
    int res;
    int length;
    for (length = 0; num[length]; length++);
    for (noCases = length - 2; noCases >= 0; noCases--) {
	for (res = length - 1; res > noCases; res--) {
	    if (num[noCases] < num[res]) {
		swap(&num[noCases], &num[res]);
		reverse(&num[noCases + 1], (length - noCases) - 1);
		return;
	    }
	}
    }
}

int Main(void)
{
    int p;
    int noCases;
    scanf("%d\n", &p);
    for (noCases = 1; noCases <= p; noCases++) {
	gets(num + 1);
	num[0] = '0';
	increase();
	printf("Case #%d: %s\n", noCases, num[0] == '0' ? num + 1 : num);
    }
    return 0;
}
