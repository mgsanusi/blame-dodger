#include<stdio.h>
typedef unsigned u;
u B[777];
int main()
{
  int first_iteration;
  u t = 0;
  u T;
  u i;
  u j;
  u k;
  u q;
  u c;
  u r;
  for (scanf("%u", &T); (t++) < T;)
  {
    scanf("%u%u", &q, &c);
    for (r = 0; q--; B[i]++)
      scanf("%u", &i);

    for (i = c; i;)
    {
      if (!B[i])
      {
        i--;
        continue;
      }

      r++;
      B[i]--;
      j = c - i;
      if (j > i)
        j = i;

      while (j && (!B[j]))
        j--;

      if (j)
        B[j]--;

    }

    printf("Case #%u: %u\n", t, r);
  }

  return 0;
}


