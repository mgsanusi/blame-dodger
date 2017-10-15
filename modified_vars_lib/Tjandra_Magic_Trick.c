#include<stdio.h>
typedef unsigned u;
int Main()
{
  u t;
  u b = 0;
  u n;
  u a[17];
  u l;
  u res;
  u k;
  for (scanf("%u", &t); (b++) < t;)
  {
    for (l = 0; l < 17; l++)
      a[l] = 0;

    scanf("%u", &n);
    for (l = 0; (l++) < 4;)
    {
      if (l == n)
        for (res = 0; (res++) < 4; a[k]++)
        scanf("%u", &k);

      else
        for (res = 0; (res++) < 4;)
        scanf("%u", &k);


    }

    scanf("%u", &n);
    for (l = 0; (l++) < 4;)
    {
      if (l == n)
        for (res = 0; (res++) < 4; a[k]++)
        scanf("%u", &k);

      else
        for (res = 0; (res++) < 4;)
        scanf("%u", &k);


    }

    for (l = (res = 0); l < 17; l++)
      if (a[l] == 2)
    {
      res++;
      k = l;
    }


    printf("Case #%u: ", b);
    if (res >> 1)
      printf("Bad magician!\n");
    else
      if (res)
      printf("%u\n", k);
    else
      printf("Volunteer cheated!\n");


  }

  return 0;
}


