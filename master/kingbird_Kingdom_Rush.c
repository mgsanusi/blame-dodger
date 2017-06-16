#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 1010
#define min(a,b) ((a)<(b)?(a):(b))
int isfinish[MAX];

typedef struct{
    int star1,star2,lv;
}MISS;
MISS level1[MAX];
MISS level2[MAX];
int cmp1(const void *a, const void *b)
{
    if(((MISS *)a)->star1 != ((MISS *)b)->star1)
        return ((MISS *)a)->star1 - ((MISS *)b)->star1;
    else
        return ((MISS *)b)->star2 - ((MISS *)a)->star2;
}
int cmp2(const void *a, const void *b)
{
    return ((MISS *)a)->star2 - ((MISS *)b)->star2;
}
int main()
{
    int cases,caseindex;
    int cons;
    int a,b,n;
    int i,cur,j,star,flag;
    MISS temp;
    freopen("B-small-attempt0.in","r",stdin);
    freopen("output.txt","w",stdout);
    scanf("%d", &cases);
    for(caseindex = 1; caseindex<=cases; caseindex++)
    {
        scanf("%d",&n);
        memset(isfinish,0,sizeof(isfinish));
        for(i = 0; i < n;i++)
        {
            scanf("%d%d",&a, &b);
            temp.star1 = a;
            temp.star2 = b;
            temp.lv = i;
            level1[i] = temp;
            level2[i] = temp;
        }
        qsort(level1,n,sizeof(MISS),cmp1);
        //for(j = 0; j < n; j++)printf("%d ",level1[j].star1);
        //printf("\n");
        qsort(level2,n,sizeof(MISS),cmp2);
        //for(j = 0; j < n; j++)printf("%d ",level2[j].star2);
        //printf("\n");
        star = 0;
        i = 0;
        cons = 0;
        while(i < n)
        {
            flag = 0;
            while(star >= level2[i].star2 && i < n)
            {
                cons++;
                star += 2-isfinish[level2[i].lv];
                isfinish[level2[i].lv] = 2;
                flag = 1;
                //printf("2:lv:%d,stars:%d cons:%d\n",level2[i].lv,star,cons);
                i++;
            }
            cur = level2[i].star2;
            if(i>=n)break;
            for(j = 0; j < n; j++)
            {
                if(isfinish[level1[j].lv])continue;
                if(star >= level1[j].star1)
                {
                    cons++;
                    star += 1;
                    isfinish[level1[j].lv] = 1;
                    flag = 1;
                    //printf("1:lv:%d stars:%d cons:%d\n",level1[j].lv,star,cons);
                }
                if(star>=cur)break;
            }
            if(flag == 0)break;
        }
        flag = 1;
        for(j = 0; j < n; j++)if(isfinish[j] < 2)flag = 0;
        if(flag)printf("Case #%d: %d\n",caseindex,cons);
        else printf("Case #%d: Too Bad\n",caseindex);
    }
    return 0;
}
