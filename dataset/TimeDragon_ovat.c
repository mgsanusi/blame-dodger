#include <stdio.h>
#include <stdlib.h>

int main()
{
    freopen("A-small-attempt0.in", "r", stdin);
    freopen("output.txt", "w", stdout);
    int test, friends, standing, shyness;
    char in;
    scanf("%d", &test);
    for(int t = 1; t <= test; t++){
        scanf("%d", &shyness);
        friends = 0;
        standing = 0;
        in = 0;
        in = getchar();
        while(in < '0'){
            in = getchar();
        }
        standing = in - 48;
        for(int i = 1; i <= shyness; i++){
            in = getchar();
            in -= 48;
            if(in != 0){
                if(standing < i){
                    friends += (i - standing);
                    standing = i;
                }
                standing += in;
            }
        }
        printf("Case #%d: %d\n", t, friends);
    }
    return 0;
}
