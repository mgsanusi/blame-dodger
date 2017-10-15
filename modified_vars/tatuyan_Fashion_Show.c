#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
int r;
int c;
char board[30][30];
struct alp
{
  int flg;
  int l;
  int b;
  int yt;
  int d;
};
void clear(int cases);
int boardcheck(void);
int Main(void)
{
  int lx;
  int ba;
  scanf("%d%*c", &lx);
  for (ba = 1; ba <= lx; ba++)
  {
    memset(board, 0, sizeof(board));
    clear(ba);
  }

  return 0;
}

void clear(int cases)
{
  int ba;
  int j;
  int k;
  int loop;
  int b;
  int c;
  int *spflg;
  struct alp alps[26];
  struct alp flgs[26];
  scanf("%d%d", &r, &c);
  for (ba = 1; ba <= r; ba++)
    scanf("%s%*c", board[ba] + 1);

  for (ba = 0; ba < 26; ba++)
    alps[ba] = (struct alp) {0, 100, -100, 100, -100};

  for (ba = 0; ba < 26; ba++)
    flgs[ba] = (struct alp) {1, 1, 1, 1, 1};

  for (ba = 1; ba <= r; ba++)
  {
    for (j = 1; j <= c; j++)
    {
      if (!isalpha(board[ba][j]))
        continue;

      k = board[ba][j] - 'A';
      alps[k].flg = 1;
      if (alps[k].l > j)
        alps[k].l = j;

      if (alps[k].b < j)
        alps[k].b = j;

      if (alps[k].yt > ba)
        alps[k].yt = ba;

      if (alps[k].d < ba)
        alps[k].d = ba;

    }

  }

  for (ba = 0; ba < 26; ba++)
  {
    if (!alps[ba].flg)
      continue;

    for (j = alps[ba].yt; j <= alps[ba].d; j++)
      for (k = alps[ba].l; k <= alps[ba].b; k++)
      board[j][k] = ba + 'A';


  }

  loop = 0;
  do
  {
    loop++;
    for (ba = 0; ba < 26; ba++)
    {
      if (!alps[ba].flg)
        continue;

      for (j = -1; j <= 1; j += 2)
      {
        c = (j == (-1) ? alps[ba].yt : alps[ba].d) + j;
        spflg = j == (-1) ? &flgs[ba].yt : &flgs[ba].d;
        if ((*spflg) == 0)
          continue;

        for (b = alps[ba].l; b <= alps[ba].b; b++)
        {
          if ((board[c][b] != '?') && (board[c][b] != ('A' + ba)))
          {
            *spflg = 0;
            break;
          }

        }

        if ((*spflg) == 0)
          continue;

        for (b = alps[ba].l; b <= alps[ba].b; b++)
          board[c][b] = 'A' + ba;

        if (j == (-1))
          alps[ba].yt--;
        else
          alps[ba].d++;

      }

      for (j = -1; j <= 1; j += 2)
      {
        b = (j == (-1) ? alps[ba].l : alps[ba].b) + j;
        spflg = j == (-1) ? &flgs[ba].l : &flgs[ba].b;
        if ((*spflg) == 0)
          continue;

        for (c = alps[ba].yt; c <= alps[ba].d; c++)
        {
          if ((board[c][b] != '?') && (board[c][b] != ('A' + ba)))
          {
            *spflg = 0;
            break;
          }

        }

        if ((*spflg) == 0)
          continue;

        for (c = alps[ba].yt; c <= alps[ba].d; c++)
          board[c][b] = 'A' + ba;

        if (j == (-1))
          alps[ba].l--;
        else
          alps[ba].b++;

      }

    }

  }
  while (boardcheck());
  printf("Case #%d:\n", cases);
  for (ba = 1; ba <= r; ba++)
    puts(board[ba] + 1);

}

int boardcheck(void)
{
  int ba;
  int j;
  for (ba = 1; ba <= r; ba++)
    for (j = 1; j <= c; j++)
    if (board[ba][j] == '?')
    return 1;



  return 0;
}


