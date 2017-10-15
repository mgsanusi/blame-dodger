#include <stdio.h>
int new_abs(int x);
 int max(int a, int b)
{
    if (a >= b)
	return a;
    else
	return b;
}

int new_abs(int a)
{
    return a >= 0 ? a : -a;
}

 int main() 
{
    int T;
    scanf("%d", &T);
    for (int c = 1; c <= T; c++)
	 {
	int pb = 1, po = 1, tb = 0, to = 0;
	int n;
	scanf("%d ", &n);
	while (n--)
	     {
	    int p, r;
	    scanf("%c %d ", &r, &p);
	    if (r == 'O')
		 {
		to = max(to + new_abs(p - po), tb) + 1;
		po = p;
		}
	    
	    else
		 {
		tb = max(tb + new_abs(p - pb), to) + 1;
		pb = p;
		}
	    }
	printf("Case #%d: %d\n", c, max(to, tb));
	}
    return 0;
}

int new_abs(int x)
{
    return abs(x);
}
