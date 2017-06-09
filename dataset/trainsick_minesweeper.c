
#include <stdio.h>
#include <stdlib.h>

#define WMAX 7
#define HMAX 5

#define W_BY_H_MAX 25

int W,H;


int *good[HMAX+1][WMAX+1];

int mine[HMAX][WMAX];
int neighbours[HMAX][WMAX];
int clicked[HMAX][WMAX];
int blankcount;
int blankfound;

int boardnum;

#define DBG_BRD 0

int min(int a, int b) { return a<b ? a : b;}
int max(int a, int b) { return a>b ? a : b;}

void countneighbours(void) {
    int x,y,n,xx,yy;
    for (y=0;y<H;y++) {
        for (x=0;x<W;x++) {
            n=0;
            //if (boardnum==DBG_BRD)
            //    printf("cn %d %d (m%d)\n",x,y,mine[y][x]);
            if (mine[y][x]) {neighbours[y][x]=-1; continue; }
            for (yy=max(0,y-1);yy<=min(H-1,y+1);yy++)
                for (xx=max(0,x-1);xx<=min(W-1,x+1);xx++) {
                    //if (boardnum==DBG_BRD)
                    //    printf("  %d %d\n",xx,yy);
                    n+=mine[yy][xx];
                }
            neighbours[y][x]=n;
        }
    }
}

void clearclicked(void) {
    int x,y;
    blankcount=0;
    for (y=0;y<H;y++) { 
        for (x=0;x<W;x++) { 
            clicked[y][x]=0;
            if (mine[y][x]==0) blankcount++;
        }
    }
}

int findzero(int *xx, int *yy) {
    int x,y,bx=-1,by=-1;
    for (y=0;y<H;y++) {
        for (x=0;x<W;x++) {
            if (neighbours[y][x]==0) {
                *xx=x;
                *yy=y;
                return 1;
            }
            if (!mine[y][x]) {bx=x;by=y;}
        }
    }
    if (bx>=0) {
        *xx=bx;*yy=by;
        return 1;
    }
    return 0;
}

void click(int x, int y) {
    int xx,yy;
    if (x<0 || x>=W) return;
    if (y<0 || y>=H) return;
    if (mine[y][x] || clicked[y][x]) return;
    blankfound++;
    clicked[y][x]=1;
    if (neighbours[y][x]!=0) return;
    for (yy=y-1;yy<=y+1;yy++)
        for (xx=x-1;xx<=x+1;xx++)
            click(xx,yy);
}

int increment(void) {
   int x,y;
   boardnum++;
   for (y=0;y<H;y++) {
        for (x=0;x<W;x++) {
            if (mine[y][x]) mine[y][x]=0;
            else {mine[y][x]=1; return 1; }
        }
    }
    return 0;
}

void clearboard(void) {
    int x,y;
    boardnum=0;
    for (y=0;y<H;y++) 
        for (x=0;x<W;x++)
            mine[y][x]=0;
}

void cleargood(void) {
    int i;
    int *g=malloc((W*H+1)*sizeof(int));
    for (i=0;i<=W*H;i++) g[i]=-1;
    good[H][W]=g;
}

void boardsize(int ww, int hh) {
    int sx,sy;
    W=ww;
    H=hh;
    clearboard();
    cleargood();
    do {
        blankfound=0;
        countneighbours();
        clearclicked();
        if (good[H][W][blankcount]!=-1) continue;
        if (findzero(&sx,&sy)) {
            click(sx,sy);
            if (blankfound==blankcount) {
                good[H][W][blankcount]=boardnum;
            }
        }
    } while (increment());
    
    /*
    printf("%d X %d\n",W,H);
    for (i=0;i<=H*W;i++) {
        if (good[i]) printf("%d %x\n",i,goodboard[i]);
    }
    printf("\n");
    return 0;
    */
}

void drawboard(void) {
    int x,y;
    char *m="c.*";
    for (y=0;y<H;y++) { 
        for (x=0;x<W;x++) {
            putchar(m[mine[y][x]+1]);
        }
        putchar('\n');
    }
}

void drawtransposed(void) {
    int x,y;
    char *m="c.*";
    for (x=0;x<W;x++) {
        for (y=0;y<H;y++) { 
            putchar(m[mine[y][x]+1]);
        }
        putchar('\n');
    }
}

void fillin(int bits) {
    int y,x;
    for (y=0;y<H;y++) {
        for (x=0;x<W;x++) {
            mine[y][x]=bits & 1;
            bits>>=1;
        }
    }
}


void printboard(int w, int h, int blank) {
    int transpose=0,t;
    int sx,sy;
    if (w<h) {transpose=1;t=w;w=h;h=t;}
    W=w;H=h;
    if (w>WMAX || h>HMAX || good[h][w]==NULL) {
        printf("TOO BIG!\n");
        return;
    }
    if (good[h][w][blank]==-1) {
        printf("Impossible\n");
        return;
    }
    fillin(good[h][w][blank]);
    findzero(&sx,&sy);
    mine[sy][sx]=-1;
    if (transpose) drawtransposed();
    else drawboard();
}

int main(int argc, char **argv) {
    int ww,hh,mines,blanks;
    int tc,casenum;
    for (ww=1;ww<=WMAX;ww++) {
        for (hh=1;hh<=ww;hh++) {
            if (ww*hh<=W_BY_H_MAX)
                boardsize(ww,hh);
        }
    }
    scanf("%d",&tc);
    for (casenum=1;casenum<=tc;casenum++) {
        printf("Case #%d:\n",casenum);
        scanf("%d %d %d",&hh, &ww, &mines);
        blanks=ww*hh-mines;
        printboard(ww,hh,blanks);
    }
    return 0;
}
