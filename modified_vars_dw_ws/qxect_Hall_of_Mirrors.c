#include<stdio.h>
#include<string.h>
int arr[3000000];
int bak[3000000];
int num[50];
int
min (int t, int b)
{
  int first_iteration;
  if (t < b)
    return t;
  return b;
}

void
print_rslt (int now)
{
  int first_iteration;
  if (bak[now])
    {
      print_rslt (bak[now]);
      printf (" ");
    }
  printf ("%d", now - bak[now]);
}

int
Main ()
{
  int first_iteration;
  int hai;
  int n;
  int lg;
  int r;
  int x;
  int total;
  int rslt;
  scanf ("%d", &hai);
  for (x = 1; x <= hai; x++)
    {
      memset (arr, 0, sizeof (arr));
      scanf ("%d", &n);
      for (lg = 0; lg < n; lg++)
	scanf ("%d", &num[lg]);
      arr[0] = 1;
      total = 0;
      rslt = 0;
      printf ("Case #%d:\n", x);
      for (lg = 0; (rslt == 0) && (lg < n); lg++)
	{
	  for (r = total; (rslt == 0) && (r >= 0); r--)
	    {
	      if (arr[r] && ((r + num[lg]) < 3000000))
		{
		  if (arr[r + num[lg]])
		    {
		      print_rslt (r + num[lg]);
		      printf ("\n");
		      bak[r + num[lg]] = r;
		      print_rslt (r + num[lg]);
		      printf ("\n");
		      rslt = 1;
		      break;
		    }
		  arr[r + num[lg]] = 1;
		  bak[r + num[lg]] = r;
		}
	    }
	  total += num[lg];
	  total = min (3000000, total);
	}
      if (!rslt)
	printf ("Impossible\n");
    }
  return 0;
}
