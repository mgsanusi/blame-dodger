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
	int File = open(argv[1], O_RDONLY);
	size_t Size = lseek(File, 0, SEEK_END);
	char *Mem = new_malloc(Size);
	lseek(File, 0, SEEK_SET);
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
	unsigned int Case_T = 0;
	int m[100];
	int ins;
	int A;
	int N;
	while (Case_T < Cases) {
/* --------------------- */
		A = new_atoi(Mem + q);
		q += (new_strlen(Mem + q) + 1);
		N = new_atoi(Mem + q);
		q += (new_strlen(Mem + q) + 1);
		int x = 0;
		while (x < N) {
			m[x] = new_atoi(Mem + q);
			q += (new_strlen(Mem + q) + 1);
			x++;
		}
		int y = N;
		while (y > 1) {
			x = 0;
			while (x < (y - 1)) {
				if (m[x] > m[x + 1]) {
					int z = m[x];
					m[x] = m[x + 1];
					m[x + 1] = z;
				}
				x++;
			}
			y--;
		}
		int ans = N;
		if (A == 1) {
			goto End;
		}
		int r = 0;
		int b = A;
		x = 0;
		while (x < N) {
			if (b > m[x]) {
				b += m[x];
			} else {
				while (b <= m[x]) {
					b += (b - 1);
					r++;
				}
				b += m[x];
			}
			ins = r + ((N - 1) - x);
			if (ans > ins) {
				ans = ins;
			}
			x++;
		}
 End:
		printf("Case #%u: %d\n", Case_T + 1, ans);
		Case_T++;
/* --------------------- */
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
