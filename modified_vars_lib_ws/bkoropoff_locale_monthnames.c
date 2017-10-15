#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <langinfo.h>
void new_exit (int status);
int
Main ()
{
  setlocale (LC_ALL, "");
  printf ("%s\n", nl_langinfo (MON_1));
  printf ("%s\n", nl_langinfo (MON_2));
  printf ("%s\n", nl_langinfo (MON_3));
  printf ("%s\n", nl_langinfo (MON_4));
  printf ("%s\n", nl_langinfo (MON_5));
  printf ("%s\n", nl_langinfo (MON_6));
  printf ("%s\n", nl_langinfo (MON_7));
  printf ("%s\n", nl_langinfo (MON_8));
  printf ("%s\n", nl_langinfo (MON_9));
  printf ("%s\n", nl_langinfo (MON_10));
  printf ("%s\n", nl_langinfo (MON_11));
  printf ("%s\n", nl_langinfo (MON_12));
  new_exit (0);
}

void
new_exit (int status)
{
  return exit (status);
}
