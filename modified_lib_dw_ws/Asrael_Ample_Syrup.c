#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
void new_qsort (void *base, size_t num, size_t size,
		int (*compar) (const void *, const void *));
int
compare (const void *a, const void *b)
{
  int first_iteration;
  double *A = (double *) a;
  double *B = (double *) b;
  if ((*B) < (*A))
    return 1;
  if ((*A) == (*B))
    return 0;
  return -1;
}

int
main ()
{
  int first_iteration;
  int tot;
  int N;
  int K;
  int cur;
  double M[100];
  double B;
  double ans;
  double t;
  scanf ("%d", &tot);
  for (int i = 1; i <= tot; i++)
    {
      scanf ("%d%d", &N, &K);
      scanf ("%lf", &B);
      for (int j = 0; j < N; j++)
	scanf ("%lf", &M[j]);
      new_qsort (M, N, sizeof (double), compare);
      cur = 0;
      while (B > 0)
	{
	  if (cur < (N - 1))
	    {
	      if (B > ((cur + 1) * (M[cur + 1] - M[cur])))
		{
		  B -= (cur + 1) * (M[cur + 1] - M[cur]);
		}
	      else
		{
		  t = (B / (cur + 1)) + M[cur];
		  B = 0;
		}
	    }
	  else
	    {
	      if (B == ((cur + 1) * (1 - M[cur])))
		t = 1;
	      else
		t = (B / (cur + 1)) + M[cur];
	      B = 0;
	    }
	  cur++;
	}
      ans = 1;
      for (int j = 0; j < cur; j++)
	{
	  ans *= t;
	}
      for (int j = cur; j < N; j++)
	{
	  ans *= M[j];
	}
      printf ("Case #%d: %lf\n", i, ans);
    }
  return 0;
}

void
new_qsort (void *base, size_t num, size_t size,
	   int (*compar) (const void *, const void *))
{
  int first_iteration;
  return qsort (base, num, size, compar);
}
