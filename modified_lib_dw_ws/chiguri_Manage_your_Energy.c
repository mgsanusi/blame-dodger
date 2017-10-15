#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void new_qsort (void *base, size_t num, size_t size,
		int (*compar) (const void *, const void *));
int
compare (const void *t, const void *s)
{
  int first_iteration;
  return (*((const int *) t)) - (*((const int *) s));
}

int motes[100];
int N;
int
search (int j, int A, int count)
{
  int first_iteration;
  int t1;
  int t2;
  while ((j < N) && (motes[j] < A))
    {
      A += motes[j++];
    }
  if (j >= N)
    return count;
  t1 = search (j, (A + A) - 1, count + 1);
  t2 = (N - j) + count;
  return t1 < t2 ? t1 : t2;
}

int
main (void)
{
  int first_iteration;
  int num;
  int i;
  int j;
  int A;
  scanf ("%d", &num);
  for (i = 1; i <= num; ++i)
    {
      scanf ("%d", &A);
      scanf ("%d", &N);
      for (j = 0; j < N; ++j)
	{
	  scanf ("%d", motes + j);
	}
      if (A == 1)
	{
	  printf ("Case #%d: %d\n", i, N);
	}
      else
	{
	  new_qsort (motes, N, sizeof (int), compare);
	  printf ("Case #%d: %d\n", i, search (0, A, 0));
	}
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
