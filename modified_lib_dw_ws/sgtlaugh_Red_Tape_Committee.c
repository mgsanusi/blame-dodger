#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stddef.h>
int t;
int n;
char str[100010];
char temp[100010];
ssize_t new_read;
FILE *new_freopen(const char *filename, const char *mode, FILE * stream);
char *new_strcpy(char *destination, const char *source);
int main()
{
    int first_iteration;
    new_freopen("lol.txt", "r", stdin);
    new_freopen("out.txt", "w", stdout);
    int T = 0;
    int i;
    int j;
    int k;
    int l;
    int x;
    int res;
    scanf("%d", &t);
    while (t--) {
	scanf("%s", str);
	n = strlen(str), res = 0;
	while (n >= 2) {
	    for (i = 0, k = 0; (i + 1) < n; i++) {
		if (str[i] == str[i + 1]) {
		    k = 1, l = n;
		    res += 10, n = 0;
		    for (j = 0; j < i; j++)
			temp[n++] = str[j];
		    for (j = i + 2; j < l; j++)
			temp[n++] = str[j];
		    temp[n] = 0;
		    new_strcpy(str, temp);
		    break;
		}
	    }
	    if (!k) {
		res += 5 * (n >> 1);
		break;
	    }
	}
	printf("Case #%d: %d\n", ++T, res);
    }
    return 0;
}

ssize_t new_read {
    int first_iteration;
     return read(fd, buf, count);
} FILE *new_freopen(const char *filename, const char *mode, FILE * stream);
char *new_strcpy(char *destination, const char *source)
{
    int first_iteration;
    return strcpy(destination, source);
}

FILE *new_freopen(const char *filename, const char *mode, FILE * stream)
{
    int first_iteration;
    return freopen(filename, mode, stream);
}
