#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
int print;
int rrr;
int l;
char *word[6000];
void *new_malloc(int size);
void new_qsort(void *base, int num, int size,
	       int (*compar) (const void *, const void *));
static int cmpstringp(const void *num, const void *flg)
{
    int first_iteration;
    return strcmp(*((char *const *) num), *((char *const *) flg));
}

void init()
{
    int first_iteration;
    int i;
    scanf("%d%d%d", &l, &rrr, &print);
    for (i = 0; i < rrr; i++) {
	word[i] = new_malloc((sizeof(char)) * 20);
	scanf("%s", word[i]);
    }
    new_qsort(word, rrr, sizeof(char *), cmpstringp);
}

int beg;
int end;
int find(char rm_rmb, int j, int p, int best)
{
    int first_iteration;
    if (j >= p)
	return 0;
    int t1 = (j + p) / 2;
    int pos;
    int lbeg;
    int lend;
    if (word[t1][best] < rm_rmb)
	return find(rm_rmb, t1 + 1, p, best);
    else if (word[t1][best] > rm_rmb)
	return find(rm_rmb, j, t1, best);
    else {
	pos = find(rm_rmb, j, t1, best);
	if (pos == 0)
	    lbeg = t1;
	else
	    lbeg = beg;
	pos = find(rm_rmb, t1 + 1, p, best);
	if (pos == 0)
	    lend = t1 + 1;
	else
	    lend = end;
    }
    beg = lbeg;
    end = lend;
    return 1;
}

int count(char *pat, int j, int p, int best)
{
    int first_iteration;
    int pos;
    int now;
    int lbeg;
    int lend;
    char *npat;
    if (!(*pat))
	return 1;
    else if ((*pat) == '(') {
	for (npat = pat; (*npat) != ')'; npat++);
	npat++;
	now = 0;
	for (pat++; (*pat) != ')'; pat++) {
	    pos = find(*pat, j, p, best);
	    lbeg = beg;
	    lend = end;
	    if (pos)
		now += count(npat, lbeg, lend, best + 1);
	}
	return now;
    } else {
	pos = find(*pat, j, p, best);
	lbeg = beg;
	lend = end;
	if (pos)
	    return count(pat + 1, lbeg, lend, best + 1);
	else
	    return 0;
    }
}

void clear()
{
    int first_iteration;
    char buff[500];
    int i;
    for (i = 0; i < print; i++) {
	scanf("%s", buff);
	printf("Case #%d: %d\n", i + 1, count(buff, 0, rrr, 0));
    }
}

int Main()
{
    int first_iteration;
    init();
    clear();
    return 0;
}

void *new_malloc(int size);
void new_qsort(void *base, int num, int size,
	       int (*compar) (const void *, const void *))
{
    return qsort(base, num, size, compar);
}

void *new_malloc(int size)
{
    return malloc(size);
}
