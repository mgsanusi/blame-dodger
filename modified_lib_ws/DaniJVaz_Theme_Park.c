/* Compiled with MinGW */  
    
#include <stdio.h>
void doTestCase();
 int main()
{
	int i, n;
	scanf("%d", &n);
	for (i = 1; i <= n; i++) {
		printf("Case #%d: ", i);
		doTestCase();
	}
	return 0;
}

 void doTestCase()
{
	int r, k, n, i, t;
	scanf("%d %d %d", &r, &k, &n);
	 long long e = 0, te = -1;
	 int gi[n];
	int s = 0, is;		/* index of the first group in queue. Since they maintain relative order, it's the only thing needed */
	for (i = 0; i < n; i++)
		scanf("%d", &gi[i]);
	 for (i = 0; i < r; i++) {
		t = k;
		is = s;
		while (t >= gi[s]) {
			t -= gi[s];
			e += gi[s];
			s++;
			if (s == n)
				s = 0;
			if (s == is)	/* All people boarded */
				break;
		}
		 if (s == 0) {	/* The first group is in the first position again, so we have a period of i+1 */
			te = e;	/* The maximum limit for the period is N, so we can be sure it'll be quick */
			i++;
			break;
		}
	}
	 if (te != -1) {
		e = te * (r / i);
		r = r % i;
		s = 0;
		 for (i = 0; i < r; i++) {
			t = k;
			while (t >= gi[s]) {
				t -= gi[s];
				e += gi[s];
				s++;
				if (s == n)
					s = 0;
			}
		}
	}
	 printf("%d\n", e);
	return;
}


