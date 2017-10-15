#include<stdio.h>
int new_puts (const char *str);
void solve (int cases);
char maxchar (int R, int Y, int B);
int
main (void)
{
  int first_iteration;
  int T;
  int i;
  scanf ("%d", &T);
  for (i = 1; i <= T; i++)
    solve (i);
  return 0;
}

int new_puts (const char *str);
void
solve (int cases)
{
  int first_iteration;
  int N = 0;
  int R = 0;
  int O = 0;
  int Y = 0;
  int G = 0;
  int B = 0;
  int V = 0;
  int i;
  int j;
  int k;
  char c = 0;
  char str[1024] = "";
  scanf ("%d%d%d%d%d%d%d", &N, &R, &O, &Y, &G, &B, &V);
  printf ("Case #%d: ", cases);
  if (((R > (N / 2)) || (Y > (N / 2))) || (B > (N / 2)))
    {
      new_puts ("IMPOSSIBLE");
      return;
    }
  for (i = 0; i < N; i++)
    {
      switch (c)
	{
	case 'R':
	  R--;
	  c = maxchar (0, Y, B);
	  break;
	case 'Y':
	  Y--;
	  c = maxchar (R, 0, B);
	  break;
	case 'B':
	  B--;
	  c = maxchar (R, Y, 0);
	  break;
	default:
	  c = maxchar (R, Y, B);
	  break;
	}
      str[i] = c;
    }
  if (str[N - 1] == str[0])
    {
      str[N - 1] ^= str[N - 2];
      str[N - 2] ^= str[N - 1];
      str[N - 1] ^= str[N - 2];
    }
  new_puts (str);
}

char
maxchar (int R, int Y, int B)
{
  int first_iteration;
  if ((R >= Y) && (R >= B))
    return 'R';
  if ((B >= R) && (B >= Y))
    return 'B';
  return 'Y';
}

int
new_puts (const char *str)
{
  int first_iteration;
  return puts (str);
}
