#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX 20
#define min(a,b) ((a)<(b) ? (a):(b))
#define max(a,b) ((a)>(b) ? (a):(b))
#define clr(ar) memset(ar, 0, sizeof(ar))
#define read() freopen("lol.txt", "r", stdin)
#define write() freopen("out.txt", "w", stdout)

int n, a, b, res;
char C[MAX], J[MAX];

void backtrack(int i, int j, int x, int y){
    if (j == n){
        if (i == 0) backtrack(1, 0, x, y);
        else{
            int z = abs(x - y);
            if (z < res) res = z, a = x, b = y;
            else if (z == res && x < a) a = x, b = y;
            else if (z == res && x == a && y < b) b = y;
        }
        return;
    }

    int k, d;
    for (k = 0; k < 10; k++){
        if (i == 0){
            d = k;
            if (C[j] != '?') d = C[j] - 48;
            backtrack(i, j + 1, (x * 10) + d, y);
        }
        else{
            d = k;
            if (J[j] != '?') d = J[j] - 48;
            backtrack(i, j + 1, x, (y * 10) + d);
        }
    }
}

int len(int x){
    if (!x) return 1;
    int counter = 0;
    while (x){
        counter++;
        x /= 10;
    }
    return counter;
}

int main(){
    read();
    write();
    int T = 0, t, i, j, k, l;

    scanf("%d", &t);
    while (t--){
        scanf("%s %s", C, J);
        res = 1 << 25, n = strlen(C);
        backtrack(0, 0, 0, 0);
        printf("Case #%d: ", ++T);
        for (i = 0; i < (n - len(a)); i++) printf("0");
        printf("%d ", a);
        for (i = 0; i < (n - len(b)); i++) printf("0");
        printf("%d\n", b);
    }
    return 0;
}
