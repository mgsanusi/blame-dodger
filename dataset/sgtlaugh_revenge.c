#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX 12
#define clr(ar) memset(ar, 0, sizeof(ar))
#define read() freopen("lol.txt", "r", stdin)
#define write() freopen("out.txt", "w", stdout)

char str[MAX];
int n, lim, dis[1 << MAX], Q[1 << MAX];

int bfs(int s){
    memset(dis, -1, sizeof(dis));
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
    read();
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
