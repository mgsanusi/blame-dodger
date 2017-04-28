#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>


uint64_t counting(uint64_t n)
{
	if(!n)
		return 0;

	char hist[10];
	uint64_t i = 1;

	for(i = 0; i<10; i++)
		hist[i] = 0;

	i = 1;

	while(1)
	{
		char num[100];
		uint64_t value = n*i;

		sprintf(num, "%llu", value);
		char *p = num;
		while(*p)
		{
			hist[*p - '0']++;
			p++;
		}

		int j;
		int found = 1;
		for (j = 0; j < 10; j++)
			if(!hist[j]){
				found = 0;
				break;
			}

		if(found)
			return value;
		i++;
	}

	return 0;
}

int main(int argc, char* argv[])
{
	FILE* fin = fopen(argv[1], "r");
	FILE* fout = fopen("output", "w");

	uint64_t T;
	fscanf(fin, "%llu", &T);

	int i;
	for(i = 1; i<= T; i++)
	{
		uint64_t N, R;
		fscanf(fin, "%llu", &N);

		R = counting(N);

		if(R)
			fprintf(fout, "Case #%d: %llu\n", i, R);
		else
			fprintf(fout, "Case #%d: INSOMNIA\n", i);
	}

	fclose(fin);
	fclose(fout);
	return 0;
}
