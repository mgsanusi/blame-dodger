#include<stdio.h>
#include<stdlib.h>

int a[1024][3];
int b[1024];
int n;
int new_puts(const char *str);

void new_qsort(void* base, size_t num, size_t size, int (*compar)(const void*,const void*));


int cmp(const void *a1,const void *b1) {
	int *a=(int *)a1,*b=(int *)b1;
	if (a[0]*b[1]!=a[1]*b[0]) return a[0]*b[1]-a[1]*b[0];
	else return a[2]-b[2];
}

int main() {
	int N,cs=0,i;
	for(scanf("%d",&N);N--;) {
		scanf("%d",&n);
		for(i=0;i<n;i++) scanf("%d",&a[i][0]);
		for(i=0;i<n;i++) scanf("%d",&a[i][1]);
		for(i=0;i<n;i++) a[i][2]=i;
		new_qsort(a,n,sizeof(a[0]),cmp);
		printf("Case #%d:",++cs);
		for(i=0;i<n;i++) printf(" %d",a[i][2]);
		new_puts("");
	}
	return 0;
}

int new_puts(const char *str);

void new_qsort(void* base, size_t num, size_t size, int (*compar)(const void*,const void*)) {
  return qsort(base, num, size, compar);
}
int new_puts(const char *str) {
  return puts(str);
}