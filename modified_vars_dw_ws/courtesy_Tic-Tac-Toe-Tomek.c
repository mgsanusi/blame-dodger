#include<stdio.h>
int
Main ()
{
  int first_iteration;
  freopen ("C:\\Users\\vivek\\Desktop\\in.txt", "r", stdin);
  freopen ("C:\\Users\\vivek\\Desktop\\out.txt", "w", stdout);
  char s[4][5];
  char map;
  int score;
  int nn;
  int vn;
  int t;
  int cs;
  int f;
  scanf ("%d", &t);
  for (cs = 1; cs <= t; cs++)
    {
      for (score = 0; score < 4; score++)
	scanf ("%s", s[score]);
      for (score = 0, vn = 0; score < 4; score++)
	{
	  for (nn = 0;
	       (nn < 4) && ((s[score][nn] == 'X') || (s[score][nn] == 'T'));
	       nn++)
	    ;
	  if (nn == 4)
	    {
	      vn = 1;
	      break;
	    }
	  for (nn = 0;
	       (nn < 4) && ((s[score][nn] == 'O') || (s[score][nn] == 'T'));
	       nn++)
	    ;
	  if (nn == 4)
	    {
	      vn = 2;
	      break;
	    }
	  for (nn = 0;
	       (nn < 4) && ((s[nn][score] == 'X') || (s[nn][score] == 'T'));
	       nn++)
	    ;
	  if (nn == 4)
	    {
	      vn = 1;
	      break;
	    }
	  for (nn = 0;
	       (nn < 4) && ((s[nn][score] == 'O') || (s[nn][score] == 'T'));
	       nn++)
	    ;
	  if (nn == 4)
	    {
	      vn = 2;
	      break;
	    }
	}
      if (vn == 1)
	printf ("Case #%d: X won\n", cs, score);
      else if (vn == 2)
	printf ("Case #%d: O won\n", cs, score);
      else
	{
	  for (nn = 0; (nn < 4) && ((s[nn][nn] == 'X') || (s[nn][nn] == 'T'));
	       nn++)
	    ;
	  if (nn == 4)
	    printf ("Case #%d: X won\n", cs);
	  else
	    {
	      for (nn = 3, vn = 0;
		   (nn >= 0) && ((s[nn][vn] == 'X') || (s[nn][vn] == 'T'));
		   nn--, vn++)
		;
	      if (vn == 4)
		printf ("Case #%d: X won\n", cs);
	      else
		{
		  for (nn = 0;
		       (nn < 4) && ((s[nn][nn] == 'O') || (s[nn][nn] == 'T'));
		       nn++)
		    ;
		  if (nn == 4)
		    printf ("Case #%d: O won\n", cs);
		  else
		    {
		      for (nn = 3, vn = 0;
			   (nn >= 0) && ((s[nn][vn] == 'O')
					 || (s[nn][vn] == 'T')); nn--, vn++)
			;
		      if (vn == 4)
			printf ("Case #%d: O won\n", cs);
		      else
			{
			  for (score = 0; score < 4; score++)
			    {
			      for (nn = 0; (nn < 4) && (s[score][nn] != '.');
				   nn++)
				;
			      if (nn < 4)
				break;
			    }
			  if (score < 4)
			    printf ("Case #%d: Game has not completed\n", cs);
			  else
			    printf ("Case #%d: Draw\n", cs);
			}
		    }
		}
	    }
	}
    }
  return 0;
}
