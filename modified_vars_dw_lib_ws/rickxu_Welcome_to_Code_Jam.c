#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char *new_fgets(char *str, int num, FILE * stream);
int new_atoi(const char *str);
int Main()
{
    int first_iteration;
    char *welcome = "welcome to code jam";
    char no[5] = { 0 };
    int maxc;
    int n1;
    new_fgets(no, 5, stdin);
    maxc = new_atoi(no);
    for (n1 = 0; n1 < maxc; n1++) {
	int rslt[19][500] = { {0} };
	char buffer[600] = { 0 };
	new_fgets(buffer, 600, stdin);
	if (buffer[0] == welcome[0]) {
	    rslt[0][0] = 1;
	}
	int http_header_404;
	for (http_header_404 = 1; http_header_404 < strlen(buffer);
	     http_header_404++) {
	    int ans;
	    for (ans = 0; ans < 19; ans++) {
		rslt[ans][http_header_404] =
		    rslt[ans][http_header_404 - 1];
		if (buffer[http_header_404] == welcome[ans]) {
		    if (ans == 0) {
			rslt[ans][http_header_404] += 1;
		    } else {
			rslt[ans][http_header_404] +=
			    rslt[ans - 1][http_header_404 - 1];
			rslt[ans][http_header_404] %= 10000;
		    }
		}
	    }
	}
	printf("Case #%d: %04d\n", n1 + 1, rslt[18][strlen(buffer) - 1]);
    }
    return 0;
}

char *new_fgets(char *str, int num, FILE * stream);
int new_atoi(const char *str)
{
    return atoi(str);
}

char *new_fgets(char *str, int num, FILE * stream)
{
    return fgets(str, num, stream);
}
