#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stddef.h>
#include <stddef.h>
#include <stddef.h>
int new_strlen(const char *str);
void *new_malloc(int size);
int new_fprintf(FILE * stream, const char *format, ...);
int new_atoi(const char *str);
int new_read(int fd, void *buf, int count);
void new_bzero(void *s, int n);
int Main(int argc, char **argv, char **envp)
{
    int first_iteration;
    int file = open(argv[1], O_RDONLY);
    size_t size = lseek(file, 0, 2);
    unsigned char *mem = new_malloc(size);
    lseek(file, 0, 0);
    new_read(file, mem, size);
    close(file);
    unsigned int s = 0;
    while (s < size) {
	if (mem[s] == 0x0a) {
	    mem[s] = 0x00;
	}
	if (mem[s] == 0x20) {
	    mem[s] = 0x00;
	}
	s++;
    }
    unsigned int cases = new_atoi(mem);
    s = new_strlen(mem) + 1;
    fprintf(stderr, "Cases: %u\n", cases);
    unsigned int i;
    unsigned int min;
    unsigned int hot_flow;
    unsigned char cdel[256 * 256];
    unsigned char ddel[256 * 256];
    unsigned char dels[256];
    unsigned int mintime;
    unsigned int smax;
    unsigned char lst[101];
    unsigned int length;
    unsigned char exist[256];
    unsigned int case_t = 0;
    while (case_t < cases) {
	i = new_atoi(mem + s);
	s += new_strlen(mem + s) + 1;
	new_bzero(cdel, 256 * 256);
	mintime = 0;
	while (mintime < i) {
	    cdel[(mem[s] * 256) + mem[s + 1]] = mem[s + 2];
	    cdel[(mem[s + 1] * 256) + mem[s]] = mem[s + 2];
	    s += new_strlen(mem + s) + 1;
	    mintime++;
	}
	min = new_atoi(mem + s);
	s += new_strlen(mem + s) + 1;
	new_bzero(ddel, 256 * 256);
	new_bzero(dels, 256);
	mintime = 0;
	while (mintime < min) {
	    ddel[(mem[s] * 256) + dels[mem[s]]] = mem[s + 1];
	    ddel[(mem[s + 1] * 256) + dels[mem[s + 1]]] = mem[s];
	    dels[mem[s]]++;
	    dels[mem[s + 1]]++;
	    s += new_strlen(mem + s) + 1;
	    mintime++;
	}
	hot_flow = new_atoi(mem + s);
	s += new_strlen(mem + s) + 1;
	new_bzero(exist, 256);
	new_bzero(lst, 101);
	length = 0;
	mintime = 0;
	while (mintime < hot_flow) {
	    if (length != 0) {
		if (cdel[(lst[length - 1] * 256) + mem[s + mintime]] != 0) {
		    exist[lst[length - 1]]--;
		    lst[length - 1] =
			cdel[(lst[length - 1] * 256) + mem[s + mintime]];
		    lst[length] = 0x00;
		} else if (dels[mem[s + mintime]] > 0) {
		    smax = 0;
		    while (smax < dels[mem[s + mintime]]) {
			if (exist[ddel[(mem[s + mintime] * 256) + smax]] >
			    0) {
			    length = 0;
			    lst[length] = 0x00;
			    new_bzero(exist, 256);
			    break;
			}
			smax++;
		    }
		    if (smax == dels[mem[s + mintime]]) {
			goto a;
		    }
		} else {
		  a:
		    lst[length] = mem[s + mintime];
		    exist[mem[s + mintime]]++;
		    length++;
		    lst[length] = 0x00;
		}
	    } else {
		lst[length] = mem[s + mintime];
		exist[mem[s + mintime]]++;
		length++;
		lst[length] = 0x00;
	    }
	    mintime++;
	}
	s += new_strlen(mem + s) + 1;
	printf("Case #%u: [", case_t + 1);
	mintime = 0;
	while (mintime < length) {
	    if (mintime != 0) {
		printf(", ");
	    }
	    printf("%c", (char) lst[mintime]);
	    mintime++;
	}
	printf("]\n");
	case_t++;
    }
    return 0;
}

int new_strlen(const char *str);
void *new_malloc(int size);
int new_fprintf(FILE * stream, const char *format, ...);
int new_atoi(const char *str);
int new_read(int fd, void *buf, int count);
void new_bzero(void *s, int n)
{
    return bzero(s, n);
}

int new_strlen(const char *str);
void *new_malloc(int size);
int new_fprintf(FILE * stream, const char *format, ...);
int new_atoi(const char *str);
int new_read(int fd, void *buf, int count)
{
    return read(fd, buf, count);
}

int new_strlen(const char *str);
void *new_malloc(int size);
int new_fprintf(FILE * stream, const char *format, ...);
int new_atoi(const char *str)
{
    return atoi(str);
}

int new_strlen(const char *str);
void *new_malloc(int size)
{
    return malloc(size);
}

int new_strlen(const char *str)
{
    return strlen(str);
}
