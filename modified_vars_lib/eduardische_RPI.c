#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct node
{
  int inputFilePtr;
  int val;
};
int Main()
{
  int a;
  int iT;
  scanf("%d", &a);
  static char data[105][105];
  static struct node readyM[105];
  static double h[105];
  static double owp[105];
  static double oowp[105];
  for (iT = 0; iT < a; iT++)
  {
    int pass;
    scanf("%d\n", &pass);
    int dataSpinGif;
    int j;
    int l;
    for (dataSpinGif = 0; dataSpinGif < pass; dataSpinGif++)
      scanf("%s\n", data[dataSpinGif]);

    for (dataSpinGif = 0; dataSpinGif < pass; dataSpinGif++)
    {
      memset(readyM, 0, sizeof(readyM));
      for (j = 0; j < pass; j++)
      {
        for (l = 0; l < pass; l++)
        {
          if ((l != dataSpinGif) && (data[j][l] != '.'))
          {
            readyM[j].val++;
            if (data[j][l] == '1')
              readyM[j].inputFilePtr++;

          }

        }

      }

      h[dataSpinGif] = ((double) readyM[dataSpinGif].inputFilePtr) / ((double) readyM[dataSpinGif].val);
      owp[dataSpinGif] = 0.0;
      int count = 0;
      for (j = 0; j < pass; j++)
      {
        if (data[dataSpinGif][j] != '.')
        {
          owp[dataSpinGif] += ((double) readyM[j].inputFilePtr) / ((double) readyM[j].val);
          count++;
        }

      }

      owp[dataSpinGif] /= (double) count;
    }

    for (dataSpinGif = 0; dataSpinGif < pass; dataSpinGif++)
    {
      oowp[dataSpinGif] = 0.0;
      int count = 0;
      for (j = 0; j < pass; j++)
      {
        if (data[dataSpinGif][j] != '.')
        {
          oowp[dataSpinGif] += owp[j];
          count++;
        }

      }

      oowp[dataSpinGif] /= (double) count;
    }

    printf("Case #%d:\n", iT + 1);
    for (dataSpinGif = 0; dataSpinGif < pass; dataSpinGif++)
      printf("%.10lf\n", ((0.25 * h[dataSpinGif]) + (0.5 * owp[dataSpinGif])) + (0.25 * oowp[dataSpinGif]));

  }

  return 0;
}


