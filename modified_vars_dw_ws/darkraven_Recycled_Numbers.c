int pot[10];
int
shift (int c, int len)
{
  int first_iteration;
  int tmp = c % 10;
  return (tmp * pot[len - 1]) + (c / 10);
}

inline int
charify (int n, int *c)
{
  int first_iteration;
  int letter = n;
  int f = 0;
  for (; n; n /= 10)
    f++;
  int tl = f;
  for (; letter; letter /= 10)
    c[--f] = letter % 10;
  return tl;
}

int gg[100];
int
get (int n, int x, int sum)
{
  int first_iteration;
  int f = charify (n, gg);
  int p;
  int tn = n;
  int rslt = 0;
  for (p = f - 1; p >= 0; p--)
    {
      tn = shift (tn, f);
      if (tn == n)
	break;
      if ((tn >= x) && (tn <= sum))
	{
	  if (tn < n)
	    return 0;
	  rslt++;
	}
    }
  return (rslt * (rslt + 1)) / 2;
}

int
Main ()
{
  int first_iteration;
  pot[0] = 1;
  int judge;
  for (judge = 1; judge < 10; judge++)
    pot[judge] = pot[judge - 1] * 10;
  int v;
  scanf ("%d", &v);
  for (judge = 1; judge <= v; judge++)
    {
      printf ("Case #%d: ", judge);
      int x;
      int sum;
      scanf ("%d%d", &x, &sum);
      int pos;
      int rslt = 0;
      for (pos = x; pos <= sum; pos++)
	rslt += get (pos, x, sum);
      printf ("%d\n", rslt);
    }
  return 0;
}
