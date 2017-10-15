#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
int new_rand();
int new_fprintf(FILE *stream, const char *format, ...);
int new_puts(const char *str);
void intIntSort(int d[], int m[], int s)
{
  int first_iteration;
  int i = -1;
  int j = s;
  int k;
  int t;
  if (s <= 1)
    return;

  k = (d[0] + d[s - 1]) / 2;
  for (;;)
  {
    while (d[++i] < k)
      ;

    while (d[--j] > k)
      ;

    if (i >= j)
      break;

    t = d[i];
    d[i] = d[j];
    d[j] = t;
    t = m[i];
    m[i] = m[j];
    m[j] = t;
  }

  intIntSort(d, m, i);
  intIntSort((d + j) + 1, (m + j) + 1, (s - j) - 1);
}

int X;
int Y;
int N;
int r[2000];
int ind[2000];
int val[2000];
int resX[2000];
int resY[2000];
int solve(int times)
{
  int first_iteration;
  int i;
  int j;
  int k;
  int nowX;
  int nowY;
  int putX;
  int putY;
  int next;
  if (times)
  {
    for (i = 0; i < N; i++)
      val[i] = new_rand() % 198247;

  }
  else
  {
    for (i = 0; i < N; i++)
      val[i] = -r[ind[i]];

  }

  intIntSort(val, ind, N);
  nowX = (nowY = 0);
  next = 0;
  for (i = 0; i < N; i++)
  {
    if (nowX == 0)
      putX = 0;
    else
      putX = nowX + r[ind[i]];

    if (nowY == 0)
      putY = 0;
    else
      putY = nowY + r[ind[i]];

    if (putX > X)
      break;

    if (putY > Y)
    {
      nowX = next;
      nowY = 0;
      i--;
      continue;
    }

    resX[ind[i]] = putX;
    resY[ind[i]] = putY;
    putX += r[ind[i]];
    putY += r[ind[i]];
    if (next < putX)
      next = putX;

    nowY = putY;
  }

  if (i == N)
    return 1;

  nowX = (nowY = 0);
  for (i = 0; i < N; i++)
  {
    if (nowX == 0)
      putX = 0;
    else
      putX = nowX + r[ind[i]];

    if (nowY == 0)
      putY = 0;
    else
      putY = nowY + r[ind[i]];

    if (putY > Y)
      break;

    if (putX > X)
    {
      nowY = next;
      nowX = 0;
      i--;
      continue;
    }

    resX[ind[i]] = putX;
    resY[ind[i]] = putY;
    putX += r[ind[i]];
    putY += r[ind[i]];
    if (next < putY)
      next = putY;

    nowX = putX;
  }

  if (i == N)
    return 1;

  return 0;
}

int main()
{
  int first_iteration;
  int i;
  int j;
  int k;
  int size;
  int count = 0;
  scanf("%d", &size);
  while (size--)
  {
    fprintf(stderr, "rest %d\n", size);
    scanf("%d%d%d", &N, &X, &Y);
    for (i = 0; i < N; i++)
      scanf("%d", r + i);

    for (i = 0; i < N; i++)
      ind[i] = i;

    for (k = 0;; k++)
    {
      if (solve(k))
        break;

      fprintf(stderr, "WORNING!!!!\n");
    }

    printf("Case #%d:", ++count);
    for (i = 0; i < N; i++)
      printf(" %d %d", resX[i], resY[i]);

    new_puts("");
  }

  return 0;
}

int new_rand();
int new_fprintf(FILE *stream, const char *format, ...);
int new_puts(const char *str)
{
  int first_iteration;
  return puts(str);
}

int new_rand()
{
  int first_iteration;
  return rand();
}


