#include <stdio.h>
#include <stdlib.h>

typedef struct {
  char ch;
  int pos;
} point;

point P[100];
int new_abs(int x);


int time_needed(int pos, int time, int dest) {

  if(new_abs(dest-pos)<time)
    return 0;
  else
    return (new_abs(dest-pos) - time);

}

int main() {

  int T, N;
  int i, op, bp, ot, bt, casenum = 0;
  scanf("%d", &T);
  
  while(T--) {
    casenum++;
    op = 1;
    bp = 1;
    ot = 0;
    bt = 0;
    scanf("%d", &N);
    int total_time = 0;
    for(i=0; i<N; i++) {
      P[i].ch = ' ';
      while(P[i].ch == ' ')
	scanf("%c", &P[i].ch);
      scanf("%d", &P[i].pos);
    }
    
    for(i=0; i<N; i++) {
      if(P[i].ch=='O') {
	int t = time_needed(op, ot, P[i].pos)+1;
	op = P[i].pos;
	bt+=t;
	total_time+=t;
	ot = 0;
      }
      else {
	int t = time_needed(bp, bt, P[i].pos)+1;
	bp = P[i].pos;
	ot+=t;
	total_time+=t;
	bt = 0;
      }
    }
    printf("Case #%d: %d\n", casenum, total_time);

  }

}

int new_abs(int x) {
  return abs(x);
}