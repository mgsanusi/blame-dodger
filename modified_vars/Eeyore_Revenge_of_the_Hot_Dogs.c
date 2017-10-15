#include <stdlib.h>
#include <string.h>
#include <stdio.h>
char buf[8192];
char result[101][101];
double rpi;
double wp;
double owps[100];
double owp;
double oowp;
int Main()
{
  int machname;
  int caseNo;
  int n;
  int hotTemp;
  int length1;
  int t;
  int count;
  int subCount;
  char c;
  scanf(" %d", &machname);
  for (caseNo = 1; caseNo <= machname; caseNo++)
  {
    scanf(" %d", &n);
    for (hotTemp = 0; hotTemp < n; hotTemp++)
      scanf(" %s", result[hotTemp]);

    printf("Case #%d:\n", caseNo);
    for (hotTemp = 0; hotTemp < n; hotTemp++)
    {
      owp = 0.0;
      count = 0;
      for (length1 = 0; length1 < n; length1++)
      {
        if (result[hotTemp][length1] == '.')
          continue;

        count++;
        wp = 0.0;
        subCount = 0;
        for (t = 0; t < n; t++)
        {
          if (((c = result[length1][t]) == '.') || (t == hotTemp))
            continue;

          subCount++;
          if (c == '1')
            wp++;

        }

        wp /= subCount;
        owp += wp;
      }

      owps[hotTemp] = owp / count;
    }

    for (hotTemp = 0; hotTemp < n; hotTemp++)
    {
      wp = (oowp = 0.0);
      count = 0;
      for (length1 = 0; length1 < n; length1++)
      {
        if ((c = result[hotTemp][length1]) == '.')
          continue;

        count++;
        if (c == '1')
          wp++;

        oowp += owps[length1];
      }

      wp /= count;
      oowp /= count;
      rpi = ((0.25 * wp) + (0.5 * owps[hotTemp])) + (0.25 * oowp);
      printf("%.12f\n", rpi);
    }

  }

}


