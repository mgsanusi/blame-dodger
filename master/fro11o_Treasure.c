#include <stdio.h>

double r, t;

double search(double left, double right) {
	//printf("%lf %lf\n", left, right);
	if(left - right < 1e-3 && left - right > -1e-3)
		return left;
	double mid = (double)((int)((left + right + 1) / 2));
	//printf("%lf\n", mid);
	if(mid * (2 * mid + 2 * r - 1) - t < 1e-3 && mid * (2 * mid + 2 * r - 1) - t > -1e-3)
		return mid;
	else if(mid * (2 * mid + 2 * r - 1) > t)
		return search((double)((long long int)left), (double)((long long int)mid - 1));
	else
		return search((double)((long long int)mid), (double)((long long int)right));
}

int main() {
	int T, i;
	long long int y;
	scanf("%d", &T);
	for(i = 0; i < T; i++) {
		scanf("%lf %lf", &r, &t);
		y = (long long int)search(0, 1000000000);
		printf("Case #%d: %lld\n", i + 1, y);
	}
	return 0;
}
