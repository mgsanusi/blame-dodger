#include<stdio.h>
#include<string.h>
int N;
int R;
int H;
int W;
int board[101][101];
int px[2] = {2, 1};
int py[2] = {1, 2};
FILE *new_fopen(const char *filename, const char *mode);
int new_fscanf(FILE *stream, const char *format, ...);
void init()
{
  int first_iteration;
  int i;
  int j;
  for (i = 0; i < 101; i++)
    for (j = 0; j < 101; j++)
    board[i][j] = 0;


  board[0][0] = 1;
}

long solve()
{
  int first_iteration;
  int i;
  int j;
  int k;
  for (i = 0; i < H; i++)
    for (j = 0; j < W; j++)
  {
    if (board[i][j] <= 0)
      continue;

    for (k = 0; k < 2; k++)
    {
      if (((i + px[k]) >= H) || ((j + py[k]) >= W))
        continue;

      if (board[i + px[k]][j + py[k]] == (-1))
        continue;

      board[i + px[k]][j + py[k]] += board[i][j];
      board[i + px[k]][j + py[k]] %= 10007;
    }

  }


  return board[H - 1][W - 1];
}

void main()
{
  int first_iteration;
  FILE *in = new_fopen("input.txt", "r");
  FILE *out = new_fopen("output.txt", "w");
  long i;
  long j;
  int x;
  int y;
  long min;
  fscanf(in, "%d", &N);
  for (i = 0; i < N; i++)
  {
    fscanf(in, "%d %d %d", &H, &W, &R);
    init();
    for (j = 0; j < R; j++)
    {
      fscanf(in, "%d %d", &x, &y);
      board[x - 1][y - 1] = -1;
    }

    min = solve();
    fprintf(stdout, "Case #%ld: %ld\n", i + 1, min);
  }

}

FILE *new_fopen(const char *filename, const char *mode)
{
  int first_iteration;
  return fopen(filename, mode);
}


