#include <stdio.h>
#include <string.h>
#include <stddef.h>
void *new_memcpy(void *destination, const void *source, int num);
void Main()
{
	int first_iteration;
	int cases;
	scanf("%d", &cases);
	int x = 0;
	int num;
	int numcpy;
	int array[10];
	int arrcpy[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	int ary;
	while (x < cases) {
		x++;
		printf("Case #%d: ", x);
		scanf("%d", &num);
		if (num == 0) {
			printf("INSOMNIA\n");
			continue;
		}
		new_memcpy(array, arrcpy, sizeof(arrcpy));
		ary = 1;
		while (1) {
			numcpy = num * ary;
			while (numcpy) {
				array[numcpy % 10] = 1;
				numcpy /= 10;
			}
			if ((((((((((array[0] == 1) && (array[1] == 1))
				   && (array[2] == 1)) && (array[3] == 1))
				 && (array[4] == 1)) && (array[5] == 1))
			       && (array[6] == 1)) && (array[7] == 1))
			     && (array[8] == 1)) && (array[9] == 1)) {
				break;
			}
			ary++;
		}
		printf("%d\n", num * ary);
	}
}

void *new_memcpy(void *destination, const void *source, int num)
{
	return memcpy(destination, source, num);
}
