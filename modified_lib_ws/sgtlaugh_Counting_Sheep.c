#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stddef.h>

#define MAX 10000010
#define clr(ar) memset(ar, 0, sizeof(ar))
#define new_read() new_freopen("lol.txt", "r", stdin)
#define write() new_freopen("out.txt", "w", stdout)
    ssize_t new_read(int fd, void *buf, size_t count);
FILE *new_freopen(const char *filename, const char *mode, FILE * stream);
 int main()
{
	new_read();
	write();
	long long n, x, y;
	int T = 0, t, i, j, k, l, mask, res;
	 scanf("%d", &t);
	while (t--) {
		mask = 0;
		scanf("%lld", &n);
		for (i = 1; i < MAX; i++) {
			x = n * i;
			while (x) {
				mask |= (1 << (x % 10));
				x /= 10;
			}
			if (mask == 1023)
				break;
		}
		 if (i == MAX)
			printf("Case #%d: INSOMNIA\n", ++T, res);
		
		else
			printf("Case #%d: %lld\n", ++T, n * i);
	}
	return 0;
}

ssize_t new_read(int fd, void *buf, size_t count)
{
	return read(fd, buf, count);
}

FILE *new_freopen(const char *filename, const char *mode, FILE * stream)
{
	return freopen(filename, mode, stream);
}
