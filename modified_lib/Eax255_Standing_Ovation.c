#include <stdio.h>
int main(){
	int T,Ti,n,i,c,r;
	char s[2000];
	scanf("%d",&T);
	for(Ti=1;Ti<=T;Ti++){
		scanf("%d",&n);
		scanf("%s",s);
		c=0;r=0;
		for(i=0;i<=n;i++){
			if(c<i)r+=i-c,c+=i-c;
			c+=s[i]-'0';
		}
        printf("Case #%d: %d\n",Ti,r);
	}
	return 0;
}
