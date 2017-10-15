#include <stdio.h>
typedef long long ll;
char batch[510][510];
ll commsum[510][510][3];
int
good (ll v, ll a, ll b)
{
  ll sum;
  ll isum;
  ll jsum;
  sum =
    ((((((commsum[((a + v) - 1) + 1][((b + v) - 1) + 1][0] -
	  commsum[a][((b + v) - 1) + 1][0]) - commsum[((a + v) - 1) +
						      1][b][0]) +
	commsum[a][b][0]) - batch[a][b]) - batch[(a + v) - 1][b]) -
     batch[a][(b + v) - 1]) - batch[(a + v) - 1][(b + v) - 1];
  isum =
    ((((((commsum[((a + v) - 1) + 1][((b + v) - 1) + 1][1] -
	  commsum[a][((b + v) - 1) + 1][1]) - commsum[((a + v) - 1) +
						      1][b][1]) +
	commsum[a][b][1]) - (a * batch[a][b])) - (((a + v) - 1) * batch[(a +
									 v) -
									1]
						  [b])) - (a * batch[a][(b +
									 v) -
									1])) -
    (((a + v) - 1) * batch[(a + v) - 1][(b + v) - 1]);
  jsum =
    ((((((commsum[((a + v) - 1) + 1][((b + v) - 1) + 1][2] -
	  commsum[a][((b + v) - 1) + 1][2]) - commsum[((a + v) - 1) +
						      1][b][2]) +
	commsum[a][b][2]) - (b * batch[a][b])) - (b * batch[(a + v) -
							    1][b])) - (((b +
									 v) -
									1) *
								       batch
								       [a][(b
									    +
									    v)
									   -
									   1]))
    - (((b + v) - 1) * batch[(a + v) - 1][(b + v) - 1]);
  if ((sum * (((2 * a) + v) - 1)) != (2 * isum))
    {
      return 0;
    }
  if ((sum * (((2 * b) + v) - 1)) != (2 * jsum))
    {
      return 0;
    }
  return 1;
}

int
Main (void)
{
  int t;
  int mul;
  scanf ("%d", &t);
  for (mul = 1; mul <= t; mul++)
    {
      ll dx;
      ll c;
      ll d;
      ll hikers;
      ll caseNo;
      ll v;
      ll s;
      ll played;
      ll y1;
      scanf ("%d %d %d\n", &dx, &c, &d);
      for (hikers = 0; hikers < dx; hikers++)
	{
	  gets (batch[hikers]);
	  for (caseNo = 0; caseNo < c; caseNo++)
	    {
	      batch[hikers][caseNo] -= '0';
	    }
	}
      for (hikers = 0; hikers < dx; hikers++)
	commsum[hikers][0][0] = (commsum[hikers][0][1] =
				 (commsum[hikers][0][2] = 0));
      for (hikers = 0; hikers < c; hikers++)
	commsum[0][hikers][0] = (commsum[0][hikers][1] =
				 (commsum[0][hikers][2] = 0));
      for (hikers = 1; hikers <= dx; hikers++)
	{
	  for (caseNo = 1; caseNo <= c; caseNo++)
	    {
	      commsum[hikers][caseNo][0] =
		commsum[hikers][caseNo - 1][0] + batch[hikers - 1][caseNo -
								   1];
	      commsum[hikers][caseNo][1] =
		commsum[hikers][caseNo - 1][1] +
		((hikers - 1) * batch[hikers - 1][caseNo - 1]);
	      commsum[hikers][caseNo][2] =
		commsum[hikers][caseNo - 1][2] +
		((caseNo - 1) * batch[hikers - 1][caseNo - 1]);
	    }
	  for (caseNo = 1; caseNo <= c; caseNo++)
	    {
	      commsum[hikers][caseNo][0] += commsum[hikers - 1][caseNo][0];
	      commsum[hikers][caseNo][1] += commsum[hikers - 1][caseNo][1];
	      commsum[hikers][caseNo][2] += commsum[hikers - 1][caseNo][2];
	    }
	}
      played = 3;
      y1 = dx < c ? dx : c;
      for (v = y1; v >= played; v--)
	{
	  for (hikers = 0; hikers <= (dx - v); hikers++)
	    {
	      for (caseNo = 0; caseNo <= (c - v); caseNo++)
		{
		  if (good (v, hikers, caseNo))
		    {
		      printf ("Case #%d: %d\n", mul, v);
		      goto next;
		    }
		}
	    }
	}
      printf ("Case #%d: IMPOSSIBLE\n", mul);
    next:
      ;
    }
  return 0;
}
