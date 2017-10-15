#include<stdio.h>
int t, o_won, x_won, uncompleted;
int T, a, b, c, d;
int tmp, N, M;
int F[100][100];
int G[100][100];
int
main ()
{
  scanf ("%d", &T);
  for (t = 1; t <= T; t++)
    {
      scanf ("%d", &N);
      scanf ("%d", &M);
      for (a = 0; a < N; a++)
	for (b = 0; b < M; b++)
	  {
	    scanf ("%d", &F[a][b]);
	    G[a][b] = 200;
	  }
      for (a = 0; a < N; a++)
	{
	  tmp = 0;
	  for (b = 0; b < M; b++)
	    {
	      if (F[a][b] > tmp)
		tmp = F[a][b];
	    }
	  for (b = 0; b < M; b++)
	    {
	      if (tmp < G[a][b])
		G[a][b] = tmp;
	    }
	}
      for (b = 0; b < M; b++)
	{
	  tmp = 0;
	  for (a = 0; a < N; a++)
	    {
	      if (F[a][b] > tmp)
		tmp = F[a][b];
	    }
	  for (a = 0; a < N; a++)
	    {
	      if (tmp < G[a][b])
		G[a][b] = tmp;
	    }
	}
      tmp = 0;
      for (a = 0; a < N; a++)
	for (b = 0; b < M; b++)
	  {
	    if (F[a][b] != G[a][b])
	      tmp = 1;
	  }
      printf ("Case #%d: ", t);
      if (tmp)
	puts ("NO");
      else
	puts ("YES");
    }
  return 0;
}
