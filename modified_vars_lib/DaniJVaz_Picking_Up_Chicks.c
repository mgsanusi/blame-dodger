#include <stdio.h>
#include <stdlib.h>
void makeTestCase();
int Main()
{
  int i;
  int s1;
  scanf("%d", &s1);
  for (i = 1; i <= s1; i++)
  {
    printf("Case #%d: ", i);
    makeTestCase();
  }

  return 0;
}

void makeTestCase()
{
  int s1;
  int k;
  int in;
  int tmp;
  scanf("%d %d %d %d", &s1, &k, &in, &tmp);
  int pos[s1];
  int vel[s1];
  int i;
  int xu;
  int rslt;
  int sum;
  for (i = 0; i < s1; i++)
    scanf("%d", pos + i);

  for (i = 0; i < s1; i++)
    scanf("%d", vel + i);

  rslt = 0;
  sum = 0;
  xu = 0;
  for (i = s1 - 1; i >= 0; i--)
  {
    if ((pos[i] + (vel[i] * tmp)) >= in)
    {
      rslt += sum;
      xu++;
      if (xu == k)
        break;

    }
    else
    {
      sum++;
    }

  }

  if (xu == k)
    printf("%d\n", rslt);
  else
    printf("IMPOSSIBLE\n");

}


