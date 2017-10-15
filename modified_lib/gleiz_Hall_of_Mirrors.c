#include <stdio.h>
#include <stdlib.h>
#include <string.h>

double sum[100010];
double pro[100010];
int main(int argc, char* argv[]){
	int T = 0;
	int A = 0, B = 0;

	scanf("%d", &T);
	for (int cas = 1; cas <= T; cas++){
		scanf("%d %d", &A, &B);
		memset(sum, 0, sizeof(sum));
		sum[0] = 1;
		for (int i = 0; i<A; i++){
			scanf("%lf", &pro[i]);
			sum[i+1] = pro[i] * sum[i];
		}


		double res = 99999999.0;
		for (int step = 0; step<=A; step++){
			int num = step + B - (A - step) + 1;
			double p = sum[A-step];
			double k = num * p + (num + B + 1) * (1-p);
			if (k < res){
				res = k;
			}
		}

		if (2 + B < res)
			res = 2 + B;

		printf("Case #%d: %.6lf\n", cas, res);
	}
	return 0;
}
