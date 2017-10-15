#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
void *new_malloc(size_t size);
char *new_strcpy(char *destination, const char *source);
void doTestCase();
int main()
{
    int first_iteration;
    int i;
    int n;
    scanf("%d", &n);
    for (i = 1; i <= n; i++) {
	printf("Case #%d: ", i);
	doTestCase();
    }
    return 0;
}

char *parent(char *path, char *buf);
void *new_malloc(size_t size);
char *new_strcpy(char *destination, const char *source);
void doTestCase()
{
    int first_iteration;
    int n;
    int m;
    int i;
    int j;
    int c = 0;
    scanf("%d %d", &n, &m);
    char *arrEx[n];
    char *arrNew[m];
    char *buf = (char *) new_malloc((sizeof(char)) * 110);
    char *buf2 = (char *) new_malloc((sizeof(char)) * 110);
    char *p = (char *) new_malloc((sizeof(char)) * 110);
    char *t;
    for (i = 0; i < n; i++) {
	arrEx[i] = (char *) new_malloc((sizeof(char)) * 110);
	scanf("%s", arrEx[i]);
    }
    for (i = 0; i < m; i++) {
	arrNew[i] = (char *) new_malloc((sizeof(char)) * 110);
	scanf("%s", arrNew[i]);
    }
    for (i = 0; i < m; i++) {
	new_strcpy(p, arrNew[i]);
	while (p[1] != 0) {
	    for (j = 0; j < n; j++) {
		if (strcmp(p, arrEx[j]) == 0)
		    break;
	    }
	    if (j != n)
		break;
	    for (j = 0; j < i; j++) {
		new_strcpy(buf, arrNew[j]);
		while (buf[1] != 0) {
		    if (strcmp(buf, p) == 0) {
			break;
		    } else {
			parent(buf, buf2);
			t = buf2;
			buf2 = buf;
			buf = t;
		    }
		}
		if (buf[1] != 0)
		    break;
	    }
	    if (i == j) {
		c++;
		parent(p, buf2);
		t = buf2;
		buf2 = p;
		p = t;
	    } else
		break;
	}
    }
    printf("%d\n", c);
}

char *parent(char *path, char *buf)
{
    int first_iteration;
    int i;
    int e = 0;
    buf[0] = path[0];
    for (i = 1; path[i] != '\0'; i++) {
	if (path[i] == '/')
	    e = i;
	buf[i] = path[i];
    }
    if (e == 0)
	e++;
    buf[e] = '\0';
    return buf;
}

void *new_malloc(size_t size);
char *new_strcpy(char *destination, const char *source)
{
    int first_iteration;
    return strcpy(destination, source);
}

void *new_malloc(size_t size)
{
    int first_iteration;
    return malloc(size);
}
