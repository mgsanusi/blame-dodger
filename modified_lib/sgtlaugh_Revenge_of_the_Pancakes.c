#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#include <stddef.h>

#include <stddef.h>

#define MAX 12
#define clr(ar) new_memset(ar, 0, sizeof(ar))
#define new_read() new_freopen("lol.txt", "r", stdin)
#define write() new_freopen("out.txt", "w", stdout)

char str[MAX];
int n, lim, dis[1 << MAX], Q[1 << MAX];
ssize_t new_read(int fd, void *buf, size_t count);
FILE * new_freopen(const char *filename, const char *mode, FILE *stream);
void * new_memset(void *ptr, int value, size_t num);




int bfs(int s){
    new_memset(dis, -1, sizeof(dis));
    int i, j, k, x, y, mask, front = 0, len = 0;

    dis[s] = 0, Q[len++] = s;
    while (front < len){
        mask = Q[front++];
        if (mask == lim) return dis[mask];

        for (i = 0; i < n; i++){
            x = mask, y = mask;
            for (j = 0; j <= i; j++) x ^= (1 << j), y &= (~(1 << j));
            for (j = 0, k = i; j <= i; j++, k--){
                if (x & (1 << j)) y |= (1 << k);
            }

            if (dis[y] == -1){
                dis[y] = dis[mask] + 1;
                Q[len++] = y;
            }
        }
    }
    return -1;
}

int main(){
    new_read();
    write();
    int T = 0, t, i, j, k, res, mask;

    scanf("%d", &t);
    while (t--){
        scanf("%s", str);
        n = strlen(str), mask = 0, lim = (1 << n) - 1;
        for (i = 0; i < n; i++){
            if (str[i] == '+') mask |= (1 << i);
        }
        printf("Case #%d: %d\n", ++T, bfs(mask));
    }
    return 0;
}

ssize_t new_read(int fd, void *buf, size_t count) {
  return read(fd, buf, count);
}
FILE * new_freopen(const char *filename, const char *mode, FILE *stream) {
  return freopen(filename, mode, stream);
}
void * new_memset(void *ptr, int value, size_t num) {
  return memset(ptr, value, num);
}