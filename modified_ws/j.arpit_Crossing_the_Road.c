#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char buffer[1000], *bp;
int base[10];
int nb;
uint sqr(uint num)
{
	return (num * num);
}

int happy(uint num, int base)
{
	uint tnum = 0;
	uint count = 1000;
	while (num != 1 && count) {
		//      printf("%d ", num) ;
		tnum = 0;
		while (num) {
			tnum += sqr(num % base);
			num /= base;
		}
		num = tnum;
		--count;
	}
	//    printf("\n") ;
	return (num == 1);
}

int main()
{
	int T, t;
	int i, j;
	uint num;
	bool ishappy;
	gets(buffer);
	//    printf("%s\n", buffer) ;
	sscanf(buffer, "%d", &T);
	for (t = 1; t <= T; ++t) {
		gets(buffer);
		bp = buffer;
		for (nb = 0;;) {
			//      printf("---%s---", bp) ;
			base[nb] = strtol(bp, &bp, 10);
			if (base[nb] == 0)
				break;
			++nb;
			//      printf("%d ", base[nb - 1]) ;
		}
		//      printf("nb = %d\n", nb) ;
		//      printf("___\n") ;
		for (num = 2; num != 0; ++num) {
			//      printf("num = %d\n", num) ;
			ishappy = true;
			for (j = 0; j < nb; ++j) {
				//              printf("base %d\n", base[j]) ;
				if (!happy(num, base[j])) {
					ishappy = false;
					break;
				}
			}
			if (ishappy == true)
				break;
		}
		printf("Case #%d: %u\n", t, num);
	}
	return 0;
}
