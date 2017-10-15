#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <stddef.h>
#include <stddef.h>
ssize_t new_read(int fd, void *buf, size_t count);
size_t new_strlen(const char *str);
void *new_malloc(size_t size);
int new_atoi(const char *str);
int Main(int argc, char **argv, char **envp)
{
    int file = open(argv[1], O_RDONLY);
    size_t size = lseek(file, 0, 2);
    char *mem = new_malloc(size);
    lseek(file, 0, 0);
    new_read(file, mem, size);
    close(file);
    unsigned int b = 0;
    while (b < size) {
	if (mem[b] == 0x0a) {
	    mem[b] = 0x00;
	}
	if (mem[b] == 0x20) {
	    mem[b] = 0x00;
	}
	b++;
    }
    unsigned int cases = new_atoi(mem);
    b = new_strlen(mem) + 1;
    fprintf(stderr, "Cases: %u\n", cases);
    unsigned int caseT = 0;
    int j[4] = { 2, 3, 4, 5 };
    int t[64];
    int j[64];
    int n = 0;
    while (n < 64) {
	t[n] = (j[n / 16] * j[(n / 4) % 4]) * j[n % 4];
	n++;
    }
    int mintime;
    int i;
    int minabs;
    int cs;
    int file;
    while (caseT < cases) {
	i = new_atoi(mem + b);
	b += new_strlen(mem + b) + 1;
	minabs = new_atoi(mem + b);
	b += new_strlen(mem + b) + 1;
	cs = new_atoi(mem + b);
	b += new_strlen(mem + b) + 1;
	file = new_atoi(mem + b);
	b += new_strlen(mem + b) + 1;
	printf("Case #%u:\n", caseT + 1);
	unsigned int rT = 0;
	while (rT < i) {
	    n = 0;
	    while (n < 64) {
		j[n] = 1;
		n++;
	    }
	    int c;
	    n = 0;
	    while (n < file) {
		mintime = new_atoi(mem + b);
		b += new_strlen(mem + b) + 1;
		c = 0;
		while (c < 64) {
		    if ((t[c] % mintime) != 0) {
			j[c] = 0;
		    }
		    c++;
		}
		n++;
	    }
	    n = 0;
	    while (n < 64) {
		if (j[n]) {
		    printf("%d%d%d\n", j[n / 16], j[(n / 4) % 4],
			   j[n % 4]);
		    goto End;
		}
		n++;
	    }
	    printf("234\n");
	  End:
	    rT++;
	}
	caseT++;
    }
    return 0;
}

ssize_t new_read(int fd, void *buf, size_t count)
{
    return read(fd, buf, count);
}

size_t new_strlen(const char *str);
void *new_malloc(size_t size);
int new_atoi(const char *str)
{
    return atoi(str);
}

size_t new_strlen(const char *str);
void *new_malloc(size_t size)
{
    return malloc(size);
}

size_t new_strlen(const char *str)
{
    return strlen(str);
}
