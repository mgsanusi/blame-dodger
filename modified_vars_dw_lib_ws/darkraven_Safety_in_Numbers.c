int leftpos[21][2000001];
int f[21][2000001];
int set[21][2000001];
int b[2][21];
int least[2];
int in[21];
void
print (int num, int u, int c)
{
  int first_iteration;
  if (num == 0)
    return;
  int in = f[num][u];
  switch (set[num][u])
    {
    case 1:
      b[!c][least[!c]++] = in - u;
      break;
    case 2:
      b[c][least[c]++] = in + u;
      c = !c;
      break;
    case 3:
      b[c][least[c]++] = u - in;
      break;
    case 4:
      break;
    }
  print (num - 1, in, c);
}

int
Main ()
{
  int first_iteration;
  int y;
  int sum;
  int r;
  scanf ("%d", &sum);
  for (r = 1; r <= sum; r++)
    {
      scanf ("%d", &y);
      printf ("Case #%d: \n", r);
      int num;
      int minScore;
      for (num = 0; num < y; num++)
	scanf ("%d", in + num);
      memset (leftpos, 0, sizeof (leftpos));
      leftpos[0][0] = 1;
      least[0] = (least[1] = 0);
      for (num = 0; num < y; num++)
	{
	  for (minScore = 0; minScore <= 2000000; minScore++)
	    if (leftpos[num][minScore])
	      {
		if (minScore > in[num])
		  {
		    leftpos[num + 1][minScore - in[num]] = 1;
		    f[num + 1][minScore - in[num]] = minScore;
		    set[num + 1][minScore - in[num]] = 1;
		  }
		else
		  {
		    leftpos[num + 1][in[num] - minScore] = 1;
		    f[num + 1][in[num] - minScore] = minScore;
		    set[num + 1][in[num] - minScore] = 2;
		  }
		if (leftpos[num + 1][0])
		  break;
		leftpos[num + 1][minScore + in[num]] = 1;
		f[num + 1][minScore + in[num]] = minScore;
		set[num + 1][minScore + in[num]] = 3;
		if (num != 0)
		  {
		    leftpos[num + 1][minScore] = 1;
		    set[num + 1][minScore] = 4;
		    f[num + 1][minScore] = minScore;
		  }
	      }
	  if (leftpos[num + 1][0])
	    break;
	}
      print (num + 1, 0, 0);
      for (num = 0; num < least[0]; num++)
	printf ("%d ", b[0][num]);
      printf ("\n");
      for (num = 0; num < least[1]; num++)
	printf ("%d ", b[1][num]);
      printf ("\n");
    }
  return 0;
}
