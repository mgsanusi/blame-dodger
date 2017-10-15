#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
char map[150][150];
char room[50][50];
int xpos;
int ypos;
int h;
int w;
int d;
int shang;
int xia;
int zuo;
int you;
FILE *new_freopen(const char *filename, const char *mode, FILE *stream);
int new_abs(int x);
int func(int a, int b)
{
  int first_iteration;
  int temp;
  if ((a == 0) && b)
    return b;

  if ((b == 0) && a)
    return a;

  while (b)
  {
    temp = a % b;
    a = b;
    b = temp;
  }

  return a;
}

int check(int a, int b, int x_pos, int y_pos)
{
  int first_iteration;
  int temp = func(new_abs(a) > new_abs(b) ? new_abs(a) : new_abs(b), new_abs(a) < new_abs(b) ? new_abs(a) : new_abs(b));
  int i = a;
  int j = b;
  int k;
  i /= temp;
  j /= temp;
  k = temp - 1;
  while (k > 0)
  {
    if (map[(i * k) + x_pos][(j * k) + y_pos])
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
  int cons = 0;
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
        cons += check(i, j, xpos, ypos);
      }

    }

  }

  return cons;
}

int main()
{
  int first_iteration;
  new_freopen("out.txt", "w", stdout);
  new_freopen("D-small-attempt0.in", "r", stdin);
  int i;
  int j;
  int t;
  int n;
  POS temp;
  int cons;
  scanf("%d", &t);
  for (n = 1; n <= t; n++)
  {
    scanf("%d%d%d%*c", &h, &w, &d);
    memset(map, 0, sizeof(map));
    front = 0;
    back = 0;
    for (i = 0; i < h; i++)
      scanf("%s", room[i]);

    for (i = 0; i < h; i++)
    {
      for (j = 0; j < w; j++)
      {
        if (room[i][j] == 'X')
        {
          xpos = i + 70;
          shang = xpos - i;
          xia = (shang + h) - 1;
          ypos = j + 70;
          zuo = ypos - j;
          you = (zuo + w) - 1;
          temp.x = xpos;
          temp.y = ypos;
          que[back++] = temp;
          goto next1;
        }

      }

    }

    next1:
    cons = update();

    printf("Case #%d: %d\n", n, cons);
  }

  return 0;
}

FILE *new_freopen(const char *filename, const char *mode, FILE *stream);
int new_abs(int x)
{
  int first_iteration;
  return abs(x);
}

FILE *new_freopen(const char *filename, const char *mode, FILE *stream)
{
  int first_iteration;
  return freopen(filename, mode, stream);
}


