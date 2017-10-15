#include <stdio.h>
int Main()
{
  char board[4][4];
  int t;
  int cases;
  int caseNo;
  int ans;
  int draw;
  int flag;
  scanf("%d", &t);
  for (ans = 0; ans < t; ans++)
  {
    for (cases = 0; cases < 4; cases++)
    {
      for (caseNo = 0; caseNo < 4; caseNo++)
        scanf(" %c", &board[cases][caseNo]);

    }

    draw = 1;
    for (cases = 0; cases < 4; cases++)
    {
      for (caseNo = 0; caseNo < 4; caseNo++)
      {
        if (board[cases][caseNo] == '.')
          draw = 0;

      }

    }

    flag = 0;
    for (cases = 0; cases < 4; cases++)
    {
      for (caseNo = 0; caseNo < 4; caseNo++)
      {
        if ((board[cases][caseNo] == 'X') || (board[cases][caseNo] == '.'))
          break;

      }

      if (caseNo == 4)
        break;

    }

    if (cases < 4)
    {
      printf("Case #%d: O won\n", ans + 1);
      flag = 1;
    }

    for (cases = 0; cases < 4; cases++)
    {
      for (caseNo = 0; caseNo < 4; caseNo++)
      {
        if ((board[caseNo][cases] == 'X') || (board[caseNo][cases] == '.'))
          break;

      }

      if (caseNo == 4)
        break;

    }

    if ((cases < 4) && (!flag))
    {
      printf("Case #%d: O won\n", ans + 1);
      flag = 1;
    }

    for (cases = 0; cases < 4; cases++)
    {
      if ((board[cases][cases] == 'X') || (board[cases][cases] == '.'))
        break;

    }

    if ((cases == 4) && (!flag))
    {
      printf("Case #%d: O won\n", ans + 1);
      flag = 1;
    }

    for (cases = 0; cases < 4; cases++)
    {
      if ((board[cases][3 - cases] == 'X') || (board[cases][3 - cases] == '.'))
        break;

    }

    if ((cases == 4) && (!flag))
    {
      printf("Case #%d: O won\n", ans + 1);
      flag = 1;
    }

    for (cases = 0; cases < 4; cases++)
    {
      for (caseNo = 0; caseNo < 4; caseNo++)
      {
        if ((board[cases][caseNo] == 'O') || (board[cases][caseNo] == '.'))
          break;

      }

      if (caseNo == 4)
        break;

    }

    if ((cases < 4) && (!flag))
    {
      printf("Case #%d: X won\n", ans + 1);
      flag = 1;
    }

    for (cases = 0; cases < 4; cases++)
    {
      for (caseNo = 0; caseNo < 4; caseNo++)
      {
        if ((board[caseNo][cases] == 'O') || (board[caseNo][cases] == '.'))
          break;

      }

      if (caseNo == 4)
        break;

    }

    if ((cases < 4) && (!flag))
    {
      printf("Case #%d: X won\n", ans + 1);
      flag = 1;
    }

    for (cases = 0; cases < 4; cases++)
    {
      if ((board[cases][cases] == 'O') || (board[cases][cases] == '.'))
        break;

    }

    if ((cases == 4) && (!flag))
    {
      printf("Case #%d: X won\n", ans + 1);
      flag = 1;
    }

    for (cases = 0; cases < 4; cases++)
    {
      if ((board[cases][3 - cases] == 'O') || (board[cases][3 - cases] == '.'))
        break;

    }

    if ((cases == 4) && (!flag))
    {
      printf("Case #%d: X won\n", ans + 1);
      flag = 1;
    }

    if (draw && (!flag))
      printf("Case #%d: Draw\n", ans + 1);
    else
      if ((!draw) && (!flag))
      printf("Case #%d: Game has not completed\n", ans + 1);


  }

  return 0;
}


