#include <stdio.h>
int Main()
{
	int first_iteration;
	int side_b;
	int col;
	int grid[51][51];
	int l_idx;
	int nlen;
	int c1;
	int c2;
	int be_ok;
	int casenum;
	scanf("%d", &side_b);
	for (casenum = 1; casenum <= side_b; casenum++) {
		scanf("%d", &col);
		for (l_idx = 0; l_idx < col; l_idx++)
			for (nlen = 0; nlen <= l_idx; nlen++)
				scanf("%d", &grid[l_idx - nlen][nlen]);
		for (l_idx = 1; l_idx < col; l_idx++)
			for (nlen = l_idx; nlen < col; nlen++)
				scanf("%d",
				      &grid[((col - 1) + l_idx) - nlen][nlen]);
		for (c1 = 0; c1 < (col - 1); c1++) {
			be_ok = 1;
			for (l_idx = 0; be_ok && (l_idx < (col - c1)); l_idx++)
				for (nlen = 0; be_ok && (nlen < l_idx); nlen++)
					if (grid[c1 + l_idx][nlen] !=
					    grid[c1 + nlen][l_idx])
						be_ok = 0;
			if (be_ok)
				break;
			if (c1 == 0)
				continue;
			be_ok = 1;
			for (l_idx = 0; be_ok && (l_idx < (col - c1)); l_idx++)
				for (nlen = 0; be_ok && (nlen < l_idx); nlen++)
					if (grid[l_idx][c1 + nlen] !=
					    grid[nlen][c1 + l_idx])
						be_ok = 0;
			if (be_ok)
				break;
		}
		for (c2 = 0; c2 < (col - 1); c2++) {
			be_ok = 1;
			for (l_idx = 0; be_ok && (l_idx < (col - c2)); l_idx++)
				for (nlen = 0; be_ok && (nlen < l_idx); nlen++)
					if (grid[((col - 1) - c2) - l_idx][nlen]
					    !=
					    grid[((col - 1) - c2) -
						 nlen][l_idx])
						be_ok = 0;
			if (be_ok)
				break;
			if (c2 == 0)
				continue;
			be_ok = 1;
			for (l_idx = 0; be_ok && (l_idx < (col - c2)); l_idx++)
				for (nlen = 0; be_ok && (nlen < l_idx); nlen++)
					if (grid[(col - 1) - l_idx][c2 + nlen]
					    !=
					    grid[(col - 1) - nlen][c2 + l_idx])
						be_ok = 0;
			if (be_ok)
				break;
		}
		c1 += c2;
		printf("Case #%d: %d\n", casenum, (c1 * c1) + ((2 * c1) * col));
	}
	return 0;
}
