#include<stdio.h>
typedef unsigned u;
int main() 
{
    u t = 0, T, i, j, k;
    char S[111];
    for (scanf("%u", &T); t++ < T; printf("Case #%u: %u\n", t, k))
	 {
	scanf("%s", S);
	for (i = -1; S[++i];);
	S[i] = '+';
	for (j = k = 0; ++j <= i;)
	    if (S[j] != S[j - 1])
		++k;
	}
    return 0;
}


