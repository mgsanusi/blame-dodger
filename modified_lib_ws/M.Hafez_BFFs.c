#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void new_qsort(void *base, size_t num, size_t size,
	       int (*compar) (const void *, const void *));
int my_cmp(const void *a, const void *b)
{
    const char *ia = (const char *) a;
    const char *ib = (const char *) b;
    return *ia > *ib;
}

int main()
{
    int t, tc = 1;
    char S[2010];
    char output[2010];
    int DAT[300];
    int i, length;
    scanf("%d", &t);
    while (t--) {
	memset(DAT, 0, 300 * sizeof(int));
	scanf("%s", S);
	length = strlen(S);
	for (i = 0; i < length; ++i) {
	    ++DAT[S[i]];
	}
	i = 0;
	while (DAT['Z']) {
	    output[i] = '0';
	    --DAT['Z'];
	    --DAT['E'];
	    --DAT['R'];
	    --DAT['O'];
	    ++i;
	}
	while (DAT['W']) {
	    output[i] = '2';
	    --DAT['T'];
	    --DAT['W'];
	    --DAT['O'];
	    ++i;
	}
	while (DAT['U']) {
	    output[i] = '4';
	    --DAT['F'];
	    --DAT['O'];
	    --DAT['U'];
	    --DAT['R'];
	    ++i;
	}
	while (DAT['F']) {
	    output[i] = '5';
	    --DAT['F'];
	    --DAT['I'];
	    --DAT['V'];
	    --DAT['E'];
	    ++i;
	}
	while (DAT['X']) {
	    output[i] = '6';
	    --DAT['S'];
	    --DAT['I'];
	    --DAT['X'];
	    ++i;
	}
	while (DAT['S']) {
	    output[i] = '7';
	    --DAT['S'];
	    --DAT['E'];
	    --DAT['V'];
	    --DAT['E'];
	    --DAT['N'];
	    ++i;
	}

	while (DAT['G']) {
	    output[i] = '8';
	    --DAT['E'];
	    --DAT['I'];
	    --DAT['G'];
	    --DAT['H'];
	    --DAT['T'];
	    ++i;
	}
	while (DAT['O']) {
	    output[i] = '1';
	    --DAT['O'];
	    --DAT['N'];
	    --DAT['E'];
	    ++i;
	}
	while (DAT['N']) {
	    output[i] = '9';
	    --DAT['N'];
	    --DAT['I'];
	    --DAT['N'];
	    --DAT['E'];
	    ++i;
	}
	while (DAT['H']) {
	    output[i] = '3';
	    --DAT['T'];
	    --DAT['H'];
	    --DAT['R'];
	    --DAT['E'];
	    --DAT['E'];
	    ++i;
	}
	output[i] = '\0';
	new_qsort(output, i, sizeof(char), my_cmp);
	printf("Case #%d: %s\n", tc++, output);
    }
    return 0;
}

void new_qsort(void *base, size_t num, size_t size,
	       int (*compar) (const void *, const void *))
{
    return qsort(base, num, size, compar);
}
