#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
void *new_malloc(size_t size);
char *new_strcpy(char *destination, const char *source);
void actTestCase();
int Main()
{
    int cas;
    int b;
    scanf("%d", &b);
    for (cas = 1; cas <= b; cas++) {
	printf("Case #%d: ", cas);
	actTestCase();
    }
    return 0;
}

char *parent(char *path, char *buffer);
void actTestCase()
{
    int b;
    int wl;
    int cas;
    int ok;
    int tmp = 0;
    scanf("%d %d", &b, &wl);
    char *arrEx[b];
    char *arrNew[wl];
    char *buffer = (char *) new_malloc((sizeof(char)) * 110);
    char *buf2 = (char *) new_malloc((sizeof(char)) * 110);
    char *p = (char *) new_malloc((sizeof(char)) * 110);
    char *l;
    for (cas = 0; cas < b; cas++) {
	arrEx[cas] = (char *) new_malloc((sizeof(char)) * 110);
	scanf("%s", arrEx[cas]);
    }
    for (cas = 0; cas < wl; cas++) {
	arrNew[cas] = (char *) new_malloc((sizeof(char)) * 110);
	scanf("%s", arrNew[cas]);
    }
    for (cas = 0; cas < wl; cas++) {
	new_strcpy(p, arrNew[cas]);
	while (p[1] != 0) {
	    for (ok = 0; ok < b; ok++) {
		if (strcmp(p, arrEx[ok]) == 0)
		    break;
	    }
	    if (ok != b)
		break;
	    for (ok = 0; ok < cas; ok++) {
		new_strcpy(buffer, arrNew[ok]);
		while (buffer[1] != 0) {
		    if (strcmp(buffer, p) == 0) {
			break;
		    } else {
			parent(buffer, buf2);
			l = buf2;
			buf2 = buffer;
			buffer = l;
		    }
		}
		if (buffer[1] != 0)
		    break;
	    }
	    if (cas == ok) {
		tmp++;
		parent(p, buf2);
		l = buf2;
		buf2 = p;
		p = l;
	    } else
		break;
	}
    }
    printf("%d\n", tmp);
}

char *parent(char *path, char *buffer)
{
    int cas;
    int l = 0;
    buffer[0] = path[0];
    for (cas = 1; path[cas] != '\0'; cas++) {
	if (path[cas] == '/')
	    l = cas;
	buffer[cas] = path[cas];
    }
    if (l == 0)
	l++;
    buffer[l] = '\0';
    return buffer;
}

void *new_malloc(size_t size);
char *new_strcpy(char *destination, const char *source)
{
    return strcpy(destination, source);
}

void *new_malloc(size_t size)
{
    return malloc(size);
}
