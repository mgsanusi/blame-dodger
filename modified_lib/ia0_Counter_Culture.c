#include <assert.h>
#include <stdio.h>


void new_assert(int expression);
static int solve(int R, int C, int W)
{
	int a = W + (C != W);
	int b = R * (C / W) + W - !(C % W);
	return a > b ? a : b;
}

int main(void) {
	int T_;
	new_assert(scanf("%d", &T_) == 1);
	for (int t_ = 1; t_ <= T_; t_++) {
		int R, C, W;
		new_assert(scanf("%d %d %d", &R, &C, &W) == 3);
		printf("Case #%d: %d\n", t_, solve(R, C, W));
	}
	return 0;
}

void new_assert(int expression) {
  return assert(expression);
}