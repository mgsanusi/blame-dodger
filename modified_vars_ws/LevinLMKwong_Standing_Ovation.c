#include<stdio.h>
int getInt()
{
    char input;
    while (input = getchar(), (input < '0') || (input > '9')) {
    }
    int result = 0;
    while ((input >= '0') && (input <= '9')) {
	result = ((result * 10) + input) - '0';
	input = getchar();
    }
    return result;
}

int Main()
{
    freopen("A.in", "r", stdin);
    freopen("A.out", "w", stdout);
    int tc;
    int e;
    int a;
    int filename;
    int answer;
    int j;
    int audCnt;
    a = getInt();
    for (e = 1; e <= a; e++) {
	filename = getInt();
	answer = 0;
	audCnt = 0;
	for (tc = 0; tc <= filename; tc++) {
	    j = getchar() - '0';
	    if (audCnt < tc) {
		answer += tc - audCnt;
		audCnt += tc - audCnt;
	    }
	    audCnt += j;
	}
	printf("Case #%d: %d\n", e, answer);
    }
}
