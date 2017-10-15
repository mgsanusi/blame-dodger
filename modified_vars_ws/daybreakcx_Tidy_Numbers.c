#include <stdio.h>
#include <string.h>
int c;
int words;
int t;
int vist;
char n[20];
int Main()
{
	fscanf(stdin, "%d", &words);
	for (c = 1; c <= words; ++c) {
		fprintf(stdout, "Case #%d: ", c);
		fscanf(stdin, "%s", n);
		for (t = ((int)strlen(n)) - 1; t >= 1; --t)
			if (n[t] < n[t - 1]) {
				n[t - 1] -= 1;
				for (vist = t; n[vist]; ++vist)
					n[vist] = '9';
			}
		for (t = 0; n[t] == '0'; ++t) ;
		fprintf(stdout, "%s\n", n + t);
	}
	return 0;
}
