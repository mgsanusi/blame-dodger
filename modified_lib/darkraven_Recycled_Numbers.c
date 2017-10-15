int pot[10];
int shift(int c, int len){
	int tmp=c%10;
	return tmp*pot[len-1]+c/10;
}
inline int charify(int n, int *c){
	int tc=n;
	int l=0;
	for(;n;n/=10)l++;
	int tl=l;
	for(;tc;tc/=10)c[--l]=tc%10;
	return tl;
}
int gg[100];
int get(int n,int a,int b){
	int l=charify(n, gg);
	int p1;
/*	for(p1=1;p1<l;){
		int p0=0;
		if(gg[p1]==0){
			p1++;
			continue;
		}
		while(gg[p1] == gg[p0]){
			p1++;
			p0++;
			if(p0 >= l)break;
		}
		if(gg[p1]<gg[p0] && p0<l){
			printf("%d\n",n);
			return 0;
		}
		p1++;
	}*/
	int tn=n;
	int ans=0;
	for(p1=l-1;p1>=0;p1--){
		tn=shift(tn,l);
		if(tn==n)break;
		if(tn>=a && tn<=b){
		//	printf("%d %d\n",n,tn);
			if(tn<n)return 0;
			ans++;
		}
	}
	return ans*(ans+1)/2;
}
int main(){
	pot[0]=1;
	int i;
	for(i=1;i<10;i++)pot[i]=pot[i-1]*10;
	int t;
	scanf("%d",&t);
	for(i=1;i<=t;i++){
		printf("Case #%d: ", i);
		int a,b;
		scanf("%d%d",&a,&b);
		int j;
		int ans=0;
		for(j=a;j<=b;j++)ans+=get(j,a,b);
		printf("%d\n",ans);
	}
	return 0;
}
