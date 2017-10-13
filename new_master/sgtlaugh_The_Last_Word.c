#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX 10010
#define clr(ar) memset(ar, 0, sizeof(ar))
#define read() freopen("lol.txt", "r", stdin)
#define write() freopen("out.txt", "w", stdout)

char str[MAX], out[MAX], lol[MAX];

void solve(int i, int j){
    if (i == j) putchar(str[i]);
    if (i >= j) return;

    int d, k, l, x, y, r, idx, max = 0, counter = 0;
    for (k = i; k <= j; k++){
        if (str[k] > max) max = str[k], idx = k;
    }
    for (k = i; k <= j; k++) counter += (str[k] == max);

    for (k = 0; k < counter; k++) putchar(max);
    solve(i, idx - 1);
    for (k = idx; k <= j; k++){
        if (str[k] != max) putchar(str[k]);
    }
}

int main(){
    read();
    write();
    int T = 0, t, n, i, j, k, l;

    scanf("%d", &t);
    while (t--){
        scanf("%s", str);
        n = strlen(str);

        printf("Case #%d: ", ++T);
        solve(0, n - 1);
        puts("");
    }
    return 0;
}
