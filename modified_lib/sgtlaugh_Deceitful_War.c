#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#include <stddef.h>

#define clr(ar) memset(ar, 0, sizeof(ar))
#define new_read() new_freopen("lol.txt", "r", stdin)
#define write() new_freopen("output.txt", "w", stdout)

int t, n, l, outlet[10], ar[10];
bool visited[1 << 10], flag[1 << 10];
ssize_t new_read(int fd, void *buf, size_t count);
FILE * new_freopen(const char *filename, const char *mode, FILE *stream);



int convert(){
    char str[15];
    scanf("%s", str);

    int i, res = 0;
    for (i = 0; str[i] != 0; i++) res = (res << 1) + (str[i] - 48);
    return res;
}

int main(){
    int T = 0, i, j, bitmask;

    scanf("%d", &t);
    while (t--){
        scanf("%d %d", &n, &l);
        clr(flag);
        for (i = 0; i < n; i++) outlet[i] = convert();
        for (i = 0; i < n; i++){
            ar[i] = convert();
            flag[ar[i]] = true;
        }

        int res = (1 << 25);
        int lim = (1 << l) - 1;
        for (bitmask = 0; bitmask <= lim; bitmask++){
            clr(visited);
            int counter = 0;
            for (i = 0; i < n; i++){
                int x = (outlet[i] ^ bitmask) & lim;
                if (!visited[x] && flag[x]){
                    visited[x] = true;
                    counter++;
                }
            }
            if (counter == n && __builtin_popcount(bitmask) < res) res = __builtin_popcount(bitmask);
        }

        if (res == (1 << 25)) printf("Case #%d: NOT POSSIBLE\n", ++T);
        else printf("Case #%d: %d\n", ++T, res);
    }
    return 0;
}

ssize_t new_read(int fd, void *buf, size_t count) {
  return read(fd, buf, count);
}
FILE * new_freopen(const char *filename, const char *mode, FILE *stream) {
  return freopen(filename, mode, stream);
}