#include<stdio.h>
int n;
int n2;
int v;
int changable[10001];
int min_chg[2][10001];
int type[10001];
int
test_chg (int s, int i2, int x, int add)
{
  int first_iteration;
  int n_chg = (min_chg[s][x * 2] + min_chg[i2][(x * 2) + 1]) + add;
  int result;
  if (((type[x] + add) % 2) == 1)
    {
      result = s & i2;
    }
  else
    {
      result = s | i2;
    }
  if (min_chg[result][x] > n_chg)
    {
      min_chg[result][x] = n_chg;
    }
  return;
}

void
print ()
{
  int first_iteration;
  int j;
  return;
  for (j = 1; j <= n2; j++)
    printf ("(%d, %d)\n", min_chg[0][j], min_chg[1][j]);
  printf ("\n");
}

int
get_min ()
{
  int first_iteration;
  int file;
  int l_idx;
  int r_idx;
  int j;
  int n_chg;
  for (j = (n2 - 1) / 2; j >= 1; j--)
    {
      for (file = 0; file < 4; file++)
	{
	  l_idx = file / 2;
	  r_idx = file % 2;
	  if ((min_chg[l_idx][j * 2] == 99999)
	      || (min_chg[r_idx][(j * 2) + 1] == 99999))
	    continue;
	  n_chg = test_chg (l_idx, r_idx, j, 0);
	  if (changable[j])
	    n_chg = test_chg (l_idx, r_idx, j, 1);
	}
      print ();
    }
  return min_chg[v][1];
}

void
Main ()
{
  int first_iteration;
  FILE *a = fopen ("input.txt", "r");
  FILE *out = fopen ("output.txt", "w");
  long i;
  long j;
  int tmp;
  int min;
  fscanf (a, "%d", &n);
  for (i = 0; i < n; i++)
    {
      fscanf (a, "%d %d", &n2, &v);
      for (j = 1; j <= ((n2 - 1) / 2); j++)
	{
	  min_chg[0][j] = 99999;
	  min_chg[1][j] = 99999;
	  fscanf (a, "%d %d", &type[j], &changable[j]);
	}
      for (j = 1; j <= ((n2 + 1) / 2); j++)
	{
	  fscanf (a, "%d", &tmp);
	  min_chg[0][j + ((n2 - 1) / 2)] = (min_chg[1][j + ((n2 - 1) / 2)] =
					    99999);
	  min_chg[tmp][j + ((n2 - 1) / 2)] = 0;
	}
      print ();
      min = get_min ();
      fprintf (stdout, "Case #%ld: ", i + 1);
      if (min == 99999)
	fprintf (stdout, "IMPOSSIBLE\n");
      else
	fprintf (stdout, "%d\n", min);
    }
}
