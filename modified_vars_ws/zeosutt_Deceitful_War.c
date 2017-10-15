#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int
Main (void)
{
  int i;
  int byte;
  int b;
  int l;
  int in;
  scanf ("%d", &in);
  for (i = 1; i <= in; i++)
    {
      int v;
      int len[100];
      int num[100][100] = { 0 };
      int tnum;
      int tmp_len;
      int temp1;
      char string[100][101];
      char tmp1[101] = "";
      scanf ("%d ", &v);
      for (byte = 0; byte < v; byte++)
	scanf ("%s%n ", string[byte], len + byte);
      tmp_len = 0;
      tnum = 1;
      for (byte = 1; byte <= len[0]; byte++)
	if (string[0][byte] == string[0][byte - 1])
	  tnum++;
	else
	  {
	    num[0][tmp_len] = tnum;
	    tmp1[tmp_len] = string[0][byte - 1];
	    tmp_len++;
	    tnum = 1;
	  }
      temp1 = 1;
      for (byte = 1; byte < v; byte++)
	{
	  char tmp2[101] = "";
	  tmp_len = 0;
	  tnum = 1;
	  for (b = 1; b <= len[byte]; b++)
	    if (string[byte][b] == string[byte][b - 1])
	      tnum++;
	    else
	      {
		num[byte][tmp_len] = tnum;
		tmp2[tmp_len] = string[byte][b - 1];
		tmp_len++;
		tnum = 1;
	      }
	  if (strcmp (tmp1, tmp2))
	    {
	      temp1 = 0;
	      break;
	    }
	}
      if (temp1)
	{
	  int result;
	  int total;
	  int min;
	  result = 0;
	  for (byte = 0; byte < tmp_len; byte++)
	    {
	      min = 1000000000;
	      for (b = 1; b <= 100; b++)
		{
		  total = 0;
		  for (l = 0; l < v; l++)
		    total += abs (b - num[l][byte]);
		  min = min < total ? min : total;
		}
	      result += min;
	    }
	  printf ("Case #%d: %d\n", i, result);
	}
      else
	printf ("Case #%d: Fegla Won\n", i);
    }
  return 0;
}
