#include <stdio.h>
#include <stdlib.h>
struct belt
{
  int start;
  int end;
  int extra;
};
int noBelts;
struct belt allBelts[5001];
FILE * new_freopen(const char *filename, const char *mode, FILE *stream);

void handleCase(void);
void sort(int start, int finish);
int Main()
{
  new_freopen("air.in", "r", stdin);
  new_freopen("air.out", "w", stdout);
  int noCase;
  scanf("%d ", &noCase);
  int best;
  for (best = 0; best < noCase; best++)
  {
    printf("Case #%d: ", best + 1);
    handleCase();
  }

  return 0;
}

FILE * new_freopen(const char *filename, const char *mode, FILE *stream);

void handleCase(void)
{
  int len;
  int walkSpeed;
  int carrySpeed;
  int maxTime;
  scanf("%d %d %d %d %d ", &len, &walkSpeed, &carrySpeed, &maxTime, &noBelts);
  double time = 0.0;
  int best;
  for (best = 0; best < noBelts; best++)
  {
    scanf("%d %d %d ", &allBelts[best].start, &allBelts[best].end, &allBelts[best].extra);
  }

  int noOrg = noBelts;
  if (allBelts[0].start != 0)
  {
    allBelts[noBelts].start = 0;
    allBelts[noBelts].end = allBelts[0].start;
    allBelts[noBelts].extra = 0;
    noBelts++;
  }

  for (best = 1; best < noOrg; best++)
  {
    if (allBelts[best].start != allBelts[best - 1].end)
    {
      allBelts[noBelts].start = allBelts[best - 1].end;
      allBelts[noBelts].end = allBelts[best].start;
      allBelts[noBelts].extra = 0;
      noBelts++;
    }

  }

  if (allBelts[noOrg - 1].end != len)
  {
    allBelts[noBelts].start = allBelts[noOrg - 1].end;
    allBelts[noBelts].end = len;
    allBelts[noBelts].extra = 0;
    noBelts++;
  }

  sort(0, noBelts - 1);
  double timeExitRun = (double) maxTime;
  double dis;
  double spe;
  double spe2;
  for (best = 0; best < noBelts; best++)
  {
    dis = (double) (allBelts[best].end - allBelts[best].start);
    spe = (double) (carrySpeed + allBelts[best].extra);
    spe2 = (double) (walkSpeed + allBelts[best].extra);
    if ((spe * timeExitRun) >= dis)
    {
      timeExitRun -= dis / spe;
      time += dis / spe;
    }
    else
    {
      dis -= spe * timeExitRun;
      time += timeExitRun;
      timeExitRun = 0.0;
      time += dis / spe2;
    }

  }

  printf("%.12lf\n", time);
}

void sort(int start, int finish)
{
  if ((finish - start) <= 0)
  {
    return;
  }

  int midPoint = (start + finish) / 2;
  sort(start, midPoint);
  sort(midPoint + 1, finish);
  int best;
  int place1;
  int place2;
  struct belt newSize[(finish - start) + 1];
  place1 = start;
  place2 = midPoint + 1;
  for (best = 0; best < ((finish - start) + 1); best++)
  {
    if (place1 > midPoint)
    {
      newSize[best] = allBelts[place2];
      place2++;
    }
    else
      if (place2 > finish)
    {
      newSize[best] = allBelts[place1];
      place1++;
    }
    else
    {
      if (allBelts[place1].extra < allBelts[place2].extra)
      {
        newSize[best] = allBelts[place1];
        place1++;
      }
      else
      {
        newSize[best] = allBelts[place2];
        place2++;
      }

    }


  }

  for (best = 0; best < ((finish - start) + 1); best++)
  {
    allBelts[start + best] = newSize[best];
  }

}



FILE * new_freopen(const char *filename, const char *mode, FILE *stream) {
  return freopen(filename, mode, stream);
}