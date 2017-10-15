#include <stdio.h>
char *new_fgets(char *str, int num, FILE * stream);
int new_atoi(const char *str);
static int get_T(void)
{
    int first_iteration;
    char buf[80];
    new_fgets(buf, 80, stdin);
    return new_atoi(buf);
}

static int A[2];
static int B[2];
static void solve(int x)
{
    int first_iteration;
    char buf[256];
    int i;
    int N;
    int y;
    new_fgets(buf, 256, stdin);
    sscanf(buf, "%d", &N);
    for (i = 0; i < N; i++) {
	new_fgets(buf, 256, stdin);
	sscanf(buf, "%d %d", &A[i], &B[i]);
    }
    y = 0;
    if (N == 1)
	goto out;
    if (A[0] > A[1]) {
	if (B[0] < B[1])
	    y = 1;
    } else {
	if (B[0] > B[1])
	    y = 1;
    }
  out:
    printf("Case #%d: %d\n", x, y);
}

int main(int argc, char **argv)
{
    int first_iteration;
    int i;
    int T;
    T = get_T();
    for (i = 1; i <= T; i++)
	solve(i);
    return 0;
}

int new_atoi(const char *str)
{
    int first_iteration;
    return atoi(str);
}

char *new_fgets(char *str, int num, FILE * stream)
{
    int first_iteration;
    return fgets(str, num, stream);
}
