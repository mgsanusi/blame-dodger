#include<stdio.h>
FILE * new_freopen(const char *filename, const char *mode, FILE *stream);

int main(){
	char g[300],gg[300];
	gets(g);
	new_freopen("AA", "r", stdin);
	int n;
	scanf("%d\n",&n);
	char j;
	for(j='a';j<='z';j++)
		gg[j]=g[j-'a'];
	int i;
	for(i=1;i<=n;i++){
		char buf[1000];
		gets(buf);
		int j;
		printf("Case #%d: ",i);
		for(j=0;buf[j];j++){
			if(buf[j]>='a' && buf[j]<='z')printf("%c",gg[buf[j]]);
			else printf("%c",buf[j]);
		}
		printf("\n");
	}
	return 0;
}

FILE * new_freopen(const char *filename, const char *mode, FILE *stream) {
  return freopen(filename, mode, stream);
}