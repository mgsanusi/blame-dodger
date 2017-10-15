# include <stdio.h>
int arr[121];


int main(void)
{
    int i,j,t,n,pg,pd,flag;
    for(i=120;i>=0;i--)
        arr[i] = 0;


    for(i=10;i>=1;i--)
        for(j=i;j>=0;j--)
        {
            t = j*100;
            t = t/i;
            if((t*i) == (j*100))
            {
                arr[t] = i;
            }
        }
            

    scanf("%d",&t);
    for(i=0;i<t;i++)
    {
        flag = 1;
        scanf("%d",&n);
        scanf("%d",&pd);
        scanf("%d",&pg);
        
//        printf("::%d::\n",arr[pd]);

        if((arr[pd] > n) || (arr[pd] == 0))
            flag = 0;

        if((pg == 100) && (pd !=100))
            flag = 0;

        if((pg == 0) && (pd !=0))
            flag = 0;

        if(flag ==1)
            printf("Case #%d: Possible\n",i+1);
        else
            printf("Case #%d: Broken\n",i+1);
     }
            
    return 1;
}

        
