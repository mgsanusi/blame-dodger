#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int cb;
int search(int pos, int j, int c)
{
  if (pos == 1)
    return 1;

  if ((pos == 2) && (((j * c) % 2) == 0))
    return 1;

  if ((((pos == 3) && (((j * c) % 3) == 0)) && (j > 1)) && (c > 1))
    return 1;

  if ((pos == 4) && (((j == 4) && (c >= 3)) || ((j >= 3) && (c == 4))))
    return 1;

  return 0;
}

int Main(void)
{
  int dataset_no;
  int case_no;
  int pos;
  int j;
  int c;
  scanf("%d", &dataset_no);
  for (case_no = 1; case_no <= dataset_no; ++case_no)
  {
    scanf("%d %d %d", &pos, &j, &c);
    printf("Case #%d: ", case_no);
    if (search(pos, j, c))
    {
      printf("GABRIEL\n");
    }
    else
    {
      printf("RICHARD\n");
    }

  }

  return 0;
}


