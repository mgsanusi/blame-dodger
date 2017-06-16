double h[201];
struct sortt{
	int id;
	double v;
}hs[201];
int sc[201];
int cmp(const void *a, const void *b){
	double aa = ((struct sortt *)a)->v, bb = ((struct sortt *)b)->v;
	if(aa>bb)return -1;
	else if (aa<bb)return 1;
	return 0;
}
int main(){
	int t,p;
	scanf("%d", &t);
	for(p=1;p<=t;p++){
		int n;
		scanf("%d", &n);
		int i,x=0;
		for(i=0;i<n;i++){
			scanf("%d",sc+i);
			x+=sc[i];
		}
		printf("Case #%d: ", p);
		for(i=0;i<n;i++){
			h[i]=(double)sc[i]/(double)x;
			hs[i].id = i;
			hs[i].v = h[i];
		}
		qsort(hs, n, sizeof(struct sortt), cmp);
		for(i=0;i<n;i++){
			int j;
			double v=2.0;
			for(j=0;j<n;j++){
				if(v/(double)(n-j)>=hs[j].v)break;
				v-=hs[j].v;
			}
			double ans = v/(double)(n-j)-h[i];
			printf("%lf ", ans>0?ans*100.0 : 0.0);
		}
		printf("\n");
	}
	return 0;
}

