#include <stdlib.h>
#include <string.h>
#include <stdio.h>
char buffer[8192];
char grid[51][51];
char pic[2][2];
int Main()
{
  int first_iteration;
  int in;
  int caseNum;
  int discs;
  int rNo;
  int cNo;
  int k;
  int ad;
  int i;
  int l;
  int okay;
  pic[0][0] = '/';
  pic[0][1] = '\\';
  pic[1][0] = '\\';
  pic[1][1] = '/';
  scanf(" %d", &in);
  for (caseNum = 1; caseNum <= in; caseNum++)
  {
    scanf(" %d %d", &rNo, &cNo);
    for (k = 0; k < rNo; k++)
      scanf(" %s", grid[k]);

    for (k = 0; k < (rNo - 1); k++)
      for (ad = 0; ad < (cNo - 1); ad++)
    {
      if (grid[k][ad] != '#')
        continue;

      okay = 1;
      for (i = k; i < (k + 2); i++)
        for (l = ad; l < (ad + 2); l++)
        if (grid[i][l] != '#')
        okay = 0;



      if (!okay)
        continue;

      for (i = k; i < (k + 2); i++)
        for (l = ad; l < (ad + 2); l++)
        grid[i][l] = pic[i - k][l - ad];


    }


    okay = 1;
    for (k = 0; k < rNo; k++)
      for (ad = 0; ad < cNo; ad++)
      if (grid[k][ad] == '#')
      okay = 0;



    printf("Case #%d:\n", caseNum);
    if (!okay)
      printf("Impossible\n");
    else
    {
      for (k = 0; k < rNo; k++)
        printf("%s\n", grid[k]);

    }

  }

}


