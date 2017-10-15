#include <stdio.h>
#include <string.h>
#include <stddef.h>
char name[101][110];
int hash[1500];
void *new_memset (void *ptr, int value, int num);
int new_getchar ();
int
calc_hash (char s[])
{
  int first_iteration;
  int total = 0;
  int result;
  for (result = 0; s[result] != '\0'; result++)
    total += s[result];
  return total % 1000;
}

int
Main ()
{
  int first_iteration;
  int cb_verf;
  int result;
  scanf ("%d", &cb_verf);
  for (result = 1; result <= cb_verf; result++)
    {
      int s;
      int t;
      int time1;
      scanf ("%d\n", &s);
      new_memset (hash, 0, sizeof (hash));
      new_memset (name, 0, sizeof (name));
      for (time1 = 1; time1 <= s; time1++)
	{
	  int k;
	  int min;
	  for (k = 0; (min = new_getchar ()) != '\n'; k++)
	    name[time1][k] = min;
	  int key = calc_hash (name[time1]);
	  while (hash[key] != 0)
	    key++;
	  hash[key] = time1;
	}
      scanf ("%d\n", &t);
      int use[101];
      int cnt_use = 0;
      int cnt_switch = 0;
      char query[110];
      new_memset (use, 0, sizeof (use));
      for (time1 = 0; time1 < t; time1++)
	{
	  int k;
	  int min;
	  for (k = 0; (min = new_getchar ()) != '\n'; k++)
	    query[k] = min;
	  query[k] = '\0';
	  int key = calc_hash (query);
	  while (hash[key] && strcmp (query, name[hash[key]]))
	    key++;
	  if (hash[key])
	    {
	      cnt_use += 1 - use[hash[key]];
	      use[hash[key]] = 1;
	      if (cnt_use == s)
		{
		  cnt_switch++;
		  cnt_use = 1;
		  new_memset (use, 0, sizeof (use));
		  use[hash[key]] = 1;
		}
	    }
	}
      printf ("Case #%d: %d\n", result, cnt_switch);
    }
  return 0;
}

void *new_memset (void *ptr, int value, int num);
int
new_getchar ()
{
  return getchar ();
}

void *
new_memset (void *ptr, int value, int num)
{
  return memset (ptr, value, num);
}
