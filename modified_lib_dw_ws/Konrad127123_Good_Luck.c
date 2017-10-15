#include<stdio.h>
#include<string.h>
int L;
int T;
int t;
char A[1000100];
int a;
int b;
int c;
long long ans;
long long s;
long long start;
long long current_count;
long long current;
int main()
{
	int first_iteration;
	scanf("%d", &T);
	for (t = 1; t <= T; t++) {
		scanf("%s", A);
		scanf("%d", &L);
		start = 0;
		current_count = 0;
		ans = 0;
		s = strlen(A);
		for (current = 0; current < s; current++) {
			if (!
			    (((((A[current] == 'a') || (A[current] == 'e'))
			       || (A[current] == 'i')) || (A[current] == 'o'))
			     || (A[current] == 'u'))) {
				current_count++;
			} else {
				current_count = 0;
			}
			if (current_count >= L) {
				ans +=
				    (s - current) * (((current + 2) - start) -
						     L);
				start = (current + 2) - L;
			}
		}
		printf("Case #%d: %lld\n", t, ans);
	}
	return 0;
}
