#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <stddef.h>
double new_pow(double base, double exponent);
int new_memcmp(const void *ptr1, const void *ptr2, size_t num);
void do_test(int t)
{
	long alphabet[26] = { 0 };
	char target[200];
	long k, l, s;
	long n;
	long shift;
	double bananas_required;
	double pw;
	int i;
	scanf(" %ld %ld %ld", &k, &l, &s);
	for (i = 0; i < k; i++) {
		char key;
		scanf(" %c", &key);
		alphabet[key - 'A']++;
	}
	for (i = 0; i < l; i++)
		scanf(" %c", &target[i]);
	n = s - l + 1;
	for (shift = 1; shift < l; shift++)
		if (new_memcmp(target, target + shift, l - shift) == 0)
			break;

	bananas_required = 1 + (s - l) / shift;
/*	fprintf(stderr, "n = %ld\nshift = %ld\nbananas_required = %f\n", n, shift, bananas_required);*/
	pw = n;
	for (i = 0; i < l; i++) {
		long key_count = alphabet[target[i] - 'A'];
		pw *= key_count;
		if (key_count == 0)
			bananas_required = 0.0;
	}
	pw /= new_pow(k, l);
	printf("Case #%d: %f\n", t + 1, bananas_required - pw);
}

int main()
{
	int t, i;
	scanf("%d", &t);

	for (i = 0; i < t; i++)
		do_test(i);
	return 0;
}

double new_pow(double base, double exponent);
int new_memcmp(const void *ptr1, const void *ptr2, size_t num)
{
	return memcmp(ptr1, ptr2, num);
}

double new_pow(double base, double exponent)
{
	return pow(base, exponent);
}
