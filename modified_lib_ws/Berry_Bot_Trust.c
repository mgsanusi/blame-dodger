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
	unsigned int N;
	unsigned char Who;
	unsigned int Button[100];
	unsigned int Pers[100];
	unsigned int PerPo[2];
	unsigned int PerTime[2];
	unsigned int qx;
	unsigned int Time;
	unsigned int Temp;
	unsigned int Case_T = 0;
	while (Case_T < Cases) {
		N = new_atoi(Mem + x);
		x += (new_strlen(Mem + x) + 1);
		qx = 0;
		while (qx < N) {
			Who = Mem[x];
			x += (new_strlen(Mem + x) + 1);
			if (Who == 'O') {
				Pers[qx] = 0;
			} else {
				Pers[qx] = 1;
			}
			Button[qx] = new_atoi(Mem + x);
			x += (new_strlen(Mem + x) + 1);
			qx++;
		}
		PerPo[0] = 1;
		PerPo[1] = 1;
		PerTime[0] = 0;
		PerTime[1] = 0;
		Time = 0;
		qx = 0;
		while (qx < N) {
			if (Button[qx] > PerPo[Pers[qx]]) {
				Temp = Button[qx] - PerPo[Pers[qx]];
			} else {
				Temp = PerPo[Pers[qx]] - Button[qx];
			}
			if (Temp > (Time - PerTime[Pers[qx]])) {
				Temp -= (Time - PerTime[Pers[qx]]);
			} else {
				Temp = 0;
			}
			Temp += 1;
			Time += Temp;
			PerPo[Pers[qx]] = Button[qx];
			PerTime[Pers[qx]] = Time;
			qx++;
		}
		printf("Case #%u: %u\n", Case_T + 1, Time);
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
