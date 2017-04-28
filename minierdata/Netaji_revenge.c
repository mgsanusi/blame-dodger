#include<stdio.h>
#include<string.h>

char* flipPancake(char* pancake, int reach) {
    int idx = 0;
    for(idx = 0; idx<=reach; idx++) {
        if(pancake[idx]=='+'){
            pancake[idx]='-';
        }else if(pancake[idx]=='-'){
            pancake[idx]='+';
        }
    }
    return pancake;
}

int happyPancake(char* pancakes) {
        int reachedPancake = -1, idx = 0, number_of_flips=0;
        while(reachedPancake!=(strlen(pancakes)-1)){
            reachedPancake++;
            if(pancakes[reachedPancake] == '-' && (pancakes[reachedPancake+1]=='+' || pancakes[reachedPancake+1]=='\r' || pancakes[reachedPancake+1]=='\n' || pancakes[reachedPancake+1]=='\0') ){
                pancakes = flipPancake(pancakes,reachedPancake);
                number_of_flips++;
                reachedPancake = -1;
            }
            else if(pancakes[reachedPancake] == '+' && pancakes[reachedPancake+1]=='-') {
                pancakes = flipPancake(pancakes,reachedPancake);
                number_of_flips++;
                reachedPancake = -1;
            }
            else if(pancakes[reachedPancake] == '+' && (pancakes[reachedPancake+1]=='\r' || pancakes[reachedPancake+1]=='\n')||pancakes[reachedPancake+1]=='\0'){
                return number_of_flips;
            }
        }
}

int main() {
    int TestCaseCount, cnt;
    char pancakes[300];
    cnt = TestCaseCount = 0;
    FILE*   fpIn = freopen("B-small-attempt0.in", "r+", stdin);
    FILE*   fpOut = freopen("out", "w+", stdout);
    memset(pancakes,'\0',300);
    scanf("%d",&TestCaseCount);
    
    for(cnt = 0; cnt<TestCaseCount; cnt++) {
        scanf("%s",pancakes);
        if(cnt!=0)
            printf("\n");
        printf("Case #%d: %d", cnt+1, happyPancake(pancakes));
        memset(pancakes,'\0',300);
    }
    
    fclose(fpIn);
    fclose(fpOut);
    
    return 0;    
}