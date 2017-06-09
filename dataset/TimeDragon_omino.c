#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main()
{
    freopen("D-small-attempt1.in", "r", stdin);
    freopen("output.txt", "w", stdout);
    int test, x, r, c, a;
    bool result = false;
    scanf("%d", &test);
    for(int i = 1; i <= test; i++){
        result = false;
        scanf("%d %d %d", &x ,&r, &c);
        if(r > c){
            a = r;
            r = c;
            c = a;
        }
        switch(r){
            case 1: switch(c){
                    case 1: if(x == 1){
                        result = true;
                    }
                    break;
                    case 2: if(x < 3){
                        result = true;
                    }
                    break;
                    case 3: if(x == 1){
                        result = true;
                    }
                    break;
                    case 4: if(x < 3){
                        result = true;
                    }
                    break;
                }
                break;
            case 2: switch(c){
                    case 2: if(x < 3){
                        result = true;
                    }
                    break;
                    case 3: if(x < 4){
                        result = true;
                    }
                    break;
                    case 4: if(x < 3){
                        result = true;
                    }
                    break;
                }
                break;
            case 3: switch(c){
                    case 3: if((x == 1) || (x == 3)){
                        result = true;
                    }
                    break;
                    case 4: if(x < 5){
                        result = true;
                    }
                    break;
                }
                break;
            case 4: switch(c){
                    case 4: if(x != 3){
                        result = true;
                    }
                    break;
                }
                break;
        }
        if(result){
            printf("Case #%d: GABRIEL\n", i);
        }else{
            printf("Case #%d: RICHARD\n", i);
        }
    }
    return 0;
}
