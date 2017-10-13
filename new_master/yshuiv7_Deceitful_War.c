#include<stdio.h>
#include <string.h>
double n[1000],k[1000];
int cmp(const void *a, const void *b){
	double x = *(const double *)a;
	double y = *(const double *)b;
	return x>y ? 1 : (x<y ? -1 : 0);
}
int d[1000];
int flag[1000], match[1000];
int ans;
int bimatch(int k){
	int i;
	for(i=d[k]; i>=0; i--){
		if(flag[i])
			continue;
		flag[i] = 1;
		if(match[i] == -1 || bimatch(match[i])){
			match[i] = k;
			return 1;
		}
	}
	return 0;
}

int main(){
	int cases,p;
	scanf("%d", &cases);
	for(p=1; p<=cases; p++){
		int m;
		scanf("%d", &m);
		int i;
		for(i=0; i<m; i++)
			scanf("%lf", n+i);
		for(i=0; i<m; i++)
			scanf("%lf", k+i);
		int ln, lk, rn, rk;
		ln=lk=0;
		rn=rk=m-1;
		qsort(n, m, sizeof(double), cmp);
		qsort(k, m, sizeof(double), cmp);
		int j=0;
		memset(match, 255, sizeof(match));
		for(i=0; i<m; i++){
			while(k[j] < n[i] && j<m)
				j++;
			d[i] = j-1;
		}
		ans = 0;
		for(i=0; i<m; i++){
			memset(flag, 0, sizeof(flag));
			if(bimatch(i))
				ans++;
		}
		int ans2=0;
		memset(flag, 0, sizeof(flag));
		for(i=0; i<m; i++){
			j = d[i]+1;
			for(;j<m;j++)
				if(!flag[j])
					break;
			if(j<m) {
				//printf("%lf(N) < %lf(K)\n", n[i], k[j]);
				flag[j]=1;
			}else{
				//printf("%lf(N) > %lf(K)\n", n[i], k[lk]);
				ans2++;
				flag[lk]=1;
				lk++;
			}
		}
		printf("Case #%d: %d %d\n", p, ans, ans2);
	}
	return 0;
}

