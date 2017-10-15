#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int data[100][100];
int cs;
int tn;
int
check (int r, int y)
{
  int dest_;
  int oa_base;
  int f = data[r][y];
  int answer = 1;
  for (dest_ = 0; dest_ < cs; ++dest_)
    {
      if (f < data[dest_][y])
	{
	  answer = 0;
	  break;
	}
    }
  if (answer)
    return 1;
  for (dest_ = 0; dest_ < tn; ++dest_)
    {
      if (f < data[r][dest_])
	{
	  return 0;
	}
    }
  return 1;
}

int
Main (void)
{
  int num;
  int dest_;
  int oa_base;
  int s;
  int answer;
  scanf ("%d", &num);
  for (dest_ = 1; dest_ <= num; ++dest_)
    {
      scanf ("%d %d", &cs, &tn);
      for (oa_base = 0; oa_base < cs; ++oa_base)
	{
	  for (s = 0; s < tn; ++s)
	    {
	      scanf ("%d", &data[oa_base][s]);
	    }
	}
      answer = 1;
      for (oa_base = 0; oa_base < cs; ++oa_base)
	{
	  for (s = 0; s < tn; ++s)
	    {
	      if (!check (oa_base, s))
		{
		  answer = 0;
		  goto LAST;
		}
	    }
	}
    LAST:
      printf ("Case #%d: ", dest_);
      if (answer)
	{
	  printf ("YES\n");
	}
      else
	{
	  printf ("NO\n");
	}
    }
  return 0;
}
