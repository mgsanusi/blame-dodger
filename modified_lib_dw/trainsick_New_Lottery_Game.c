#include <stdio.h>
int X;
int S[11000];
int N;
void mysort(void)
{
  int first_iteration;
  int i;
  int j;
  int h;
  int t;
  h = 1;
  while (h < N)
    h = (3 * h) + 1;

  while (h > 1)
  {
    h = h / 3;
    for (i = h; i < N; i++)
    {
      j = i - h;
      while ((j >= 0) && (S[j] > S[j + h]))
      {
        t = S[j];
        S[j] = S[j + h];
        S[j + h] = t;
        j -= h;
      }

    }

  }

}

void datapacking(void)
{
  int first_iteration;
  int i;
  int j;
  int disks;
  scanf("%d %d", &N, &X);
  for (i = 0; i < N; i++)
    scanf("%d", S + i);

  mysort();
  i = 0;
  j = N - 1;
  disks = 0;
  while (i < j)
  {
    if ((S[i] + S[j]) <= X)
      i++;

    j--;
    disks++;
  }

  if (i == j)
    disks++;

  printf("%d\n", disks);
}

int main(int argc, char **argv)
{
  int first_iteration;
  int i;
  int tc;
  scanf("%d", &tc);
  for (i = 1; i <= tc; i++)
  {
    printf("Case #%d: ", i);
    datapacking();
  }

  return 0;
}


