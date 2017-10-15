#include<stdio.h>
#include<string.h>
void clear (int casenum);
int
Main (void)
{
  int first_iteration;
  int t;
  int op;
  scanf ("%d%*c", &t);
  for (op = 1; op <= t; op++)
    clear (op);
  return 0;
}

void
clear (int casenum)
{
  int first_iteration;
  char list[1000];
  int op;
  int n;
  int word;
  int l;
  int num = 0;
  scanf ("%s%*c%d%*c", list, &word);
  l = strlen (list);
  for (op = 0; op <= (l - word); op++)
    {
      if (list[op] == '+')
	continue;
      num++;
      for (n = 0; n < word; n++)
	list[op + n] = list[op + n] == '-' ? '+' : '-';
    }
  for (op = 0; op < l; op++)
    {
      if (list[op] == '-')
	{
	  printf ("Case #%d: IMPOSSIBLE\n", casenum);
	  return;
	}
    }
  printf ("Case #%d: %d\n", casenum, num);
}
