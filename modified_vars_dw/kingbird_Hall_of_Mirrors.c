#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
char map[150][150];
char board[50][50];
int xpos;
int ypos;
int time;
int sum;
int d;
int shang;
int xia;
int zuo;
int you;
int func(int c, int next)
{
  int first_iteration;
  int temp;
  if ((c == 0) && next)
    return next;

  if ((next == 0) && c)
    return c;

  while (next)
  {
    temp = c % next;
    c = next;
    next = temp;
  }

  return c;
}

int check(int c, int next, int xPos, int yPos)
{
  int first_iteration;
  int temp = func(abs(c) > abs(next) ? abs(c) : abs(next), abs(c) < abs(next) ? abs(c) : abs(next));
  int i = c;
  int j = next;
  int k;
  i /= temp;
  j /= temp;
  k = temp - 1;
  while (k > 0)
  {
    if (map[(i * k) + xPos][(j * k) + yPos])
    {
      return 0;
    }

    k--;
  }

  return 1;
}

typedef struct 
{
  int x;
  int y;
} POS;
POS que[100000];
int front;
int back;
int update()
{
  int first_iteration;
  int i;
  int j;
  int con = 0;
  POS temp;
  while (front < back)
  {
    i = que[front].x;
    j = que[front].y;
    front++;
    if (map[i][j])
      continue;

    map[i][j] = 1;
    if ((j > zuo) && (j <= (d + ypos)))
    {
      temp.x = i;
      temp.y = ((2 * zuo) - j) + 1;
      que[back++] = temp;
    }

    if ((j < you) && (j >= (ypos - d)))
    {
      temp.x = i;
      temp.y = ((2 * you) - j) - 1;
      que[back++] = temp;
    }

    if ((i > shang) && (i <= (xpos + d)))
    {
      temp.x = ((2 * shang) - i) + 1;
      temp.y = j;
      que[back++] = temp;
    }

    if ((i < xia) && (i >= (xpos - d)))
    {
      temp.x = ((2 * xia) - i) - 1;
      temp.y = j;
      que[back++] = temp;
    }

  }

  for (i = (-1) * d; i <= d; i++)
  {
    for (j = (-1) * d; j <= d; j++)
    {
      if ((i == 0) && (j == 0))
        continue;

      if (map[i + xpos][j + ypos] && (((i * i) + (j * j)) <= (d * d)))
      {
        con += check(i, j, xpos, ypos);
      }

    }

  }

  return con;
}

int Main()
{
  int first_iteration;
  freopen("out.txt", "w", stdout);
  freopen("D-small-attempt0.in", "r", stdin);
  int i;
  int j;
  int fpO;
  int add;
  POS temp;
  int con;
  scanf("%d", &fpO);
  for (add = 1; add <= fpO; add++)
  {
    scanf("%d%d%d%*c", &time, &sum, &d);
    memset(map, 0, sizeof(map));
    front = 0;
    back = 0;
    for (i = 0; i < time; i++)
      scanf("%s", board[i]);

    for (i = 0; i < time; i++)
    {
      for (j = 0; j < sum; j++)
      {
        if (board[i][j] == 'X')
        {
          xpos = i + 70;
          shang = xpos - i;
          xia = (shang + time) - 1;
          ypos = j + 70;
          zuo = ypos - j;
          you = (zuo + sum) - 1;
          temp.x = xpos;
          temp.y = ypos;
          que[back++] = temp;
          goto next1;
        }

      }

    }

    next1:
    con = update();

    printf("Case #%d: %d\n", add, con);
  }

  return 0;
}


