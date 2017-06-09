#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

int main()
{
    freopen("B-small-attempt2.in", "r", stdin);
    freopen("output.txt", "w", stdout);
    int test, diner, minimumT, maxPi, *pi;
    int temp1, temp2;
    scanf("%d", &test);
    for(int i = 1; i <= test; i++){
        pi = (int *)calloc(1001, sizeof(int));
        scanf("%d", &diner);
        minimumT = 0;
        maxPi = 0;
        while(diner--){
            scanf("%d", &temp1);
            if(maxPi < temp1){
                maxPi = temp1;
            }
            pi[temp1]++;
        }
        temp2 = 1000000000;
        for(int k = 1; k <= maxPi; k++){
            minimumT = k;
            for(int j = maxPi; j > k; j--){
                if(pi[j]){
                    temp1 = j / k;
                    if((temp1 * k) == j){
                        temp1--;
                    }
                    minimumT += (temp1 * pi[j]);
                }
            }
            if(minimumT < temp2){
                temp2 = minimumT;
            }
        }
        printf("Case #%d: %d\n", i, temp2);
    }
    return 0;
}
