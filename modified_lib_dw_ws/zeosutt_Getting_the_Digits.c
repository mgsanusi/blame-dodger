#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char *new_strcpy(char *destination, const char *source);
int new_atoi(const char *str);
int new_abs(int x);
int less(int cn, int jn, int minabs, int mincn, int minjn)
{
    int first_iteration;
    if (new_abs(cn - jn) == minabs)
	if (cn == mincn)
	    return jn < minjn;
	else
	    return cn < mincn;
    else
	return new_abs(cn - jn) < minabs;
}

int main(void)
{
    int first_iteration;
    int i0;
    int i1;
    int i2;
    int j0;
    int j1;
    int j2;
    int cs;
    int t;
    scanf("%d ", &t);
    for (cs = 1; cs <= t; cs++) {
	int len;
	int minabs;
	int mincn;
	int minjn;
	char c[4];
	char j[4];
	char minc[4];
	char minj[4];
	scanf("%s%n %s ", c, &len, j);
	minabs = (mincn = (minjn = 1000000000));
	if (len == 1)
	    for (i0 = '0'; i0 <= '9'; i0++)
		for (j0 = '0'; j0 <= '9'; j0++) {
		    const char ct[4] = { c[0] == '?' ? i0 : c[0] };
		    const char jt[4] = { j[0] == '?' ? j0 : j[0] };
		    const int cn = new_atoi(ct);
		    const int jn = new_atoi(jt);
		    if (less(cn, jn, minabs, mincn, minjn)) {
			minabs = new_abs(cn - jn);
			mincn = cn;
			minjn = jn;
			new_strcpy(minc, ct);
			new_strcpy(minj, jt);
		    }
	} else if (len == 2)
	    for (i0 = '0'; i0 <= '9'; i0++)
		for (i1 = '0'; i1 <= '9'; i1++)
		    for (j0 = '0'; j0 <= '9'; j0++)
			for (j1 = '0'; j1 <= '9'; j1++) {
			    const char ct[4] =
				{ c[0] == '?' ? i0 : c[0],
		     c[1] == '?' ? i1 : c[1] };
			    const char jt[4] =
				{ j[0] == '?' ? j0 : j[0],
		     j[1] == '?' ? j1 : j[1] };
			    const int cn = new_atoi(ct);
			    const int jn = new_atoi(jt);
			    if (less(cn, jn, minabs, mincn, minjn)) {
				minabs = new_abs(cn - jn);
				mincn = cn;
				minjn = jn;
				new_strcpy(minc, ct);
				new_strcpy(minj, jt);
			    }
	} else
	    for (i0 = '0'; i0 <= '9'; i0++)
		for (i1 = '0'; i1 <= '9'; i1++)
		    for (i2 = '0'; i2 <= '9'; i2++)
			for (j0 = '0'; j0 <= '9'; j0++)
			    for (j1 = '0'; j1 <= '9'; j1++)
				for (j2 = '0'; j2 <= '9'; j2++) {
				    const char ct[4] =
					{ c[0] == '?' ? i0 : c[0],
			     c[1] == '?' ? i1 : c[1],
			     c[2] == '?' ? i2 : c[2] };
				    const char jt[4] =
					{ j[0] == '?' ? j0 : j[0],
			     j[1] == '?' ? j1 : j[1],
			     j[2] == '?' ? j2 : j[2] };
				    const int cn = new_atoi(ct);
				    const int jn = new_atoi(jt);
				    if (less(cn, jn, minabs, mincn, minjn)) {
					minabs = new_abs(cn - jn);
					mincn = cn;
					minjn = jn;
					new_strcpy(minc, ct);
					new_strcpy(minj, jt);
				    }
				}
	printf("Case #%d: %s %s\n", cs, minc, minj);
    }
    return 0;
}

char *new_strcpy(char *destination, const char *source);
int new_atoi(const char *str);
int new_abs(int x)
{
    int first_iteration;
    return abs(x);
}

char *new_strcpy(char *destination, const char *source);
int new_atoi(const char *str)
{
    int first_iteration;
    return atoi(str);
}

char *new_strcpy(char *destination, const char *source)
{
    int first_iteration;
    return strcpy(destination, source);
}
