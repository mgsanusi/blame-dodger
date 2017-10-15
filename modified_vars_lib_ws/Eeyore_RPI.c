#include <stdlib.h>
#include <string.h>
#include <stdio.h>
char buff[8192];
char result[101][101];
double rpi;
double cs;
double owps[100];
double owp;
double oowp;
int
Main ()
{
  int b;
  int caseNum;
  int mask;
  int i;
  int oaLength;
  int v;
  int cnt;
  int subCnt;
  char p;
  scanf (" %d", &b);
  for (caseNum = 1; caseNum <= b; caseNum++)
    {
      scanf (" %d", &mask);
      for (i = 0; i < mask; i++)
	scanf (" %s", result[i]);
      printf ("Case #%d:\n", caseNum);
      for (i = 0; i < mask; i++)
	{
	  owp = 0.0;
	  cnt = 0;
	  for (oaLength = 0; oaLength < mask; oaLength++)
	    {
	      if (result[i][oaLength] == '.')
		continue;
	      cnt++;
	      cs = 0.0;
	      subCnt = 0;
	      for (v = 0; v < mask; v++)
		{
		  if (((p = result[oaLength][v]) == '.') || (v == i))
		    continue;
		  subCnt++;
		  if (p == '1')
		    cs++;
		}
	      cs /= subCnt;
	      owp += cs;
	    }
	  owps[i] = owp / cnt;
	}
      for (i = 0; i < mask; i++)
	{
	  cs = (oowp = 0.0);
	  cnt = 0;
	  for (oaLength = 0; oaLength < mask; oaLength++)
	    {
	      if ((p = result[i][oaLength]) == '.')
		continue;
	      cnt++;
	      if (p == '1')
		cs++;
	      oowp += owps[oaLength];
	    }
	  cs /= cnt;
	  oowp /= cnt;
	  rpi = ((0.25 * cs) + (0.5 * owps[i])) + (0.25 * oowp);
	  printf ("%.12f\n", rpi);
	}
    }
}
