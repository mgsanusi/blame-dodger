#include <stdio.h>
#include <stdlib.h>

int arr[1001];

int main()
{
    freopen("A-small-attempt0.in", "r", stdin);
    freopen("output.txt", "w", stdout);
    int test;
    scanf("%d", &test);
    int n = 0;
    int y, z;
    int diff = 0, a, b;
    for(int i = 1; i <= test; i++){
        scanf("%d", &n);
        a = 0; b = 0; diff = 0;
        for(int j = 0; j < n; j++){
            scanf("%d", &b);
            arr[j] = b;
            if(diff < (a - b)){
                diff = (a - b);
            }
            a = b;
        }
        z = 0;
        y = 0;
        for(int j = 1; j < n; j++){
            if(arr[j] < arr[j - 1]){
                y += (arr[j - 1] - arr[j]);
            }
            if(arr[j - 1] < diff){
                z += arr[j - 1];
            }
            else{
                z += diff;
            }
        }
        printf("Case #%d: %d %d\n", i, y, z);
    }
    return 0;
}
