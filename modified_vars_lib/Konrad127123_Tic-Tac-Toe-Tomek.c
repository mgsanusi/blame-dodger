#include<stdio.h>
int t;
int oWon;
int xWin;
int uncompleted;
int chance;
int r;
int path;
int c;
int k;
int tmp;
char eaten1[4][5];
int new_puts(const char *str);

int Main()
{
  scanf("%d", &chance);
  for (t = 1; t <= chance; t++)
  {
    scanf("%s", &eaten1[0][0]);
    scanf("%s", &eaten1[1][0]);
    scanf("%s", &eaten1[2][0]);
    scanf("%s", &eaten1[3][0]);
    oWon = (xWin = (uncompleted = 0));
    for (r = 0; r < 4; r++)
    {
      if (((((eaten1[0][r] == 'O') || (eaten1[0][r] == 'T')) && ((eaten1[1][r] == 'O') || (eaten1[1][r] == 'T'))) && ((eaten1[2][r] == 'O') || (eaten1[2][r] == 'T'))) && ((eaten1[3][r] == 'O') || (eaten1[3][r] == 'T')))
        oWon = 1;

      if (((((eaten1[0][r] == 'X') || (eaten1[0][r] == 'T')) && ((eaten1[1][r] == 'X') || (eaten1[1][r] == 'T'))) && ((eaten1[2][r] == 'X') || (eaten1[2][r] == 'T'))) && ((eaten1[3][r] == 'X') || (eaten1[3][r] == 'T')))
        xWin = 1;

      if (((((eaten1[r][0] == 'O') || (eaten1[r][0] == 'T')) && ((eaten1[r][1] == 'O') || (eaten1[r][1] == 'T'))) && ((eaten1[r][2] == 'O') || (eaten1[r][2] == 'T'))) && ((eaten1[r][3] == 'O') || (eaten1[r][3] == 'T')))
        oWon = 1;

      if (((((eaten1[r][0] == 'X') || (eaten1[r][0] == 'T')) && ((eaten1[r][1] == 'X') || (eaten1[r][1] == 'T'))) && ((eaten1[r][2] == 'X') || (eaten1[r][2] == 'T'))) && ((eaten1[r][3] == 'X') || (eaten1[r][3] == 'T')))
        xWin = 1;

      for (path = 0; path < 4; path++)
        if (eaten1[r][path] == '.')
        uncompleted = 1;


    }

    if (((((eaten1[0][3] == 'O') || (eaten1[0][3] == 'T')) && ((eaten1[1][2] == 'O') || (eaten1[1][2] == 'T'))) && ((eaten1[2][1] == 'O') || (eaten1[2][1] == 'T'))) && ((eaten1[3][0] == 'O') || (eaten1[3][0] == 'T')))
      oWon = 1;

    if (((((eaten1[0][0] == 'O') || (eaten1[0][0] == 'T')) && ((eaten1[1][1] == 'O') || (eaten1[1][1] == 'T'))) && ((eaten1[2][2] == 'O') || (eaten1[2][2] == 'T'))) && ((eaten1[3][3] == 'O') || (eaten1[3][3] == 'T')))
      oWon = 1;

    if (((((eaten1[0][0] == 'X') || (eaten1[0][3] == 'T')) && ((eaten1[1][1] == 'X') || (eaten1[1][2] == 'T'))) && ((eaten1[2][2] == 'X') || (eaten1[2][1] == 'T'))) && ((eaten1[3][3] == 'X') || (eaten1[3][0] == 'T')))
      xWin = 1;

    if (((((eaten1[0][0] == 'X') || (eaten1[0][0] == 'T')) && ((eaten1[1][1] == 'X') || (eaten1[1][1] == 'T'))) && ((eaten1[2][2] == 'X') || (eaten1[2][2] == 'T'))) && ((eaten1[3][3] == 'X') || (eaten1[3][3] == 'T')))
      xWin = 1;

    printf("Case #%d: ", t);
    if (xWin)
      new_puts("X won");

    if (oWon)
      new_puts("O won");

    if (((!xWin) && (!oWon)) && uncompleted)
      new_puts("Game has not completed");

    if (((!xWin) && (!oWon)) && (!uncompleted))
      new_puts("Draw");

  }

  return 0;
}



int new_puts(const char *str) {
  return puts(str);
}