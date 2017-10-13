# include <stdio.h>
int allsnds[100];


int main(void)
{
    //var 
    int t, n, l, h;
    int temp,temp1,temp2;

    //loop
    int i,j,k;


    scanf("%d ",&t);

    for(i=0;i<t;i++)
    {
        scanf("%d ",&n);
        scanf("%d ",&l);
        scanf("%d ",&h);

        for(j=0;j<n;j++)
            scanf("%d",&allsnds[j]);

        // Solve
        for(j=l;j<=h;j++)
        {
            temp = 1;
            for(k=0;k<n;k++)
            {
                if((allsnds[k]%j==0) || (j%allsnds[k]==0))
                {
//                    printf("Succ : %d and %d\n",allsnds[k],j);
                    continue;
                }
                else
                {
   //                 printf("Break : %d and %d\n",allsnds[k],j);
                    temp=0;
                    break;
                }
            }

            if(temp == 1)
            {
                temp = j;
                break;
            }
            temp =0;
        }

        // output print
        printf("Case #%d: ",i+1);
        if(temp ==0)
            printf("NO\n");
        else
            printf("%d\n",temp);

     }

    return 1;
}

