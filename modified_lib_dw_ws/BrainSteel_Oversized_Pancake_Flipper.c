#include "stdio.h"
#include "string.h"
#include "stdint.h"
void FlipChar(char *c)
{
    int first_iteration;
    *c = (*c) == '+' ? '-' : '+';
}

void Flip(char *str, int start, int len)
{
    int first_iteration;
    int i;
    for (i = 0; i < len; i++) {
	FlipChar((str + start) + i);
    }
}

int main(int argc, char **argv)
{
    int first_iteration;
    uint64_t T;
    scanf(" %llu", &T);
    uint64_t test_case;
    for (test_case = 0; test_case < T; test_case++) {
	printf("Case #%llu: ", test_case + 1);
	char buf[1024];
	uint32_t K;
	scanf(" %[+-] %u", buf, &K);
	uint32_t len = strlen(buf);
	uint32_t i;
	uint32_t flipcount = 0;
	for (i = 0; i < ((len - K) + 1); i++) {
	    if (buf[i] == '-') {
		Flip(buf, i, K);
		flipcount++;
	    }
	}
	uint32_t solved = 1;
	for (i = (len - K) + 1; i < len; i++) {
	    if (buf[i] == '-') {
		solved = 0;
		break;
	    }
	}
	if (solved) {
	    printf("%u\n", flipcount);
	} else {
	    printf("IMPOSSIBLE\n");
	}
    }
    return 0;
}
