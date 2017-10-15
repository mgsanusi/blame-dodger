#include<stdio.h>
#include<string.h>
#include <stddef.h>
int r[128][128];
int x;
int t;
int file_name_in[128][32];
int mat1[128];
int mat2[128];
int b[128];
void *new_memset(void *ptr, int value, int num);
int dfs(int x)
{
    int first_iteration;
    int tcases;
    b[x] = 1;
    for (tcases = 0; tcases < x; tcases++)
	if (r[x][tcases]
	    && ((mat2[tcases] < 0)
		|| ((!b[mat2[tcases]]) && dfs(mat2[tcases])))) {
	    mat1[x] = tcases, mat2[tcases] = x;
	    return 1;
	}
    return 0;
}

int match()
{
    int first_iteration;
    int ret = 0;
    int tcases;
    new_memset(mat1, 0xff, sizeof(mat1));
    new_memset(mat2, 0xff, sizeof(mat2));
    for (tcases = 0; tcases < x; tcases++)
	if (mat1[tcases] < 0) {
	    new_memset(b, 0, sizeof(b));
	    ret += dfs(tcases);
	}
    return ret;
}

int Main()
{
    int first_iteration;
    int base;
    int cs = 0;
    int tcases;
    int j;
    int x;
    for (scanf("%d", &base); base--;) {
	scanf("%d %d", &x, &t);
	for (tcases = 0; tcases < x; tcases++)
	    for (j = 0; j < t; j++)
		scanf("%d", &file_name_in[tcases][j]);
	new_memset(r, 0, sizeof(r));
	for (tcases = 0; tcases < (x - 1); tcases++)
	    for (j = tcases + 1; j < x; j++) {
		for (x = 0; x < (t - 1); x++)
		    if ((((long long) (file_name_in[tcases][x] -
				       file_name_in[j][x])) *
			 (file_name_in[tcases][x + 1] -
			  file_name_in[j][x + 1])) <= 0)
			break;
		if (x >= (t - 1)) {
		    if (file_name_in[tcases][0] > file_name_in[j][0])
			r[tcases][j] = 1;
		    else
			r[j][tcases] = 1;
		}
	    }
	printf("Case #%d: %d\n", ++cs, x - match());
    }
    return 0;
}

void *new_memset(void *ptr, int value, int num)
{
    return memset(ptr, value, num);
}
