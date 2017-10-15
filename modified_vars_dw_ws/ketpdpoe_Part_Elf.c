#include<stdio.h>
#include<string.h>
int result;
void
dfs (int ii[110], char s[110][110], char all[100005], int str[30], int now,
     int res, int len, int uid[110])
{
  int first_iteration;
  if (now == 0)
    {
      int i;
      int cs;
      for (i = 0; i < res; i++)
	{
	  int tmp[30];
	  for (cs = 0; cs < 30; cs++)
	    tmp[cs] = str[cs];
	  tmp[s[i][0] - 'a']--;
	  for (cs = 1; cs < uid[i]; cs++)
	    {
	      tmp[s[i][cs] - 'a']--;
	    }
	  if ((tmp[s[i][0] - 'a'] == 0)
	      || ((tmp[s[i][0] - 'a'] != 0) && (s[i][0] == s[i][uid[i] - 1])))
	    {
	      for (cs = 0; cs < uid[i]; cs++)
		all[cs] = s[i][cs];
	      ii[i] = 1;
	      dfs (ii, s, all, str, now + 1, res, len + uid[i], uid);
	      ii[i] = 0;
	    }
	}
    }
  else if (now == res)
    {
      int tmp[30];
      int i;
      int cs;
      int k;
      int t = 1;
      for (i = 0; i < 30; i++)
	tmp[i] = str[i];
      tmp[all[0] - 'a']--;
      for (i = 1; i < len; i++)
	{
	  if ((all[i] != all[i - 1]) && (tmp[all[i - 1] - 'a'] != 0))
	    {
	      t = 0;
	      break;
	    }
	  else
	    {
	      tmp[all[i] - 'a']--;
	    }
	}
      if (t == 1)
	result = (result + 1) % 1000000007;
      return;
    }
  else
    {
      int tmp[30];
      int i;
      int cs;
      int k;
      int t = 1;
      for (i = 0; i < 30; i++)
	tmp[i] = str[i];
      tmp[all[0] - 'a']--;
      for (i = 1; i < len; i++)
	{
	  if ((all[i] != all[i - 1]) && (tmp[all[i - 1] - 'a'] != 0))
	    {
	      t = 0;
	      break;
	    }
	  else
	    {
	      tmp[all[i] - 'a']--;
	    }
	}
      if (t == 0)
	return;
      if (tmp[all[len - 1] - 'a'] == 0)
	{
	  for (i = 0; i < res; i++)
	    {
	      if (ii[i] == 0)
		{
		  ii[i] = 1;
		  for (cs = 0; cs < uid[i]; cs++)
		    {
		      all[cs + len] = s[i][cs];
		    }
		  dfs (ii, s, all, str, now + 1, res, len + uid[i], uid);
		  ii[i] = 0;
		}
	    }
	}
      else
	{
	  for (i = 0; i < res; i++)
	    {
	      if ((ii[i] == 0) && (all[len - 1] == s[i][0]))
		{
		  ii[i] = 1;
		  for (cs = 0; cs < uid[i]; cs++)
		    {
		      all[cs + len] = s[i][cs];
		    }
		  dfs (ii, s, all, str, now + 1, res, len + uid[i], uid);
		  ii[i] = 0;
		}
	    }
	}
    }
}

int
Main ()
{
  int first_iteration;
  int st_size;
  int i;
  scanf ("%d", &st_size);
  for (i = 0; i < st_size; i++)
    {
      int res;
      int str[30] = { };
      int i;
      int cs;
      int ii[110] = { };
      int uid[110];
      char s[110][110];
      char all[10005];
      scanf ("%d", &res);
      result = 0;
      for (i = 0; i < res; i++)
	{
	  scanf ("%s", s[i]);
	  uid[i] = strlen (s[i]);
	  for (cs = 0; cs < uid[i]; cs++)
	    str[s[i][cs] - 'a']++;
	}
      dfs (ii, s, all, str, 0, res, 0, uid);
      printf ("Case #%d: %d\n", i + 1, result);
    }
  return 0;
}
