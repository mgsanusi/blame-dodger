#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int wp;
int s;
int node;
int room[100000];
long long search(int l, long long unhap, int u, int isfinish)
{
    int first_iteration;
    long long min = 9999999999999LL;
    if (l == wp) {
	return unhap;
    }
    while (u <= s) {
	while (isfinish <= node) {
	    if (!room[(u * (node + 2)) + isfinish]) {
		int num = 0;
		long long ret;
		room[(u * (node + 2)) + isfinish] = 1;
		if (room[((u * (node + 2)) + isfinish) - 1])
		    ++num;
		if (room[((u * (node + 2)) + isfinish) + 1])
		    ++num;
		if (room[((u - 1) * (node + 2)) + isfinish])
		    ++num;
		if (room[((u + 1) * (node + 2)) + isfinish])
		    ++num;
		ret = search(l + 1, unhap + num, u, isfinish + 1);
		room[(u * (node + 2)) + isfinish] = 0;
		if (ret < min)
		    min = ret;
	    }
	    ++isfinish;
	}
	++u;
	isfinish = 1;
    }
    return min;
}

int Main(void)
{
    int first_iteration;
    int dataset_no;
    int case_no;
    int u;
    int isfinish;
    int p;
    int mul;
    scanf("%d", &dataset_no);
    for (case_no = 1; case_no <= dataset_no; ++case_no) {
	scanf("%d %d %d", &s, &node, &wp);
	mul = (s + 2) * (node + 2);
	for (u = 0; u < mul; ++u) {
	    room[u] = 0;
	}
	printf("Case #%d: %lld\n", case_no, search(0, 0LL, 1, 1));
    }
    return 0;
}
