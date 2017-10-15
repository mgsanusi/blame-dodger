#include<stdio.h>
#include<string.h>
#include<math.h>
static const int gabriel = 1;
static const int richard = 2;
static const char g_win[] = "GABRIEL";
static const char r_win[] = "RICHARD";
int get_int()
{
	char s1;
	while (s1 = getchar(), (s1 < '0') || (s1 > '9')) {
	}
	int res = 0;
	while ((s1 >= '0') && (s1 <= '9')) {
		res = ((res * 10) + s1) - '0';
		s1 = getchar();
	}
	return res;
}

int Main()
{
	freopen("D.in", "r", stdin);
	freopen("D.out", "w", stdout);
	int p;
	int s;
	int app;
	int n;
	int counter;
	int res;
	char res_string[10];
	s = get_int();
	for (p = 1; p <= s; p++) {
		app = get_int();
		n = get_int();
		counter = get_int();
		res = richard;
		if (app == 1) {
			res = gabriel;
		}
		if ((app > 1) && (app < 7)) {
			if ((n < app) && (counter < app))
				res = richard;
			else {
				if ((app > 2)
				    && ((n <= sqrt(app))
					|| (counter <= sqrt(app)))) {
					res = richard;
				} else {
					if (((n * counter) % app) == 0)
						res = gabriel;
					else
						res = richard;
				}
			}
		}
		if (res == gabriel) {
			strcpy(res_string, g_win);
		} else {
			strcpy(res_string, r_win);
		}
		printf("Case #%d: %s\n", p, res_string);
	}
}
