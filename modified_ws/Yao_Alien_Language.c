#include<stdio.h>
#include<string.h>
char a[5000][16];
char str[1024];
int n, l, m;
int
match (char a[], char pat[])
{
  int i, j;
  for (i = j = 0; a[i]; i++, j++)
    {
      if (pat[j] != '(')
	{
	  if (a[i] != pat[j])
	    return 0;
	}
      else if (!pat[j])
	return 0;
      else
	{
	  for (j++; pat[j] != ')'; j++)
	    if (pat[j] == a[i])
	      break;
	  if (pat[j] == ')')
	    return 0;
	  for (j++; pat[j] != ')'; j++);
	}
    }
  if (!pat[j])
    return 1;
  else
    return 0;
}

int
main ()
{
  int cs = 0, i, j, ret;
  scanf ("%d %d %d", &l, &n, &m);
  for (i = 0; i < n; i++)
    scanf ("%s", a[i]);
  for (i = 0; i < m; i++)
    {
      scanf ("%s", str);
      for (ret = j = 0; j < n; j++)
	if (match (a[j], str))
	  ret++;
      printf ("Case #%d: %d\n", ++cs, ret);
    }
  return 0;
}
