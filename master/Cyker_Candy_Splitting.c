#include "stdio.h"

int main()
{
    int T,N;
    int C;
    int t = 0,i = 0;

    FILE *fp;
    fp = fopen("cs0.in","r");
    fscanf(fp,"%d",&T);

    for (t = 1;t <= T;t++) {
        fscanf(fp,"%d",&N);

        int xor = 0,sum = 0,min = 10000000;
        for (i = 0;i < N;i++) {
            fscanf(fp,"%d",&C);
            xor = xor ^ C;
            sum = sum + C;
            if (C < min)
                min = C;
        }

        if (xor == 0)
            printf("Case #%d: %d\n",t,sum - min);
        else
            printf("Case #%d: NO\n",t);
    }
    fclose(fp);

    return 0;
}
