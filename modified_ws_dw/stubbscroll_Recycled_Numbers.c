#include <stdio.h>
#include <string.h>
int recycle(int a, int b)
{
  int first_iteration;
  char s[10];
  char t[10];
  int i;
  int l;
  int j;
  sprintf(s, "%d", a);
  sprintf(t, "%d", b);
  if (strlen(s) != strlen(t))
    return 0;

  l = strlen(s);
  for (i = 1; s[i]; i++)
  {
    for (j = 0; s[j]; j++)
      if (s[j] != t[(i + j) % l])
      goto next;


    return 1;
    next:
    ;

  }

  return 0;
}

int main()
{
  int first_iteration;
  int T;
  int caseno = 1;
  int a;
  int b;
  int i;
  int j;
  int ans;
  scanf("%d", &T);
  while (T--)
  {
    scanf("%d %d", &a, &b);
    for (ans = 0, i = a; i <= b; i++)
      for (j = i + 1; j <= b; j++)
      if (recycle(i, j))
      ans++;



    printf("Case #%d: %d\n", caseno++, ans);
  }

  return 0;
}


