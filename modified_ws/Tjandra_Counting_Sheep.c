#include<stdio.h>
typedef unsigned u;
int main() 
{
	u t = 0, T, n, i, j, k, C[11], r;
	for (scanf("%u", &T); t++ < T;)
		 {
		scanf("%u", &n);
		r = 0;
		printf("Case #%u: ", t);
		for (i = -1; ++i < 11;)
			C[i] = 0;
		for (i = j = 0; ++i < 111;)
			 {
			for (k = (j += n); k; k /= 10)
				if (++C[k % 10] == 1)
					++r;
			if (r == 10)
				break;
			}
		printf(r == 10 ? "%u\n" : "INSOMNIA\n", j);
		}
	return 0;
}


