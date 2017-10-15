#include <stdio.h>
int Main()
{
  int first_iteration;
  int y;
  int tCase;
  for (scanf("%d", &tCase), y = 1; y <= tCase; y++)
  {
    int board;
    int i;
    int j;
    char mat[0x7f][0x7f];
    scanf("%d", &board);
    for (i = 0; i < board; i++)
      scanf("%s", mat[i]);

    int count[0x7f];
    float caseIdx[0x7f];
    float owp[0x7f];
    float oowp[0x7f];
    for (i = 0; i < board; i++)
    {
      count[i] = 0;
      for (j = 0; j < board; j++)
        if (mat[i][j] != '.')
        count[i]++;


    }

    for (i = 0; i < board; i++)
    {
      int winCount = 0;
      for (j = 0; j < board; j++)
        if (mat[i][j] == '1')
        winCount++;


      caseIdx[i] = (winCount * 1.0) / count[i];
    }

    for (i = 0; i < board; i++)
    {
      float wpCount = 0;
      for (j = 0; j < board; j++)
        if (mat[i][j] != '.')
        wpCount += ((caseIdx[j] * count[j]) - (mat[i][j] == '0')) / (count[j] - 1);


      owp[i] = wpCount / count[i];
    }

    for (i = 0; i < board; i++)
    {
      float owpCount = 0;
      for (j = 0; j < board; j++)
        if (mat[i][j] != '.')
        owpCount += owp[j];


      oowp[i] = owpCount / count[i];
    }

    printf("Case #%d:\n", y);
    for (i = 0; i < board; i++)
      printf("%f\n", ((0.25 * caseIdx[i]) + (0.5 * owp[i])) + (0.25 * oowp[i]));

  }

  return 0;
}


