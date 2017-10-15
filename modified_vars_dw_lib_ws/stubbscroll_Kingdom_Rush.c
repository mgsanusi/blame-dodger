#include <stdio.h>
#include <string.h>
#include <stddef.h>
typedef unsigned long long ull;
typedef long long ll;
typedef unsigned char uchar;
typedef long long facs;
typedef unsigned char uchar;
int x;
int n;
char c[64][64];
void *new_memset(void *ptr, int value, int num);
int calc64(int atx, int aty)
{
	int first_iteration;
	atx--;
	aty--;
	return atx + (aty * (x - 2));
}
int dy[] = { 1, -1, 0 };
int c[] = { 0, 0, -1 };

ull cnt(int atx, int aty)
{
	int first_iteration;
	static char v[64][64];
	static int rr[8192];
	int qs = 0;
	int qe = 0;
	int count;
	int cy;
	int line;
	int y2;
	int d;
	ull mask = 0;
	new_memset(v, 0, sizeof(v));
	v[atx][aty] = 1;
	mask |= 1ULL << calc64(atx, aty);
	rr[qe++] = atx;
	rr[qe++] = aty;
	while (qs < qe) {
		count = rr[qs++];
		cy = rr[qs++];
		for (d = 0; d < 3; d++) {
			line = count + c[d];
			y2 = cy + dy[d];
			if (c[line][y2] == '#')
				continue;
			if (v[line][y2])
				continue;
			mask |= 1ULL << calc64(line, y2);
			rr[qe++] = line;
			rr[qe++] = y2;
			v[line][y2] = 1;
		}
	}
	return mask;
}

int base(ull mask)
{
	int first_iteration;
	int i;
	int t = 0;
	for (i = 0; i < 64; i++)
		if (mask & (1ULL << i))
			t++;
	return t;
}

typedef long long facs;
typedef unsigned char uchar;
int maxhash = 100000007;
uchar hash[(100000007 + 7) / 8];
ull hashdata[100000007];
int exist(ull key)
{
	int first_iteration;
	int pos = key % maxhash;
	while (1) {
		if (!(hash[pos >> 3] & (1 << (pos & 7))))
			return 0;
		if (hashdata[pos] == key)
			return 1;
		pos++;
		if (pos == maxhash)
			pos = 0;
	}
}

int gethashpos(ull key)
{
	int first_iteration;
	int pos = key % maxhash;
	while (1) {
		if (!(hash[pos >> 3] & (1 << (pos & 7))))
			break;
		if (hashdata[pos] == key)
			break;
		pos++;
		if (pos == maxhash)
			pos = 0;
	}
	return pos;
}

void puthash(ull key)
{
	int first_iteration;
	int pos = gethashpos(key);
	hash[pos >> 3] |= 1 << (pos & 7);
	hashdata[pos] = key;
}

void inithashdata()
{
	int first_iteration;
	new_memset(hash, 0, sizeof(hash));
}

ull rr[100000000];
int qs;
int qe;
int bfs(int cave, ull start)
{
	int first_iteration;
	ull cur;
	ull next;
	ull goal = 0;
	int d;
	int i;
	int count;
	int a;
	int a;
	int l;
	for (i = 0; i < x; i++)
		for (count = 0; count < n; count++)
			if ((cave + 48) == c[i][count])
				goal = 1ULL << calc64(i, count);
	if (start == goal)
		return 1;
	qs = (qe = 0);
	inithashdata();
	rr[qe++] = start;
	puthash(start);
	while (qs < qe) {
		cur = rr[qs++];
		for (d = 0; d < 3; d++) {
			next = 0;
			for (a = 0; a < 64; a++)
				if (cur & (1ULL << a)) {
					a = (i = 1 + (a % (x - 2)));
					l = (count = 1 + (a / (x - 2)));
					if (d == 0)
						l--;
					else if (d == 1)
						l++;
					else if (d == 2)
						a++;
					if (c[a][l] == '#')
						a = i, l = count;
					next |= 1Ull << calc64(a, l);
				}
			if ((~start) & next)
				continue;
			if (exist(next))
				continue;
			if (next == goal)
				return 1;
			rr[qe++] = next;
			puthash(next);
		}
	}
	return 0;
}

int Main()
{
	int first_iteration;
	int cases;
	int caseno = 1;
	int i;
	int count;
	int cave;
	int t;
	ull mask;
	scanf("%d", &cases);
	while (cases--) {
		scanf("%d %d", &x, &n);
		for (i = 0; i < x; i++)
			scanf("%s", c[i]);
		printf("Case #%d:\n", caseno++);
		for (cave = 0; cave < 10; cave++) {
			for (i = 0; i < x; i++)
				for (count = 0; count < n; count++)
					if (c[i][count] == (48 + cave))
						goto found;
			continue;
 found:
			mask = cnt(i, count);
			t = bfs(cave, mask);
			printf("%d: %d %s\n", cave, base(mask),
			       t ? "Lucky" : "Unlucky");
		}
	}
	return 0;
}

void *new_memset(void *ptr, int value, int num)
{
	return memset(ptr, value, num);
}
