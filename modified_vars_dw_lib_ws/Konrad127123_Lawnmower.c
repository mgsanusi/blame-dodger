#include<stdio.h>
int t;
int o_win;
int x_gain;
int uncompleted;
int out;
int min;
int b;
int next;
int w;
int tmp;
int i;
int oset;
int req_flags[100][100];
int pm[100][100];
int new_puts(const char *str);
int Main()
{
	int first_iteration;
	scanf("%d", &out);
	for (t = 1; t <= out; t++) {
		scanf("%d", &i);
		scanf("%d", &oset);
		for (min = 0; min < i; min++)
			for (b = 0; b < oset; b++) {
				scanf("%d", &req_flags[min][b]);
				pm[min][b] = 200;
			}
		for (min = 0; min < i; min++) {
			tmp = 0;
			for (b = 0; b < oset; b++) {
				if (req_flags[min][b] > tmp)
					tmp = req_flags[min][b];
			}
			for (b = 0; b < oset; b++) {
				if (tmp < pm[min][b])
					pm[min][b] = tmp;
			}
		}
		for (b = 0; b < oset; b++) {
			tmp = 0;
			for (min = 0; min < i; min++) {
				if (req_flags[min][b] > tmp)
					tmp = req_flags[min][b];
			}
			for (min = 0; min < i; min++) {
				if (tmp < pm[min][b])
					pm[min][b] = tmp;
			}
		}
		tmp = 0;
		for (min = 0; min < i; min++)
			for (b = 0; b < oset; b++) {
				if (req_flags[min][b] != pm[min][b])
					tmp = 1;
			}
		printf("Case #%d: ", t);
		if (tmp)
			new_puts("NO");
		else
			new_puts("YES");
	}
	return 0;
}

int new_puts(const char *str)
{
	return puts(str);
}
