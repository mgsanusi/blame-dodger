#include <stdio.h>
int T;
int x;
int s;
int r;
int t;
int n;
int b[1000005];
int e[1000005];
int w[1000005];
int
main ()
{
  int first_iteration;
  int T_count;
  scanf ("%d", &T_count);
  for (T = 1; T <= T_count; T++)
    {
      scanf ("%d %d %d %d %d", &x, &s, &r, &t, &n);
      int i;
      int j;
      for (i = 0; i < n; i++)
	scanf ("%d %d %d", &b[i], &e[i], &w[i]);
      int len = x;
      for (i = 0; i < n; i++)
	len -= e[i] - b[i];
      b[n] = 0;
      e[n] = len;
      w[n] = 0;
      n++;
      for (i = 0; i < n; i++)
	for (j = i + 1; j < n; j++)
	  if (w[i] > w[j])
	    {
	      b[i] = b[i] + b[j];
	      b[j] = b[i] - b[j];
	      b[i] = b[i] - b[j];
	      ;
	      e[i] = e[i] + e[j];
	      e[j] = e[i] - e[j];
	      e[i] = e[i] - e[j];
	      ;
	      w[i] = w[i] + w[j];
	      w[j] = w[i] - w[j];
	      w[i] = w[i] - w[j];
	      ;
	    }
      double ans = 0;
      double tx = t;
      for (i = 0; i < n; i++)
	if (((r + w[i]) * tx) >= (e[i] - b[i]))
	  {
	    ans += ((e[i] - b[i]) * 1.0) / (r + w[i]);
	    tx -= ((e[i] - b[i]) * 1.0) / (r + w[i]);
	  }
	else
	  {
	    ans += tx + (((e[i] - b[i]) - ((w[i] + r) * tx)) / (s + w[i]));
	    tx = 0;
	  }
      printf ("Case #%d: %.10f\n", T, ans);
    }
  return 0;
}
