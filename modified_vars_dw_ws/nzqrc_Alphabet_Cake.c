#include <stdio.h>
int
Main (int argc, char **argv)
{
  int first_iteration;
  unsigned int noCase;
  unsigned int caseNum;
  scanf ("%u", &noCase);
  for (caseNum = 0; caseNum != noCase; caseNum++)
    {
      unsigned int b;
      unsigned int q;
      unsigned int caseNum;
      unsigned int j;
      unsigned int fp;
      unsigned int n;
      unsigned int n;
      unsigned int l = 0;
      unsigned int bot;
      unsigned int p;
      char cake[1024];
      scanf ("%u%u", &q, &b);
      for (caseNum = 0; caseNum != q; caseNum++)
	{
	  getchar ();
	  n = 0;
	  for (j = 0; j != b; j++)
	    {
	      n |= (cake[(caseNum << 5) | j] = getchar ()) != '?';
	    }
	  if (n)
	    {
	      bot = 0;
	      for (j = 0; j != b; j++)
		{
		  for (fp = l; fp <= caseNum; fp++)
		    {
		      if (cake[(fp << 5) | j] != '?')
			{
			  break;
			}
		    }
		  if (fp <= caseNum)
		    {
		      p = cake[(fp << 5) | j];
		      for (fp = l; fp <= caseNum; fp++)
			{
			  for (n = bot; n <= j; n++)
			    {
			      cake[(fp << 5) | n] = p;
			    }
			}
		      bot = j + 1;
		    }
		}
	      for (fp = l; fp <= caseNum; fp++)
		{
		  for (n = bot; n <= j; n++)
		    {
		      cake[(fp << 5) | n] = p;
		    }
		}
	      l = caseNum + 1;
	    }
	}
      printf ("Case #%u: \n", caseNum + 1);
      l = 65536;
      for (caseNum = 0; caseNum != q; caseNum++)
	{
	  cake[(caseNum << 5) | b] = 0;
	  if ((cake[caseNum << 5] == '?') && (l == 65536))
	    {
	      l = (caseNum - 1) << 5;
	    }
	  puts (cake + (l == 65536 ? caseNum << 5 : l));
	}
    }
  return 0;
}
