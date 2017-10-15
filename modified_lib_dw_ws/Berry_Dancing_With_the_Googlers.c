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
int main(int argc, char **argv, char **envp)
{
    int first_iteration;
    int File = open(argv[1], O_RDONLY);
    size_t Size = lseek(File, 0, 2);
    unsigned char *Mem = new_malloc(Size);
    lseek(File, 0, 0);
    new_read(File, Mem, Size);
    close(File);
    unsigned int q = 0;
    while (q < Size) {
	if (Mem[q] == 0x0a) {
	    Mem[q] = 0x00;
	}
	if (Mem[q] == 0x20) {
	    Mem[q] = 0x00;
	}
	q++;
    }
    unsigned int Cases = new_atoi(Mem);
    q = new_strlen(Mem) + 1;
    fprintf(stderr, "Cases: %u\n", Cases);
    int N;
    int S;
    int p;
    int T_a[100];
    unsigned int Case_T = 0;
    while (Case_T < Cases) {
	N = new_atoi(Mem + q);
	q += new_strlen(Mem + q) + 1;
	S = new_atoi(Mem + q);
	q += new_strlen(Mem + q) + 1;
	p = new_atoi(Mem + q);
	q += new_strlen(Mem + q) + 1;
	int x = 0;
	while (x < N) {
	    T_a[x] = new_atoi(Mem + q);
	    q += new_strlen(Mem + q) + 1;
	    x++;
	}
	int ans = 0;
	x = 0;
	while (x < N) {
	    if (((T_a[x] + 2) / 3) >= p) {
		ans++;
	    } else
		if ((((((T_a[x] + 2) / 3) == ((T_a[x] + 1) / 3))
		      && ((((T_a[x] + 2) / 3) + 1) >= p))
		     && (((T_a[x] + 2) / 3) != 0)) && (S > 0)) {
		S--;
		ans++;
	    }
	    x++;
	}
	printf("Case #%u: %d\n", Case_T + 1, ans);
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
