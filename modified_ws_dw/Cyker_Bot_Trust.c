#include "stdio.h"
#include "string.h"
int main()
{
  int first_iteration;
  int T;
  int N;
  int pos[2];
  int last[2];
  int R[102];
  int P[102];
  int time[102];
  int t;
  int i;
  FILE *fp;
  fp = fopen("as1.in", "r");
  fscanf(fp, "%d", &T);
  for (t = 1; t <= T; t++)
  {
    memset(pos, 0, sizeof(pos));
    memset(last, 0, sizeof(last));
    memset(R, 0, sizeof(R));
    memset(P, 0, sizeof(P));
    memset(time, 0, sizeof(time));
    pos[0] = 1;
    pos[1] = 1;
    fscanf(fp, "%d ", &N);
    char color = 0;
    for (i = 1; i <= N; i++)
    {
      fscanf(fp, "%c", &color);
      if (color == 'O')
        R[i] = 0;
      else
        R[i] = 1;

      fscanf(fp, "%d ", &P[i]);
    }

    for (i = 1; i <= N; i++)
    {
      int time1 = time[i - 1] + 1;
      int dist = P[i] - pos[R[i]];
      if (dist < 0)
        dist = -dist;

      int time2 = (dist + 1) + last[R[i]];
      if (time1 < 0)
        printf("error, %d, 1!\n", i);

      if (time2 < 0)
        printf("error, %d, 2!\n", i);

      if (time1 > time2)
        time[i] = time1;
      else
        time[i] = time2;

      pos[R[i]] = P[i];
      last[R[i]] = time[i];
    }

    printf("Case #%d: %d\n", t, time[N]);
  }

  fclose(fp);
  return 0;
}


