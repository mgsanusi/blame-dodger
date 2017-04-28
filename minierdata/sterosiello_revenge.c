#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

int solve(char* seq)
{
	int res = 0;

	while(*seq)
	{
		if(*seq == '+')
		{
			char* p = seq;
			while(*p == '+')
			{
				*p = '-';
				p++;
				if(!(*p))
					return res;
			}
			if((*p))
				res++;
		} else {
			while(*seq == '-')
			{
				seq++;
				if(!(*seq))
					return res+1;
			}
			res++;
		}
	}

	return res;
}

int main(int argc, char* argv[])
{
	FILE* fin = fopen(argv[1], "r");
	FILE* fout = fopen("output", "w");

	int T;
	fscanf(fin, "%d", &T);

	int i;
	for(i = 1; i<= T; i++)
	{
		char sequence[150];
		fscanf(fin, "%s", sequence);
		int R = solve(sequence);
		fprintf(fout, "Case #%d: %d\n", i, R);
	}

	fclose(fin);
	fclose(fout);
	return 0;
}
