
#include <stdio.h>

int abs(int x) {
    return x>=0 ? x : -x;
}

void repeater(void) {
    static char aa[110],bb[110];
    int ac,bc;
    int score=0;
    int N;
    char *a,*b,c;
    scanf("%d",&N);
    
    scanf("%s",aa);
    scanf("%s",bb);
    a=aa;
    b=bb;
    while (1) {
        if (*a!=*b) {score=-1;break;}
        if (*a==0) break;
        c=*a;
        ac=bc=0;
        while (c==*a) {a++;ac++;}
        while (c==*b) {b++;bc++;}
        score+=abs(ac-bc);
    }
    if (score>=0) printf("%d\n",score);
    else printf("Fegla Won\n");
}

int main(int argc, char **argv) {
    int i,tc;
    scanf("%d",&tc);
    for (i=1;i<=tc;i++) {
        printf("Case #%d: ",i);
        repeater();
    }
    return 0;
}
