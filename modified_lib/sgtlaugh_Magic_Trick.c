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
    int T = 0, t, i, j, k, ar[2], z, r;

    scanf("%d", &t);
    while (t--){
        ar[0] = ar[1] = 0;
        for (k = 0; k < 2; k++){
            scanf("%d", &r);
            for (i = 1; i <= 4; i++){
                for (j = 1; j <= 4; j++){
                    scanf("%d", &z);
                    if (i == r) ar[k] |= (1 << z);
                }
            }
        }

        int bitmask = ar[0] & ar[1];
        if (__builtin_popcount(bitmask) == 1) printf("Case #%d: %d\n", ++T, __builtin_ctz(bitmask));
        else if (__builtin_popcount(bitmask) > 1) printf("Case #%d: Bad magician!\n", ++T);
        else printf("Case #%d: Volunteer cheated!\n", ++T);
    }
    return 0;
}


ssize_t new_read(int fd, void *buf, size_t count) {
  return read(fd, buf, count);
}
FILE * new_freopen(const char *filename, const char *mode, FILE *stream) {
  return freopen(filename, mode, stream);
}