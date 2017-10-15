#include <stdio.h>
int Main()
{
  int first_iteration;
  int b;
  int testCase = 0;
  for (scanf("%d", &b); b; b--)
  {
    int w;
    int bb;
    int deltaS;
    int i;
    int j;
    int ansLen;
    char cStr[0x7f][0x7f];
    char dString[0x7f][0x7f];
    char nString[0x7f];
    char answerStr[0x7f];
    for (scanf("%d", &w), i = 0; i < w; i++)
      scanf("%s", &cStr[i]);

    for (scanf("%d", &bb), i = 0; i < bb; i++)
      scanf("%s", &dString[i]);

    scanf("%d", &deltaS);
    scanf("%s", nString);
    ansLen = 0;
    for (deltaS = 0; nString[deltaS]; deltaS++)
    {
      answerStr[ansLen] = nString[deltaS];
      ansLen++;
      int combined = 0;
      if (ansLen > 1)
        for (i = 0; i < w; i++)
        if (((cStr[i][0] == answerStr[ansLen - 2]) && (cStr[i][1] == answerStr[ansLen - 1])) || ((cStr[i][1] == answerStr[ansLen - 2]) && (cStr[i][0] == answerStr[ansLen - 1])))
      {
        answerStr[ansLen - 2] = cStr[i][2];
        ansLen--;
        combined = 1;
        break;
      }



      int oppose = 0;
      if (!combined)
        for (i = 0; i < bb; i++)
        for (j = 0; j < (ansLen - 1); j++)
        if (((dString[i][0] == answerStr[ansLen - 1]) && (dString[i][1] == answerStr[j])) || ((dString[i][1] == answerStr[ansLen - 1]) && (dString[i][0] == answerStr[j])))
      {
        ansLen = 0;
        oppose = 1;
        break;
      }




    }

    testCase++;
    printf("Case #%d: [", testCase);
    if (!ansLen)
      printf("]\n");
    else
      for (i = 0; i < ansLen; i++)
      printf("%c%s", answerStr[i], i == (ansLen - 1) ? "]\n" : ", ");


  }

  return 0;
}


