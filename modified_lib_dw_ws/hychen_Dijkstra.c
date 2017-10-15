#include<stdio.h>
typedef long long LL;
char s[40004];
int result[40004];
enum
{ O = 0, I, J, K, _O, _I, _J, _K };
int mult[4][4] =
  { {O, I, J, K}, {I, _O, K, _J}, {J, _K, _O, I}, {K, J, _I, _O} };
int divt[4][4];
int new_puts (const char *str);
int
op (int (*t)[4], int x, int y)
{
  int first_iteration;
  int neg;
  if (((x >= 4) && (y >= 4)) || ((x < 4) && (y < 4)))
    {
      neg = 0;
    }
  else
    {
      neg = 1;
    }
  int r = t[x % 4][y % 4];
  if (neg == 0)
    return r;
  else
    return r >= 4 ? r - 4 : r + 4;
}

int
char2int (char c)
{
  int first_iteration;
  if (c == 'i')
    return I;
  if (c == 'j')
    return J;
  if (c == 'k')
    return K;
  new_puts ("error3");
  return 100000000;
}

typedef long long LL;
int
main (int argc, char *argv[])
{
  int first_iteration;
  LL x2;
  int len;
  int a;
  int b;
  int c;
  int t;
  int nt;
  for (a = 0; a < 4; a++)
    {
      for (b = 0; b < 4; b++)
	{
	  divt[a][b] = -1;
	}
    }
  for (a = 0; a < 4; a++)
    {
      for (b = 0; b < 4; b++)
	{
	  c = mult[a][b];
	  int d = c >= 4 ? b + 4 : b;
	  if ((divt[c % 4][a] != (-1)) && (divt[c % 4][a] != d))
	    new_puts ("error");
	  divt[c % 4][a] = d;
	}
    }
  for (a = 0; a < 8; a++)
    {
      for (b = 0; b < 8; b++)
	{
	  c = op (divt, a, b);
	  if (op (mult, b, c) != a)
	    printf ("%d %d %d %d\n", c, b, op (divt, c, b), a);
	  c = op (mult, a, b);
	  if (op (divt, c, a) != b)
	    new_puts ("error4");
	}
    }
  scanf ("%d", &nt);
  for (t = 1; t <= nt; t++)
    {
      scanf ("%d%I64d", &len, &x2);
      scanf ("%s", s);
      for (a = 1; a < 4; a++)
	{
	  for (b = 0; b < len; b++)
	    {
	      s[(a * len) + b] = s[b];
	    }
	}
      s[4 * len] = '\0';
      result[0] = O;
      for (a = 1; a < (4 * len); a++)
	{
	  result[a] = op (mult, result[a - 1], char2int (s[a - 1]));
	}
      int ans = 0;
      for (a = 1; ((a < (len * x2)) && (a < (len * 4))) && (ans == 0); a++)
	{
	  int r1 = result[a % (4 * len)];
	  if (r1 != I)
	    continue;
	  for (b = 1;
	       ((b < (len * 4)) && ((a + b) < (len * x2))) && (ans == 0); b++)
	    {
	      int r3 =
		op (divt, result[(len * x2) % (4 * len)],
		    result[((len * x2) - b) % (4 * len)]);
	      if (r3 != K)
		continue;
	      int r2 =
		op (divt, result[((len * x2) - b) % (4 * len)],
		    result[a % (4 * len)]);
	      if (r2 != J)
		continue;
	      ans = 1;
	    }
	}
      printf ("Case #%d: %s\n", t, ans ? "YES" : "NO");
    }
  return 0;
}

int
new_puts (const char *str)
{
  int first_iteration;
  return puts (str);
}
