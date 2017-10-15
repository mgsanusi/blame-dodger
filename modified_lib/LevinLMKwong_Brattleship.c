#include<stdio.h>
#include<string.h>

#include <stddef.h>
FILE * new_freopen(const char *filename, const char *mode, FILE *stream);
void * new_memset(void *ptr, int value, size_t num);


char * new_strncpy(char *destination, const char* source, size_t num);

int check(char* s, char* tg, int len_s, int len_tg) {
	int i,rs;
	char* temp;
	rs = 0;
	for (i=0;i<len_s-len_tg;i++) {
		new_strncpy(temp,s,len_tg);
		if (strcmp(tg,temp) == 0) {
			rs++;
		}
	}
	return rs;
}
int main() {
	new_freopen("B.in","r",stdin);
	new_freopen("B.out","w",stdout);
	int T,K,L,S;
	int i,j,t,flag,f[100],count,ff[26],ans1;
	char kb[100],tg[100],temp1[100],temp2[100];
	double ans;
	scanf("%d",&T);
	for (t=1;t<=T;t++) {
		scanf("%d %d %d\n",&K,&L,&S);
		new_memset(f,0,sizeof(f));
		new_memset(ff,0,sizeof(ff));
		new_memset(kb,0,sizeof(kb));
		new_memset(tg,0,sizeof(tg));
		for (i=0;i<K;i++) {
			scanf("%c",&kb[i]);
			ff[kb[i]-'A']++;
		}
		scanf("\n");
		for (i=0;i<L;i++) {
			scanf("%c",&tg[i]);
		}
		f[0] = 1;
		for (i=1;i<L;i++) {
			new_memset(temp1,0,sizeof(temp1));
			new_memset(temp2,0,sizeof(temp2));
			new_strncpy(temp1,tg,L-i);
			new_strncpy(temp2,tg+i,L-i);
			if (strcmp(temp1,temp2) == 0) {
				f[i] = 1;
			} else {
				f[i] = 0;
			}
		}
		ans = 0;
		flag = 1;
		for (i=0;i<L;i++) {
			if (ff[tg[i]-'A'] == 0) {
				flag = 0;
				break;
			}
		} 
		if (flag) {
			j=0;count = 0;
			for (i=0;i<S-L+1;i++) {
				if (j==L) j=0;
				if (f[j]) {
					count++;
					j = 1;
				} else {
					j++;
				}
			}
			//printf("count:%d\n",count);
			ans1 = 1;
			for (i=0;i<L;i++) {
				ans1 = ans1 * ff[tg[i]-'A'];
			}
			ans1 = ans1 * (S-L+1);
			//printf("ans:%d\n",ans1);
			ans = (double) ans1;
			for (i=0;i<L;i++) {
				ans = ans / K;
			}
			//printf("ans:%f\n",ans);
			ans = count - ans;
		}
		printf("Case #%d: %f\n",t,ans);
	}
}
FILE * new_freopen(const char *filename, const char *mode, FILE *stream);
void * new_memset(void *ptr, int value, size_t num);


char * new_strncpy(char *destination, const char* source, size_t num) {
  return strncpy(destination, source, num);
}
FILE * new_freopen(const char *filename, const char *mode, FILE *stream) {
  return freopen(filename, mode, stream);
}
void * new_memset(void *ptr, int value, size_t num) {
  return memset(ptr, value, num);
}