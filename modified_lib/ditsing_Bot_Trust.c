#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#define MAXN 100
#define MAXL 100
#define MIN( a, b) ( ( a) < ( b) ? ( a) : ( b))
#define MAX( a, b) ( ( a) > ( b) ? ( a) : ( b))

int dp[MAXN][MAXL];
int p[MAXN];
int f[MAXN];
int pos[2][MAXN];
int N;
int new_abs(int x);


int main()
{
	int Tcases;
	scanf("%d", &Tcases);
	int cases;
	for ( cases = 0; cases != Tcases; cases++)
	{
		memset( dp, 0x3F, sizeof( dp));
		scanf("%d", &N);
		char c;
		int dis;
		int i;
		for ( i = 0; i < N; i++)
		{
			scanf(" %c %d", &c, &dis);
			--dis;
			f[i] = c != 'O';
			p[i] = dis;
			pos[f[i]][i] = dis;
			pos[1-f[i]][i] = -1;
		}

		for ( i = N - 1; i; i--)
		{
			if ( pos[0][i-1] == -1)
			{
				pos[0][i-1] = pos[0][i];
			}
			if ( pos[1][i-1] == -1)
			{
				pos[1][i-1] = pos[1][i];
			}
		}

		int ans = 0;
		int cur[2] = { 0, 0};
		for ( i = 0; i < N; i++)
		{
			int curl = new_abs( cur[f[i]] - p[i]) + 1;
			cur[f[i]] = p[i];
			ans += curl;
			if ( pos[1-f[i]][i] != -1)
			{
				if ( new_abs( cur[1-f[i]] - pos[1-f[i]][i]) <= curl)
				{
					cur[1-f[i]] = pos[1-f[i]][i];
				}
				else
				{
					if ( pos[1-f[i]][i] > cur[1-f[i]])
					{
						cur[1-f[i]] += curl;
					}
					else
					{
						cur[1-f[i]] -= curl;
					}
				}
			}
		}

		/*
		int j, k;
		for ( i = 0; i < MAXL; i++)
		{
			dp[0][i] = MAX( p[0] + 1, i);
		}

		for ( i = 1; i < N; i++)
		{
			for ( j = 0; j < MAXL; j++)
			{
				for( k = 0; k < MAXL; k++)
				{
					if ( f[i] ^ f[i-1])
					{
						dp[i][j] = MIN( dp[i][j], dp[i-1][k] + MAX( new_abs( p[i] - k) + 1, new_abs( p[i-1] - j)));
					}
					else
					{
						dp[i][j] = MIN( dp[i][j], dp[i-1][k] + MAX( new_abs( j - k), new_abs( p[i] - p[i-1]) + 1));
					}
				}
			}
		}

		int ans = INT_MAX;
		for ( i = 0; i < MAXL; i++)
		{
			ans = MIN( ans, dp[N-1][i]);
		}
		*/

		printf("Case #%d: %d\n", cases + 1, ans);
	}
	return 0;
}


int new_abs(int x) {
  return abs(x);
}