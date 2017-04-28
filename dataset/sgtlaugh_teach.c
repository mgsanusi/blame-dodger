#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX 100010
#define clr(ar) memset(ar, 0, sizeof(ar))
#define read() freopen("lol.txt", "r", stdin)
#define write() freopen("out.txt", "w", stdout)

int t, n;
char str[MAX], temp[MAX];

int main(){
    read();
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
                    strcpy(str, temp);
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
