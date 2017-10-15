#include<stdio.h>
int Main()
{
  int subject;
  scanf("%d", &subject);
  int n;
  int map;
  for (n = 1; n <= subject; n++)
  {
    int l;
    scanf("%d", &l);
    int i;
    int flipper;
    map = 0;
    for (i = 0; i < 4; i++)
      for (flipper = 0; flipper < 4; flipper++)
    {
      int tmp;
      scanf("%d", &tmp);
      if (i != (l - 1))
        continue;

      map |= 1 << (tmp - 1);
    }


    scanf("%d", &l);
    int ans;
    int ansc = 0;
    for (i = 0; i < 4; i++)
      for (flipper = 0; flipper < 4; flipper++)
    {
      int tmp;
      scanf("%d", &tmp);
      if (i != (l - 1))
        continue;

      int answer = (map >> (tmp - 1)) & 1;
      ansc += answer;
      if (answer)
        ans = tmp;

    }


    printf("Case #%d: ", n);
    if (ansc > 1)
      printf("Bad magician!\n");
    else
      if (ansc == 0)
      printf("Volunteer cheated!\n");
    else
      printf("%d\n", ans);


  }

  return 0;
}


