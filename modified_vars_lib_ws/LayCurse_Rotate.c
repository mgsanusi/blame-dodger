#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int g;
int decimal;
char yyu[60][60];
char tmp[60][60];
int new_puts(const char *str);
int clear(char c)
{
	int v;
	int res;
	int k;
	int gss_c_nt_hostbased_service_x;
	int interval;
	int xpos;
	int nj;
	for (v = 0; v < g; v++)
		for (res = 0; res < g; res++)
			for (gss_c_nt_hostbased_service_x = -1;
			     gss_c_nt_hostbased_service_x < 2;
			     gss_c_nt_hostbased_service_x++)
				for (interval = 0; interval < 2; interval++)
					if (gss_c_nt_hostbased_service_x
					    || interval) {
						k = 0;
						xpos = v;
						nj = res;
						for (;;) {
							if (((((xpos < 0)
							       || (nj < 0))
							      || (xpos >= g))
							     || (nj >= g))
							    || (yyu[xpos][nj] !=
								c))
								break;
							k++;
							xpos +=
							    gss_c_nt_hostbased_service_x;
							nj += interval;
						}
						if (k >= decimal)
							return 1;
					}
	return 0;
}

int Main()
{
	int v;
	int res;
	int k;
	int i1;
	int fg1;
	int fg2;
	int size;
	int count = 0;
	scanf("%d", &size);
	while (size--) {
		scanf("%d%d", &g, &decimal);
		for (v = 0; v < g; v++)
			scanf("%s", tmp[v]);
		for (v = 0; v < g; v++)
			for (res = 0; res < g; res++)
				yyu[res][(g - 1) - v] = tmp[v][res];
		for (res = 0; res < g; res++) {
			k = g - 1;
			for (v = g - 1; v >= 0; v--)
				if (yyu[v][res] != '.')
					yyu[k][res] = yyu[v][res], k--;
			while (k >= 0)
				yyu[k][res] = '.', k--;
		}
		fg1 = clear('R');
		fg2 = clear('B');
		printf("Case #%d: ", ++count);
		if (fg1 && fg2)
			new_puts("Both");
		if (fg1 && (!fg2))
			new_puts("Red");
		if ((!fg1) && fg2)
			new_puts("Blue");
		if ((!fg1) && (!fg2))
			new_puts("Neither");
	}
	return 0;
}

int new_puts(const char *str)
{
	return puts(str);
}
