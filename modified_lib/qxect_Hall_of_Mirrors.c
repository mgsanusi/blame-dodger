#include<stdio.h>
#include<string.h>

int arr[3000000],bak[3000000];
int num[50];

int min(int a,int b){
	if(a<b)return a;
	return b;
}

void print_ans(int now){
	if(bak[now]){
		 print_ans(bak[now]);
		 printf(" ");
	}
	printf("%d",now-bak[now]);
	
}

int main()
{
	int tn;
	int n;
	
	int i,j,k;
	
	int total;
	int ans;
	
	scanf("%d",&tn);
	
	for(k=1;k<=tn;k++){
		memset(arr,0,sizeof(arr));
		scanf("%d",&n);
		for(i=0;i<n;i++)scanf("%d",&num[i]);
		arr[0] = 1;
		total = 0;
		ans = 0;
		printf("Case #%d:\n",k);
		for(i=0;ans==0 && i<n;i++){
			for(j=total;ans==0 && j>=0;j--){
				if(arr[j] && j+num[i]<3000000){
					if(arr[j+num[i]]){
						print_ans(j+num[i]);
						printf("\n");
						bak[j+num[i]] = j;
						print_ans(j+num[i]);
						printf("\n");
						ans = 1;
						break;
					}
					
					arr[j+num[i]] = 1;
					bak[j+num[i]] = j;
				}
			}
			total += num[i];
			total = min(3000000,total);
		}
		
		if(!ans)printf("Impossible\n");
		
	}
	return 0;
}
