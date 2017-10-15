#include <stdio.h>
int a[4][4];
int b[4][4];
int r1;
int r2;
int new_puts(const char *str);
void solve()
{
  int first_iteration;
  int i;
  int j;
  int num = -1;
  int k;
  scanf("%d", &r1);
  for (i = 0; i < 4; i++)
    for (j = 0; j < 4; j++)
    scanf("%d", &a[i][j]);


  scanf("%d", &r2);
  for (i = 0; i < 4; i++)
    for (j = 0; j < 4; j++)
    scanf("%d", &b[i][j]);


  for (k = 1; k < 17; k++)
  {
    for (i = 0; i < 4; i++)
      if (a[r1 - 1][i] == k)
      goto next;


    continue;
    next:
    for (i = 0; i < 4; i++)
      if (b[r2 - 1][i] == k)
      goto next2;



    continue;
    next2:
    if (num > (-1))
    {
      new_puts("Bad magician!");
      return;
    }


    num = k;
  }

  if (num < 0)
    new_puts("Volunteer cheated!");
  else
    printf("%d\n", num);

}

int main()
{
  int first_iteration;
  int T;
  int no = 1;
  scanf("%d", &T);
  while (T--)
    printf("Case #%d: ", no++), solve();

  return 0;
}

int new_puts(const char *str)
{
  int first_iteration;
  return puts(str);
}


