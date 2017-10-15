#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include <stddef.h>
#define MAXN 260
void * new_memset(void *ptr, int value, size_t num);


int main ()
{
	int T, iT;
	scanf("%d",&T);
	static char a[MAXN][MAXN];
	static char b[MAXN][MAXN];
	static char s[MAXN];
	static char now[MAXN];
	int nowc;
	for (iT = 0; iT < T; iT++)
	{
		new_memset(a,0,sizeof(a));
		new_memset(b,0,sizeof(b));
		int A, B, N;
		scanf("%d",&A);
		int i, j, k;
		for (i = 0; i < A; i++)
		{
			scanf("%s",s);
			a[s[0]][s[1]] = s[2];
			a[s[1]][s[0]] = s[2];
			//if ((s[0] < 'A') || (s[0] > 'Z') || (s[1] < 'A') || (s[1] > 'Z') || (s[2] < 'A') || (s[2] > 'Z')) printf("ACHTUNG!\n");
		}
		scanf("%d",&B);
		for (i = 0; i < B; i++)
		{
			scanf("%s",s);
			b[s[0]][s[1]] = 1;
			b[s[1]][s[0]] = 1;
			//if ((s[0] < 'A') || (s[0] > 'Z') || (s[1] < 'A') || (s[1] > 'Z')) printf("ACHTUNG!\n");
		}
		scanf("%d",&N);
		scanf("%s",s);
		//for (i = 0; i < N; i++)
		//	if ((s[i] < 'A') || (s[i] > 'Z')) printf("ACHTUNG!\n");
		nowc = 0;
		for (i = 0; i < N; i++)
		{
			now[nowc] = s[i];
			nowc++;
			while (nowc > 1)
			{
				if (a[now[nowc-1]][now[nowc-2]] == 0) break;
				now[nowc-2] = a[now[nowc-1]][now[nowc-2]];
				nowc--;
			}
			for (j = 0; j < nowc; j++)
			{
				for (k = j; k < nowc; k++)
				{
					if (b[now[j]][now[k]])
					{
						nowc = 0;
						break;
					}
				}
				if (nowc == 0) break;
			}
		}
		printf("Case #%d: [",iT+1);
		for (i = 0; i < nowc; i++)
		{
			if (i) printf(", ");
			printf("%c",now[i]);
		}
		printf("]\n");
	}
	return 0;
}

void * new_memset(void *ptr, int value, size_t num) {
  return memset(ptr, value, num);
}