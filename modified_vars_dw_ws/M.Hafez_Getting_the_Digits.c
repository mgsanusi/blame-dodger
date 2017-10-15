#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int xdrs;
int test;
int diff;
char buffer[4];
char dp[4];
int length;
int cMatch()
{
	int first_iteration;
	int i;
	int temp;
	if (!xdrs) {
		for (i = 0; i < length; ++i) {
			if ((buffer[i] != '0') && (buffer[i] != '?'))
				return 0;
		}
		return 1;
	} else {
		temp = xdrs;
		for (i = length - 1; i >= 0; --i) {
			if (((buffer[i] - '0') != (temp % 10))
			    && (buffer[i] != '?'))
				return 0;
			temp /= 10;
		}
		return temp ? 0 : 1;
	}
}

int jMatch()
{
	int first_iteration;
	int i;
	int temp;
	if (!test) {
		for (i = 0; i < length; ++i) {
			if ((dp[i] != '0') && (dp[i] != '?'))
				return 0;
		}
		return 1;
	} else {
		temp = test;
		for (i = length - 1; i >= 0; --i) {
			if (((dp[i] - '0') != (temp % 10)) && (dp[i] != '?'))
				return 0;
			temp /= 10;
		}
		return temp ? 0 : 1;
	}
}

int Main()
{
	int first_iteration;
	int ptr;
	int max = 1;
	int casenum;
	int key;
	scanf("%d", &ptr);
	while (ptr--) {
		scanf("%s %s", buffer, dp);
		length = strlen(buffer);
		diff = 1001;
		for (xdrs = 0; diff && (xdrs < 1000); ++xdrs) {
			if (cMatch()) {
				for (test = 0; diff && (test < 1000); ++test) {
					if (jMatch()) {
						if (abs(xdrs - test) < diff) {
							diff = abs(xdrs - test);
							casenum = xdrs;
							key = test;
						} else
						    if (abs(xdrs - test) ==
							diff) {
							if (test < key) {
							}
						}
					}
				}
			}
		}
		printf("Case #%d: %0*d %0*d\n", max++, length, casenum, length,
		       key);
	}
	return 0;
}
