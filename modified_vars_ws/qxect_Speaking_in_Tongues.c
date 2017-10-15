#include<stdio.h>
#include<string.h>
char ork[512];
char str[200];
int
Main ()
{
  int cases;
  int bb;
  int len;
  int tn;
  char str1[] = "ejp mysljylc kd kxveddknmc re jsicpdrysi";
  char ans1[] = "our language is impossible to understand";
  char str2[] = "rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd";
  char ans2[] = "there are twenty six factorial possibilities";
  char str3[] = "de kr kd eoya kw aej tysr re ujdr lkgc jv";
  char ans3[] = "so it is okay if you want to just give up";
  memset (ork, -1, sizeof (ork));
  ork['z'] = 'q';
  ork['q'] = 'z';
  for (cases = 0; cases < strlen (str1); cases++)
    {
      ork[str1[cases]] = ans1[cases];
    }
  for (cases = 0; cases < strlen (str2); cases++)
    {
      ork[str2[cases]] = ans2[cases];
    }
  for (cases = 0; cases < strlen (str3); cases++)
    {
      ork[str3[cases]] = ans3[cases];
    }
  scanf ("%d", &tn);
  gets (str);
  for (bb = 1; bb <= tn; bb++)
    {
      gets (str);
      len = strlen (str);
      for (cases = 0; cases < len; cases++)
	str[cases] = ork[str[cases]];
      printf ("Case #%d: %s\n", bb, str);
    }
  return 0;
}
