#include <stdlib.h>
#include <string.h>
#include <stdio.h>
char buffer[8192];
int xor(int input_file_name, int ans)
{
  return (input_file_name | ans) & (~(input_file_name & ans));
}

int Main()
{
  int n;
  int case_num;
  int sn;
  int pow[20];
  int mididx;
  int mask;
  int full;
  int small;
  for (mididx = 0; mididx < 20; mididx++)
    pow[mididx] = 1 << mididx;

  scanf(" %d", &n);
  for (case_num = 1; case_num <= n; case_num++)
  {
    scanf(" %d", &sn);
    full = (mask = 0);
    small = 2 * pow[19];
    while ((sn--) > 0)
    {
      scanf(" %d", &mididx);
      if (mididx < small)
        small = mididx;

      full += mididx;
      mask = xor(mask, mididx);
    }

    printf("Case #%d: ", case_num);
    if (mask == 0)
      printf("%d", full - small);
    else
      printf("NO");

    printf("\n");
  }

}


