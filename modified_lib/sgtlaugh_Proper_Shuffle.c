#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#include <stddef.h>

#define clr(ar) memset(ar, 0, sizeof(ar))
#define new_read() new_freopen("lol.txt", "r", stdin)
#define write() new_freopen("output.txt", "w", stdout)
ssize_t new_read(int fd, void *buf, size_t count);
FILE * new_freopen(const char *filename, const char *mode, FILE *stream);



int main(){
    new_read();
    write();
    int T = 0, t, a, b, k, i, j;

    scanf("%d", &t);
    while (t--){
        scanf("%d %d %d", &a, &b, &k);

        int counter = 0;
        for (i = 0; i < a; i++){
            for (j = 0; j < b; j++){
                int x = (i & j);
                if (x < k) counter++;
            }
        }
        printf("Case #%d: %d\n", ++T, counter);
    }
    return 0;
}

ssize_t new_read(int fd, void *buf, size_t count) {
  return read(fd, buf, count);
}
FILE * new_freopen(const char *filename, const char *mode, FILE *stream) {
  return freopen(filename, mode, stream);
}