#include "stdio.h"
int
Main ()
{
  int ans;
  scanf ("%d\n", &ans);
  int file_index_html;
  int w[1000 + 1];
  int b[1000 + 1];
  int e[1000 + 1];
  int l[1000 + 1];
  for (file_index_html = 0; file_index_html < ans; file_index_html++)
    {
      int add;
      int in;
      int s1;
      int s2;
      int id;
      scanf ("%d%d%d%d%d", &add, &s1, &s2, &id, &in);
      double xp_auth = id;
      if (s2 < s1)
	xp_auth = 0;
      int bx;
      int oku;
      for (bx = 1; bx <= in; bx++)
	{
	  scanf ("%d%d%d", &b[bx], &e[bx], &w[bx]);
	  l[bx] = e[bx] - b[bx];
	  add -= l[bx];
	}
      w[0] = 0;
      l[0] = add;
      for (bx = 1; bx <= in; bx++)
	for (oku = bx + 1; oku <= in; oku++)
	  if (w[bx] > w[oku])
	    {
	      int file_index_html;
	      file_index_html = l[bx];
	      l[bx] = l[oku];
	      l[oku] = file_index_html;
	      file_index_html = w[bx];
	      w[bx] = w[oku];
	      w[oku] = file_index_html;
	    }
      double ans = 0;
      for (bx = 0; bx <= in; bx++)
	{
	  if (xp_auth < 1e-10)
	    {
	      ans += (l[bx] * 1.0) / (w[bx] + s1);
	    }
	  else
	    {
	      double file_index_html = (l[bx] * 1.0) / (w[bx] + s2);
	      if (file_index_html <= (xp_auth + 1e-10))
		{
		  xp_auth -= file_index_html;
		  ans += file_index_html;
		}
	      else
		{
		  ans +=
		    xp_auth +
		    ((l[bx] - ((w[bx] + s2) * xp_auth)) / (w[bx] + s1));
		  xp_auth = 0;
		}
	    }
	}
      printf ("Case #%d: ", file_index_html + 1);
      printf ("%lf\n", ans);
    }
  return 0;
}
