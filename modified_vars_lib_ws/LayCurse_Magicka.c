#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int new_putchar(int character);
int new_puts(const char *str);
int Main()
{
    int dp;
    int j;
    int y;
    int b;
    int t;
    int n;
    int del;
    int max;
    int won;
    char a[100][10];
    char str[100][10];
    char in[1000];
    char ans[1000];
    int ans_size;
    int size;
    int cnt = 0;
    scanf("%d", &size);
    while (size--) {
	scanf("%d", &max);
	for (dp = 0; dp < max; dp++)
	    scanf("%s", a[dp]);
	scanf("%d", &won);
	for (dp = 0; dp < won; dp++)
	    scanf("%s", str[dp]);
	scanf("%d", &n);
	scanf("%s", in);
	ans_size = 0;
	for (y = 0; y < n; y++) {
	    ans[ans_size++] = in[y];
	    for (;;) {
		int sc = 0;
		for (t = 0; t < max; t++) {
		    for (dp = 0; dp < ans_size; dp++)
			for (j = dp + 1; j < ans_size; j++)
			    if ((dp + 1) == j)
				if (!sc) {
				    if (((ans[dp] == a[t][0])
					 && (ans[j] == a[t][1]))
					|| ((ans[dp] == a[t][1])
					    && (ans[j] == a[t][0]))) {
					sc = 1;
					ans[dp] = a[t][2];
					ans_size--;
					for (b = dp + 1; b < ans_size; b++)
					    ans[b] = ans[b + 1];
				    }
				}
		}
		for (t = 0; t < won; t++) {
		    for (dp = 0; dp < ans_size; dp++)
			for (j = dp + 1; j < ans_size; j++)
			    if (!sc) {
				if (((ans[dp] == str[t][0])
				     && (ans[j] == str[t][1]))
				    || ((ans[dp] == str[t][1])
					&& (ans[j] == str[t][0]))) {
				    sc = 1;
				    ans_size = 0;
				}
			    }
		}
		if (!sc)
		    break;
	    }
	}
	printf("Case #%d: [", ++cnt);
	for (dp = 0; dp < ans_size; dp++) {
	    if (dp)
		printf(", ");
	    new_putchar(ans[dp]);
	}
	new_puts("]");
    }
    return 0;
}

int new_putchar(int character);
int new_puts(const char *str)
{
    return puts(str);
}

int new_putchar(int character)
{
    return putchar(character);
}
