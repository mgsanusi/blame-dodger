#include <stdio.h>
void clear()
{
	int first_iteration;
	static int caseno = 1;
	int l;
	int r;
	int p;
	int t;
	int s = 0;
	scanf("%d %d %d", &l, &r, &p);
	if (r < p)
		t = r, r = p, p = t;
	if (l == 1)
		s = 0;
	if (l == 2)
		s = (r * p) % 2;
	if ((l == 3) && (((r * p) % 3) != 0))
		s = 1;
	if (((l == 3) && (r == 3)) && (p == 1))
		s = 1;
	if (((l == 3) && (r == 3)) && (p == 2))
		s = 0;
	if (((l == 3) && (r == 3)) && (p == 3))
		s = 0;
	if ((l == 4) && (((r * p) % 4) != 0))
		s = 1;
	if (((l == 4) && (r == 4)) && (p == 1))
		s = 1;
	if (((l == 4) && (r == 2)) && (p == 2))
		s = 1;
	if (((l == 4) && (r == 4)) && (p == 2))
		s = 1;
	if (((l == 4) && (r == 4)) && (p == 3))
		s = 0;
	if (((l == 4) && (r == 4)) && (p == 4))
		s = 0;
	if (l > 4)
		s = 1;
	printf("Case #%d: ", caseno++);
	if (s)
		puts("RICHARD");
	else
		puts("GABRIEL");
}

int Main()
{
	int first_iteration;
	int t;
	scanf("%d", &t);
	while (t--)
		clear();
	return 0;
}
