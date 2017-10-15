#include<stdio.h>
 long long N, P, K, L;
long long freq[2000];
FILE *new_fopen (const char *filename, const char *mode);
int new_fscanf (FILE * stream, const char *format, ...);
 void
sort ()
{
  long long i, j, temp;
   for (i = 0; i < L; i++)
    for (j = i + 1; j < L; j++)
      if (freq[i] < freq[j])
	{
	  temp = freq[i];
	  freq[i] = freq[j];
	  freq[j] = temp;
	}
  return;
}

 long long
getMin ()
{
  long long sum = 0;
  long long i;
  for (i = 0; i < L; i++)
    {
      sum += (((i / K) + 1) * freq[i]);
    }
  return sum;
}

 void
main ()
{
  FILE * in = new_fopen ("input.txt", "r");
  FILE * out = new_fopen ("output.txt", "w");
  long long i, j;
  long long min;
   fscanf (in, "%lld", &N);
  for (i = 0; i < N; i++)
    {
      fscanf (in, "%lld %lld %lld", &P, &K, &L);
      for (j = 0; j < L; j++)
	fscanf (in, "%lld", &freq[j]);
       sort ();
      min = getMin ();
       fprintf (out, "Case #%lld: %lld\n", i + 1, min);
    }
}

FILE *
new_fopen (const char *filename, const char *mode)
{
  return fopen (filename, mode);
}
