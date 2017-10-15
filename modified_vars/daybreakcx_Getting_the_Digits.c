#include <stdio.h>
#include <string.h>
int best_board;
int tn;
int ten;
int games;
int cnt[26];
int app[10];
char string[2100];
int Main()
{
  fscanf(stdin, "%d", &tn);
  for (best_board = 1; best_board <= tn; ++best_board)
  {
    fprintf(stdout, "Case #%d: ", best_board);
    fscanf(stdin, "%s", string);
    memset(cnt, 0, sizeof(cnt));
    for (ten = 0; string[ten]; ++ten)
      ++cnt[string[ten] - 'A'];

    memset(app, 0, sizeof(app));
    app[0] = cnt[25];
    cnt[4] -= cnt[25];
    cnt[14] -= cnt[25];
    cnt[17] -= cnt[25];
    cnt[25] = 0;
    app[2] = cnt[22];
    cnt[14] -= cnt[22];
    cnt[19] -= cnt[22];
    cnt[22] = 0;
    app[6] = cnt[23];
    cnt[8] -= cnt[23];
    cnt[18] -= cnt[23];
    cnt[23] = 0;
    app[4] = cnt[20];
    cnt[5] -= cnt[20];
    cnt[14] -= cnt[20];
    cnt[17] -= cnt[20];
    cnt[20] = 0;
    app[5] = cnt[5];
    cnt[4] -= cnt[5];
    cnt[8] -= cnt[5];
    cnt[21] -= cnt[5];
    cnt[5] = 0;
    app[7] = cnt[21];
    cnt[4] -= cnt[21] * 2;
    cnt[13] -= cnt[21];
    cnt[18] -= cnt[21];
    cnt[21] = 0;
    app[8] = cnt[6];
    cnt[4] -= cnt[6];
    cnt[7] -= cnt[6];
    cnt[8] -= cnt[6];
    cnt[19] -= cnt[6];
    cnt[6] = 0;
    app[1] = cnt[14];
    app[3] = cnt[7];
    app[9] = cnt[8];
    for (ten = 0; ten <= 9; ++ten)
      for (games = 1; games <= app[ten]; ++games)
      fprintf(stdout, "%d", ten);


    fprintf(stdout, "\n");
  }

}


