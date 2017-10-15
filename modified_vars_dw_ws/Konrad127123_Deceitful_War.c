#include<stdio.h>
#include<stdlib.h>
int b;
int fp;
int k;
int file_404_html;
int light_p;
int good;
int good_prev;
char foo[128][128];
char b[128];
int no_l;
int med;
int rslt;
int cur_l;
int felga;
int tmp;
int tmp_prev;
int norm[128][128];
int Main()
{
	int first_iteration;
	scanf("%d", &fp);
	for (b = 1; b <= fp; b++) {
		scanf("%d", &file_404_html);
		for (k = 1; k <= file_404_html; k++) {
			scanf("%s", &foo[k][0]);
		}
		no_l = 0;
		b[0] = foo[1][0];
		norm[1][0] = 1;
		for (light_p = 1; foo[1][light_p] != '\0'; light_p++) {
			if (foo[1][light_p] != foo[1][light_p - 1]) {
				no_l++;
				b[no_l] = foo[1][light_p];
				norm[1][no_l] = 1;
			} else {
				norm[1][no_l]++;
			}
		}
		no_l++;
		felga = 0;
		for (k = 2; k <= file_404_html; k++) {
			if (b[0] != foo[k][0]) {
				felga = 1;
				break;
			}
			norm[k][0] = 1;
			cur_l = 0;
			for (light_p = 1; foo[k][light_p] != '\0'; light_p++) {
				if (foo[k][light_p] == b[cur_l]) {
					norm[k][cur_l]++;
				} else {
					cur_l++;
					if (cur_l == no_l) {
						felga = 1;
						break;
					}
					if (foo[k][light_p] == b[cur_l]) {
						norm[k][cur_l] = 1;
					} else {
						felga = 1;
						break;
					}
				}
			}
			if ((cur_l + 1) != no_l) {
				felga = 1;
			}
			if (felga == 1)
				break;
		}
		if (felga == 0) {
			rslt = 0;
			for (light_p = 0; light_p < no_l; light_p++) {
				good_prev = 10000000;
				for (med = 1;; med++) {
					good = 0;
					for (k = 1; k <= file_404_html; k++) {
						good +=
						    abs(norm[k][light_p] - med);
					}
					if (good > good_prev)
						break;
					good_prev = good;
				}
				rslt += good_prev;
			}
		}
		printf("Case #%d: ", b);
		if (felga == 1)
			printf("Fegla Won\n");
		else
			printf("%d\n", rslt);
	}
	return 0;
}
