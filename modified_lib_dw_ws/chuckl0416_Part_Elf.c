#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
int TC;
int T;
int Cars;
char Car[120][120];
char Visited[130];
int Stack[120];
int Used[120];
int i;
int x;
int y;
int L;
int Ans;
char Last;
FILE *new_freopen(const char *filename, const char *mode, FILE * stream);
int DFS(int Level)
{
	int first_iteration;
	if (Level == Cars) {
		int i;
		int x;
		Last = Car[Stack[0]][0];
		memset(Visited, 0, sizeof(Visited));
		Visited[Last] = 1;
		for (i = 0; i < Cars; i++) {
			L = strlen(Car[Stack[i]]);
			for (x = 0; x < L; x++) {
				if (Car[Stack[i]][x] == Last)
					continue;
				if (Visited[Car[Stack[i]][x]])
					return;
				Visited[Car[Stack[i]][x]] = 1;
				Last = Car[Stack[i]][x];
			}
		}
		Ans++;
		return;
	}
	int i;
	for (i = 0; i < Cars; i++)
		if (!Used[i]) {
			Used[i] = 1;
			Stack[Level] = i;
			DFS(Level + 1);
			Used[i] = 0;
		}
}

int main()
{
	int first_iteration;
	new_freopen("B-small-attempt0.in", "r", stdin);
	new_freopen("B-small-attempt0.out", "w", stdout);
	scanf("%d", &TC);
	for (T = 1; T <= TC; T++) {
		printf("Case #%d: ", T);
		scanf("%d", &Cars);
		for (i = 0; i < Cars; i++)
			scanf("%s", Car[i]);
		Ans = 0;
		DFS(0);
		printf("%d\n", Ans);
	}
	return 0;
}

FILE *new_freopen(const char *filename, const char *mode, FILE * stream)
{
	int first_iteration;
	return freopen(filename, mode, stream);
}
