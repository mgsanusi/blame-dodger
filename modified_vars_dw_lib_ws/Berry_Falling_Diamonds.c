#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <stddef.h>
#include <stddef.h>
#include <stddef.h>
#include <stddef.h>
void *swapchair;
int new_strlen(const char *str);
void *new_malloc(int size);
int new_fprintf(FILE * stream, const char *format, ...);
void *new_memcpy(void *destination, const void *source, int num);
int new_atoi(const char *str);
int new_read(int fd, void *buf, int count);
void new_bzero(void *s, int n);
int new_abs(int x);
int Main(int argc, char **argv, char **envp)
{
	int first_iteration;
	int file = open(argv[1], O_RDONLY);
	size_t size = lseek(file, 0, 2);
	char *mem = new_malloc(size);
	lseek(file, 0, 0);
	new_read(file, mem, size);
	close(file);
	unsigned int t = 0;
	while (t < size) {
		if (mem[t] == 0x0a) {
			mem[t] = 0x00;
		}
		if (mem[t] == 0x20) {
			mem[t] = 0x00;
		}
		t++;
	}
	unsigned int cases = new_atoi(mem);
	t = new_strlen(mem) + 1;
	fprintf(stderr, "Cases: %u\n", cases);
	unsigned int caseT = 0;
	int64_t ava;
	int64_t s;
	while (caseT < cases) {
		ava = atoll(mem + t);
		t += new_strlen(mem + t) + 1;
		s = atoll(mem + t);
		t += new_strlen(mem + t) + 1;
		int64_t i = s - 1;
		int64_t f = 1LL << (ava - 1);
		int64_t lend = 2;
		int64_t worstans = 0;
		if (s == (1LL << ava)) {
			worstans = s - 1;
			goto e;
		}
		while (i >= f) {
			worstans += lend;
			i -= f;
			lend <<= 1;
			f >>= 1;
		}
 e:
		1;
		f = 2;
		int64_t ans = 1LL << (ava - 1);
		int64_t bestans = 0;
		while (f <= s) {
			bestans += ans;
			ans >>= 1;
			f <<= 1;
		}
		printf("Case #%u: %lld %lld\n", caseT + 1, worstans, bestans);
		caseT++;
	}
	return 0;
}

int new_strlen(const char *str);
void *new_malloc(int size);
int new_fprintf(FILE * stream, const char *format, ...);
void *new_memcpy(void *destination, const void *source, int num);
int new_atoi(const char *str);
int new_read(int fd, void *buf, int count);
void new_bzero(void *s, int n);
int new_abs(int x)
{
	return abs(x);
}

int new_strlen(const char *str);
void *new_malloc(int size);
int new_fprintf(FILE * stream, const char *format, ...);
void *new_memcpy(void *destination, const void *source, int num);
int new_atoi(const char *str);
int new_read(int fd, void *buf, int count);
void new_bzero(void *s, int n)
{
	return bzero(s, n);
}

int new_strlen(const char *str);
void *new_malloc(int size);
int new_fprintf(FILE * stream, const char *format, ...);
void *new_memcpy(void *destination, const void *source, int num);
int new_atoi(const char *str);
int new_read(int fd, void *buf, int count)
{
	return read(fd, buf, count);
}

int new_strlen(const char *str);
void *new_malloc(int size);
int new_fprintf(FILE * stream, const char *format, ...);
void *new_memcpy(void *destination, const void *source, int num);
int new_atoi(const char *str)
{
	return atoi(str);
}

int new_strlen(const char *str);
void *new_malloc(int size);
int new_fprintf(FILE * stream, const char *format, ...);
void *new_memcpy(void *destination, const void *source, int num)
{
	return memcpy(destination, source, num);
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
