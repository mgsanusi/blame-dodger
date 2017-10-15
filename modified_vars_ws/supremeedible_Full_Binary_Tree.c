#include <stdio.h>
int Main()
{
	int t;
	scanf("%d", &t);
	for (int caseno = 1; caseno <= t; caseno++) {
		int c;
		int l;
		scanf("%d %d", &c, &l);
		char exit[c][l + 1];
		char devices[c][l + 1];
		for (int temp = 0; temp < c; temp++) {
			scanf(" %s", exit[temp]);
		}
		for (int temp = 0; temp < c; temp++) {
			scanf(" %s", devices[temp]);
		}
		int min_l = l + 1;
		for (int temp = 0; temp < c; temp++) {
			int eq[l];
			int current_l = 0;
			for (int queries = 0; queries < l; queries++) {
				if (exit[0][queries] != devices[temp][queries]) {
					eq[queries] = 0;
					current_l++;
				} else {
					eq[queries] = 1;
				}
			}
			if (current_l >= min_l)
				continue;
			int all_match = 1;
			for (int a = 1; a < c; a++) {
				int some_match = 0;
				for (int word = 0; word < c; word++) {
					int this_match = 1;
					for (int queries = 0; queries < l;
					     queries++) {
						if ((exit[a][queries] ==
						     devices[word][queries]) !=
						    eq[queries]) {
							this_match = 0;
							break;
						}
					}
					if (this_match) {
						some_match = 1;
						break;
					}
				}
				if (!some_match) {
					all_match = 0;
					break;
				}
			}
			if (all_match)
				min_l = current_l;
		}
		if (min_l > l) {
			printf("Case #%d: NOT POSSIBLE\n", caseno);
		} else {
			printf("Case #%d: %d\n", caseno, min_l);
		}
	}
}
