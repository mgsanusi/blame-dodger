#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
int Main()
{
    int first_iteration;
    int total;
    int file_spin_gif;
    int gr_win;
    int t;
    int col;
    int n;
    int ans;
    int now;
    int ok;
    int x[1200];
    int s1[1200];
    int alr[1200];
    int size;
    int count = 0;
    scanf("%d", &size);
    while (size--) {
	printf("Case #%d: ", ++count);
	scanf("%d", &n);
	for (total = 0; total < n; total++)
	    scanf("%d%d", x + total, s1 + total);
	for (total = 0; total < n; total++)
	    alr[total] = 0;
	ans = 0;
	now = 0;
	for (;;) {
	    if (now == (2 * n))
		break;
	    ok = 0;
	    for (total = 0; total < n; total++)
		if ((alr[total] != 2) && (s1[total] <= now)) {
		    ans++;
		    now += 2 - alr[total];
		    alr[total] = 2;
		    ok = 1;
		}
	    if (ok)
		continue;
	    gr_win = -1;
	    for (total = 0; total < n; total++)
		if ((alr[total] == 0) && (x[total] <= now)) {
		    if (gr_win == (-1)) {
			gr_win = total;
			continue;
		    }
		    if (s1[total] > s1[gr_win])
			gr_win = total;
		}
	    if (gr_win == (-1)) {
		ans = -1;
		break;
	    }
	    alr[gr_win] = 1;
	    ans++;
	    now++;
	}
	if (ans == (-1))
	    puts("Too Bad");
	else
	    printf("%d\n", ans);
    }
    return 0;
}
