#include <stdio.h>
#include <stdlib.h>
void handleCase ();
long long sum;
long long no;
long long j;
long long values[10001];
int
Main ()
{
  freopen ("b.in", "r", stdin);
  freopen ("b.out", "w", stdout);
  int n2;
  int y;
  scanf ("%d ", &y);
  for (n2 = 0; n2 < y; n2++)
    {
      printf ("Case #%d: ", n2 + 1);
      handleCase ();
    }
  return 0;
}

long long
findMax (long long begin, long long end, long long eneBegin, long long eneEnd)
{
  if (begin > end)
    {
      return 0;
    }
  long long high = -1ll;
  long long n2;
  for (n2 = begin; n2 <= end; n2++)
    {
      if ((high == (-1ll)) || (values[n2] > values[high]))
	{
	  high = n2;
	}
    }
  long long maxThen = eneBegin + (no * (high - begin));
  if (maxThen > sum)
    {
      maxThen = sum;
    }
  long long recAmo = (end - high) * no;
  long long saveAmo = eneEnd - recAmo;
  if (saveAmo < 0ll)
    {
      saveAmo = 0ll;
    }
  long long spend = maxThen - saveAmo;
  long long value = spend * values[high];
  value += findMax (begin, high - 1ll, eneBegin, maxThen - no);
  value += findMax (high + 1ll, end, saveAmo + no, eneEnd);
  return value;
}

void
handleCase ()
{
  scanf ("%I64d %I64d %I64d ", &sum, &no, &j);
  int n2;
  for (n2 = 0; n2 < j; n2++)
    {
      scanf ("%I64d ", &values[n2]);
    }
  printf ("%I64d\n", findMax (0, j - 1, sum, 0));
}
