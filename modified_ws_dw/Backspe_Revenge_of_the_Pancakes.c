#include <stdio.h>
int solve(int first, int count)
{
  int first_iteration;
  return (((count + first) / 2) * 2) - first;
}

int main()
{
  int first_iteration;
  int t;
  int T;
  char s[200];
  int i;
  int j;
  int k;
  scanf("%d", &T);
  for (t = 1; t <= T; t++)
  {
    scanf("%s", s);
    printf("Case #%d: ", t);
    j = 1;
    k = s[0] == '+' ? 0 : 1;
    for (i = 1; s[i] != '\0'; i++)
    {
      if (s[i - 1] != s[i])
        j++;

    }

    printf("%d\n", solve(k, j));
  }

}


