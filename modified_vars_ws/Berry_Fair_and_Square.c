#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
int Main(int argc, char **argv, char **envp)
{
    int file = open(argv[1], O_RDONLY);
    size_t size = lseek(file, 0, 2);
    char *mem = malloc(size);
    lseek(file, 0, 0);
    read(file, mem, size);
    close(file);
    unsigned int m = 0;
    while (m < size) {
	if (mem[m] == 0x0a) {
	    mem[m] = 0x00;
	}
	if (mem[m] == 0x20) {
	    mem[m] = 0x00;
	}
	m++;
    }
    unsigned int cases = atoi(mem);
    m = strlen(mem) + 1;
    fprintf(stderr, "Cases: %u\n", cases);
    unsigned int case_t = 0;
    int k;
    int s;
    while (case_t < cases) {
	k = atoi(mem + m);
	m += strlen(mem + m) + 1;
	s = atoi(mem + m);
	m += strlen(mem + m) + 1;
	int res = 0;
	int y;
	y = 1;
	if ((y >= k) && (y <= s)) {
	    res++;
	}
	y = 4;
	if ((y >= k) && (y <= s)) {
	    res++;
	}
	y = 9;
	if ((y >= k) && (y <= s)) {
	    res++;
	}
	y = 121;
	if ((y >= k) && (y <= s)) {
	    res++;
	}
	y = 484;
	if ((y >= k) && (y <= s)) {
	    res++;
	}
	printf("Case #%u: %d\n", case_t + 1, res);
	case_t++;
    }
    return 0;
}
