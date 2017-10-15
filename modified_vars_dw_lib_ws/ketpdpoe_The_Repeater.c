#include<stdio.h>
#include<string.h>
int Main()
{
    int first_iteration;
    int a;
    int temp;
    scanf("%d", &a);
    for (temp = 0; temp < a; temp++) {
	char s[100][105];
	int move[105][105] = { };
	int cases;
	int best;
	int b;
	scanf("%d", &b);
	int a;
	for (cases = 0; cases < b; cases++) {
	    scanf("%s", s[cases]);
	    int l = strlen(s[cases]);
	    a = 1;
	    for (best = 1; best < l; best++) {
		if (s[cases][best] == s[cases][best - 1]) {
		    move[cases][a - 1]++;
		} else {
		    s[cases][a] = s[cases][best];
		    a++;
		}
	    }
	    s[cases][a] = '\0';
	}
	int end = 1;
	int tmp;
	int k;
	printf("Case #%d: ", temp + 1);
	for (cases = 1; cases < b; cases++)
	    if (strcmp(s[cases], s[0]) != 0) {
		end = 0;
		break;
	    }
	if (end == 0)
	    printf("Fegla Won\n");
	else {
	    int rslt = 0;
	    int mid;
	    for (k = 0; k < a; k++) {
		for (cases = 0; cases < b; cases++) {
		    for (best = cases + 1; best < b; best++) {
			if (move[cases][k] > move[best][k]) {
			    tmp = move[cases][k];
			    move[cases][k] = move[best][k];
			    move[best][k] = tmp;
			}
		    }
		}
		if ((b % 2) == 0) {
		    mid = (move[b / 2][k] + move[(b / 2) - 1][k]) / 2;
		} else
		    mid = move[b / 2][k];
		for (cases = 0; cases < b; cases++) {
		    if (mid > move[cases][k])
			rslt += mid - move[cases][k];
		    else
			rslt += move[cases][k] - mid;
		}
	    }
	    printf("%d\n", rslt);
	}
    }
    return 0;
}
