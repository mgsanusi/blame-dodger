#include <stdio.h>
int ii[2020];
int r[2020];
int b[2020];
int buffer;
int found;
void erdos (int n);
void
label (int in, int in, int del, int *ex, int *n)
{
  int n;
  int m = 0;
  for (n = in; n != in; n += del)
    {
      if (ii[n])
	{
	  if (n[n] > m)
	    m = n[n];
	  ex[n] = 0;
	}
      else
	{
	  ex[n] = m + 1;
	}
    }
}

void
findX (int ret, int *expA, int *expB)
{
  int n;
  for (n = 1; n <= buffer; n++)
    {
      if ((expA[n] == r[n]) && (expB[n] == b[n]))
	{
	  ii[n] = ret;
	  erdos (ret + 1);
	  ii[n] = 0;
	}
    }
}

void
readstuff (void)
{
  int n;
  scanf ("%d", &buffer);
  for (n = 1; n <= buffer; n++)
    scanf ("%d", r + n);
  for (n = 1; n <= buffer; n++)
    scanf ("%d", b + n);
  for (n = 1; n <= buffer; n++)
    ii[n] = 0;
  found = 0;
}

void
dump (int n, int *expA, int *expB)
{
  printf ("i=%d\n", n);
  for (n = 1; n <= buffer; n++)
    printf ("%d ", expA[n]);
  printf ("\n");
  for (n = 1; n <= buffer; n++)
    printf ("%d ", expB[n]);
  printf ("\n");
}

void
erdos (int n)
{
  int expA[30];
  int expB[30];
  if (found)
    return;
  if (n <= buffer)
    {
      label (1, buffer + 1, 1, expA, r);
      label (buffer, 0, -1, expB, b);
      findX (n, expA, expB);
    }
  else
    {
      found = 1;
      for (n = 1; n <= buffer; n++)
	printf ("%d ", ii[n]);
      printf ("\n");
    }
}

int
Main (int argc, char **argv)
{
  int n;
  int start;
  scanf ("%d", &start);
  for (n = 1; n <= start; n++)
    {
      printf ("Case #%d: ", n);
      readstuff ();
      erdos (1);
    }
  return 0;
}
