#include<stdio.h>
int L;
int map[4][4] = {{1,2,3,4},{2,-1,4,-3},{3,-4,-1,2},{4,3,-2,-1}};
int l[10000];
int get_int(){
	char c;
	while (c=getchar(),c<'0'||c>'9'){}
	int result = 0;
	while (c>='0'&&c<='9'){
		result = result*10+c-'0';
		c = getchar();
	}
	return result;
}
int get_longlong(){
	char c;
	while (c=getchar(),c<'0'||c>'9'){}
	long long result = 0;
	while (c>='0'&&c<='9'){
		result = result*10+c-'0';
		c = getchar();
	}
	return result;
}
int f(long long left, long long right){
	if (left == right) {
		return l[left%L];
	} else {
		long long mid = (left+right)/2;
		int left_val = f(left,mid);
		int right_val = f(mid+1,right);
		if (left_val>0&&right_val>0) {return map[left_val-1][right_val-1];}
		if (left_val>0&&right_val<0) {return (-1)*map[left_val-1][(-1)*right_val-1];}
		if (left_val<0&&right_val>0) {return (-1)*map[(-1)*left_val-1][right_val-1];}
		if (left_val<0&&right_val<0) {return map[(-1)*left_val-1][(-1)*right_val-1];}
	}
}
int main(){
	freopen("C.in","r",stdin);
	freopen("C.out","w",stdout);
	int i,j,t,T,ans,left,right,temp,len_i,len_k;
	long long X,len,index_i[10000],index_k[10000],iter;
	T = get_int();
	for (t=1;t<=T;t++){
		L = get_int();
		X = get_longlong();
		len = X*L;
		for (i=0;i<L;i++){
			l[i] = getchar()-'i'+2;
		}
		ans = 0;
		if (len>=3 && f(0,len-1)==-1) {
			temp = 1;
			len_i = 0;
			for (iter=0;iter<len;iter++) {
				if (temp > 0){
					temp = map[temp-1][l[iter%L]-1];
				} else {
					temp = (-1) * map[(-1)*temp-1][l[iter%L]-1];
				}
				if (temp == 2) {
					index_i[len_i++] = iter;
				}
			}
			temp = 1;
			len_k = 0;
			for (iter=len-1;iter>=0;iter--) {
				if (temp > 0){
					temp = map[l[iter%L]-1][temp-1];
				} else {
					temp = (-1) * map[l[iter%L]-1][(-1)*temp-1];
				}
				if (temp == 4) {
					index_k[len_k++] = iter;
				}
			}
			for (i=0;i<len_i;i++) {
				if (ans) break;
				for (j=0;j<len_k;j++){
					if (index_k[j]-index_i[i]>1) {
						if (f(index_i[i]+1,index_k[j]-1) == 3) {
							ans = 1;
							break;
						}
					}
				}
			}
		} else {
			ans = 0;
		}
		if (ans) printf("Case #%d: YES\n",t);
		else printf("Case #%d: NO\n",t);
	}
}