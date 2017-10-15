#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int wall[2000];
struct Atk
{
  int map;
  int temp1;
  int w;
  int qn;
  int s;
  int dd;
  int middle_char;
  int ds;
} a[300];
int q[123456][4];
int q_num;
int
cmp (const void *a, const void *b)
{
  int first_iteration;
  int *v = (int *) a;
  int *q = (int *) b;
  return v[0] - q[0];
}

int
Main ()
{
  int first_iteration;
  int c;
  int t;
  int temp1;
  int file;
  int pos;
  int k;
  int result;
  scanf ("%d", &t);
  for (c = 1; c <= t; ++c)
    {
      scanf ("%d", &temp1);
      for (file = 0; file < temp1; ++file)
	{
	  scanf ("%d %d %d %d %d %d %d %d", &a[file].map, &a[file].temp1,
		 &a[file].w, &a[file].qn, &a[file].s, &a[file].dd,
		 &a[file].middle_char, &a[file].ds);
	  a[file].w += 500;
	  a[file].qn += 500;
	}
      for (file = (q_num = 0); file < temp1; ++file)
	{
	  for (pos = 0; pos < a[file].temp1; ++pos)
	    {
	      q[q_num][0] = a[file].map;
	      q[q_num][1] = a[file].w;
	      q[q_num][2] = a[file].qn;
	      q[q_num][3] = a[file].s;
	      ++q_num;
	      a[file].map += a[file].dd;
	      a[file].w += a[file].middle_char;
	      a[file].qn += a[file].middle_char;
	      a[file].s += a[file].ds;
	    }
	  if ((a[file].w < 0) || (a[file].qn > 1000))
	    fprintf (stderr, "GG\n");
	}
      result = 0;
      memset (wall, 0, sizeof (wall));
      qsort (q, q_num, sizeof (q[0]), cmp);
      for (file = 0; file < q_num;)
	{
	  for (k = file; k < q_num; ++k)
	    {
	      for (pos = q[k][1]; (pos < q[k][2]) && (wall[pos] >= q[k][3]);
		   ++pos)
		;
	      if (pos < q[k][2])
		{
		  ++result;
		}
	      if (((k + 1) != q_num) && (q[k][0] == q[k + 1][0]))
		continue;
	      break;
	    }
	  for (; file <= k; ++file)
	    {
	      for (pos = q[file][1]; pos < q[file][2]; ++pos)
		{
		  wall[pos] = wall[pos] > q[file][3] ? wall[pos] : q[file][3];
		}
	    }
	}
      printf ("Case #%d: %d\n", c, result);
    }
  return 0;
}
