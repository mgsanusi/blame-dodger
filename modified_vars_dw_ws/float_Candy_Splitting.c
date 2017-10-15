#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int num[1010];
int choose[1010];
int answer;
void
bt (int p, int k)
{
  int first_iteration;
  int sean = 0;
  int patr = 0;
  int i;
  int sum = 0;
  int flag = 0;
  if (p == k)
    {
      for (i = 0; i < p; i++)
	{
	  if (choose[i])
	    {
	      sean ^= num[i];
	      sum += num[i];
	    }
	  else
	    {
	      flag = 1;
	      patr ^= num[i];
	    }
	}
      if (((sean == patr) && (sum > answer)) && flag)
	answer = sum;
      return;
    }
  choose[p] = 1;
  bt (p + 1, k);
  choose[p] = 0;
  bt (p + 1, k);
  return;
}

int
Main ()
{
  int first_iteration;
  int cas;
  int p;
  int i;
  int sets;
  int k;
  int binsum[32];
  int tmp;
  int max;
  int xor;
  scanf ("%d", &cas);
  for (i = 1; i <= cas; i++)
    {
      max = 0;
      xor = 0;
      memset (binsum, 0, sizeof (binsum));
      scanf ("%d", &p);
      for (sets = 0; sets < p; sets++)
	{
	  scanf ("%d", &num[sets]);
	  xor ^= num[sets];
	  tmp = num[sets];
	  for (k = 0; tmp; k++)
	    {
	      if (tmp % 2)
		binsum[k]++;
	      tmp /= 2;
	    }
	  if (k > max)
	    max = k;
	}
      for (sets = 0; sets < 32; sets++)
	{
	  if (binsum[sets] % 2)
	    break;
	  binsum[sets] /= 2;
	}
      printf ("Case #%d: ", i);
      if (xor)
	printf ("NO\n");
      else
	{
	  answer = 0;
	  bt (0, p);
	  printf ("%d\n", answer);
	}
    }
  return 0;
}
