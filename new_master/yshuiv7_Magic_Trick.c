#include<stdio.h>
int main(){
	int cases;
	scanf("%d", &cases);
	int p, map;
	for(p=1; p<=cases; p++){
		int a1;
		scanf("%d", &a1);
		int i,j;
		map=0;
		for(i=0; i<4; i++)
		for(j=0; j<4; j++){
			int tmp;
			scanf("%d", &tmp);
			if(i!=a1-1)
				continue;
			map |= (1<<(tmp-1));
		}
		scanf("%d", &a1);
		int ans, ansc=0;
		for(i=0; i<4; i++)
		for(j=0; j<4; j++){
			int tmp;
			scanf("%d", &tmp);
			if(i!=a1-1)
				continue;
			int res = (map>>(tmp-1))&1;
			ansc+=res;
			if(res)
				ans=tmp;
		}
		printf("Case #%d: ", p);
		if(ansc > 1)
			printf("Bad magician!\n");
		else if(ansc == 0)
			printf("Volunteer cheated!\n");
		else
			printf("%d\n", ans);
	}
	return 0;
}




