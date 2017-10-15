
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *train[10];
int N;
int count;

void readtrains(void) {
    int i;
    static char buff[200];
    scanf("%d",&N);
    for (i=0;i<N;i++) {
        if (train[i]) free(train[i]);
        scanf("%s",buff);
        train[i]=strdup(buff);
    }
}

void visit(char *car, int start, int visited, int last) {
    int b;
    int i;
    char *tmp;
    while (*car) {
        b=*car-'a';
        if ((b!=last) && (visited & (1<<b))) return;
        visited |= (1<<b);
        last=b;
        car++;
    }
    if (start==N) {count++;return;}
    for (i=start;i<N;i++) {
        tmp=train[start];train[start]=train[i];train[i]=tmp;
        visit(train[start],start+1,visited,last);
        tmp=train[start];train[start]=train[i];train[i]=tmp;        
    }
}

int main(int argc, char **argv) {
    int tc,i;
    scanf("%d",&tc);
    for (i=1;i<=tc;i++) {
        printf("Case #%d: ",i);
        count=0;
        readtrains();
        visit("",0,0,-1);
        printf("%d\n",count);
    }
    return 0;
}
