#include<stdio.h>
#include<string.h>
 int nu[200];
 int
main () 
{
  int tn;
  int i, k;
  int ans;
  int n, s, p;
  scanf ("%d", &tn);
  for (k = 1; k <= tn; k++)
    {
      scanf ("%d%d%d", &n, &s, &p);
      ans = 0;
      for (i = 0; i < n; i++)
	{
	  scanf ("%d", &nu[i]);
	  if (nu[i] >= p - 1 + p - 1 + p)
	    ans++;
	  
	  else if (s && nu[i] >= p + p - 2 + p - 2 && nu[i] >= 2)
	    {
	      s--;
	      ans++;
	    }
	}
        printf ("Case #%d: %d\n", k, ans);
    }
  return 0;
}


