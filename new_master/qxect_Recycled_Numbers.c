#include<stdio.h>
#include<string.h>
#include<math.h>
double judge[300];
double rat[300];
double min(double a,double b){
	if(a<b)return a;
	return b;
}
int main()
{
	int tn,n;
	
	int i,j,k;
	int t;
	int min_t;
	int cnt;
	
	double l,r,mid;
	double sum,sum2,sum3;
	double my_score,you_score,min_score;
	double tt;
	double ans;
	scanf("%d",&tn);
	
	for(k=1;k<=tn;k++){
		scanf("%d",&n);
		sum = 0;
		for(i=0;i<n;i++){
			scanf("%lf",&judge[i]);
			sum += judge[i];
			
		}
		sum2 = sum*2.0;
		sum2 = sum2/n;
		cnt = 0;
		tt = 0;
		for(i=0;i<n;i++){
			if(fabs(judge[i]-sum2)>1e-6 && sum2 > judge[i]){
				cnt++;
			}else {
				tt += judge[i];
			}
		}
		/*printf("cnt %d\n",cnt);*/
		sum3 = sum*2.0-tt;
		sum3 = sum3/cnt;
		/*printf("sum2 %lf\n",sum2);
		*/
		for(i=0;i<n;i++){
		
			if(fabs(judge[i]-sum2)<1e-6 || judge[i]>sum2){
				
				rat[i] = 0.0;
				continue;
			}
			ans = sum3-judge[i];
			ans /= sum;
			/*printf("i %d: sum2 %lf\n",i,ans);
		*/
			
			rat[i] = ans*100.0;
			if(rat[i]<0)rat[i]=0.0;
			if(rat[i]>100)rat[i] = 100.0;
		}
		
		
		printf("Case #%d:",k);
		for(i=0;i<n;i++)printf(" %lf",rat[i]+1e-7);
		printf("\n");
	}
	
	return 0;
}
