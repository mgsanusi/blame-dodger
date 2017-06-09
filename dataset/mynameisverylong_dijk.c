#include <stdio.h>

char a[110000];
long ii[2]={1,2},jj[2]={1,3},kk[2]={1,4};

int qmult(long a[],long b[],long x[]){
    long c[2];
    c[0]=a[0]*b[0];
    if (a[1]==1||b[1]==1)
        c[1]=a[1]*b[1];
    else if (a[1]==b[1]){
        c[1]=1;
        c[0]*=-1;
    }
    else {
        c[1]=9-a[1]-b[1];
        if ((a[1]-b[1]+3)%3==1)
            c[0]*=-1;
    }
    x[0]=c[0];
    x[1]=c[1];
    return 0;
}

long *trans(char c){
    if (c=='i')
        return ii;
    if (c=='j')
        return jj;
    if (c=='k')
        return kk;
    return 0;
}

int main() {
    long i,t,tt,l,x,t1[2],t2[2],*p,u;
    freopen("C-small-attempt1.in.txt", "r", stdin);
    freopen("C-small-attempt1.out.txt", "w", stdout);
    scanf("%ld",&t);
    for (tt=1;tt<=t;tt++){
        scanf("%ld%ld",&l,&x);
        scanf("%s",a);
        printf("Case #%ld: ",tt);
        p=t1;
        for (i=0,t1[0]=1,t1[1]=1;i<l;i++){
            p=trans(a[i]);
            qmult(t1, p, t1);
        }
        for (i=0,t2[0]=1,t2[1]=1;i<(x%4);i++){
            qmult(t2, t1, t2);
        }
        if (t2[0]*t2[1]!=-1){
            printf("NO\n");
            continue;
        }
        for (i=l;i<l*9;i++){
            a[i]=a[i-l];
        }
        for (i=0,t1[0]=1,t1[1]=1,u=0;i<9*l&&i<x*l;i++){
            p=trans(a[i]);
            qmult(t1, p, t1);
            if (!u){
                if (t1[0]==1&&t1[1]==2)
                    u=1;
            }
            else
                if (t1[0]==1&&t1[1]==4){
                    u=2;
                    break;
                }
        }
        if (u==2)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
