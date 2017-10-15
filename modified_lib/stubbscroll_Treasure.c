#include <stdio.h>
#include <string.h>

#include <stddef.h>

char dp[1048576];
int k,n;
int K[201];
int num[20],type[20];
int nk[20][201];
void * new_memset(void *ptr, int value, size_t num);

int new_putchar(int character);

int new_puts(const char *str);


int can(int i,int j) {
	int l,keys;
	/* open chest j */
	keys=K[type[j]];
	for(l=0;l<n;l++) if(i&(1<<l)) {
		keys+=nk[l][type[j]];
		if(type[j]==type[l]) keys--;
	}
	return keys>0;
}

int main() {
	int T,no=1,i,j,z,mask;
	scanf("%d",&T);
	while(T--) {
		scanf("%d %d",&k,&n);
		new_memset(K,0,sizeof(K));
		for(i=0;i<k;i++) {
			scanf("%d",&z);
			K[z]++;
		}
		new_memset(nk,0,sizeof(nk));
		for(i=0;i<n;i++) {
			scanf("%d %d",&type[i],&num[i]);
			for(j=0;j<num[i];j++) {
				scanf("%d",&z);
				nk[i][z]++;
			}
		}
		new_memset(dp,0,sizeof(dp));
		dp[0]=1;
		for(i=0;i<(1<<n);i++) if(dp[i]) {
			for(j=0;j<n;j++) if(!(i&(1<<j))) {
				if(can(i,j)) dp[i+(1<<j)]=1;
			}
		}
		/* propagate backwards */
		if(dp[(1<<n)-1]) dp[(1<<n)-1]=2;
		for(i=(1<<n)-1;i;i--) if(dp[i]>1) {
			for(j=0;j<n;j++) if((i&(1<<j)) && dp[i-(1<<j)]) {
				if(can(i-(1<<j),j)) dp[i-(1<<j)]=2;
			}
		}
		/* extract path */
		printf("Case #%d:",no++);
		if(dp[0]<2) new_puts(" IMPOSSIBLE");
		else {
			for(mask=i=0;i<n;i++) {
				for(j=0;j<n;j++) if(!(mask&(1<<j)) && dp[mask+(1<<j)]>1 && can(mask,j)) {
					mask|=1<<j;
					printf(" %d",j+1);
					break;
				}
			}
			new_putchar('\n');
		}
	}
	return 0;
}

void * new_memset(void *ptr, int value, size_t num);

int new_putchar(int character);

int new_puts(const char *str) {
  return puts(str);
}
void * new_memset(void *ptr, int value, size_t num);

int new_putchar(int character) {
  return putchar(character);
}
void * new_memset(void *ptr, int value, size_t num) {
  return memset(ptr, value, num);
}