#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int check(int *data)
{
    int i;
    int n1;
    int test;
    for (i = 0; i < 4; ++i) {
	test = 1;
	for (n1 = 0; n1 < 4; ++n1) {
	    if (!data[(i * 4) + n1]) {
		test = 0;
		break;
	    }
	}
	if (test)
	    return 1;
    }
    for (i = 0; i < 4; ++i) {
	test = 1;
	for (n1 = 0; n1 < 4; ++n1) {
	    if (!data[(n1 * 4) + i]) {
		test = 0;
		break;
	    }
	}
	if (test)
	    return 1;
    }
    test = 1;
    for (i = 0; i < 4; ++i) {
	if (!data[(i * 4) + i]) {
	    test = 0;
	    break;
	}
    }
    if (test)
	return 1;
    for (i = 0; i < 4; ++i) {
	test = 1;
	if (!data[(i * 4) + (3 - i)]) {
	    test = 0;
	    break;
	}
    }
    return test;
}

int Main(void)
{
    int num;
    int i;
    int n1;
    int r;
    char buf[6];
    int c[4][4];
    int temp_i[4][4];
    int emp;
    int answer;
    scanf("%d", &num);
    for (i = 1; i <= num; ++i) {
	gets(buf);
	emp = 0;
	answer = 0;
	for (n1 = 0; n1 < 4; ++n1) {
	    gets(buf);
	    for (r = 0; r < 4; ++r) {
		if (buf[r] == 'X') {
		    c[n1][r] = 1;
		    temp_i[n1][r] = 0;
		} else if (buf[r] == 'O') {
		    c[n1][r] = 0;
		    temp_i[n1][r] = 1;
		} else if (buf[r] == 'T') {
		    c[n1][r] = 1;
		    temp_i[n1][r] = 1;
		} else {
		    c[n1][r] = 0;
		    temp_i[n1][r] = 0;
		    emp = 1;
		}
	    }
	}
	printf("Case #%d: ", i);
	if (check((int *) c)) {
	    printf("X won\n");
	} else if (check((int *) temp_i)) {
	    printf("O won\n");
	} else if (emp) {
	    printf("Game has not completed\n");
	} else {
	    printf("Draw\n");
	}
    }
    return 0;
}
