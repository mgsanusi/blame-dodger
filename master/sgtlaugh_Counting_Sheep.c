#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX 10000010
#define clr(ar) memset(ar, 0, sizeof(ar))
#define read() freopen("lol.txt", "r", stdin)
#define write() freopen("out.txt", "w", stdout)

int main(){
    read();
    write();
    long long n, x, y;
    int T = 0, t, i, j, k, l, mask, res;

    scanf("%d", &t);
    while (t--){
        mask = 0;
        scanf("%lld", &n);
        for (i = 1; i < MAX; i++){
            x = n * i;
            while (x){
                mask |= (1 << (x % 10));
                x /= 10;
            }
            if (mask == 1023) break;
        }

        if (i == MAX) printf("Case #%d: INSOMNIA\n", ++T, res);
        else printf("Case #%d: %lld\n", ++T, n * i);
    }
    return 0;
}
