#include <stdio.h>
#include <string.h>
int i;
int j;
int n;
int p;
int d;
int ss;
int tn;
int res[200];
int opp[26];
int comb[26][26];
char str[200];
int
Main ()
{
  int first_iteration;
  scanf ("%d", &tn);
  for (ss = 1; ss <= tn; ++ss)
    {
      memset (comb, -1, sizeof (comb));
      scanf ("%d", &p);
      for (i = 0; i < p; ++i)
	{
	  scanf ("%s", str);
	  comb[str[0] - 'A'][str[1] - 'A'] =
	    (comb[str[1] - 'A'][str[0] - 'A'] = str[2] - 'A');
	}
      memset (opp, 0, sizeof (opp));
      scanf ("%d", &d);
      for (i = 0; i < d; ++i)
	{
	  scanf ("%s", str);
	  opp[str[0] - 'A'] |= 1 << (str[1] - 'A');
	  opp[str[1] - 'A'] |= 1 << (str[0] - 'A');
	}
      scanf ("%d", &n);
      scanf ("%s", str);
      res[0] = 0;
      for (i = 0; str[i]; ++i)
	if (!res[0])
	  res[++res[0]] = str[i] - 'A';
	else if (comb[str[i] - 'A'][res[res[0]]] != (-1))
	  res[res[0]] = comb[str[i] - 'A'][res[res[0]]];
	else
	  {
	    for (j = res[0]; j >= 1; --j)
	      if (opp[str[i] - 'A'] & (1 << res[j]))
		break;
	    if (j)
	      res[0] = 0;
	    else
	      res[++res[0]] = str[i] - 'A';
	  }
      printf ("Case #%d: [", ss);
      for (i = 1; i < res[0]; ++i)
	printf ("%c, ", res[i] + 'A');
      if (res[0])
	putchar (res[res[0]] + 'A');
      printf ("]\n");
    }
  return 0;
}
