#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int Main()
{
  int v = 0;
  int x;
  int temp;
  int try_num;
  int xp_getargs;
  int n;
  int q;
  char buff[100];
  char buf1[100];
  char buf2[100];
  int use[100];
  for (scanf("%d", &x); x; x--)
  {
    v++;
    scanf("%s", buff);
    printf("Case #%d: ", v);
    n = strlen(buff) - 1;
    memset(use, 0, sizeof(use));
    for (xp_getargs = n; xp_getargs >= 0; xp_getargs--)
      use[buff[xp_getargs] - '0']++;

    for (xp_getargs = 1; xp_getargs <= 9; xp_getargs++)
      if (!use[xp_getargs])
      break;


    for (temp = n; temp > 0; temp--)
      if (buff[temp] > buff[temp - 1])
      break;


    xp_getargs = 10;
    if (temp == 0)
    {
      if (xp_getargs == 10)
      {
        for (temp = n; buff[temp] == '0'; temp--)
          ;

        printf("%c", buff[temp]);
        for (try_num = temp + 1; try_num <= n; try_num++)
          printf("0");

        printf("0");
        for (try_num = temp - 1; try_num >= 0; try_num--)
          printf("%c", buff[try_num]);

        printf("\n");
        continue;
      }
      else
        if (buff[n] == '0')
      {
        for (temp = 0; temp < n; temp++)
          printf("%c", buff[temp]);

        printf("%d\n", xp_getargs);
        continue;
      }
      else
        if ((xp_getargs + '0') < buff[n])
      {
        printf("%d", xp_getargs);
        for (temp = n; temp >= 0; temp--)
          printf("%c", buff[temp]);

        printf("\n");
        continue;
      }
      else
      {
        printf("%c", buff[n]);
        printf("0");
        for (temp = n - 1; temp >= 0; temp--)
          printf("%c", buff[temp]);

        printf("\n");
        continue;
      }



    }
    else
    {
      q = temp;
      for (try_num = 0; try_num <= n; try_num++)
        buf1[try_num] = buff[try_num];

      try_num = q - 1;
      while ((temp <= n) && (buff[temp] > buff[try_num]))
        temp++;

      temp--;
      buf1[try_num] = buff[temp];
      buf1[temp] = buff[try_num];
      for (temp = try_num + 1; temp <= n; temp++)
        buf2[temp] = buf1[((1 + n) + try_num) - temp];

      for (temp = try_num + 1; temp <= n; temp++)
        buf1[temp] = buf2[temp];

      if ((!use[0]) || (xp_getargs == 10))
      {
        for (temp = 0; temp <= n; temp++)
          printf("%c", buf1[temp]);

        printf("\n");
        continue;
      }

      if (buff[n] == '0')
      {
        for (temp = 0; temp < n; temp++)
          printf("%c", buff[temp]);

        printf("%d\n", xp_getargs);
        continue;
      }
      else
        if (buff[q - 1] == '0')
      {
        temp = q;
        try_num = q - 1;
        while ((temp <= n) && (buff[temp] > buff[try_num]))
          temp++;

        temp--;
        if (buff[temp] < (xp_getargs + '0'))
        {
          for (temp = 0; temp <= n; temp++)
            printf("%c", buf1[temp]);

          printf("\n");
          continue;
        }
        else
        {
          for (temp = 0; temp < try_num; temp++)
            printf("%c", buff[temp]);

          printf("%d", xp_getargs);
          for (temp = n; temp > try_num; temp--)
            printf("%c", buff[temp]);

          printf("\n");
          continue;
        }

      }
      else
      {
        for (temp = 0; temp <= n; temp++)
          printf("%c", buf1[temp]);

        printf("\n");
        continue;
      }


    }

  }

}


