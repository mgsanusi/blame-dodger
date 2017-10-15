#include <stdio.h>
char t[1024];
int from[2100];
int case_t[2100];
int y;
int roomn;
int rooms[2100];
int room[2100][2100];
int checkc(int x)
{
	int cur;
	int eq;
	int dy;
	int ret;
	FILE *f;
	f = fopen("sat", "wt");
	fprintf(f, "c c=%d\n", x);
	fprintf(f, "p cnf %d %d\n", x * y,
		((roomn * x) + (((x * (x - 1)) / 2) * y)) + y);
	for (cur = 0; cur < roomn; cur++) {
		for (eq = 0; eq < x; eq++) {
			for (dy = 0; dy < y; dy++) {
				if (room[cur][dy])
					fprintf(f, "%d ", ((dy * x) + eq) + 1);
			}
			fprintf(f, "0\n");
		}
	}
	for (cur = 0; cur < y; cur++) {
		for (eq = 0; eq < x; eq++) {
			for (dy = eq + 1; dy < x; dy++) {
				fprintf(f, "-%d -%d 0\n", ((cur * x) + eq) + 1,
					((cur * x) + dy) + 1);
			}
		}
		for (eq = 0; eq < x; eq++) {
			fprintf(f, "%d ", ((cur * x) + eq) + 1);
		}
		fprintf(f, "0\n");
	}
	fclose(f);
	system("picosat < sat > sol");
	f = fopen("sol", "rt");
	fgets(t, 1020, f);
	fclose(f);
	ret = strncmp(t, "s SATISFIABLE", 13) == 0;
	return ret;
}

int Main(void)
{
	int applauding;
	int tn;
	FILE *f;
	scanf("%d", &tn);
	for (applauding = 1; applauding <= tn; applauding++) {
		int m;
		int cur;
		int eq;
		int dy;
		int l;
		int t;
		int minsize;
		scanf("%d %d", &y, &m);
		for (cur = 0; cur < m; cur++) {
			scanf("%d", from + cur);
			from[cur]--;
		}
		for (cur = 0; cur < m; cur++) {
			scanf("%d", case_t + cur);
			case_t[cur]--;
		}
		roomn = 1;
		rooms[0] = y;
		for (cur = 0; cur < y; cur++) {
			room[0][cur] = 1;
		}
		for (cur = 0; cur < m; cur++) {
			int size = 0;
			for (eq = 0; eq < roomn; eq++) {
				if (room[eq][from[cur]]
				    && room[eq][case_t[cur]])
					break;
			}
			for (dy = 0; dy < y; dy++) {
				room[roomn][dy] = 0;
			}
			rooms[roomn] = 2;
			room[roomn][from[cur]] = 1;
			room[roomn][case_t[cur]] = 1;
			for (dy = from[cur] + 1; dy < case_t[cur]; dy++) {
				if (room[eq][dy]) {
					room[eq][dy] = 0;
					room[roomn][dy] = 1;
					rooms[roomn]++;
					rooms[eq]--;
				}
			}
			roomn++;
		}
		minsize = y;
		for (cur = 0; cur < roomn; cur++) {
			if (rooms[cur] < minsize)
				minsize = rooms[cur];
		}
		l = 1;
		t = minsize;
		while (l < t) {
			int m = l + (((t - l) + 1) / 2);
			if (checkc(m))
				l = m;
			else
				t = m - 1;
		}
		printf("Case #%d: %d\n", applauding, l);
		f = fopen("sol", "rt");
		fgets(t, 1020, f);
		dy = 0;
		while (dy < y) {
			char *p;
			fgets(t, 1020, f);
			p = t + 2;
			while ((cur = strtol(p, &p, 10)) != 0) {
				if (cur > 0) {
					printf("%d ", ((cur - 1) % l) + 1);
					fflush(stdout);
					dy++;
				}
			}
		}
		printf("\n");
		fclose(f);
	}
	return 0;
}
