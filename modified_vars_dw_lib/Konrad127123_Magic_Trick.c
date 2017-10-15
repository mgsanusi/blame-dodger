#include<stdio.h>
int cnta;
int ti;
int ind[32];
int num[5][5];
int count;
int o;
int fg1;
int answer;
int numAnswer;
int Main()
{
  int first_iteration;
  scanf("%d", &ti);
  for (cnta = 1; cnta <= ti; cnta++)
  {
    scanf("%d", &answer);
    for (count = 1; count <= 4; count++)
      for (o = 1; o <= 4; o++)
    {
      scanf("%d", &num[count][o]);
    }


    for (fg1 = 0; fg1 < 32; fg1++)
      ind[fg1] = 0;

    for (o = 1; o <= 4; o++)
      ind[num[answer][o]]++;

    scanf("%d", &answer);
    for (count = 1; count <= 4; count++)
      for (o = 1; o <= 4; o++)
    {
      scanf("%d", &num[count][o]);
    }


    for (o = 1; o <= 4; o++)
      ind[num[answer][o]]++;

    answer = 0;
    numAnswer = 0;
    for (fg1 = 1; fg1 <= 16; fg1++)
      if (ind[fg1] > 1)
    {
      answer = fg1;
      numAnswer++;
    }


    printf("Case #%d: ", cnta);
    if (numAnswer == 0)
      printf("Volunteer cheated!\n");

    if (numAnswer == 1)
      printf("%d\n", answer);

    if (numAnswer > 1)
      printf("Bad magician!\n");

  }

  return 0;
}


