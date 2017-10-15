#include<stdio.h>
int tt[10001];
int s[10001];
int ch[10001];
int foundx[10001][2];
int disks;
int size;
void run(int smallest)
{
  int first_iteration;
  int l;
  int len;
  int ret;
  scanf("%d %d", &disks, &size);
  for (l = 0; l <= disks; l++)
    foundx[l][0] = (foundx[l][1] = 1000000000);

  for (l = 1; l < ((disks + 1) / 2); l++)
  {
    scanf("%d %d", &ch[l], &s[l]);
  }

  for (; l <= disks; l++)
  {
    scanf("%d", &tt[l]);
    foundx[l][tt[l]] = 0;
    foundx[l][1 - tt[l]] = 1000000000;
  }

  for (l = (disks - 1) / 2; l; l--)
  {
    for (len = 0; len < 2; len++)
      if (foundx[l << 1][len] < 1000000000)
      for (ret = 0; ret < 2; ret++)
      if (foundx[(l << 1) | 1][ret] < 1000000000)
    {
      if (ch[l])
      {
        int cur = len & ret;
        if (foundx[l][cur] > (foundx[l << 1][len] + foundx[(l << 1) | 1][ret]))
          foundx[l][cur] = foundx[l << 1][len] + foundx[(l << 1) | 1][ret];

        if (s[l])
        {
          cur = len | ret;
          if (foundx[l][cur] > ((foundx[l << 1][len] + foundx[(l << 1) | 1][ret]) + 1))
            foundx[l][cur] = (foundx[l << 1][len] + foundx[(l << 1) | 1][ret]) + 1;

        }

      }
      else
      {
        int cur = len | ret;
        if (foundx[l][cur] > (foundx[l << 1][len] + foundx[(l << 1) | 1][ret]))
          foundx[l][cur] = foundx[l << 1][len] + foundx[(l << 1) | 1][ret];

        if (s[l])
        {
          cur = len & ret;
          if (foundx[l][cur] > ((foundx[l << 1][len] + foundx[(l << 1) | 1][ret]) + 1))
            foundx[l][cur] = (foundx[l << 1][len] + foundx[(l << 1) | 1][ret]) + 1;

        }

      }

    }




  }

  if (foundx[1][size] < 1000000000)
    printf("Case #%d: %d\n", smallest, foundx[1][size]);
  else
    printf("Case #%d: IMPOSSIBLE\n", smallest);

}

int Main()
{
  int first_iteration;
  int r;
  int num = 0;
  for (scanf("%d", &r); r--;)
    run(++num);

  return 0;
}


