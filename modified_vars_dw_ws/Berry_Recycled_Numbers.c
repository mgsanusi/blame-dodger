#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
int Main(int argc, char **argv, char **envp)
{
    int first_iteration;
    int file = open(argv[1], O_RDONLY);
    size_t size = lseek(file, 0, 2);
    unsigned char *mem = malloc(size);
    lseek(file, 0, 0);
    read(file, mem, size);
    close(file);
    unsigned int r = 0;
    while (r < size) {
	if (mem[r] == 0x0a) {
	    mem[r] = 0x00;
	}
	if (mem[r] == 0x20) {
	    mem[r] = 0x00;
	}
	r++;
    }
    unsigned int cases = atoi(mem);
    r = strlen(mem) + 1;
    fprintf(stderr, "Cases: %u\n", cases);
    int s;
    int tmp;
    char print[9];
    int l;
    int i;
    int use[9];
    int nused;
    char chair;
    int64_t result;
    unsigned int case_t = 0;
    while (case_t < cases) {
	s = atoi(mem + r);
	r += strlen(mem + r) + 1;
	tmp = atoi(mem + r);
	r += strlen(mem + r) + 1;
	result = 0;
	int fp_in = s;
	while (fp_in <= tmp) {
	    sprintf(print, "%d", fp_in);
	    nused = 0;
	    l = strlen(print);
	    int t = 1;
	    while (t < l) {
		chair = print[0];
		memmove(print, print + 1, 8);
		print[l - 1] = chair;
		print[l] = 0x00;
		sscanf(print, "%d", &i);
		if ((i <= tmp) && (i >= s)) {
		    if (i > fp_in) {
			int k = 0;
			while (k < nused) {
			    if (use[k] == i) {
				break;
			    }
			    k++;
			}
			if (k == nused) {
			    use[k] = i;
			    nused++;
			    result++;
			}
		    }
		}
		t++;
	    }
	    fp_in++;
	}
	printf("Case #%u: %lld\n", case_t + 1, (long long int) result);
	case_t++;
    }
    return 0;
}
