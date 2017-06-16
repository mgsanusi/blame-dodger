#include "stdio.h"
#include "string.h"

int main()
{
    int T;
    int C,D,N;
    char comb[26][26];
    int oppo[26][26];
    char str[102];
    int t = 0,i = 0,j = 0;
    char c1,c2,c3;
    int ix = 0;

    FILE *fp;
    fp = fopen("bs1.in","r");
    fscanf(fp,"%d",&T);

    for (t = 1;t <= T;t++) {
        memset(comb,0,sizeof(comb));
        memset(oppo,0,sizeof(oppo));
        memset(str,0,sizeof(str));
        ix = 0;
        c1 = 0;
        c2 = 0;
        c3 = 0;

        fscanf(fp,"%d ",&C);
        for (i = 0;i < C;i++) {
            fscanf(fp,"%c",&c1);
            fscanf(fp,"%c",&c2);
            fscanf(fp,"%c",&c3);
            comb[c1-'A'][c2-'A'] = c3;
            comb[c2-'A'][c1-'A'] = c3;
            fscanf(fp,"%c",&c1); //space
        }

        fscanf(fp,"%d ",&D);
        for (i = 0;i < D;i++) {
            fscanf(fp,"%c",&c1);
            fscanf(fp,"%c",&c2);
            oppo[c1-'A'][c2-'A'] = 1;
            oppo[c2-'A'][c1-'A'] = 1;
            fscanf(fp,"%c",&c1); //space
        }

        fscanf(fp,"%d ",&N);
        for (i = 0;i < N;i++) {
            fscanf(fp,"%c",&c1);
            if (ix == 0) {
                str[ix] = c1;
                ix++;
            } else if (comb[str[ix-1]-'A'][c1-'A'] != 0) {
                str[ix-1] = comb[str[ix-1]-'A'][c1-'A'];
            } else if (comb[c1-'A'][str[ix-1]-'A'] != 0) {
                str[ix-1] = comb[c1-'A'][str[ix-1]-'A'];
            } else {
                int op = 0;
                for (j = 0;j < ix;j++) {
                    if (oppo[str[j]-'A'][c1-'A'] == 1 || oppo[c1-'A'][str[j]-'A'] == 1) {
                        op = 1;
                        break;
                    }
                }
                if (op)
                    ix = 0;
                else {
                    str[ix] = c1;
                    ix++;
                }
            }
            //printf("ix = %d\n",ix);
        }

        printf("Case #%d: [",t);
        if (ix != 0) {
            for (i = 0;i < ix-1;i++) {
                printf("%c, ",str[i]);
            }
            printf("%c",str[i]);
        }
        //printf("ix = %d",ix);
        printf("]\n");
    }
    fclose(fp);

    return 0;
}
