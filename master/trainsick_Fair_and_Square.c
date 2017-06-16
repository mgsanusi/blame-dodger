
#include <stdio.h>
#include <math.h>

long long reverse(long long a) {
    long long r=0;
    while (a) {
        r=r*10+a%10;
        a=a/10;
    }
    return r;
}

int fair(void) {
    long long a,b;
    int cnt=0;
    long long sq,i;
    scanf("%lld %lld",&a,&b);
    i=(long long int)sqrt(a);
    while (i*i<a) i++;
    sq=i*i;
    while (sq<=b) {
        if (sq==reverse(sq) && i==reverse(i)) {
            //printf("%lld %lld %lld\n",i,sq,reverse(sq));
            cnt++;
        }
        sq+=2*i+1;
        i++;
    }
    return cnt;
}

int main(int argc, char **argv) {
    int i,t;
    //printf("rev %lld=%lld\n",1234LL,reverse(1234LL));
    scanf("%d",&t);
    for (i=1;i<=t;i++) {
        printf("Case #%d: %d\n",i,fair());
    }
    return 0;
}