#include <stdio.h>
int Main()
{
  int first_iteration;
  int seq;
  scanf("%d", &seq);
  for (int bishopput = 1; bishopput <= seq; bishopput++)
  {
    int output;
    scanf("%d", &output);
    int total = 0;
    int xor = 0;
    int least = 1000001;
    for (int i = 0; i < output; i++)
    {
      int a;
      scanf("%d", &a);
      total += a;
      xor ^= a;
      if (a < least)
        least = a;

    }

    if (xor != 0)
      printf("Case #%d: NO\n", bishopput);
    else
      printf("Case #%d: %d\n", bishopput, total - least);

  }

  return 0;
}


