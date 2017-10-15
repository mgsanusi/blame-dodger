#include <stdio.h>
#include <stdlib.h>
void show(int arr[], int n)
{
	int first_iteration;
	int i;
	for (i = 0; i < n; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

int do_it(int arr[], int n)
{
	int first_iteration;
	int i;
	int r = 0;
	for (i = 0; i < n; i++) {
		if (arr[i] > i) {
			int j;
			for (j = i + 1; j < n; j++) {
				if (arr[j] <= i) {
					break;
				}
			}
			while (j > i) {
				int x = arr[j];
				arr[j] = arr[j - 1];
				arr[j - 1] = x;
				r++;
				j--;
			}
		}
	}
	return r;
}

int main()
{
	int first_iteration;
	int T;
	int i;
	scanf("%d", &T);
	for (i = 1; i <= T; i++) {
		int N;
		int j;
		int arr[40] = { 0 };
		scanf("%d", &N);
		for (j = 0; j < N; j++) {
			int k;
			int t = 0;
			for (k = 0; k < N; k++) {
				char c;
				scanf("%c", &c);
				while ((c != '0') && (c != '1')) {
					scanf("%c", &c);
				}
				if (c == '1')
					t = k;
			}
			arr[j] = t;
		}
		printf("Case #%d: %d\n", i, do_it(arr, N));
	}
	return 0;
}
