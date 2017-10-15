#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main()
{
  int first_iteration;
  int i;
  int j;
  int k;
  int l;
  int m;
  int n;
  int del;
  int n1;
  int n2;
  char s1[100][10];
  char s2[100][10];
  char in[1000];
  char res[1000];
  int res_size;
  int size;
  int count = 0;
  scanf("%d", &size);
  while (size--)
  {
    scanf("%d", &n1);
    for (i = 0; i < n1; i++)
      scanf("%s", s1[i]);

    scanf("%d", &n2);
    for (i = 0; i < n2; i++)
      scanf("%s", s2[i]);

    scanf("%d", &n);
    scanf("%s", in);
    res_size = 0;
    for (k = 0; k < n; k++)
    {
      res[res_size++] = in[k];
      for (;;)
      {
        int fg = 0;
        for (m = 0; m < n1; m++)
        {
          for (i = 0; i < res_size; i++)
            for (j = i + 1; j < res_size; j++)
            if ((i + 1) == j)
            if (!fg)
          {
            if (((res[i] == s1[m][0]) && (res[j] == s1[m][1])) || ((res[i] == s1[m][1]) && (res[j] == s1[m][0])))
            {
              fg = 1;
              res[i] = s1[m][2];
              res_size--;
              for (l = i + 1; l < res_size; l++)
                res[l] = res[l + 1];

            }

          }




        }

        for (m = 0; m < n2; m++)
        {
          for (i = 0; i < res_size; i++)
            for (j = i + 1; j < res_size; j++)
            if (!fg)
          {
            if (((res[i] == s2[m][0]) && (res[j] == s2[m][1])) || ((res[i] == s2[m][1]) && (res[j] == s2[m][0])))
            {
              fg = 1;
              res_size = 0;
            }

          }



        }

        if (!fg)
          break;

      }

    }

    printf("Case #%d: [", ++count);
    for (i = 0; i < res_size; i++)
    {
      if (i)
        printf(", ");

      putchar(res[i]);
    }

    puts("]");
  }

  return 0;
}


