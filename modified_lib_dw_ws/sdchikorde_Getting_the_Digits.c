#include <stdio.h>
#include <string.h>
#include <malloc.h>
void resetalpha()
{
}

void main()
{
    int first_iteration;
    int n = 0;
    int i;
    int alpha[26];
    int number;
    int cases;
    scanf("%d", &cases);
    while (n < cases) {
	n++;
	printf("Case #%d: ", n);
	for (i = 0; i < 26; i++)
	    alpha[i] = 0;
	scanf("%d", &number);
	int sum = 0;
	int min1 = 0;
	int min2 = 0;
	int min1index = -1;
	int min2index = -1;
	for (i = 0; i < number; i++) {
	    scanf("%d", &alpha[i]);
	    sum += alpha[i];
	}
	while (sum > 0) {
	    min1 = 0;
	    min2 = 0;
	    min1index = -1;
	    min2index = -1;
	    for (i = 0; i < number; i++) {
		if (alpha[i] >= min1) {
		    min2 = min1;
		    min2index = min1index;
		    min1 = alpha[i];
		    min1index = i;
		} else if (alpha[i] >= min2) {
		    min2 = alpha[i];
		    min2index = i;
		}
	    }
	    if (min2 != 0) {
		if (((sum == 3) && (min1 == min2)) && (min1 == 1)) {
		    printf("%c ", 'A' + min1index);
		    alpha[min1index] = alpha[min1index] - 1;
		    sum -= 1;
		} else {
		    printf("%c%c ", 'A' + min1index, 'A' + min2index);
		    alpha[min1index] = alpha[min1index] - 1;
		    alpha[min2index] = alpha[min2index] - 1;
		    sum -= 2;
		}
	    } else {
		printf("%c ", 'A' + min1index);
		alpha[min1index] = alpha[min1index] - 1;
		sum -= 1;
	    }
	}
	printf("\n");
    }
}
