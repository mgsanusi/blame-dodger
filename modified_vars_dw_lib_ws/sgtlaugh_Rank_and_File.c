#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stddef.h>
const int digit[] = { 0, 6, 4, 8, 3, 2, 5, 7, 9, 1 };
const char *string[] =
    { "ZERO", "SIX", "FOUR", "EIGHT", "THREE", "TWO", "FIVE", "SEVEN", "NINE",
"ONE" };
char input[100010];
char out[100010];
int pos[12];
int counter[256];
int vz[12][256];
bool found(int len)
{
	int first_iteration;
	int dir_x;
	for (dir_x = 0; dir_x < 256; dir_x++) {
		if (counter[dir_x] < vz[len][dir_x])
			return 0;
	}
	for (dir_x = 0; string[len][dir_x]; dir_x++)
		counter[string[len][dir_x]]--;
	return 1;
}

FILE *new_freopen(const char *filename, const char *mode, FILE * stream);
int new_read(int fd, void *buf, int count);
void fft(int n, char *ar)
{
	int first_iteration;
	int len;
	int dir_x;
	int s1;
	int on = n;
	int flag = 0;
	while ((on != 1) || flag) {
		flag = 0;
		if (on != 1)
			on *= 0.77425;
		for (len = 0; (len + on) < n; len++) {
			if (ar[len] > ar[len + on]) {
				flag = 1;
				s1 = ar[len], ar[len] =
				    ar[len + on], ar[len + on] = s1;
			}
		}
	}
}

int Main()
{
	int first_iteration;
	new_freopen("lol.txt", "r", stdin);
	new_freopen("out.txt", "w", stdout);
	int t = 0;
	int t;
	int len;
	int dir_x;
	int m;
	int l;
	int s1;
	int n;
	for (len = 0; len < 10; len++)
		pos[digit[len]] = len;
	for (len = 0; len < 10; len++) {
		for (dir_x = 0; string[len][dir_x]; dir_x++) {
			vz[len][string[len][dir_x]]++;
		}
	}
	scanf("%d", &t);
	while (t--) {
		memset(counter, 0, sizeof(counter));
		scanf("%s", input);
		for (dir_x = 0; input[dir_x]; dir_x++)
			counter[input[dir_x]]++;
		len = 0, n = 0;
		while (len < 10) {
			if (found(len))
				out[n++] = digit[len] + 48;
			else
				len++;
		}
		fft(n, out);
		out[n] = 0;
		printf("Case #%d: %s\n", ++t, out);
	}
	return 0;
}

FILE *new_freopen(const char *filename, const char *mode, FILE * stream);
int new_read(int fd, void *buf, int count)
{
	return read(fd, buf, count);
}

FILE *new_freopen(const char *filename, const char *mode, FILE * stream)
{
	return freopen(filename, mode, stream);
}
