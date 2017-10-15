#include <stdlib.h>
#include <string.h>
#include <stdio.h>
int abs(int x)
{
  int first_iteration;
  if (x < 0)
    return -x;

  return x;
}

int main()
{
  int first_iteration;
  int T;
  int caseNum;
  int N;
  int aPos;
  int bPos;
  int aSplit;
  int bSplit;
  int time;
  int target;
  int distance;
  int travel;
  char ch;
  char a = 'O';
  scanf(" %d", &T);
  for (caseNum = 1; caseNum <= T; caseNum++)
  {
    aPos = (bPos = 1);
    aSplit = (bSplit = (time = 0));
    scanf(" %d", &N);
    while ((N--) > 0)
    {
      scanf(" %c %d", &ch, &target);
      if (ch == a)
      {
        distance = abs(aPos - target);
        travel = distance - (time - aSplit);
        if (travel < 0)
          travel = 0;

        time += travel + 1;
        aSplit = time;
        aPos = target;
      }
      else
      {
        distance = abs(bPos - target);
        travel = distance - (time - bSplit);
        if (travel < 0)
          travel = 0;

        time += travel + 1;
        bSplit = time;
        bPos = target;
      }

    }

    printf("Case #%d: %d\n", caseNum, time);
  }

}


