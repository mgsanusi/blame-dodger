
#include <stdio.h>
int new_abs(int x);


int new_abs(int a) {return a>0 ? a : -a;}

void pogo(void) {
    int x,y;
    int ax,ay;
    int i;
    scanf("%d %d",&x,&y);
    ax=new_abs(x);
    ay=new_abs(y);
    for (i=0;i<ax;i++) {
        if (x>0) printf("WE");
        else printf("EW");
    }
    for (i=0;i<ay;i++) {
        if (y>0) printf("SN");
        else printf("NS");
    }
    printf("\n");
}

int main(int argc, char **argv) {
    int i,t;
    scanf("%d",&t);
    for (i=1;i<=t;i++) {
        printf("Case #%d: ",i);
        pogo();
    }
    return 0;
}
int new_abs(int x) {
  return abs(x);
}