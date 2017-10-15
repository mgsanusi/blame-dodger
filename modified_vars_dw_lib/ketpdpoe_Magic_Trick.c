#include<stdio.h>
int Main()
{
  int first_iteration;
  int s;
  int i;
  scanf("%d", &s);
  for (i = 0; i < s; i++)
  {
    int size[4][4];
    int t[8];
    int result[5];
    int a2 = 0;
    int g;
    int j;
    int b;
    int binsum;
    scanf("%d", &binsum);
    for (g = 0; g < 4; g++)
    {
      for (j = 0; j < 4; j++)
      {
        scanf("%d", &size[g][j]);
        if (g == (binsum - 1))
          t[j] = size[g][j];

      }

    }

    scanf("%d", &binsum);
    for (g = 0; g < 4; g++)
    {
      for (j = 0; j < 4; j++)
      {
        scanf("%d", &size[g][j]);
        if (g == (binsum - 1))
        {
          for (b = 0; b < 4; b++)
            if (t[b] == size[g][j])
          {
            result[a2] = t[b];
            a2++;
          }


        }

      }

    }

    printf("Case #%d: ", i + 1);
    if (a2 == 0)
      printf("Volunteer cheated!\n");
    else
      if (a2 == 1)
      printf("%d\n", result[0]);
    else
      printf("Bad magician!\n");


  }

  return 0;
}


