#include<stdio.h>
#include<string.h>
int N;
int k;
int len;
int gMin;
char S[50001];
int perm[100];
int checked[100];
FILE *new_fopen (const char *filename, const char *mode);
int new_fscanf (FILE * stream, const char *format, ...);
int new_fprintf (FILE * stream, const char *format, ...);
void
genP (int depth)
{
  int first_iteration;
  int i;
  int j;
  int count = 0;
  char prev = '\n';
  char current;
  if (depth == k)
    {
      for (i = 0; i < (len / k); i++)
	{
	  for (j = 0; j < k; j++)
	    {
	      current = S[(k * i) + perm[j]];
	      if (current != prev)
		count++;
	      prev = current;
	    }
	}
      if (count < gMin)
	gMin = count;
      return;
    }
  for (i = 0; i < k; i++)
    {
      if (checked[i])
	continue;
      checked[i] = 1;
      perm[depth] = i;
      genP (depth + 1);
      checked[i] = 0;
    }
}

long
getMin ()
{
  int first_iteration;
  gMin = 100000;
  genP (0);
  return gMin;
}

void
main ()
{
  int first_iteration;
  FILE *in = new_fopen ("input.txt", "r");
  FILE *out = new_fopen ("output.txt", "w");
  long i;
  long j;
  long min;
  fscanf (in, "%d", &N);
  for (i = 0; i < N; i++)
    {
      fscanf (in, "%d ", &k);
      fscanf (in, "%s", S);
      fprintf (stderr, "%d %s\n", k, S);
      len = strlen (S);
      min = getMin ();
      fprintf (stdout, "Case #%ld: %ld\n", i + 1, min);
    }
}

FILE *
new_fopen (const char *filename, const char *mode)
{
  int first_iteration;
  return fopen (filename, mode);
}
