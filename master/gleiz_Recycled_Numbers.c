#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int tens[32] = {0};
int label[3000000] = {0};

int getnum(int x){
	int ret = 0;
	while (x){
		ret++;
		x/=10;
	}
	return ret;
}

int main(int argc, char* argv[]){
	int T = 0;
	int A = 0, B = 0;

	tens[0] = 1;
	for (int i = 1; i<=12; i++){
		tens[i] = tens[i-1] * 10;
	}
	
	scanf("%d", &T);

	for (int cas = 1; cas <= T; cas++){
		scanf("%d %d", &A, &B);

		memset(label, -1, sizeof(label));
		int res = 0;
		for (int i = A; i <= B; i++){
			int num = getnum(i);
			int x = i;
			for (int j = 0; j<num; j++){
				x = x / tens[num-1] + x % tens[num-1] * 10;			  
				if (x<i && x>=A && x<=B && x/tens[num-1] != 0){
					if (label[x] != i){
						label[x] = i;
						res++;
					}
				}
			}
		}

		printf("Case #%d: %d\n", cas, res);
	}
	return 0;
}
