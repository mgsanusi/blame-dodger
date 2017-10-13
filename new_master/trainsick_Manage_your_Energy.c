
#include <stdio.h>

int R,N,M,K;

int powN(int n, int p) {
    int r=0;
    while (n % p==0) {r++;n=n/p;}
    return r;
}

int max(int a, int b) {return a>b?a:b;}

void goody(void) {
    int max3=0;
    int max5=0;
    int oddpow2=0;
    int max2=0;
    int i,v,p2;
    int left;
    for (i=0;i<K;i++) {
        scanf("%d",&v);
        max3=max(max3,powN(v,3));
        max5=max(max5,powN(v,5));
        p2=powN(v,2);
        max2=max(max2,p2);
        oddpow2 |= p2 & 1;
    }
    //printf("max3=%d max5=%d max2=%d odd2=%d\n",max3,max5,max2,oddpow2);
    left=N;
    while (max3) {
        printf("3");
        max3--;
        left--;
    }
    while (max5) {
        printf("5");
        max5--;
        left--;
    }
    if (oddpow2) {
        printf("2");
        max2--;
        left--;
    }
    //printf("  left=%d max2
    while (max2 && 2*left>max2) {
        printf("2");
        max2--;
        left--;
    }
    while (left>0) {
        printf("4");
        max2-=2;
        left--;
    }
    printf("\n");
}

void lucky(void) {
    int i;
    scanf("%d %d %d %d",&R,&N,&M,&K);
    for (i=1;i<=R;i++) {
        goody();
    }
}

int main(int argc, char **argv) {
    int t;
    scanf("%d",&t);
    printf("Case #1:\n");
    lucky();
    return 0;
}