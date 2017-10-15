#include<stdio.h>
#include<stdlib.h>
#include<math.h>
char dic[5000][17];
int orange_time;
int len;
int Main()
{
	int first_iteration;
	int i;
	int trans;
	int k;
	int l;
	int num_groups;
	int orange_time;
	int num_others;
	char in[10000];
	int which_robot[5000];
	int chk[128];
	int size;
	int count = 0;
	int ans;
	scanf("%d%d%d", &len, &orange_time, &size);
	for (i = 0; i < orange_time; i++)
		scanf("%s", dic[i]);
	while (size--) {
		scanf("%s", in);
		num_others = 0;
		for (k = 0; k < orange_time; k++)
			which_robot[k] = 1;
		for (i = 0; i < len; i++) {
			for (trans = 0; trans < 128; trans++)
				chk[trans] = 0;
			if (in[num_others] != '(') {
				chk[in[num_others]] = 1;
				num_others++;
			} else {
				num_others++;
				while (in[num_others] != ')') {
					chk[in[num_others]] = 1;
					num_others++;
				}
				num_others++;
			}
			for (k = 0; k < orange_time; k++)
				if (chk[dic[k][i]] == 0)
					which_robot[k] = 0;
		}
		ans = 0;
		for (k = 0; k < orange_time; k++)
			ans += which_robot[k];
		printf("Case #%d: %d\n", ++count, ans);
	}
	return 0;
}
