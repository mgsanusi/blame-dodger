#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int new_puts(const char *str);
void intSort(int p[], int s)
{
    int iT = -1;
    int j = s;
    int buttonPosList;
    int str;
    if (s <= 1)
	return;
    buttonPosList = (p[0] + p[s - 1]) / 2;
    for (;;) {
	while (p[++iT] < buttonPosList);
	while (p[--j] > buttonPosList);
	if (iT >= j)
	    break;
	str = p[iT];
	p[iT] = p[j];
	p[j] = str;
    }
    intSort(p, iT);
    intSort((p + j) + 1, (s - j) - 1);
}

int Main()
{
    int iT;
    int j;
    int buttonPosList;
    int l;
    int m;
    int r;
    int in[1200];
    int total;
    int input;
    int size;
    int cnt = 0;
    scanf("%d", &size);
    while (size--) {
	scanf("%d", &r);
	for (iT = 0; iT < r; iT++)
	    scanf("%d", in + iT);
	input = (total = 0);
	for (iT = 0; iT < r; iT++)
	    input ^= in[iT], total += in[iT];
	printf("Case #%d: ", ++cnt);
	if (input) {
	    new_puts("NO");
	    continue;
	}
	intSort(in, r);
	total -= in[0];
	printf("%d\n", total);
    }
    return 0;
}

int new_puts(const char *str)
{
    return puts(str);
}
