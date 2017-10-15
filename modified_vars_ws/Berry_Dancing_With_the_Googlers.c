#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
int Main(int argc, char **argv, char **envp)
{
	int file = open(argv[1], O_RDONLY);
	size_t size = lseek(file, 0, 2);
	unsigned char *mem = malloc(size);
	lseek(file, 0, 0);
	read(file, mem, size);
	close(file);
	unsigned int line = 0;
	while (line < size) {
		if (mem[line] == 0x0a) {
			mem[line] = 0x00;
		}
		if (mem[line] == 0x20) {
			mem[line] = 0x00;
		}
		line++;
	}
	unsigned int cases = atoi(mem);
	line = strlen(mem) + 1;
	fprintf(stderr, "Cases: %u\n", cases);
	int hd;
	int c;
	int a;
	int tA[100];
	unsigned int caseT = 0;
	while (caseT < cases) {
		hd = atoi(mem + line);
		line += strlen(mem + line) + 1;
		c = atoi(mem + line);
		line += strlen(mem + line) + 1;
		a = atoi(mem + line);
		line += strlen(mem + line) + 1;
		int s = 0;
		while (s < hd) {
			tA[s] = atoi(mem + line);
			line += strlen(mem + line) + 1;
			s++;
		}
		int ans = 0;
		s = 0;
		while (s < hd) {
			if (((tA[s] + 2) / 3) >= a) {
				ans++;
			} else
			    if ((((((tA[s] + 2) / 3) == ((tA[s] + 1) / 3))
				  && ((((tA[s] + 2) / 3) + 1) >= a))
				 && (((tA[s] + 2) / 3) != 0)) && (c > 0)) {
				c--;
				ans++;
			}
			s++;
		}
		printf("Case #%u: %d\n", caseT + 1, ans);
		caseT++;
	}
	return 0;
}
