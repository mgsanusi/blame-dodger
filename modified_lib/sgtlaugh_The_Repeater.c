#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#include <stddef.h>

#define MAX 10010
#define clr(ar) memset(ar, 0, sizeof(ar))
#define new_read() new_freopen("lol.txt", "r", stdin)
#define write() new_freopen("output.txt", "w", stdout)
ssize_t new_read(int fd, void *buf, size_t count);
FILE * new_freopen(const char *filename, const char *mode, FILE *stream);


void new_qsort(void* base, size_t num, size_t size, int (*compar)(const void*,const void*));


int compare(const void* a, const void* b){
    return (*(int*)a - *(int*)b);
}

bool visited[MAX];
int t, n, m, ar[MAX];

int main(){
    new_read();
    write();
    int T = 0, i, j, k;

    scanf("%d", &t);
    while (t--){
        scanf("%d %d", &n, &m);
        for (i = 0; i < n; i++) scanf("%d", &ar[i]);

        clr(visited);
        int counter = 0;
        new_qsort(ar, n, sizeof(int), compare);
        for (i = n - 1; i >= 0; i--){
            if (!visited[i]){
                counter++;
                int idx = -1, res = m;
                for (j = 0; j < i; j++){
                    if (!visited[j]){
                        if ((ar[i] + ar[j]) <= m){
                            int x = m - (ar[i] + ar[j]);
                            if (x < res) res = x, idx = j;
                        }
                    }
                }

                visited[i] = true;
                if (idx != -1) visited[idx] = true;
            }
        }

        printf("Case #%d: %d\n", ++T, counter);
    }
    return 0;
}

ssize_t new_read(int fd, void *buf, size_t count);
FILE * new_freopen(const char *filename, const char *mode, FILE *stream);


void new_qsort(void* base, size_t num, size_t size, int (*compar)(const void*,const void*)) {
  return qsort(base, num, size, compar);
}
ssize_t new_read(int fd, void *buf, size_t count) {
  return read(fd, buf, count);
}
FILE * new_freopen(const char *filename, const char *mode, FILE *stream) {
  return freopen(filename, mode, stream);
}