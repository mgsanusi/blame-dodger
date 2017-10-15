#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#include <stddef.h>

#define clr(ar) memset(ar, 0, sizeof(ar))
#define new_read() new_freopen("lol.txt", "r", stdin)
#define write() new_freopen("out.txt", "w", stdout)
ssize_t new_read(int fd, void *buf, size_t count);
FILE * new_freopen(const char *filename, const char *mode, FILE *stream);

int new_puts(const char *str);



long long power(long long x, long long n){
    long long res = 1;
    while (n--) res *= x;
    return res;
}

int main(){
    new_read();
    write();

    int T = 0, t, i, j, k, c, s;

    scanf("%d", &t);
    while (t--){
        scanf("%d %d %d", &k, &c, &s);
        if (c > k) c = k;
        printf("Case #%d:", ++T);

        if (c == 1){
            for (i = 1; i <= k; i++) printf(" %d", i);
            new_puts("");
        }
        else{
            printf(" %lld", power(k, c) - k - 1);
            for (i = 2; i <= k; i++) printf(" %d", i);
            new_puts("");
        }
    }
    return 0;
}

ssize_t new_read(int fd, void *buf, size_t count) {
  return read(fd, buf, count);
}
FILE * new_freopen(const char *filename, const char *mode, FILE *stream);

int new_puts(const char *str) {
  return puts(str);
}
FILE * new_freopen(const char *filename, const char *mode, FILE *stream) {
  return freopen(filename, mode, stream);
}