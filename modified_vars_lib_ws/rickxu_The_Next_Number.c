#include <stdio.h>
#include <stdlib.h>
void read(int array[], int n)
{
	int i;
	for (i = 0; i < n; i++)
		printf("%d ", array[i]);
	printf("\n");
}

int makeIt(int array[], int n)
{
	int i;
	int in = 0;
	for (i = 0; i < n; i++) {
		if (array[i] > i) {
			int frequency;
			for (frequency = i + 1; frequency < n; frequency++) {
				if (array[frequency] <= i) {
					break;
				}
			}
			while (frequency > i) {
				int a = array[frequency];
				array[frequency] = array[frequency - 1];
				array[frequency - 1] = a;
				in++;
				frequency--;
			}
		}
	}
	return in;
}

int Main()
{
	int b;
	int i;
	scanf("%d", &b);
	for (i = 1; i <= b; i++) {
		int max;
		int frequency;
		int array[40] = { 0 };
		scanf("%d", &max);
		for (frequency = 0; frequency < max; frequency++) {
			int ar;
			int l = 0;
			for (ar = 0; ar < max; ar++) {
				char c;
				scanf("%c", &c);
				while ((c != '0') && (c != '1')) {
					scanf("%c", &c);
				}
				if (c == '1')
					l = ar;
			}
			array[frequency] = l;
		}
		printf("Case #%d: %d\n", i, makeIt(array, max));
	}
	return 0;
}
