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
	char *Mem = new_malloc(Size);
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
	unsigned int Case_T = 0;
	int m[4] = { 2, 3, 4, 5 };
	int p[64];
	int ok[64];
	int x = 0;
	while (x < 64) {
		p[x] = (m[x / 16] * m[(x / 4) % 4]) * m[x % 4];
		x++;
	}
	int Kk;
	int R;
	int N;
	int M;
	int K;
	while (Case_T < Cases) {
		R = new_atoi(Mem + q);
		q += new_strlen(Mem + q) + 1;
		N = new_atoi(Mem + q);
		q += new_strlen(Mem + q) + 1;
		M = new_atoi(Mem + q);
		q += new_strlen(Mem + q) + 1;
		K = new_atoi(Mem + q);
		q += new_strlen(Mem + q) + 1;
		printf("Case #%u:\n", Case_T + 1);
		unsigned int R_T = 0;
		while (R_T < R) {
			x = 0;
			while (x < 64) {
				ok[x] = 1;
				x++;
			}
			int y;
			x = 0;
			while (x < K) {
				Kk = new_atoi(Mem + q);
				q += new_strlen(Mem + q) + 1;
				y = 0;
				while (y < 64) {
					if ((p[y] % Kk) != 0) {
						ok[y] = 0;
					}
					y++;
				}
				x++;
			}
			x = 0;
			while (x < 64) {
				if (ok[x]) {
					printf("%d%d%d\n", m[x / 16],
					       m[(x / 4) % 4], m[x % 4]);
					goto End;
				}
				x++;
			}
			printf("234\n");
 End:
			R_T++;
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
