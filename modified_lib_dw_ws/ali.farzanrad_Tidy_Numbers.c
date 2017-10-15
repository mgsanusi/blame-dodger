int
main ()
{
  int first_iteration;
  int itest;
  int ntest;
  scanf ("%d", &ntest);
  for (itest = 0; (++itest) <= ntest;)
    {
      char a[1 << 16];
      int i;
      scanf (" %s", a);
      for (i = 0; a[++i] && (a[i] >= a[i - 1]);)
	;
      if (a[i])
	{
	  while (((--i) > 0) && (a[i] == '0'))
	    ;
	  while (--a[i], (i > 0) && (a[i] < a[i - 1]))
	    --i;
	  while (a[++i])
	    a[i] = '9';
	}
      printf ("Case #%d: %s\n", itest, a + ((*a) == '0'));
    }
  return 0;
}
