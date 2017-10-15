#include<stdio.h>
#include<stdlib.h>
struct list {
    int g;
    int n;
    struct list *next;
};
int compar(const void *a, const void *b)
{
    return (*((int *) a)) - (*((int *) b));
}

void total(int x, struct list **l)
{
    if ((*l) == 0) {
	*l = (struct list *) malloc(sizeof(struct list));
	(*l)->g = x;
	(*l)->n = 1;
	(*l)->next = 0;
    } else if ((*l)->g == x) {
	(*l)->n++;
    } else {
	total(x, &(*l)->next);
    }
    return;
}

void rfree(struct list **l)
{
    if ((*l) == 0)
	return;
    if ((*l)->next != 0)
	rfree(&(*l)->next);
    free(*l);
    return;
}

int Main()
{
    int t;
    int n;
    int g;
    int j;
    int d;
    int x;
    int check[50];
    struct list *l = 0;
    struct list *p = 0;
    scanf("%d", &t);
    for (g = 0; g < t; g++) {
	scanf("%d", &n);
	for (j = 0; j < ((2 * n) - 1); j++) {
	    for (d = 0; d < n; d++) {
		scanf("%d", &x);
		total(x, &l);
	    }
	}
	for (p = l, j = 0; p != 0; p = p->next) {
	    if ((p->n % 2) == 1) {
		check[j] = p->g;
		j++;
	    }
	}
	qsort(check, j, sizeof(int), compar);
	printf("Case #%d: ", g + 1);
	for (d = 0; d < j; d++)
	    printf("%d ", check[d]);
	printf("\n");
	rfree(&l);
	l = 0;
    }
    return 0;
}
