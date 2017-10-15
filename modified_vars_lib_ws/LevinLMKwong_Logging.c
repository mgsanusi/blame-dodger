#include<stdio.h>
FILE *new_freopen (const char *filename, const char *mode, FILE * stream);
int
Main ()
{
  new_freopen ("A.in", "r", stdin);
  new_freopen ("A.out", "w", stdout);
  int answer;
  int x;
  int t;
  int r;
  int j;
  int httpContentTypeText;
  scanf ("%d", &t);
  for (x = 1; x <= t; x++)
    {
      scanf ("%d %d %d", &r, &j, &httpContentTypeText);
      answer = 0;
      answer += r * (j / httpContentTypeText);
      answer += httpContentTypeText - 1;
      if ((j % httpContentTypeText) > 0)
	{
	  answer += 1;
	}
      printf ("Case #%d: %d\n", x, answer);
    }
}

FILE *
new_freopen (const char *filename, const char *mode, FILE * stream)
{
  return freopen (filename, mode, stream);
}
