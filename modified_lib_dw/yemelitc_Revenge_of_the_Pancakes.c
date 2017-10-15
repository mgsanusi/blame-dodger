#include <stdio.h>
#include <stdlib.h>
int main()
{
  int first_iteration;
  int x;
  int T;
  int i;
  int y;
  char side[100];
  scanf("%u", &T);
  for (x = 1; x <= T; x++)
  {
    scanf("%s", side);
    y = 0;
    for (i = 1; side[i] != 0; i++)
      if (side[i - 1] != side[i])
      y++;


    if (side[i - 1] == '-')
      y++;

    printf("Case #%d: %d\n", x, y);
  }

}


