#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
long long int systemo(int base, int pos)
{
    return (long long int) (pow(base, pos) + 0.5);
} long long int divisor(long long int number)
{
    long long int i, kapa;
    kapa = (long long int) sqrt(number) + 0.5;
    for (i = 2; i <= kapa; i++) {
	if (number % i == 0)
	    return i;
     }
    return 1;
}

  int main()
{
    FILE * fp;
    FILE * fo;
    fo = fopen("outputa.txt", "w");
    fp = fopen("inputa.in", "r");
    int i, j, n, array[35], ja, sum, k;
    long long int total, answer[100], kapa;
    bool work = true;
    n = 16;
    ja = 50;
    for (i = 2; i <= n - 1; i++) {
	array[i] = 0;
    }
    array[n] = 1;
    array[1] = 1;
    sum = 1;
    fprintf(fo, "Case #");
    fprintf(fo, "%d", 1);
    fprintf(fo, ":");
    fprintf(fo, "\n");
    while (work) {
	total = 0;
	for (j = 2; j <= 10; j++) {
	    total = 0;
	    for (i = 1; i <= n; i++) {
		total = total + systemo(j, i - 1) * array[i];
	    }
	     answer[j] = divisor(total);
	     if (answer[j] == 1) {
		break;
	    }
	    if (j == 10)
		 {
		sum = sum + 1;
		fprintf(fo, " ");
		for (i = n; i >= 1; i--) {
		    fprintf(fo, "%d", array[i]);
		}
		fprintf(fo, " ");
		for (k = 2; k <= 10; k++) {
		    fprintf(fo, "%lld", answer[k]);
		    fprintf(fo, " ");
		}
		fprintf(fo, "\n");
		}
	}
	
//next
	    for (i = 2; i < n; i++) {
	    if (array[i] == 0) {
		array[i] = 1;
		break;
	    }
	    
	    else
		array[i] = 0;
	}
	 if (sum == ja + 1) {
	    work = false;
	}
    }
       return 1;
}

 
