#include<stdio.h>
#include<stdlib.h>

#define MAX(x,y) (((x)<(y))?(y):(x))
#define MIN(x,y) (((x)>(y))?(y):(x))

struct sec{
  int l,r,size;
};

void solve(int casenum);
void add_heap(struct sec *array, int n, struct sec new);
struct sec pop_heaproot(struct sec *array, int n);
int comp(struct sec a,struct sec b);

int main(void){
  int T,i;
  scanf("%d",&T);
  for(i=1;i<=T;i++) solve(i);
  return 0;
}

void solve(int casenum){
  struct sec *Q,get,in[2],*freep;
  int Qn;
  int i,j,N,K,ls,rs;
  scanf("%d%d",&N,&K);
  if(N==K){
    printf("Case #%d: %d %d\n",casenum,0,0);
    return;
  }
  freep=Q=(struct sec *)calloc(1000000,sizeof(struct sec));
  //puts("calloc success");
  for(i=1;i<=N;i++) Q[i]=(struct sec){0,0,0};
  Q[0]=(struct sec){1,N,N-1+1};
  Qn=1;
  for(i=0;i<K;i++){
    get=pop_heaproot(Q,Qn--);
    //printf("get=%d,%d,%d\n",get.l,get.r,get.size);
    in[0]=(struct sec){get.l,(get.l+get.r)/2-1,(get.l+get.r)/2-get.l};
    //printf("\tin0=%d,%d,%d\n",in[0].l,in[0].r,in[0].size);
    in[1]=(struct sec){(get.l+get.r)/2+1,get.r,get.r-(get.l+get.r)/2};
    //printf("\tin1=%d,%d,%d\n",in[1].l,in[1].r,in[1].size);
    if(in[0].l>0 && in[0].r>=in[0].l && in[0].size>0) add_heap(Q,Qn++,in[0]);
    if(in[1].l>0 && in[1].r>=in[1].l && in[1].size>0) add_heap(Q,Qn++,in[1]);
    //for(j=0;j<Qn;j++) printf("%s%d%c",j==0?"Q:":"",Q[j].size,j==Qn-1?'\n':' ');
  }
  ls=(get.l+get.r)/2-get.l;
  rs=get.r-(get.l+get.r)/2; 
  printf("Case #%d: %d %d\n",casenum,MAX(ls,rs),MIN(ls,rs));
  free(freep);
}

int comp(struct sec a,struct sec b){
  if(a.size>b.size) return 1;
  if(a.size<b.size) return -1;
  if(a.l<b.l) return 1;
  return -1;
}

void add_heap(struct sec *array, int n, struct sec new) {
  struct sec swaps;
  int i, next, tmp;

  array[n] = new;

  for(i = n; i > 0; i = (i - 1) / 2) {
    if(comp(array[(i-1)/2],array[i])==-1){
      swaps = array[i];
      array[i] = array[(i - 1) / 2];
      array[(i - 1) / 2] = swaps;
    } else break;
  }
}

struct sec pop_heaproot(struct sec *array, int n) {
  struct sec ret, swaps;
  int i, next, tmp;
  ret = array[0];
  array[0] = array[n - 1];

  for(i = 0; 2 * i < n - 2; i = next) {
    if(2 * i + 2 < n - 1 && comp(array[2*i+2],array[2*i+1])==1) next = 2 * i + 2;
    else next = 2 * i + 1;
    if(comp(array[next],array[i])==1) {
      swaps = array[i];
      array[i] = array[next];
      array[next] = swaps;
    } else break;
  }
  return ret;
}

