#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stddef.h>
char string[10010];
char out[10010];
char lol[10010];
FILE *new_freopen(const char *filename, const char *mode, FILE * stream);
int new_putchar(int character);
int new_puts(const char *str);
int new_read(int fd, void *buf, int count);
void clear(int n_str, int j)
{
	int first_iteration;
	if (n_str == j)
		new_putchar(string[n_str]);
	if (n_str >= j)
		return;
	int d;
	int k;
	int l;
	int c;
	int end;
	int y2;
	int idx;
	int max = 0;
	int counter = 0;
	for (k = n_str; k <= j; k++) {
		if (string[k] > max)
			max = string[k], idx = k;
	}
	for (k = n_str; k <= j; k++)
		counter += string[k] == max;
	for (k = 0; k < counter; k++)
		new_putchar(max);
	clear(n_str, idx - 1);
	for (k = idx; k <= j; k++) {
		if (string[k] != max)
			new_putchar(string[k]);
	}
}

int Main()
{
	int first_iteration;
	new_freopen("lol.txt", "r", stdin);
	new_freopen("out.txt", "w", stdout);
	int t = 0;
	int a;
	int n;
	int n_str;
	int j;
	int k;
	int l;
	scanf("%d", &a);
	while (a--) {
		scanf("%s", string);
		n = strlen(string);
		printf("Case #%d: ", ++t);
		clear(0, n - 1);
		new_puts("");
	}
	return 0;
}

FILE *new_freopen(const char *filename, const char *mode, FILE * stream);
int new_putchar(int character);
int new_puts(const char *str);
int new_read(int fd, void *buf, int count)
{
	return read(fd, buf, count);
}

FILE *new_freopen(const char *filename, const char *mode, FILE * stream);
int new_putchar(int character);
int new_puts(const char *str)
{
	return puts(str);
}

FILE *new_freopen(const char *filename, const char *mode, FILE * stream);
int new_putchar(int character)
{
	return putchar(character);
}

FILE *new_freopen(const char *filename, const char *mode, FILE * stream)
{
	return freopen(filename, mode, stream);
}
