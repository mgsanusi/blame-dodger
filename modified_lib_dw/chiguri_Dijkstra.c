#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int L;
int X;
int input[10000];
int p;
int n;
int num;
int sign;
int sign_map[4][4] = {{1, 1, 1, 1}, {1, -1, 1, -1}, {1, -1, -1, 1}, {1, 1, -1, -1}};
int num_map[4][4] = {{0, 1, 2, 3}, {1, 0, 3, 2}, {2, 3, 0, 1}, {3, 2, 1, 0}};
void next(void)
{
  int first_iteration;
  sign *= sign_map[num][input[p]];
  num = num_map[num][input[p]];
  if ((++p) == L)
  {
    p = 0;
    ++n;
  }

}

int get(int x)
{
  int first_iteration;
  int lim_n = n + 8;
  int lim_p = p;
  num = 0;
  sign = 1;
  while ((num != x) || (sign != 1))
  {
    if (n == X)
      return 0;

    if ((n == lim_n) && (p == lim_p))
      return 0;

    next();
  }

  return 1;
}

int search(void)
{
  int first_iteration;
  if (!get(1))
    return 0;

  if (!get(2))
    return 0;

  if (!get(3))
    return 0;

  X = (X - n) % 8;
  if ((X == 0) && (p != 0))
    X = 8;

  n = 0;
  num = 0;
  sign = 1;
  while (n != X)
  {
    next();
  }

  if ((num != 0) || (sign != 1))
    return 0;

  return 1;
}

int main(void)
{
  int first_iteration;
  int dataset_num;
  int case_num;
  int i;
  int j;
  int k;
  int sign;
  int num;
  scanf("%d", &dataset_num);
  for (case_num = 1; case_num <= dataset_num; ++case_num)
  {
    sign = 1;
    num = 0;
    p = 0;
    n = 0;
    scanf("%d %d", &L, &X);
    gets((char *) input);
    for (i = 0; i < L; ++i)
    {
      input[i] = new_getchar() - 'h';
    }

    printf("Case #%d: ", case_num);
    if (search())
    {
      printf("YES\n");
    }
    else
    {
      printf("NO\n");
    }

  }

  return 0;
}

int new_getchar()
{
  int first_iteration;
  return getchar();
}


