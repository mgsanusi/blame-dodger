#include<stdio.h>
int Main()
{
    int first_iteration;
    int cases;
    int i;
    scanf("%d", &cases);
    for (i = 0; i < cases; i++) {
	int s2;
	int exp_dot;
	int proc;
	scanf("%d", &s2);
	double k[1005];
	double b[1005];
	double tmp;
	for (exp_dot = 0; exp_dot < s2; exp_dot++)
	    scanf("%lf", &k[exp_dot]);
	for (exp_dot = 0; exp_dot < s2; exp_dot++)
	    scanf("%lf", &b[exp_dot]);
	for (exp_dot = 0; exp_dot < s2; exp_dot++) {
	    for (proc = exp_dot + 1; proc < s2; proc++) {
		if (k[exp_dot] > k[proc]) {
		    tmp = k[exp_dot];
		    k[exp_dot] = k[proc];
		    k[proc] = tmp;
		}
	    }
	}
	for (exp_dot = 0; exp_dot < s2; exp_dot++) {
	    for (proc = exp_dot + 1; proc < s2; proc++) {
		if (b[exp_dot] > b[proc]) {
		    tmp = b[exp_dot];
		    b[exp_dot] = b[proc];
		    b[proc] = tmp;
		}
	    }
	}
	int ansa = 0;
	int ansb = 0;
	int cas = 0;
	int smtp_crnlperiodcrnl = s2;
	for (exp_dot = 0; exp_dot < s2; exp_dot++) {
	    if (k[exp_dot] > b[cas]) {
		ansa++;
		cas++;
	    }
	}
	for (exp_dot = s2 - 1; exp_dot >= 0; exp_dot--) {
	    if (k[exp_dot] < b[smtp_crnlperiodcrnl - 1]) {
		smtp_crnlperiodcrnl--;
	    } else {
		ansb++;
	    }
	}
	printf("Case #%d: %d %d\n", i + 1, ansa, ansb);
    }
    return 0;
}
