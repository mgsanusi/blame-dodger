#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct party {
    int index;
    int number;
};
int my_cmp(const void *a, const void *b)
{
    const struct party *ia = (const struct party *) a;
    const struct party *ib = (const struct party *) b;
    return (*ia).number < (*ib).number;
}

int main()
{
    int t, tc = 1, n, i, sum, p;
    struct party parties[30];
    scanf("%d", &t);
    while (t--) {
	scanf("%d", &n);
	for (i = sum = 0; i < n; ++i) {
	    scanf("%d", &p);
	    sum += p;
	    struct party cur_party;
	    cur_party.index = i;
	    cur_party.number = p;
	    parties[i] = cur_party;
	}
	printf("Case #%d:", tc++);
	while (sum > 0) {
	    qsort(parties, n, sizeof(struct party), my_cmp);
	    if (sum != 3) {
		if (parties[0].number > 0 && parties[1].number > 0) {
		    printf(" %c%c", parties[0].index + 'A',
			   parties[1].index + 'A');
		    parties[0].number--;
		    parties[1].number--;
		    sum -= 2;
		} else {
		    printf(" %c", parties[0].index + 'A');
		    parties[0].number--;
		    sum -= 1;
		}
	    } else {
		printf(" %c", parties[0].index + 'A');
		parties[0].number--;
		sum -= 1;
	    }
	}
	printf("\n");
    }
    return 0;
}
