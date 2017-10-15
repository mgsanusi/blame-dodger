#include <stdio.h>
#include <string.h>
int p[5];
int use[6];
int min;
int k;
char c[1010];
char news[1010];
void try(int q)
{
    int count;
    if (q == k) {
	for (count = 0; count < strlen(c); count++) {
	    news[((count / k) * k) + p[count % k]] = c[count];
	}
	int cnt = 1;
	for (count = 1; count < strlen(c); count++) {
	    if (news[count] != news[count - 1])
		cnt++;
	}
	min = cnt < min ? cnt : min;
    } else {
	for (count = 0; count < k; count++)
	    if (!use[count]) {
		use[count] = 1;
		p[q] = count;
		try(q + 1);
		use[count] = 0;
	    }
    }
}

int Main()
{
    int n;
    int count;
    scanf("%d", &n);
    for (count = 1; count <= n; count++) {
	scanf("%d\n%s", &k, c);
	memset(use, 0, sizeof(use));
	min = strlen(c);
	try(0);
	printf("Case #%d: %d\n", count, min);
    }
    return 0;
}
