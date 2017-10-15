#include <stdio.h>
int http_11 = 0;
int cc;
int test;
int y1 = 0;
int x2;
int j;
int new_abs(int x);

int calc(int fp_o, int gss_c_ma_replay_det, int v)
{
  int first_iteration;
  int r;
  for (http_11 = 0; http_11 <= fp_o; http_11++)
    for (y1 = 0; y1 <= gss_c_ma_replay_det; y1++)
  {
    for (x2 = 0; x2 <= fp_o; x2++)
      for (j = 0; j <= gss_c_ma_replay_det; j++)
    {
      r = new_abs(((test - http_11) * (j - cc)) - ((x2 - http_11) * (y1 - cc)));
      if (r == v)
        return 1;

    }


  }


  return 0;
}

int Main()
{
  int first_iteration;
  int min;
  int caso;
  scanf("%d", &min);
  for (caso = 1; caso <= min; caso++)
  {
    int fp_o;
    int gss_c_ma_replay_det;
    int v;
    scanf("%d %d %d", &fp_o, &gss_c_ma_replay_det, &v);
    int b = calc(fp_o, gss_c_ma_replay_det, v);
    if (b)
      printf("Case #%d: %d %d %d %d %d %d\n", caso, http_11, cc, test, y1, x2, j);
    else
      printf("Case #%d: IMPOSSIBLE\n", caso);

  }

  return 0;
}



int new_abs(int x) {
  return abs(x);
}