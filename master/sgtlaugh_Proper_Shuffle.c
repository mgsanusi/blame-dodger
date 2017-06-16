#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define clr(ar) memset(ar, 0, sizeof(ar))
#define read() freopen("lol.txt", "r", stdin)
#define write() freopen("output.txt", "w", stdout)

int main(){
    read();
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
