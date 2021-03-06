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
	int File = open(argv[1], O_RDONLY);
	size_t Size = lseek(File, 0, SEEK_END);
	unsigned char *Mem = new_malloc(Size);
	lseek(File, 0, SEEK_SET);
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
	int64_t N, P_D, P_G;
	int64_t Temp;
	unsigned Possible;
	unsigned int Case_T = 0;
	while (Case_T < Cases) {
		N = atoll(Mem + x);
		x += (new_strlen(Mem + x) + 1);
		P_D = atoll(Mem + x);
		x += (new_strlen(Mem + x) + 1);
		P_G = atoll(Mem + x);
		x += (new_strlen(Mem + x) + 1);
		Possible = 0;
		Temp = 1;
		while ((Temp < 101) && (Temp <= N)) {
			if ((Temp * P_D) % 100 == 0) {
				goto Skip;
			}
			Temp++;
		}
		goto Impossible;
 Skip:
		1;
		if (((P_D == 100) && (P_G == 0))
		    || ((P_D != 100) && (P_G == 100)) || ((P_D != 0)
							  && (P_G == 0))) {
			goto Impossible;
		}
		Possible = 1;
 Impossible:
		printf("Case #%u: %s\n", Case_T + 1,
		       (Possible == 1) ? "Possible" : "Broken");
		Case_T++;
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
