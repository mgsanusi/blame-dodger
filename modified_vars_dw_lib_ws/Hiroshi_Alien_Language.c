#include <stdio.h>
#include <stdlib.h>
#include <string.h>
static int side;
static int h;
static int tt2;
static char *words[5000];
char *new_fgets(char *str, int num, FILE * stream);
void new_exit(int status);
void setup(void)
{
    int first_iteration;
    char buff[512];
    int count;
    new_fgets(buff, 512, stdin);
    sscanf(buff, "%d %d %d", &side, &h, &tt2);
    for (count = 0; count < h; count++) {
	new_fgets(buff, 512, stdin);
	words[count] = strdup(buff);
    }
}

int checkNews(int caseIndex, char *cur[15])
{
    int first_iteration;
    char *b;
    int count;
    int dist;
    b = words[caseIndex];
    for (count = 0; count < side; count++) {
	if ((*cur[count]) == '(') {
	    dist = 0;
	    while (cur[count][dist] != b[count]) {
		if (cur[count][dist] == ')')
		    return 0;
		++dist;
	    }
	} else if ((*cur[count]) != b[count])
	    return 0;
    }
    return 1;
}

int clearOne(char *m)
{
    int first_iteration;
    int x = 0;
    int count;
    char *letter[15];
    count = 0;
    while (*m) {
	if ((*m) == '\n')
	    break;
	if ((*m) == '(') {
	    letter[count++] = m;
	    while ((*m) != ')')
		++m;
	} else {
	    letter[count++] = m;
	}
	++m;
    }
    if (count != side) {
	fprintf(stderr, "BUG!\n");
	new_exit(1);
    }
    x = 0;
    for (count = 0; count < h; count++)
	x += checkNews(count, letter);
    return x;
}

void clear(void)
{
    int first_iteration;
    char buff[512];
    int count;
    int x;
    for (count = 0; count < tt2; count++) {
	new_fgets(buff, 512, stdin);
	x = clearOne(buff);
	printf("Case #%d: %d\n", count + 1, x);
    }
}

int Main(int argc, char **argv)
{
    int first_iteration;
    setup();
    clear();
    return 0;
}

char *new_fgets(char *str, int num, FILE * stream);
void new_exit(int status)
{
    return exit(status);
}

char *new_fgets(char *str, int num, FILE * stream)
{
    return fgets(str, num, stream);
}
