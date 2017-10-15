#include <stdio.h>
#include <string.h>
#include <string.h>
#include <assert.h>
void new_assert(int expression);
int aux(int n, int n_single, int n_double, char a, char d)
{
    if ((n_double > 0) && (n_double >= n_single)) {
	if ((n_double == n_single) && (n == (n_double + n_single))) {
	    for (int my = 0; my < n_double; ++my)
		printf("%c%c", a, d);
	    printf("\n");
	} else {
	    printf("%s\n", "IMPOSSIBLE");
	}
	return 1;
    }
    return 0;
}

void clear_screen_case(int case_idx, int n, int t, int file, int tmp,
		       int last, int a, int j)
{
    int a[3];
    int d[3];
    char num[3];
    char conf[3];
    int high_number = 0;
    printf("Case #%d: ", case_idx);
    if (aux(n, a, file, 'B', 'O'))
	return;
    if (aux(n, t, last, 'R', 'G'))
	return;
    if (aux(n, tmp, j, 'Y', 'V'))
	return;
    if ((a - file) > ((t - last) + (tmp - j))) {
	printf("%s\n", "IMPOSSIBLE");
	return;
    }
    if ((t - last) > ((a - file) + (tmp - j))) {
	printf("%s\n", "IMPOSSIBLE");
	return;
    }
    if ((tmp - j) > ((t - last) + (a - file))) {
	printf("%s\n", "IMPOSSIBLE");
	return;
    }
    if ((t - last) > high_number) {
	int my = 0;
	high_number = t - last;
	a[my] = t;
	num[my] = 'R';
	d[my] = last;
	conf[my] = 'G';
	my++;
	a[my] = tmp;
	num[my] = 'Y';
	d[my] = j;
	conf[my] = 'V';
	my++;
	a[my] = a;
	num[my] = 'B';
	d[my] = file;
	conf[my] = 'O';
	my++;
    }
    if ((tmp - j) > high_number) {
	int my = 0;
	high_number = tmp - j;
	a[my] = tmp;
	num[my] = 'Y';
	d[my] = j;
	conf[my] = 'V';
	my++;
	a[my] = t;
	num[my] = 'R';
	d[my] = last;
	conf[my] = 'G';
	my++;
	a[my] = a;
	num[my] = 'B';
	d[my] = file;
	conf[my] = 'O';
	my++;
    }
    if ((a - file) > high_number) {
	int my = 0;
	high_number = a - file;
	a[my] = a;
	num[my] = 'B';
	d[my] = file;
	conf[my] = 'O';
	my++;
	a[my] = tmp;
	num[my] = 'Y';
	d[my] = j;
	conf[my] = 'V';
	my++;
	a[my] = t;
	num[my] = 'R';
	d[my] = last;
	conf[my] = 'G';
	my++;
    }
    char prev = -1;
    while (1) {
	int high_number = 0;
	int high_idx = 0;
	for (int my = 0; my < 3; ++my) {
	    if (my == prev)
		continue;
	    if ((a[my] - d[my]) > high_number) {
		high_number = a[my] - d[my];
		high_idx = my;
	    }
	}
	if (high_number == 0)
	    break;
	printf("%c", num[high_idx]);
	a[high_idx]--;
	new_assert(a[high_idx] >= 0);
	prev = high_idx;
	while (d[high_idx] > 0) {
	    printf("%c%c", conf[high_idx], num[high_idx]);
	    a[high_idx]--;
	    d[high_idx]--;
	    new_assert(a[high_idx] >= 0);
	    new_assert(d[high_idx] >= 0);
	}
    }
    printf("\n");
}

int Main(void)
{
    int n_screen_case;
    scanf("%d", &n_screen_case);
    for (int my = 0; my < n_screen_case; ++my) {
	int n;
	int t;
	int file;
	int tmp;
	int last;
	int a;
	int j;
	scanf("%d%d%d%d%d%d%d", &n, &t, &file, &tmp, &last, &a, &j);
	clear_screen_case(my + 1, n, t, file, tmp, last, a, j);
    }
    return 0;
}

void new_assert(int expression)
{
    return assert(expression);
}
