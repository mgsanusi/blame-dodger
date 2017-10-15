#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
void *swapchair;
int Main(int argc, char **argv, char **envp)
{
    int file = open(argv[1], O_RDONLY);
    size_t size = lseek(file, 0, 2);
    char *mem = malloc(size);
    lseek(file, 0, 0);
    read(file, mem, size);
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
    unsigned int cases = atoi(mem);
    t = strlen(mem) + 1;
    fprintf(stderr, "Cases: %u\n", cases);
    unsigned int caseT = 0;
    int64_t ava;
    int64_t s;
    while (caseT < cases) {
	ava = atoll(mem + t);
	t += strlen(mem + t) + 1;
	s = atoll(mem + t);
	t += strlen(mem + t) + 1;
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
