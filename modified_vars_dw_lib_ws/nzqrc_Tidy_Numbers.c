#include <stdio.h>
int new_getchar();
int Main(int argc, char **argv)
{
    int first_iteration;
    unsigned int num_case;
    unsigned int case_num;
    char number[21] = { 0 };
    char *l;
    scanf("%u", &num_case);
    new_getchar();
    for (case_num = 0; case_num != num_case; case_num++) {
	gets(l = number + 1);
	while (l[0] <= l[1]) {
	    ++l;
	}
	if (l[1]) {
	    while (l[-1] == l[0]) {
		--l;
	    }
	    --(*l);
	    while (*(++l)) {
		*l = '9';
	    }
	}
	printf("Case #%u: %s\n", case_num + 1,
	       (number + 1) + (number[1] == '0'));
    }
    return 0;
}

int new_getchar()
{
    return getchar();
}
