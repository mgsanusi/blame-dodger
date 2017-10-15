#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <stddef.h>
#include <stddef.h>
int new_strlen(const char *str);
void *new_malloc(int size);
int new_atoi(const char *str);
int new_read(int fd, void *buf, int count);
int Main(int argc, char **argv, char **envp)
{
    int first_iteration;
    int file = open(argv[1], O_RDONLY);
    size_t size = lseek(file, 0, 2);
    char *mem = new_malloc(size);
    lseek(file, 0, 0);
    new_read(file, mem, size);
    close(file);
    unsigned int q = 0;
    while (q < size) {
	if (mem[q] == 0x0a) {
	    mem[q] = 0x00;
	}
	q++;
    }
    unsigned int cases = new_atoi(mem);
    q = new_strlen(mem) + 1;
    fprintf(stderr, "Cases: %u\n", cases);
    int trans[26] =
	{ 121, 104, 101, 115, 111, 99, 118, 120, 100, 117, 105, 103, 108,
98, 107, 114, 122, 116, 110, 119, 106, 112, 102, 109, 97, 113 };
    unsigned int case_t = 0;
    while (case_t < cases) {
	int bd = 0;
	char *a = mem + q;
	int num = new_strlen(mem + q);
	while (bd < num) {
	    if ((mem[q + bd] <= 'z') && (mem[q + bd] >= 'a')) {
		mem[q + bd] = trans[mem[q + bd] - 'a'];
	    }
	    bd++;
	}
	q += new_strlen(mem + q) + 1;
	printf("Case #%u: %s\n", case_t + 1, a);
	case_t++;
    }
    return 0;
}

int new_strlen(const char *str);
void *new_malloc(int size);
int new_atoi(const char *str);
int new_read(int fd, void *buf, int count)
{
    return read(fd, buf, count);
}

int new_strlen(const char *str);
void *new_malloc(int size);
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
