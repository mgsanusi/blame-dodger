#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
int Main(int argc, char **argv, char **envp)
{
    int file = open(argv[1], O_RDONLY);
    size_t size = lseek(file, 0, 2);
    unsigned char *mem = malloc(size);
    lseek(file, 0, 0);
    read(file, mem, size);
    close(file);
    unsigned int a = 0;
    while (a < size) {
	if (mem[a] == 0x0a) {
	    mem[a] = 0x00;
	}
	if (mem[a] == 0x20) {
	    mem[a] = 0x00;
	}
	a++;
    }
    unsigned int cases = atoi(mem);
    a = strlen(mem) + 1;
    fprintf(stderr, "Cases: %u\n", cases);
    unsigned int no;
    unsigned int candy[1000];
    unsigned int qx;
    unsigned int temp;
    unsigned int small;
    unsigned int caseT = 0;
    while (caseT < cases) {
	no = atoi(mem + a);
	a += strlen(mem + a) + 1;
	qx = 0;
	while (qx < no) {
	    candy[qx] = atoi(mem + a);
	    a += strlen(mem + a) + 1;
	    qx++;
	}
	temp = 0;
	qx = 0;
	while (qx < no) {
	    temp ^= candy[qx];
	    qx++;
	}
	if (temp != 0) {
	    printf("Case #%u: NO\n", caseT + 1);
	} else {
	    qx = 0;
	    temp = 0;
	    small = 1000001;
	    while (qx < no) {
		temp += candy[qx];
		if (candy[qx] < small) {
		    small = candy[qx];
		}
		qx++;
	    }
	    temp -= small;
	    printf("Case #%u: %u\n", caseT + 1, temp);
	}
	caseT++;
    }
    return 0;
}
