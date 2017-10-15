int
Main ()
{
  int y3;
  int m;
  int fc;
  int i1;
  int buttonId;
  int paths;
  int t;
  scanf ("%d", &fc);
  for (buttonId = 1; buttonId <= fc; buttonId++)
    {
      scanf ("%d%d%d", &y3, &m, &i1);
      if ((y3 * m) < i1)
	{
	  printf ("Case #%d: IMPOSSIBLE\n", buttonId);
	  continue;
	}
      paths = ((i1 + y3) - 1) / y3;
      t = (y3 - (i1 % y3)) % y3;
      printf ("Case #%d: %d %d %d %d %d %d\n", buttonId, 0, 0, t, paths, y3,
	      1);
    }
}
