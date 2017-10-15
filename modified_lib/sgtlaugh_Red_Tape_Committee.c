#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#include <stddef.h>

#define MAX 100010
#define clr(ar) memset(ar, 0, sizeof(ar))
#define new_read() new_freopen("lol.txt", "r", stdin)
#define write() new_freopen("out.txt", "w", stdout)

int t, n;
char str[MAX], temp[MAX];
ssize_t new_read(int fd, void *buf, size_t count);
FILE * new_freopen(const char *filename, const char *mode, FILE *stream);

char * new_strcpy(char *destination, const char *source);



int main(){
    new_read();
    write();
    int T = 0, i, j, k, l, x, res;

    scanf("%d", &t);
    while (t--){
        scanf("%s", str);
        n = strlen(str), res = 0;

        while (n >= 2){
            for (i = 0, k = 0; (i + 1) < n; i++){
                if (str[i] == str[i + 1]){
                    k = 1, l = n;
                    res += 10, n = 0;
                    for (j = 0; j < i; j++) temp[n++] = str[j];
                    for (j = i + 2; j < l; j++) temp[n++] = str[j];
                    temp[n] = 0;
                    new_strcpy(str, temp);
                    break;
                }
            }

            if (!k){
                res += (5 * (n >> 1));
                break;
            }
        }

        printf("Case #%d: %d\n", ++T, res);
    }
    return 0;
}

ssize_t new_read(int fd, void *buf, size_t count) {
  return read(fd, buf, count);
}
FILE * new_freopen(const char *filename, const char *mode, FILE *stream);

char * new_strcpy(char *destination, const char *source) {
  return strcpy(destination, source);
}
FILE * new_freopen(const char *filename, const char *mode, FILE *stream) {
  return freopen(filename, mode, stream);
}