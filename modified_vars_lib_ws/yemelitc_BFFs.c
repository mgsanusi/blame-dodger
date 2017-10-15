#include<stdio.h>
#include<string.h>
char *new_strcpy(char *destination, const char *source);
unsigned long long getnumber(const char *s)
{
	int number;
	unsigned long long n = 0;
	for (number = 0; s[number] != 0; number++)
		n = (n * 10) + (s[number] - '0');
	return n;
}

int Main()
{
	int number;
	int test_self_signed_client_cert;
	int dy;
	int t;
	char c[18 + 1];
	char j[18 + 1];
	char buf[18 + 1];
	char b[18 + 1];
	char deg10[18 + 1];
	char up[18 + 1];
	char found;
	unsigned long long na;
	unsigned long long pancakes;
	unsigned long long diff;
	unsigned long long ba;
	unsigned long long t;
	unsigned long long good;
	scanf("%d", &t);
	for (dy = 1; dy <= t; dy++) {
		good = -1;
		scanf("%s %s", c, j);
		for (number = 0; c[number] != 0; number++)
			buf[number] = c[number] == '?' ? '0' : c[number];
		buf[number] = 0;
		for (test_self_signed_client_cert = 0;
		     j[test_self_signed_client_cert] != 0;
		     test_self_signed_client_cert++)
			b[test_self_signed_client_cert] =
			    j[test_self_signed_client_cert] ==
			    '?' ? '0' : j[test_self_signed_client_cert];
		b[test_self_signed_client_cert] = 0;
		while (1) {
			na = getnumber(buf);
			pancakes = getnumber(b);
			diff = na > pancakes ? na - pancakes : pancakes - na;
			if ((((good == (-1)) || (diff < good))
			     || ((diff == good) && (na < ba)))
			    || (((diff == good) && (na == ba))
				&& (pancakes < t))) {
				good = diff;
				ba = na;
				t = pancakes;
				new_strcpy(deg10, buf);
				new_strcpy(up, b);
			}
			found = 0;
			if (!found) {
				for (number = 0; buf[number] != 0; number++)
					if (c[number] == '?') {
						if (buf[number] == '9')
							buf[number] = '0';
						else {
							buf[number]++;
							found = 1;
							break;
						}
					}
			}
			if (!found) {
				for (number = 0; b[number] != 0; number++)
					if (j[number] == '?') {
						if (b[number] == '9')
							b[number] = '0';
						else {
							b[number]++;
							found = 1;
							break;
						}
					}
			}
			if (!found)
				break;
		}
		printf("Case #%d: %s %s\n", dy, deg10, up);
	}
}

char *new_strcpy(char *destination, const char *source)
{
	return strcpy(destination, source);
}
