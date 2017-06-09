#include <stdio.h>
#include <stdlib.h>

int main()
{
    int T, numRow;
    int iCase, i, j;
    int flag, numN;
    int mat[4][4], hasNum[17];

    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);

    scanf("%d",&T);
    for (iCase=1;iCase<=T;iCase++)
    {
        if (iCase == 99)
            iCase = 99;
        for (i=1; i<=16; i++)
            hasNum[i] = 0;

        scanf("%d",&numRow);
        for ( i=0; i<4; i++)
            for ( j=0; j<4; j++)
                scanf("%d",&mat[i][j]);
        for ( i=0; i<4; i++)
            hasNum[ mat[numRow-1][i] ]++;

        scanf("%d",&numRow);
        for ( i=0; i<4; i++)
            for ( j=0; j<4; j++)
                scanf("%d",&mat[i][j]);
        for ( i=0; i<4; i++)
            hasNum[ mat[numRow-1][i] ]++;

        flag = 0;
        for ( i=1; i<=16; i++)
            if (hasNum[i] == 2)
                if (flag==0)
                {
                    flag = 1;
                    numN = i;
                }
                else
                {
                    flag = 2;
                    break;
                }

        printf("Case #%d: ", iCase);
        if ( flag == 0)
            printf("Volunteer cheated!\n");
        else if (flag == 1)
            printf("%d\n", numN);
        else
            printf("Bad magician!\n");
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}
