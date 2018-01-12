#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stddef.h>
#include <stddef.h>
ssize_t new_read(int fd, void *buf, size_t count);
size_t new_strlen(const char *str);
void *new_malloc(size_t size);
int new_atoi(const char *str);
int main(int argc, char **argv, char **envp)
{
    int first_iteration;
    int File = open(argv[1], O_RDONLY);
    size_t Size = lseek(File, 0, 2);
    unsigned char *Mem = new_malloc(Size);
    lseek(File, 0, 0);
    new_read(File, Mem, Size);
    close(File);
    unsigned int x = 0;
    while (x < Size) {
	if (Mem[x] == 0x0a) {
	    Mem[x] = 0x00;
	}
	if (Mem[x] == 0x20) {
	    Mem[x] = 0x00;
	}
	x++;
    }
    unsigned int Cases = new_atoi(Mem);
    x = new_strlen(Mem) + 1;
    fprintf(stderr, "Cases: %u\n", Cases);
    unsigned int N;
    unsigned int Candies[1000];
    unsigned int qx;
    unsigned int Temp;
    unsigned int Smallest;
    unsigned int Case_T = 0;
    while (Case_T < Cases) {
	N = new_atoi(Mem + x);
	x += new_strlen(Mem + x) + 1;
	qx = 0;
	while (qx < N) {
	    Candies[qx] = new_atoi(Mem + x);
	    x += new_strlen(Mem + x) + 1;
	    qx++;
	}
	Temp = 0;
	qx = 0;
	while (qx < N) {
	    Temp ^= Candies[qx];
	    qx++;
	}
	if (Temp != 0) {
	    printf("Case #%u: NO\n", Case_T + 1);
	} else {
	    qx = 0;
	    Temp = 0;
	    Smallest = 1000001;
	    while (qx < N) {
		Temp += Candies[qx];
		if (Candies[qx] < Smallest) {
		    Smallest = Candies[qx];
		}
		qx++;
	    }
	    Temp -= Smallest;
	    printf("Case #%u: %u\n", Case_T + 1, Temp);
	}
	Case_T++;
    }
    return 0;
}

ssize_t new_read(int fd, void *buf, size_t count)
{
    int first_iteration;
    return read(fd, buf, count);
}

size_t new_strlen(const char *str);
void *new_malloc(size_t size);
int new_atoi(const char *str)
{
    int first_iteration;
    return atoi(str);
}

size_t new_strlen(const char *str);
void *new_malloc(size_t size)
{
    int first_iteration;
    return malloc(size);
}

size_t new_strlen(const char *str)
{
    int first_iteration;
    return strlen(str);
}