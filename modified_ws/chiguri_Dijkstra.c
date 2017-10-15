#include<stdio.h>
#include<stdlib.h>
#include<string.h>
 
// for qsort
/*
int compare(int *t, int *s) {
    return *t - *s;
}
*/ 
int L, X;
int input[10000];
int p, n;
int num, sign;
  
// 1 -> 0, i -> 1, j -> 2, k -> 3
int sign_map[4][4] = { 
    {1, 1, 1, 1}, {1, -1, 1, -1}, {1, -1, -1, 1}, {1, 1, -1, -1} 
};
 int num_map[4][4] = { 
    {0, 1, 2, 3}, {1, 0, 3, 2}, {2, 3, 0, 1}, {3, 2, 1, 0} 
};

 void
next (void)
{
  sign *= sign_map[num][input[p]];
  num = num_map[num][input[p]];
  if (++p == L)
    {
      p = 0;
      ++n;
    }
}

  int
get (int x)
{
  int lim_n = n + 8;		// repeating 8 times makes 1
  int lim_p = p;
  num = 0;
  sign = 1;
  while (num != x || sign != 1)
    {
      if (n == X)
	return 0;
      if (n == lim_n && p == lim_p)
	return 0;
      next ();
    }
  return 1;
}

 int
search (void)
{
  if (!get (1))
    return 0;
  
    //puts("get i");
    if (!get (2))
    return 0;
  
    //puts("get j");
    if (!get (3))
    return 0;
  
    //puts("get k");
    //printf("%d %d with i, j, k\n", p, n);
    X = (X - n) % 8;
  if (X == 0 && p != 0)
    X = 8;
  n = 0;
  num = 0;
  sign = 1;
  while (n != X)
    {
      next ();
    }
  if (num != 0 || sign != 1)
    return 0;
  return 1;
}

   int
main (void)
{
  int dataset_num, case_num;
  int i, j, k;
  int sign, num;
   scanf ("%d", &dataset_num);
  for (case_num = 1; case_num <= dataset_num; ++case_num)
    {
      sign = 1;
      num = 0;
      p = 0;
      n = 0;
      scanf ("%d %d", &L, &X);
      gets ((char *) input);	// to skip newline
      for (i = 0; i < L; ++i)
	{
	  input[i] = getchar () - 'h';	// h i j k ...
	}
       printf ("Case #%d: ", case_num);
      if (search ())
	{
	  printf ("YES\n");
	}
      
      else
	{
	  printf ("NO\n");
	}
    }
   return 0;
}


