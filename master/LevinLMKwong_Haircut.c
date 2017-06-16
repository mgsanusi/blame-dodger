#include<stdio.h>
#include<string.h>
long long gcd(long long a, long long b){
	while(a!=b)
    {
        if(a>b)
            a-=b;
        else
            b-=a;
    }
	return a;
}
int main(){
	freopen("B.in", "r", stdin);
	freopen("B.out", "w", stdout);
	int i,j,t,T,B,N,m[1000],c[1000],min,ans;
	long long lcm, m_gcd, loop;
	scanf("%d",&T);
	for (t=1;t<=T;t++){
		scanf("%d %d",&B,&N);
		for (i=0;i<B;i++) {scanf("%d",&m[i]);}
		m_gcd = m[0];
		lcm = m[0];
		for (i=1;i<B;i++) {
			m_gcd = gcd(lcm,m[i]);
			lcm = lcm * m[i] / m_gcd;
		}
		loop = 0;
		for (i=0;i<B;i++) {loop+=lcm/m[i];}
		N = (N-1) % loop;
		memset(c,0,sizeof(c));
		ans = 0;
		for (i=0;i<=N;i++) {
			min = 0x3f3f3f3f;
			for (j=0;j<B;j++){
				if(c[j] < min){
					min = c[j];
					ans = j;
				}
			}
			for (j=0;j<B;j++){
				if(j == ans){
					c[j]=m[j];
				} else {
					c[j]-=min;
				}
			}
		}
		printf("Case #%d: %d\n",t,(ans+1));
	}
}