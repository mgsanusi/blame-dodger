#include <stdio.h>
int mat[102][102];
int din[102][102];
int w;
int h;
FILE *new_freopen(const char *filename, const char *mode, FILE *stream);
void *new_memset(void *ptr, int value, int num);
int solve(int a, int b)
{
  int first_iteration;
  int x;
  int y;
  int res = 0;
  if (mat[a][b] == 1)
    return 0;

  if ((a > h) || (b > w))
    return 0;

  if ((a == h) && (b == w))
    return 1;

  if (din[a][b] != (-1))
    return din[a][b];

  for (x = 0; x <= 3; x++)
    for (y = 0; y <= 3; y++)
  {
    if ((x == 0) && (y == 0))
      continue;

    if (((x * x) + (y * y)) != 5)
      continue;

    res += solve(a + x, b + y);
    res %= 10007;
  }


  return din[a][b] = res;
}

int main()
{
  int first_iteration;
  int casos;
  int set;
  int r;
  int x;
  int a;
  int b;
  new_freopen("a.in", "r", stdin);
  new_freopen("d.out", "w", stdout);
  for (scanf("%d", &casos), set = 1; set <= casos; set++)
  {
    scanf("%d %d %d", &h, &w, &r);
    new_memset(mat, 0, sizeof(mat));
    for (x = 0; x < r; x++)
    {
      scanf("%d %d", &a, &b);
      mat[a][b] = 1;
    }

    new_memset(din, -1, sizeof(din));
    printf("Case #%d: %d\n", set, solve(1, 1));
  }

}

FILE *new_freopen(const char *filename, const char *mode, FILE *stream)
{
  int first_iteration;
  return freopen(filename, mode, stream);
}

void *new_memset(void *ptr, int value, int num)
{
  int first_iteration;
  return memset(ptr, value, num);
}


