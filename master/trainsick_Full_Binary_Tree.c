
#include <stdio.h>

int A,B,K;

int kpicked[1100];

void lottery(void) {
    scanf("%d %d %d",&A,&B,&K);
    int a,b,k,kc=0;
    for (k=0;k<K;k++) kpicked[k]=0;
    for (a=0;a<A;a++) {
        for (b=0;b<B;b++) {
            /*if (!kpicked[a & b]) {
                kpicked[a & b]=1;
                kc++;
            }*/
            if ((a & b)<K) kc++;
        }
    }
    printf("%d\n",kc);
}

int main(int argc, char **argv) {
    int i,tc;
    scanf("%d",&tc);
    for (i=1;i<=tc;i++) {
        printf("Case #%d: ",i);
        lottery();
    }
    return 0;
}
