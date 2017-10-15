#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
 int TC, T;
long long int Groups;
long long int Start[10];
long long int Hikers[10];
long long int Time[10];
long long int i, x, y, Ans, Key;
FILE *new_freopen(const char *filename, const char *mode, FILE * stream);
int new_puts(const char *str);
 int main()
{
	new_freopen("C-small-1-attempt2.in", "r", stdin);
	new_freopen("C-small-1-attempt2.out", "w", stdout);
	 scanf("%d", &TC);
	for (T = 1; T <= TC; T++) {
		printf("Case #%d: ", T);
		scanf("%lld", &Groups);
		for (i = 0; i < Groups; i++)
			scanf("%lld%lld%lld", &Start[i], &Hikers[i], &Time[i]);
		 if (Groups == 1)
			if (Hikers[0] == 1) {
				new_puts("0");
				continue;
			}
		 if (Groups == 1)
			if (Hikers[0] == 2) {
				if ((360 - Start[0]) * (Time[0] + 1) <
				     (720 - Start[0]) * (Time[0]))
					new_puts("0");
				
				else
					new_puts("1");
				continue;
			}
		 if (Start[0] > Start[1]) {
			Key = Start[0];
			Start[0] = Start[1];
			Start[1] = Key;
			Key = Time[0];
			Time[0] = Time[1];
			Time[1] = Key;
		}
		 if (Time[0] >= Time[1]) {
			if ((360 - Start[0]) * (Time[0]) <
			     (720 - Start[1]) * (Time[1]))
				new_puts("0");
			
			else
				new_puts("1");
		}
		if (Time[0] < Time[1]) {
			if ((360 - Start[1]) * (Time[1]) <
			     (720 - Start[0]) * (Time[0]))
				new_puts("0");
			
			else
				new_puts("1");
		}
	 }
	 return 0;
}

 FILE * new_freopen(const char *filename, const char *mode, FILE * stream);
int new_puts(const char *str)
{
	return puts(str);
}

FILE *new_freopen(const char *filename, const char *mode, FILE * stream)
{
	return freopen(filename, mode, stream);
}
