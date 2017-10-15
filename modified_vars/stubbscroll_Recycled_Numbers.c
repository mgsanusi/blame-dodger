#include <stdio.h>
#include <string.h>
int recycle(int p, int w)
{
  char s[10];
  char c[10];
  int i;
  int in;
  int tiempo;
  sprintf(s, "%d", p);
  sprintf(c, "%d", w);
  if (strlen(s) != strlen(c))
    return 0;

  in = strlen(s);
  for (i = 1; s[i]; i++)
  {
    for (tiempo = 0; s[tiempo]; tiempo++)
      if (s[tiempo] != c[(i + tiempo) % in])
      goto next;


    return 1;
    next:
    ;

  }

  return 0;
}

int Main()
{
  int m;
  int caseno = 1;
  int p;
  int w;
  int i;
  int tiempo;
  int result;
  scanf("%d", &m);
  while (m--)
  {
    scanf("%d %d", &p, &w);
    for (result = 0, i = p; i <= w; i++)
      for (tiempo = i + 1; tiempo <= w; tiempo++)
      if (recycle(i, tiempo))
      result++;



    printf("Case #%d: %d\n", caseno++, result);
  }

  return 0;
}


