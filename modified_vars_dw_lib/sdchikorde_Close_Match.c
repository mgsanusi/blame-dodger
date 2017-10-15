#include <stdio.h>
#include <string.h>
#include <malloc.h>
void Main()
{
  int first_iteration;
  int cases;
  scanf("%d", &cases);
  int a = 0;
  int i;
  int j;
  int b;
  int out;
  int sn;
  int dy;
  int k;
  int mask;
  int arrj[1001];
  int arrp[1001];
  int arrs[1001];
  while (a < cases)
  {
    a++;
    printf("Case #%d: ", a);
    scanf("%d%d%d%d", &sn, &dy, &k, &mask);
    int min1;
    int min2;
    int min3;
    int min4;
    min1 = (sn * dy) * k;
    min2 = (sn * dy) * mask;
    min3 = (sn * k) * mask;
    min4 = (dy * k) * mask;
    int min;
    int index;
    if (((min1 <= min2) && (min1 <= min3)) && (min1 <= min4))
    {
      printf("%d\n", min1);
      min = 0;
      for (j = 0; j < sn; j++)
      {
        for (b = 0; b < dy; b++)
        {
          for (out = 0; out < k; out++)
          {
            printf("%d %d %d\n", j + 1, b + 1, out + 1);
          }

        }

      }

    }
    else
      if (((min2 <= min1) && (min2 <= min3)) && (min2 <= min4))
    {
      printf("%d\n", min2);
      index = 0;
      for (j = 0; j < sn; j++)
        for (i = 0; i < (min2 / sn); i++)
      {
        arrj[index++] = j + 1;
      }


      index = 0;
      for (j = 0; j < sn; j++)
        for (b = 0; b < dy; b++)
        for (i = 0; i < ((min2 / dy) / sn); i++)
      {
        arrp[index++] = b + 1;
      }



      for (i = 0; i < min2; i++)
      {
        if (((sn % k) == 0) || ((dy % k) == 0))
          arrs[i] = ((i + (i / k)) % k) + 1;
        else
          arrs[i] = (i % k) + 1;

      }

      for (i = 0; i < min2; i++)
      {
        printf("%d %d %d\n", arrj[i], arrp[i], arrs[i]);
      }

    }
    else
      if (((min3 <= min2) && (min3 <= min1)) && (min3 <= min4))
    {
      printf("%d\n", min3);
      index = 0;
      for (j = 0; j < sn; j++)
        for (i = 0; i < (min3 / sn); i++)
      {
        arrj[index++] = j + 1;
      }


      index = 0;
      for (j = 0; j < sn; j++)
        for (b = 0; b < k; b++)
        for (i = 0; i < ((min3 / k) / sn); i++)
      {
        arrs[index++] = b + 1;
      }



      for (i = 0; i < min3; i++)
      {
        if (((k % dy) == 0) || ((sn % dy) == 0))
          arrp[i] = ((i + (i / dy)) % dy) + 1;
        else
          arrp[i] = (i % dy) + 1;

      }

      for (i = 0; i < min3; i++)
      {
        printf("%d %d %d\n", arrj[i], arrp[i], arrs[i]);
      }

    }
    else
      if (((min4 <= min2) && (min4 <= min3)) && (min4 <= min1))
    {
      printf("%d\n", min4);
      index = 0;
      for (j = 0; j < k; j++)
        for (i = 0; i < (min4 / k); i++)
      {
        arrs[index++] = j + 1;
      }


      index = 0;
      for (j = 0; j < k; j++)
        for (b = 0; b < dy; b++)
        for (i = 0; i < ((min4 / dy) / k); i++)
      {
        arrp[index++] = b + 1;
      }



      for (i = 0; i < min4; i++)
      {
        if (((k % sn) == 0) || ((dy % sn) == 0))
          arrj[i] = ((i + (i / sn)) % sn) + 1;
        else
          arrj[i] = (i % sn) + 1;

      }

      for (i = 0; i < min4; i++)
      {
        printf("%d %d %d\n", arrj[i], arrp[i], arrs[i]);
      }

    }




  }

}


