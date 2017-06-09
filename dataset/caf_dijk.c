#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

enum {
	Q_1,
	Q_NEG_1,
	Q_I,
	Q_NEG_I,
	Q_J,
	Q_NEG_J,
	Q_K,
	Q_NEG_K
};

typedef unsigned char q_type;

const q_type input_lookup[256] = {
	['i'] = Q_I,
	['I'] = Q_I,
	['j'] = Q_J,
	['J'] = Q_J,
	['k'] = Q_K,
	['K'] = Q_K,
};

const q_type q_mult[8][8] = {
	[Q_1] = { 
		[Q_1] = Q_1, 
		[Q_NEG_1] = Q_NEG_1, 
		[Q_I] = Q_I, 
		[Q_NEG_I] = Q_NEG_I, 
		[Q_J] = Q_J,
		[Q_NEG_J] = Q_NEG_J,
		[Q_K] = Q_K,
		[Q_NEG_K] = Q_NEG_K },
	[Q_NEG_1] = {
		[Q_1] = Q_NEG_1, 
		[Q_NEG_1] = Q_1, 
		[Q_I] = Q_NEG_I, 
		[Q_NEG_I] = Q_I, 
		[Q_J] = Q_NEG_J,
		[Q_NEG_J] = Q_J,
		[Q_K] = Q_NEG_K,
		[Q_NEG_K] =  Q_K},
	[Q_I] = {
		[Q_1] = Q_I, 
		[Q_NEG_1] = Q_NEG_I, 
		[Q_I] = Q_NEG_1, 
		[Q_NEG_I] = Q_1, 
		[Q_J] = Q_K,
		[Q_NEG_J] = Q_NEG_K,
		[Q_K] = Q_NEG_J,
		[Q_NEG_K] = Q_J },
	[Q_NEG_I] = {
		[Q_1] = Q_NEG_I, 
		[Q_NEG_1] = Q_I, 
		[Q_I] = Q_1, 
		[Q_NEG_I] = Q_NEG_1, 
		[Q_J] = Q_NEG_K,
		[Q_NEG_J] = Q_K,
		[Q_K] = Q_J,
		[Q_NEG_K] = Q_NEG_J },
	[Q_J] = {
		[Q_1] = Q_J, 
		[Q_NEG_1] = Q_NEG_J, 
		[Q_I] = Q_NEG_K, 
		[Q_NEG_I] = Q_K, 
		[Q_J] = Q_NEG_1,
		[Q_NEG_J] = Q_1,
		[Q_K] = Q_I,
		[Q_NEG_K] = Q_NEG_I },
	[Q_NEG_J] = {
		[Q_1] = Q_NEG_J, 
		[Q_NEG_1] = Q_J, 
		[Q_I] = Q_K, 
		[Q_NEG_I] = Q_NEG_K, 
		[Q_J] = Q_1,
		[Q_NEG_J] = Q_NEG_1,
		[Q_K] = Q_NEG_I,
		[Q_NEG_K] = Q_I },
	[Q_K] = {
		[Q_1] = Q_K, 
		[Q_NEG_1] = Q_NEG_K, 
		[Q_I] = Q_J, 
		[Q_NEG_I] = Q_NEG_J, 
		[Q_J] = Q_NEG_I,
		[Q_NEG_J] = Q_I,
		[Q_K] = Q_NEG_1,
		[Q_NEG_K] = Q_1 },
	[Q_NEG_K] = {
		[Q_1] = Q_NEG_K, 
		[Q_NEG_1] = Q_K, 
		[Q_I] = Q_NEG_J, 
		[Q_NEG_I] = Q_J, 
		[Q_J] = Q_I,
		[Q_NEG_J] = Q_NEG_I,
		[Q_K] = Q_1,
		[Q_NEG_K] = Q_NEG_1 },
};

void do_test(int t)
{
	char *result = "NO";
	q_type pattern[10000];
	q_type pattern_prod = Q_1;	/* Quaternion product of entire pattern */
	q_type a_base = Q_1;
	int l;
	long long x;
	int i;
	int a;	/* a copies of the patter in the first substring */
	
	scanf("%d %lld", &l, &x);

	for (i = 0; i < l; i++)
	{
		char c;
		scanf(" %c", &c);
	
		pattern[i] = input_lookup[(unsigned char)c];
		pattern_prod = q_mult[pattern_prod][pattern[i]];
	}	

	for (a = 0; a < 4 && a < x; a++)
	{
		int n;
		q_type a_prod = a_base;

		for (n = 0; n < l; n++)
		{
			a_prod = q_mult[a_prod][pattern[n]];

			if (a_prod == Q_I)
			{
				int m, b;
				q_type b_base = Q_1;

/*				printf("Found i (P * %d + %d)\n", a, n + 1);*/

				for (m = n + 1; m < l; m++)
				{
					b_base = q_mult[b_base][pattern[m]];

					if (b_base == Q_J)
					{
						int o, c;
						int patterns_left = (x - a - 1) % 4;
						q_type c_prod = Q_1;

/*						printf("\tFound j (%d)\n", m - n);*/

						for (o = m + 1; o < l; o++)
							c_prod = q_mult[c_prod][pattern[o]];

						for (c = 0; c < patterns_left; c++)
							c_prod = q_mult[c_prod][pattern_prod];

						if (c_prod == Q_K)
						{
							result = "YES";
							goto out;
/*							printf("\t\tFound k\n");*/
						}
					}
				}

				for (b = 0; b < 4 && b < (x - a - 1); b++)
				{
					q_type b_prod = b_base;

					for (m = 0; m < l; m++)
					{
						if (b_prod == Q_J)
						{
							int o, c;
							int patterns_left = (x - a - 1 - b - 1) % 4;
							q_type c_prod = Q_1;
	
/*							printf("\tFound j (%d + P * %d + %d)\n", l - n - 1, b, m);*/

							for (o = m; o < l; o++)
								c_prod = q_mult[c_prod][pattern[o]];

							for (c = 0; c < patterns_left; c++)
								c_prod = q_mult[c_prod][pattern_prod];

							if (c_prod == Q_K)
							{
								result = "YES";
								goto out;
/*								printf("\t\tFound k\n");*/
							}
						}
	
						b_prod = q_mult[b_prod][pattern[m]];
					}		
					b_base = q_mult[b_base][pattern_prod];
				}
			}
		}

		a_base = q_mult[a_base][pattern_prod];
	}
out:
	printf("Case #%d: %s\n", t + 1, result);
}

int main()
{
	int t, i;

	scanf("%d", &t);
	
	for (i = 0; i < t; i++)
		do_test(i);

	return 0;
}
