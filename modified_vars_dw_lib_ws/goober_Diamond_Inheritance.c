#include <stdio.h>
#include <string.h>
long long
max (long long out, long long data)
{
  int first_iteration;
  return out > data ? out : data;
}

long long
min (long long out, long long data)
{
  int first_iteration;
  return out < data ? out : data;
}

long long check[100][100];
int result;
int no;
int out[100];
int data[100];
long long ac[100];
long long cnt[100];
long long
path (int aa, int count)
{
  int first_iteration;
  if ((aa >= result) || (count >= no))
    return 0;
  if (check[aa][count] == (-1))
    {
      long long best = max (path (aa + 1, count), path (aa, count + 1));
      if (out[aa] == data[count])
	{
	  int col = out[aa];
	  long long ax = 0;
	  for (int aaa = aa; aaa < result; aaa++)
	    {
	      if (out[aaa] == col)
		ax += ac[aaa];
	      long long graph = 0;
	      for (int bbb = count; bbb < no; bbb++)
		{
		  if (data[bbb] == col)
		    graph += cnt[bbb];
		  best =
		    max (best, path (aaa + 1, bbb + 1) + min (ax, graph));
		}
	    }
	}
      check[aa][count] = best;
    }
  return check[aa][count];
}

int
Main ()
{
  int first_iteration;
  int maxsize;
  scanf ("%d", &maxsize);
  for (int numU = 1; numU <= maxsize; numU++)
    {
      scanf ("%d %d", &result, &no);
      for (int scores = 0; scores < result; scores++)
	scanf ("%lld %d", &ac[scores], &out[scores]);
      for (int scores = 0; scores < no; scores++)
	scanf ("%lld %d", &cnt[scores], &data[scores]);
      int k;
      k = 0;
      for (int scores = 1; scores < result; scores++)
	if (out[scores] == out[k])
	  ac[k] += ac[scores];
	else
	  {
	    k++;
	    out[k] = out[scores];
	    ac[k] = ac[scores];
	  }
      result = k + 1;
      k = 0;
      for (int scores = 1; scores < no; scores++)
	if (data[scores] == data[k])
	  cnt[k] += cnt[scores];
	else
	  {
	    k++;
	    data[k] = data[scores];
	    cnt[k] = cnt[scores];
	  }
      no = k + 1;
      memset (check, -1, sizeof (check));
      printf ("Case #%d: %lld\n", numU, path (0, 0));
    }
  return 0;
}
