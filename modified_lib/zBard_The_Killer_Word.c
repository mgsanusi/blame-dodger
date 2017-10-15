# include <stdio.h>
char tiles[6][6];



int main(void)
{
    //var 
    int t, n, a, b,r,c;
    int temp,temp1,temp2,flag;

    //loop
    int i,j,k,l;


    scanf("%d ",&t);

    for(i=0;i<t;i++)
    {
        scanf("%d ",&r);
        scanf("%d ",&c);
        for(j=0;j<r;j++)
            for(k=0;k<c;k++)
                scanf(" %c",&tiles[j][k]);
        
        flag = 1;

        // Solve
        for(j=0;j<r;j++)
        {
            for(k=0;k<c;k++)
                if(tiles[j][k] == '#')
                {
                    if((j<(r-1)) && (k<(c-1)))
                    {
                        if(tiles[j+1][k] == '#')
                        if(tiles[j][k+1] == '#')
                        if(tiles[j+1][k+1] == '#')
                        {    
                            tiles[j+1][k+1] = '/';
                            tiles[j][k] = '/';
                            tiles[j+1][k] = '\\';
                            tiles[j][k+1] = '\\';
                        }
                    }
                }
        }

        for(j=0;j<r;j++)
            for(k=0;k<c;k++)
                if(tiles[j][k] == '#')
                    flag = 0;
                        

        // output print
        printf("Case #%d:\n",i+1);
        if(flag == 0)
        {
            printf("Impossible\n");
        }
        else
        {
            for(j=0;j<r;j++)
            {
                for(k=0;k<c;k++)
                    printf("%c",tiles[j][k]);
                printf("\n");
            }
        }

     }

    return 1;
}

