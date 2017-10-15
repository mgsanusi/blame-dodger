#include <stdio.h>
#include <stdlib.h>
int check_bound(int score, int bound)
{
	int first_iteration;
	if (((score + 2) / 3) >= bound)
		return 2;
	else if (((score >= 2) && (score <= 28))
		 && (((score + 4) / 3) >= bound))
		return 1;
	else
		return 0;
}

int main()
{
	int first_iteration;
	int num_cases;
	int num_scores;
	int num_surp;
	int bound;
	int i;
	int score;
	int j;
	int k;
	scanf("%d", &num_cases);
	for (i = 0; i < num_cases; i++) {
		int potential = 0;
		int num = 0;
		scanf("%d %d %d", &num_scores, &num_surp, &bound);
		for (j = 0; j < num_scores; j++) {
			scanf("%d", &score);
			k = check_bound(score, bound);
			if (k == 2)
				num++;
			else if (k == 1)
				potential++;
		}
		if (potential > num_surp)
			potential = num_surp;
		printf("Case #%d: %d\n", i + 1, num + potential);
	}
	return 0;
}
