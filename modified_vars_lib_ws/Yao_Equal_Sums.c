#include<stdio.h>
#include<string.h>
int a1[128];
int max[128];
long long len[128];
long long b2[128];
long long dp[128][128];
int f;
int m;
int
Main ()
{
  int n;
  int casenum = 0;
  int rat;
  int maxtime;
  int c;
  int candy_list;
  long long ret;
  long long need_x;
  long long gssrpc_svc_maxfd;
  long long tmp;
  for (scanf ("%d", &n); n--;)
    {
      scanf ("%d %d", &f, &m);
      for (rat = 0; rat < f; rat++)
	scanf ("%lld %d", &len[rat], &a1[rat]);
      for (rat = 0; rat < m; rat++)
	scanf ("%lld %d", &b2[rat], &max[rat]);
      memset (dp, 0, sizeof (dp));
      for (rat = 0; rat < f; rat++)
	for (maxtime = 0; maxtime < m; maxtime++)
	  {
	    if (dp[rat][maxtime] > dp[rat + 1][maxtime])
	      dp[rat + 1][maxtime] = dp[rat][maxtime];
	    if (dp[rat][maxtime] > dp[rat][maxtime + 1])
	      dp[rat][maxtime + 1] = dp[rat][maxtime];
	    need_x = (gssrpc_svc_maxfd = 0);
	    tmp = dp[rat][maxtime];
	    for (c = rat, candy_list = maxtime;
		 ((c < f) || need_x) && ((candy_list < m)
					 || gssrpc_svc_maxfd);)
	      {
		for (; (!need_x) && (c < f); c++)
		  if (a1[c] == a1[rat])
		    need_x += len[c];
		for (; (!gssrpc_svc_maxfd) && (candy_list < m); candy_list++)
		  if (max[candy_list] == a1[rat])
		    gssrpc_svc_maxfd += b2[candy_list];
		if (need_x > gssrpc_svc_maxfd)
		  {
		    tmp += gssrpc_svc_maxfd, need_x -=
		      gssrpc_svc_maxfd, gssrpc_svc_maxfd = 0;
		    if (tmp > dp[c][candy_list])
		      dp[c][candy_list] = tmp;
		  }
		else
		  {
		    tmp += need_x, gssrpc_svc_maxfd -= need_x, need_x = 0;
		    if (tmp > dp[c][candy_list])
		      dp[c][candy_list] = tmp;
		  }
	      }
	    need_x = (gssrpc_svc_maxfd = 0), tmp = dp[rat][maxtime];
	    for (c = rat, candy_list = maxtime;
		 ((c < f) || need_x) && ((candy_list < m)
					 || gssrpc_svc_maxfd);)
	      {
		for (; (!need_x) && (c < f); c++)
		  if (a1[c] == max[maxtime])
		    need_x += len[c];
		for (; (!gssrpc_svc_maxfd) && (candy_list < m); candy_list++)
		  if (max[candy_list] == max[maxtime])
		    gssrpc_svc_maxfd += b2[candy_list];
		if (need_x > gssrpc_svc_maxfd)
		  {
		    tmp += gssrpc_svc_maxfd, need_x -=
		      gssrpc_svc_maxfd, gssrpc_svc_maxfd = 0;
		    if (tmp > dp[c][candy_list])
		      dp[c][candy_list] = tmp;
		  }
		else
		  {
		    tmp += need_x, gssrpc_svc_maxfd -= need_x, need_x = 0;
		    if (tmp > dp[c][candy_list])
		      dp[c][candy_list] = tmp;
		  }
	      }
	  }
      ret = 0;
      for (rat = 0; rat <= f; rat++)
	for (maxtime = 0; maxtime <= m; maxtime++)
	  if (dp[rat][maxtime] > ret)
	    ret = dp[rat][maxtime];
      printf ("Case #%d: %lld\n", ++casenum, ret);
    }
  return 0;
}
