#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_A 1000000

void do_test(int t)
{
	int a, b, n;
	double p_i, cumulative = 1.0, best_ev;
	int i;

	scanf("%d %d", &a, &b);

	/* Probability of getting it right if we backspace is 'cumulative'
	 * number of characters to type is (a - i) backspaces + (b - i) chars + 1 enter
	 * n = a + b + 1 - 2 * i;
	 * expected number of keys is n * cumulative + (b + 1) * (1 - cumulative)
	*/

	/* Expected value for just hitting enter: b + 2;
	 */

	n = a + b + 1;

	if (a < 1)
		best_ev = 1 + b;
	else
		best_ev = 2 + b;

	for (i = 0; i < a; i++)
	{
		double ev;
		scanf("%lf", &p_i);
		n -= 2;
		cumulative *= p_i;

		ev = n * cumulative + (n + b + 1) * (1.0 - cumulative);
		if (ev < best_ev)
			best_ev = ev;
	}	

	printf("Case #%d: %f\n", t + 1, best_ev);
}

int main()
{
	int t, i;

	scanf("%d", &t);
	
	for (i = 0; i < t; i++)
		do_test(i);

	return 0;
}
