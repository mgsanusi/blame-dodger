#include<stdio.h>



int main() {
    int TestCaseCount, cnt, idx;
    int nOfTiles, Complexity, nOfStudents;
    nOfTiles = Complexity =  nOfStudents = TestCaseCount = cnt = idx = 0;
    FILE*   fpIn = freopen("D-small-attempt0.in", "r+", stdin);
    FILE*   fpOut = freopen("out", "w+", stdout);
    scanf("%d",&TestCaseCount);
    
    for(cnt = 0; cnt<TestCaseCount; cnt++) {
        scanf("%d %d %d", &nOfTiles, &Complexity, &nOfStudents);
        if(cnt!=0)
            printf("\n");
        printf("Case #%d:", cnt+1);
        if(nOfStudents == 0){
           printf(" IMPOSSIBLE");
           continue; 
        }
        if((Complexity == 1) ){
            if(nOfStudents<nOfTiles){
                printf(" IMPOSSIBLE");
                continue;  
            }
            else{
                for(idx = 1; idx<=nOfTiles; idx++){
                    printf(" %d", idx);
                }
            }
        }else{
            if(nOfStudents < nOfTiles-1){
               printf(" IMPOSSIBLE");
               continue; 
            }else if(nOfTiles == 1){
                printf(" %d", 1);
            }else{
                for(idx = 2; idx<=nOfTiles; idx++){
                    printf(" %d", idx);
                }
            }
        }
        
    }
    
    fclose(fpIn);
    fclose(fpOut);
    
    return 0;    
}