#include <stdio.h>
#include <string.h>

enum
{
    MAX_LEN = 512,
    MAX_PAT_LEN = 32
};

char line[MAX_LEN];
char patt[] = " welcome to code jam";
int count[MAX_PAT_LEN];
 
int calc(void)
{
    int i, j;
    
    memset(count, 0, sizeof count);
    count[0] = 1;
    for(i = 0; line[i]; ++i)
    {
        for(j = 1; patt[j]; ++j)
        {
            if(patt[j] == line[i])
            {
                count[j] = (count[j]+count[j-1]) % 10000;
            }
        }
    }
    
    /* Find the length of the pattern */
    for(j = 1; patt[j]; ++j);
    return count[j-1];
}
 
int main(void)
{
    int N, test;
    
    scanf("%d\n", &N);
    
    for(test = 1; test <= N; ++test)
    {
        fgets(line, MAX_LEN, stdin);
        printf("Case #%d: %04d\n", test, calc());
    }
    
    return 0;
}
