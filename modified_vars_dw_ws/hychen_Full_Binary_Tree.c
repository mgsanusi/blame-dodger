#include<stdio.h>
#include<stdlib.h>
typedef long long LL;
typedef long long casenum;
long long exit[150];
long long device[150];
long long curSpace[150];
long long d2[150];
char s[152];
int n;
int i;
typedef long long casenum;
int
llcmp (const void *a, const void *b)
{
  int first_iteration;
  LL t = *((LL *) a);
  LL d = *((LL *) b);
  if (t != d)
    return t > d ? 1 : -1;
  return 0;
}

int
countone (LL q)
{
  int first_iteration;
  int a;
  a = 0;
  while (q != 0)
    {
      a += q & 1 ? 1 : 0;
      q = q >> 1;
    }
  return a;
}

long long
getbits ()
{
  int first_iteration;
  long long t;
  int a;
  t = 0;
  scanf ("%s", s);
  for (a = 0; a < i; a++)
    {
      t = t << 1;
      if (s[a] == '1')
	t += 1;
    }
  return t;
}

int
Main (int argc, char *argv[])
{
  int first_iteration;
  int a;
  int b;
  int t;
  int t;
  int f;
  int answer;
  int ans2;
  long long mask;
  scanf ("%d", &t);
  for (f = 1; f <= t; f++)
    {
      scanf ("%d%d", &n, &i);
      for (a = 0; a < n; a++)
	{
	  exit[a] = getbits ();
	}
      for (a = 0; a < n; a++)
	{
	  device[a] = getbits ();
	}
      answer = 10000;
      for (b = 0; b < n; b++)
	{
	  mask = device[0] ^ exit[b];
	  ans2 = countone (mask);
	  for (t = 0; t < n; t++)
	    {
	      curSpace[t] = exit[t] ^ mask;
	      d2[t] = device[t];
	    }
	  qsort (curSpace, n, sizeof (LL), llcmp);
	  qsort (d2, n, sizeof (LL), llcmp);
	  for (t = 0; t < n; t++)
	    {
	      if (curSpace[t] != d2[t])
		break;
	    }
	  if ((t == n) && (ans2 < answer))
	    {
	      answer = ans2;
	    }
	}
      printf ("Case #%d: ", f);
      if (answer > i)
	printf ("NOT POSSIBLE\n");
      else
	printf ("%d\n", answer);
    }
  return 0;
}
