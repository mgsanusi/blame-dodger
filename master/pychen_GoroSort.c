#include <stdio.h>

#define MAX_N 0x7f

int main()
{
	int t, t_case;
	for (scanf("%d", &t_case), t = 1; t <= t_case; t++)
	{
		int n, i, j;
		char mat[MAX_N][MAX_N];
		scanf("%d", &n);
		for (i = 0; i < n; i++)
			scanf("%s", mat[i]);
			
		int count[MAX_N];			
		float wp[MAX_N], owp[MAX_N], oowp[MAX_N];
		
		for (i = 0; i < n; i++)
		{
			count[i] = 0;
			for (j = 0; j < n; j++)
				if (mat[i][j] != '.')
					count[i]++;		
		}

		for (i = 0; i < n; i++)
		{
			int win_count = 0;
			for (j = 0; j < n; j++)
				if (mat[i][j] == '1')
					win_count++;
			wp[i] = win_count * 1.0 / count[i];
		}
		
		for (i = 0; i < n; i++)
		{
			float wp_count = 0;
			for (j = 0; j < n; j++)
				if (mat[i][j] != '.')
					wp_count += (wp[j] * count[j] - (mat[i][j] == '0')) / (count[j] - 1);
			owp[i] = wp_count / count[i];
		}
		
		for (i = 0; i < n; i++)
		{
			float owp_count = 0;
			for (j = 0; j < n; j++)
				if (mat[i][j] != '.')
					owp_count += owp[j];
			oowp[i] = owp_count / count[i];
		}	
		
		printf("Case #%d:\n", t);
		for (i = 0; i < n; i++)
			printf("%f\n", 0.25 * wp[i] + 0.5 * owp[i] + 0.25 * oowp[i]);
			
	}
	
	return 0;
}
